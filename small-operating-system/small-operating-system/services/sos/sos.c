#include "sos.h"
#include <stdlib.h>

/* Initialize the DB global pointer to NULL. */
st_SOS_task_property_t* (*g_ptr_SOS_db)[5] = NULL;

/**
 * @brief Creates the DB instance and assigns the address of this DB to the global DB pointer.
 *  - This is done using the malloc() function where we allocate the DB on the head in accordance to the number of tasks
 *  defined in the sos.h file.
 *  - Then the address of the allocated DB is assigned to the DB global address.
 *  - A nullification to all the elements of the array to prevent segmentation fault.
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

/**
 * @brief De-allocates the created DB instance and pointing the global DB pointer to NULL.
 * - This is done using the free() function.
 * @return en_SOS_SYSTEM_STATUS_t
 */
en_SOS_SYSTEM_STATUS_t SOS_deinit(void) {
    if (g_ptr_SOS_db == NULL) {
        return SOS_STATUS_INVALID_STATE;
    } else {
        /* Delete the DB from the heap. */
        free(g_ptr_SOS_db);

        /* Assign the address of the DB to NULL to prevent segmentation fault. */
        g_ptr_SOS_db = NULL;
    }
    return SOS_STATUS_SUCCESS;
}

