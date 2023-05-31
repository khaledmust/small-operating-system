#include "sos.h"
#include <stdlib.h>

st_SOS_task_property_t* (*g_ptr_SOS_db)[5] = NULL;

/**
 * @brief Creates the DB instance and assigns the address of this DB to the global pointer.
 *
 * @return en_SOS_SYSTEM_STATUS_t
 */
en_SOS_SYSTEM_STATUS_t SOS_init(void) {
    if (g_ptr_SOS_db != NULL) {
        return SOS_STATUS_INVALID_STATE;
    } else {
        /* Allocate an array of structure pointers on the heap. */
        st_SOS_task_property_t* (*ptr_tmp_SOS_db)[NUM_OF_TASKS] = malloc(NUM_OF_TASKS * sizeof(st_SOS_task_property_t*));

        /* Assign the address of the created array to the global database pointer. */
        g_ptr_SOS_db = ptr_tmp_SOS_db;

        /* Iterate over every element of the DB and assign it to NULL. */
        int i;
        for (i = 0; i < NUM_OF_TASKS; i++) {
            (*g_ptr_SOS_db)[i] = NULL;
        }
    }
    return SOS_STATUS_SUCCESS;
}

