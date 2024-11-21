#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // toupper

void addTodo();
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