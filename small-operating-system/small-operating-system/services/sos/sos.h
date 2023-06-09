#ifndef SOS_H_
#define SOS_H_

#include "../../utilities/std_types.h"

#define NUM_OF_TASKS 5

/**
 * @brief Describes the system status of the OS.
 * 
 */
typedef enum {
    SOS_STATUS_SUCCESS, SOS_STATUS_INVALID_STATE
}en_SOS_SYSTEM_STATUS_t;

/**
 * @brief Tasks configuration structure.
 * @var st_SOS_TASK_t::pid
 * The task's unique ID.
 * @var st_SOS_TASK_t::process_priority_level
 * The task's priority level.
 * This is a value staring from 1, where 1 is the highest priority task.
 */
typedef struct {
    uint8 process_id;
    uint8 process_priority_level;
    void (*fptr_task) (void);
}st_SOS_task_property_t;


/*Global pointer to the address of the database.*/
extern st_SOS_task_property_t* (*g_ptr_SOS_db)[5];

/**
 * @brief Creates the DB instance and assigns the address of this DB to the global pointer.
 *
 * @return en_SOS_SYSTEM_STATUS_t 
 */
en_SOS_SYSTEM_STATUS_t SOS_init(void);

/**
 * @brief De-allocates the created DB instance and points the DB pointer to NULL.
 *
 * @return en_SOS_SYSTEM_STATUS_t 
 */
en_SOS_SYSTEM_STATUS_t SOS_deinit(void);

/**
 * @brief Adds a new task to the database.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 * @param priority_level Task's priority level.
 */
en_SOS_SYSTEM_STATUS_t SOS_crateTask(st_SOS_task_property_t* (*ptr_st_SOS_DB)[NUM_OF_TASKS], uint8 pid, uint8 priority_level, void (*fptr_task) (void));

/**
 * @brief Removes a task from the database.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 */
en_SOS_SYSTEM_STATUS_t SOS_deleteTask(st_SOS_task_property_t* (*ptr_st_SOS_DB)[NUM_OF_TASKS], uint8 pid);

/**
 * @brief Modifies the priority level of a task.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 * @param priority_level Task's priority level.
 */
en_SOS_SYSTEM_STATUS_t SOS_modifyTask(st_SOS_task_property_t* (*ptr_st_SOS_DB)[NUM_OF_TASKS], uint8 pid, uint8 priority_level);

/**
 * @brief Runs the small OS.
 * This is done by loading the timer with a preloaded value which will be the period of every task.
 * @param ptr_st_SOS_DB Address of the tasks database.
 */
void SOS_run(st_SOS_task_property_t *ptr_st_SOS_DB);

/**
 * @brief Halts the operation of the small OS.
 * This is done by disengaging the timer.
 * @param ptr_st_SOS_DB Address of the tasks database.
 */
void SOS_disable(st_SOS_task_property_t *ptr_st_SOS_DB);

#endif /* SOS_H_ */
