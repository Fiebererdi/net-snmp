/* This file was generated by mib2c and is intended for use as
   a mib module for the ucd-snmp snmpd agent. */


/* This should always be included first before anything else */
#include <net-snmp/net-snmp-config.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif


/* minimal include directives */
#include "mibincl.h"
#include "header_complex.h"
#include "mteTriggerDeltaTable.h"
#include "mteTriggerTable.h"
#include "snmp-tc.h"


/* 
 * mteTriggerDeltaTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */


oid mteTriggerDeltaTable_variables_oid[] = { 1,3,6,1,2,1,88,1,2,3 };


/* 
 * variable2 mteTriggerDeltaTable_variables:
 *   this variable defines function callbacks and type return information 
 *   for the mteTriggerDeltaTable mib section 
 */


struct variable2 mteTriggerDeltaTable_variables[] = {
/*  magic number        , variable type , ro/rw , callback fn  , L, oidsuffix */
#define   MTETRIGGERDELTADISCONTINUITYID  3
  { MTETRIGGERDELTADISCONTINUITYID, ASN_OBJECT_ID , RWRITE, var_mteTriggerDeltaTable, 2, { 1,1 } },
#define   MTETRIGGERDELTADISCONTINUITYIDWILDCARD  4
  { MTETRIGGERDELTADISCONTINUITYIDWILDCARD, ASN_INTEGER   , RWRITE, var_mteTriggerDeltaTable, 2, { 1,2 } },
#define   MTETRIGGERDELTADISCONTINUITYIDTYPE  5
  { MTETRIGGERDELTADISCONTINUITYIDTYPE, ASN_INTEGER   , RWRITE, var_mteTriggerDeltaTable, 2, { 1,3 } },

};
/*    (L = length of the oidsuffix) */


/* global storage of our data, saved in and configured by header_complex() */
extern struct header_complex_index *mteTriggerTableStorage;



/*
 * init_mteTriggerDeltaTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void init_mteTriggerDeltaTable(void) {
  DEBUGMSGTL(("mteTriggerDeltaTable", "initializing...  "));


  /* register ourselves with the agent to handle our mib tree */
  REGISTER_MIB("mteTriggerDeltaTable", mteTriggerDeltaTable_variables, variable2,
               mteTriggerDeltaTable_variables_oid);

  DEBUGMSGTL(("mteTriggerDeltaTable", "done.\n"));
}

/*
 * var_mteTriggerDeltaTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_mteTriggerDeltaTable above.
 */
unsigned char *
var_mteTriggerDeltaTable(struct variable *vp,
    	    oid     *name,
    	    size_t  *length,
    	    int     exact,
    	    size_t  *var_len,
    	    WriteMethod **write_method)
{


struct mteTriggerTable_data *StorageTmp = NULL;


  DEBUGMSGTL(("mteTriggerDeltaTable", "var_mteTriggerDeltaTable: Entering...  \n"));
  /* 
   * this assumes you have registered all your data properly
   */
  if ((StorageTmp =
       header_complex(mteTriggerTableStorage, vp,name,length,exact,
                      var_len,write_method)) == NULL)
      return NULL;

  /* 
   * this is where we do the value assignments for the mib results.
   */
  switch(vp->magic) {


    case MTETRIGGERDELTADISCONTINUITYID:
        *write_method = write_mteTriggerDeltaDiscontinuityID;
        *var_len = StorageTmp->mteTriggerDeltaDiscontinuityIDLen * sizeof(oid);
        return (u_char *) StorageTmp->mteTriggerDeltaDiscontinuityID;

    case MTETRIGGERDELTADISCONTINUITYIDWILDCARD:
        *write_method = write_mteTriggerDeltaDiscontinuityIDWildcard;
        *var_len = sizeof(StorageTmp->mteTriggerDeltaDiscontinuityIDWildcard);
        return (u_char *) &StorageTmp->mteTriggerDeltaDiscontinuityIDWildcard;

    case MTETRIGGERDELTADISCONTINUITYIDTYPE:
        *write_method = write_mteTriggerDeltaDiscontinuityIDType;
        *var_len = sizeof(StorageTmp->mteTriggerDeltaDiscontinuityIDType);
        return (u_char *) &StorageTmp->mteTriggerDeltaDiscontinuityIDType;


    default:
      ERROR_MSG("");
  }
  return NULL;
}




