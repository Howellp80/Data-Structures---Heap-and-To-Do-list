/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
	Task* newTask = malloc(sizeof(Task));
	assert(newTask != 0);  

	newTask->priority = priority;
	strcpy(newTask->name, name);

	return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
	// cast the void pointers
	struct Task *lTask, *rTask;
	lTask = (struct Task *) left;
	rTask = (struct Task *) right;

	// compare values
	if (lTask->priority < rTask->priority)
		return -1;
	else if (lTask->priority > rTask->priority)
		return 1;
	else
		return 0;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
