#include <stdio.h>
#include <string.h>

void printMenu() {
    printf("\nSIMPLE PLANNER\n");
    printf("1. ADD TASK\n");
    printf("2. VIEW TASK\n");
    printf("3. VIEW ALL TASKS\n");
    printf("4. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
}

int main() {
    char tasks[15][200];   // up to 15 tasks, each max 200 chars
    int count = 0;         // number of tasks added
    int choice;

    while (1) {   // keep showing menu until user exits
        printMenu();
        scanf(" %d", &choice);   // space before %d skips stray newlines

        switch (choice) {
            case 1:  // ADD TASK
                if (count == 15) {
                    printf("Task list is full\n");
                    break;
                }
                printf("Enter your task: ");
                getchar();   // consume leftover newline
                fgets(tasks[count], 200, stdin);
                tasks[count][strcspn(tasks[count], "\n")] = '\0'; // remove newline
                count++;
                printf("Task added!\n");
                break;

            case 2: {  // VIEW TASK
                if (count == 0) {
                    printf("No tasks available\n");
                    break;
                }
                printf("Enter task number 1-%d: ", count);
                int t;
                scanf("%d", &t);

                if (t < 1 || t > count) {
                    printf("Invalid task number\n");
                    break;
                }
                printf("Task %d: %s\n", t, tasks[t-1]);
                break;
            }

            case 3:  // VIEW ALL TASKS
                if (count == 0) {
                    printf("No tasks available\n");
                    break;
                }
                printf("ALL TASKS:\n");
                for (int j = 0; j < count; j++) {
                    printf("%d. %s\n", j+1, tasks[j]);
                }
                break;

            case 4:  // EXIT
                printf("Exiting planner...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}