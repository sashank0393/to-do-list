#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char description[100];
    int completed;
};

struct Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks < MAX_TASKS) {
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[numTasks].description);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void displayTasks() {
    if (numTasks == 0) {
        printf("No tasks to display.\n");
    } else {
        printf("Tasks:\n");
        for (int i = 0; i < numTasks; i++) {
            printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
        }
    }
}

void markTaskCompleted() {
    displayTasks();
    if (numTasks > 0) {
        printf("Enter task number to mark as completed: ");
        int taskNumber;
        scanf("%d", &taskNumber);

        if (taskNumber > 0 && taskNumber <= numTasks) {
            tasks[taskNumber - 1].completed = 1;
            printf("Task marked as completed!\n");
        } else {
            printf("Invalid task number.\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
