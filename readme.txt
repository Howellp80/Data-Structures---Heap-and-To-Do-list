This assignmnet had us implement a heap-based Priority Queue, including the Heapsort algorithm. 
This Priority Queue is then used to implement a To-Do List.

The Heap interface is provided via functions defined in dynamicArray.c
A basic test suite can be found in tests.c

The To-Do List will prompt the user with 7 options:
l to load the list from a file (function implemented for you).
s to save the list to a file (function implemented for you).
a to add a new task to the list.
g to get the first task from the list.
r to remove the first task from the list.
p to print the list (function implemented for you).
e to exit the program.

To run
Add all included files to your directory and type:
$ make all
$ toDo

or to run the tests you can type:
$ tests

To clean up type:
$ make clean
