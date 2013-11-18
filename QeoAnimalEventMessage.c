/**************************************************************
 ********          THIS IS A GENERATED FILE         ***********
 **************************************************************/

#include "QeoAnimalEventMessage.h"

const DDS_TypeSupport_meta qeo_animall_gamelle_NewWeight_type[] = {
    { .tc = CDR_TYPECODE_STRUCT, .name = "qeo.animall.gamelle.NewWeight", .flags = TSMFLAG_DYNAMIC|TSMFLAG_GENID|TSMFLAG_MUTABLE, .nelem = 3, .size = sizeof(qeo_animall_gamelle_NewWeight_t) },  
    { .tc = CDR_TYPECODE_CSTRING, .name = "from", .flags = TSMFLAG_DYNAMIC, .offset = offsetof(qeo_animall_gamelle_NewWeight_t, from), .size = 0 },  
    { .tc = CDR_TYPECODE_FLOAT, .name = "weight", .offset = offsetof(qeo_animall_gamelle_NewWeight_t, weight) },  
    { .tc = CDR_TYPECODE_LONG, .name = "timestamp", .offset = offsetof(qeo_animall_gamelle_NewWeight_t, timestamp) },  
};

const DDS_TypeSupport_meta qeo_animall_balance_NewWeight_type[] = {
    { .tc = CDR_TYPECODE_STRUCT, .name = "qeo.animall.balance.NewWeight", .flags = TSMFLAG_DYNAMIC|TSMFLAG_GENID|TSMFLAG_MUTABLE, .nelem = 3, .size = sizeof(qeo_animall_balance_NewWeight_t) },  
    { .tc = CDR_TYPECODE_CSTRING, .name = "from", .flags = TSMFLAG_DYNAMIC, .offset = offsetof(qeo_animall_balance_NewWeight_t, from), .size = 0 },  
    { .tc = CDR_TYPECODE_FLOAT, .name = "weight", .offset = offsetof(qeo_animall_balance_NewWeight_t, weight) },  
    { .tc = CDR_TYPECODE_LONG, .name = "timestamp", .offset = offsetof(qeo_animall_balance_NewWeight_t, timestamp) },  
};
