/**************************************************************
 ********          THIS IS A GENERATED FILE         ***********
 **************************************************************/

#ifndef QDM_QEOANIMALEVENTMESSAGE_H_
#define QDM_QEOANIMALEVENTMESSAGE_H_

#include <qeo/types.h>


/**
 * Change de poid de la gamelle
 */
typedef struct {
    /**
     * uuid de la gamelle.
     */
    char * uuid;
    /**
     * the new poids
     */
    float weight;
    /**
     * timestamp
     */
    int32_t timestamp;
} qeo_animall_gamelle_NewWeight_t;
extern const DDS_TypeSupport_meta qeo_animall_gamelle_NewWeight_type[];

/**
 * Change de poid de la gamelle
 */
typedef struct {
    /**
     * uuid de la gamelle.
     */
    char * uuid;
    /**
     * the new poids
     */
    float weight;
    /**
     * timestamp
     */
    int32_t timestamp;
} qeo_animall_balance_NewWeight_t;
extern const DDS_TypeSupport_meta qeo_animall_balance_NewWeight_type[];


#endif /* QDM_QEOANIMALEVENTMESSAGE_H_ */

