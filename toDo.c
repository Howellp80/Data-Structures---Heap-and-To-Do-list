/*
 * CS 261 Assignment 5
 * Name: Parker Howell
 * Date: 5-14-16
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
	printf("\n");
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
	//"'l' to load to-do list from a file\n"
	if (command == 'l'){
		char filename[50];
		printf("Please enter the filename : ");
		fgets(filename, 50, stdin);
		
		FILE* inputFile = fopen(filename, "r");

		listLoad(list, inputFile);
		fclose(inputFile);

		printf("The list has been loaded from file successfully.\n\n");
	}

	//"'s' to save to-do list to a file\n"
	else if (command == 's'){
		char filename[50];
		printf("Please enter the filename : ");
		fgets(filename, 50, stdin);
		
		FILE* outputFile = fopen(filename, "w");

		listSave(list, outputFile);
		fclose(outputFile);

		printf("The list has been saved into the file successfully.\n\n");	
	}

	//"'a' to add a new task\n"
	else if (command == 'a'){
		char name[50];
		char priority[50];
		int pri;
		printf("Please enter the task description : ");
		fgets(name, 50, stdin);

		printf("Please enter the task priority(0 - 999) :");
		//scanf("%d", &pri);
		//
		fgets(priority, sizeof(priority), stdin);
		sscanf(priority, "%d", &pri);

		Task* newTask = taskNew(pri, name);
		dyHeapAdd(list, newTask, taskCompare);

		printf("The task '");
		printf("%s", newTask->name);
		printf("' has been added to your to - do list.\n\n");
	}

	//"'g' to get the first task\n"
	else if (command == 'g'){
		if (dySize(list) > 0){
			printf("Your first task is : ");
			Task* task = dyHeapGetMin(list);
			printf("%s\n\n", task->name);
		}
		else
			printf("Your to-do list is empty!\n\n");
	}

	//"'r' to remove the first task\n"
	else if (command == 'r'){
		if (dySize(list) > 0){
			printf("Your first task, '");
			Task* task = dyHeapGetMin(list);
			printf("%s", task->name);
			printf("', has been removed from the list.\n\n");

			dyHeapRemoveMin(list, taskCompare);
		}
		else
			printf("Your to-do list is empty!\n\n");
	}

	//"'p' to print the list\n"
	else if (command == 'p'){
		listPrint(list);
	}

	//"'e' to exit the program\n"
	else if (command == 'e'){
		printf("Bye!\n\n");
	}

	else
		printf("Please enter a valid command.\n\n");

}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}