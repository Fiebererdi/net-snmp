#include <net-snmp/net-snmp-config.h>

#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#include "mibincl.h"
#include "tools.h"
#include "snmp_agent.h"
#include "bulk_to_next.h"

#if HAVE_DMALLOC_H
#include <dmalloc.h>
#endif

/** @defgroup bulk_to_next bulk_to_next: convert GETBULK requests into GETNEXT requests for the handler.
 *  The only purpose of this handler is to convert a GETBULK request
 *  to a GETNEXT request.  It is inserted into handler chains where
 *  the handler has not set the HANDLER_CAN_GETBULK flag.
 *  @ingroup handler
 *  @{
 */

/** returns a bulk_to_next handler that can be injected into a given
 *  handler chain.
 */
mib_handler *
get_bulk_to_next_handler(void) {
    return create_handler("bulk_to_next", bulk_to_next_helper);
}

/** @internal Implements the bulk_to_next handler */
int
bulk_to_next_helper(
    mib_handler               *handler,
    handler_registration      *reginfo,
    agent_request_info        *reqinfo,
    request_info              *requests) {

    int ret;
    request_info              *request;

    switch(reqinfo->mode) {
        
        case MODE_GETBULK:
            reqinfo->mode = MODE_GETNEXT;
            ret = call_next_handler(handler, reginfo, reqinfo, requests);
            reqinfo->mode = MODE_GETBULK;

            /* update the varbinds for the next request series */
            for(request = requests; request; request = request->next) {
                if (request->repeat && request->requestvb->type != ASN_NULL &&
                    request->requestvb->type != ASN_PRIV_RETRY) {
                    request->repeat--;
                    snmp_set_var_objid(request->requestvb->next_variable,
                                       request->requestvb->name,
                                       request->requestvb->name_length);
                    request->requestvb =
                        request->requestvb->next_variable;
                    request->requestvb->type = ASN_PRIV_RETRY;
                }
            }
            return ret;
            
        default:
            return call_next_handler(handler, reginfo, reqinfo, requests);
    }
    return SNMP_ERR_GENERR; /* should never get here */
}

/** initializes the bulk_to_next helper which then registers a bulk_to_next
 *  handler as a run-time injectable handler for configuration file
 *  use.
 */
void
init_bulk_to_next_helper(void) 
{
    register_handler_by_name("bulk_to_next", get_bulk_to_next_handler());
}
