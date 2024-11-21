#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // toupper
#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

struct Todo {
    char name[50];
    char time[50]; // creation time
    _Bool isDone;
};
typedef struct Todo Todo;

Todo todoList[50];
int todos = 0; // no. of todo
FILE *filePointer;

void saveToFile() {
    filePointer = fopen("./file.bin", "w"); // write operation
    if(!filePointer) {
        printf("\nCan not save your todo in file");
    } else {
        for(size_t i = 0; i < todos; i++) {
            fwrite(&todoList[i], sizeof(Todo), 1, filePointer);
        }
        fclose(filePointer);
    }
}

void getFileSize() {
    fseek(filePointer, 0L, SEEK_END);
    unsigned int long size = ftell(filePointer);
    fseek(filePointer, 0L, SEEK_SET);
    todos = size / sizeof(struct Todo);
}

void readFromFile() {
    filePointer = fopen("./file.bin", "r"); // read operation
    if(!filePointer) {
        printf("\nWe are not able to fetchs any todo from file");
    } else {
        getFileSize();
        for(size_t i = 0; i < todos; i++) {
            fread(&todoList[i], sizeof(Todo), 1, filePointer);
        }
        fclose(filePointer);
    }
}

void addTodo() {
    // Input todo title
    char inputName[50];
    printf("\nEnter todo : ");
    fflush(stdin);
    scanf("%[^\n]s",inputName);
    strcpy(todoList[todos].name, inputName);

    // store creation time
    char inputTime[50];
    time_t currentTime; // Variable to store time in seconds
    currentTime = time(NULL); // fetch current time
    struct tm *local_time; // Pointer to store broken-down time (year, month, day, etc.)
    local_time = localtime(&currentTime);
    strftime(inputTime, sizeof inputTime, "%d-%m-%Y %H:%M:%S", local_time);
    strcpy(todoList[todos].time, inputTime);

    // mark todo is not done at initial
    todoList[todos].isDone = false;
    todos++; // ready to store next todo
}

void viewTodos() {
    printf("+----+-------------------------------------+--------------------------+-------------+\n");
    printf("| ID |            Todo Title               |       Creation Time      |  Completed  |\n");
    printf("+----+-------------------------------------+--------------------------+-------------+\n");

    for (int i = 0; i < todos; i++)
    {
        printf("|%3d | %-35s | %-24s | %-11s |\n", i + 1, todoList[i].name, todoList[i].time, (!todoList[i].isDone) ? " No " : " Yes ");
        printf("+----+-------------------------------------+--------------------------+-------------+\n");
    }
}

void removeTodo() {
    int todoId;
    printf("\nEnter todo id: ");
    scanf("%d",&todoId);
    if(todoId < 0 || todoId > todos) {
        printf("\nInvalid todo id: %d", todoId);
    } else {
         // Shift elements to the left
        // for(int i = todoId; i < todos - 1; i++) {
        //     todoList[i] = todoList[i + 1];
        // }

        // Use memmove to shift elements after the index to the left
        if(todoId < todos-1) {
            memmove(&todoList[todoId], &todoList[todoId+1], (todos-todoId)*sizeof(todoList));
        }
        todos--;
        printf("\nYour todo has been deleted %d",todoId);
    }
}

void markAsDone() {
    int todoId;
    printf("\nEnter the todo id: ");
    scanf("%d", &todoId);
    todoId--; // at index
    if (todoId < 0 || todoId > todos) {
        printf("\nInvalid todo id %d",todoId);
    } else {
        todoList[todoId].isDone = true;
        printf("\nTodo marked as completed");
    }
}

void showOption() {
    char option;
    system("color 3F");
    system("cls");
    printf("A. Add todo\n");
    printf("V. View todos\n");
    printf("D. Delete todo\n");
    printf("M. Mark as done\n");
    printf("Q. Quit\n");
    option = getchar();
    option = toupper(option);
    getchar();
    switch (option) {
        case 'A':
            addTodo();
            break;
        case 'V':
            viewTodos();
            break;
        case 'D':
            removeTodo();
            getchar();
            break;
        case 'M':
            markAsDone();
            getchar();
            break;
        case 'Q':
            exit(0);
            break;
        default:
            printf("\nInvalid Input\n");
            showOption();
            break;
    }
    saveToFile();
    getchar();
    showOption();

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
    if (access("./file.bin", F_OK) != -1) {
        readFromFile();
        showOption();
    } else
    {
        showOption();
    }
}

int main() {
    system("cls");
    appStart();
    return 0;
}