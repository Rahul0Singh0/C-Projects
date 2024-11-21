#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // toupper
#include <time.h>
#include <stdbool.h>

struct Todo {
    char name[50];
    char time[50]; // creation time
    _Bool isDone;
};
typedef struct Todo Todo;

Todo todoList[50];
int todos = 0; // no. of todo

void addTodo() {
    // Input todo title
    char inputName[50];
    pritnf("\nEnter todo : ");
    fflush(stdin);
    scanf("%[^\n]s",inputName);
    strcpy(todoList->name[todos], inputName);

    // store creation time
    char inputTime[50];
    time_t currentTime; // Variable to store time in seconds
    struct tm *local_time; // Pointer to store broken-down time (year, month, day, etc.)
    // Convert to local time format
    local_time = localtime(&currentTime);
    strftime(inputTime, sizeof inputTime, "%d-%m-%Y %H:%M:%S", local_time);
    strcpy(todoList->time[todos], inputTime);

    // mark todo is not done at initial
    todoList->isDone = false;
    todos++; // ready to store next todo
}
void removeTodo();
void listTodos();
void markAsDone();

void showOption() {
    char option;
    system("color 3F");
    while(1) {
        system("cls");
        printf("A. Add todo\n");
        printf("V. View todos\n");
        printf("D. Delete todo\n");
        printf("M. Mark as done\n");
        printf("Q. Quit\n");
        scanf("%c",&option);
        option = toupper(option);
        switch (option) {
            case 'A':
                addTodo();
                break;
            case 'V':
                // listTodos();
                break;
            case 'D':
                // removeTodo();
                break;
            case 'M':
                // markAsDone();
                break;
            case 'Q':
                exit(0);
                break;
            default:
                printf("\nInvalid Input\n");
                showOption();
                break;
        }
    }
}

void interface() {
    system("color 8F");
    printf("\n\n\n");
    printf("\t`````````````````````````````````````````````````````````````````````````````\n");
    printf("\t`````````````````````````````````````````````````````````````````````````````\n\n");
    printf("\t[[[[[[[[[[[[[[[[[[[[[[[[[[[ Welcome To Todo App ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]\n\n\n");
    printf("\t@Rahul Singh\n\n\n\n\n\n\n");
    system("pause");
}

void appStart() {
    interface();
    showOption();
}

int main() {
    system("cls");
    appStart();
    return 0;
}