int
write_mteTriggerDeltaDiscontinuityID(int      action,
            u_char   *var_val,
            u_char   var_val_type,
            size_t   var_val_len,
            u_char   *statP,
            oid      *name,
            size_t    name_len)
{
  static oid * tmpvar;
  struct mteTriggerTable_data *StorageTmp = NULL;
  static size_t tmplen;
  size_t newlen=name_len - (sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1);


  DEBUGMSGTL(("mteTriggerDeltaTable", "write_mteTriggerDeltaDiscontinuityID entering action=%d...  \n", action));
  if ((StorageTmp =
       header_complex(mteTriggerTableStorage, NULL,
                      &name[sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1], 
                      &newlen, 1, NULL, NULL)) == NULL)
      return SNMP_ERR_NOSUCHNAME; /* remove if you support creation here */


  switch ( action ) {
        case RESERVE1:
          if (var_val_type != ASN_OBJECT_ID){
              fprintf(stderr, "write to mteTriggerDeltaDiscontinuityID not ASN_OBJECT_ID\n");
              return SNMP_ERR_WRONGTYPE;
          }
          if (StorageTmp->storageType != ST_NONVOLATILE)
              return SNMP_ERR_NOTWRITABLE;
          break;


        case RESERVE2:
             /* memory reseveration, final preparation... */
          break;


        case FREE:
             /* Release any resources that have been allocated */
          break;


        case ACTION:
             /* The variable has been stored in objid for
             you to use, and you have just been asked to do something with
             it.  Note that anything done here must be reversable in the UNDO case */
             tmpvar = StorageTmp->mteTriggerDeltaDiscontinuityID;
             tmplen = StorageTmp->mteTriggerDeltaDiscontinuityIDLen;
             memdup((u_char **) &StorageTmp->mteTriggerDeltaDiscontinuityID, var_val, var_val_len);
             StorageTmp->mteTriggerDeltaDiscontinuityIDLen = var_val_len/sizeof(oid);
          break;


        case UNDO:
             /* Back out any changes made in the ACTION case */
             SNMP_FREE(StorageTmp->mteTriggerDeltaDiscontinuityID);
             StorageTmp->mteTriggerDeltaDiscontinuityID = tmpvar;
             StorageTmp->mteTriggerDeltaDiscontinuityIDLen = tmplen;
          break;


        case COMMIT:
             /* Things are working well, so it's now safe to make the change
             permanently.  Make sure that anything done here can't fail! */
     SNMP_FREE(tmpvar);
          break;
  }
  return SNMP_ERR_NOERROR;
}



int
write_mteTriggerDeltaDiscontinuityIDWildcard(int      action,
            u_char   *var_val,
            u_char   var_val_type,
            size_t   var_val_len,
            u_char   *statP,
            oid      *name,
            size_t    name_len)
{
  static int tmpvar;
  struct mteTriggerTable_data *StorageTmp = NULL;
  size_t newlen=name_len - (sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1);


  DEBUGMSGTL(("mteTriggerDeltaTable", "write_mteTriggerDeltaDiscontinuityIDWildcard entering action=%d...  \n", action));
  if ((StorageTmp =
       header_complex(mteTriggerTableStorage, NULL,
                      &name[sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1], 
                      &newlen, 1, NULL, NULL)) == NULL)
      return SNMP_ERR_NOSUCHNAME; /* remove if you support creation here */


  switch ( action ) {
        case RESERVE1:
          if (var_val_type != ASN_INTEGER){
              fprintf(stderr, "write to mteTriggerDeltaDiscontinuityIDWildcard not ASN_INTEGER\n");
              return SNMP_ERR_WRONGTYPE;
          }
          if (StorageTmp->storageType != ST_NONVOLATILE)
              return SNMP_ERR_NOTWRITABLE;
          break;


        case RESERVE2:
             /* memory reseveration, final preparation... */
          break;


        case FREE:
             /* Release any resources that have been allocated */
          break;


        case ACTION:
             /* The variable has been stored in long_ret for
             you to use, and you have just been asked to do something with
             it.  Note that anything done here must be reversable in the UNDO case */
             tmpvar = StorageTmp->mteTriggerDeltaDiscontinuityIDWildcard;
             StorageTmp->mteTriggerDeltaDiscontinuityIDWildcard = *((long *) var_val);
          break;


        case UNDO:
             /* Back out any changes made in the ACTION case */
             StorageTmp->mteTriggerDeltaDiscontinuityIDWildcard = tmpvar;
          break;


        case COMMIT:
             /* Things are working well, so it's now safe to make the change
             permanently.  Make sure that anything done here can't fail! */

          break;
  }
  return SNMP_ERR_NOERROR;
}



int
write_mteTriggerDeltaDiscontinuityIDType(int      action,
            u_char   *var_val,
            u_char   var_val_type,
            size_t   var_val_len,
            u_char   *statP,
            oid      *name,
            size_t    name_len)
{
  static int tmpvar;
  struct mteTriggerTable_data *StorageTmp = NULL;
  size_t newlen=name_len - (sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1);


  DEBUGMSGTL(("mteTriggerDeltaTable", "write_mteTriggerDeltaDiscontinuityIDType entering action=%d...  \n", action));
  if ((StorageTmp =
       header_complex(mteTriggerTableStorage, NULL,
                      &name[sizeof(mteTriggerDeltaTable_variables_oid)/sizeof(oid) + 3 - 1], 
                      &newlen, 1, NULL, NULL)) == NULL)
      return SNMP_ERR_NOSUCHNAME; /* remove if you support creation here */


  switch ( action ) {
        case RESERVE1:
          if (var_val_type != ASN_INTEGER){
              fprintf(stderr, "write to mteTriggerDeltaDiscontinuityIDType not ASN_INTEGER\n");
              return SNMP_ERR_WRONGTYPE;
          }
          if (StorageTmp->storageType != ST_NONVOLATILE)
              return SNMP_ERR_NOTWRITABLE;
          break;


        case RESERVE2:
             /* memory reseveration, final preparation... */
          break;


        case FREE:
             /* Release any resources that have been allocated */
          break;


        case ACTION:
             /* The variable has been stored in long_ret for
             you to use, and you have just been asked to do something with
             it.  Note that anything done here must be reversable in the UNDO case */
             tmpvar = StorageTmp->mteTriggerDeltaDiscontinuityIDType;
             StorageTmp->mteTriggerDeltaDiscontinuityIDType = *((long *) var_val);
          break;


        case UNDO:
             /* Back out any changes made in the ACTION case */
             StorageTmp->mteTriggerDeltaDiscontinuityIDType = tmpvar;
          break;


        case COMMIT:
             /* Things are working well, so it's now safe to make the change
             permanently.  Make sure that anything done here can't fail! */

          break;
  }
  return SNMP_ERR_NOERROR;
}








