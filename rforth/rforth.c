#include <stdio.h>
#include <stdlib.h>
#include "rforth_functions.h"
#include <string.h>

int_stack_t myStack;
const int capacity = 30;
const int var_capacity = 100;

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int_stack_init(&myStack, capacity);

    char* stringList[var_capacity];
    int intList[var_capacity];
    for (int i = 0; i < var_capacity; i++) {
        stringList[i] = NULL;
        intList[i] = 0;
    }
    printf("\033[0;95m"); //makes text pink by mixing blue and red ANSI color code
    printf("Type 'bye' to exit\n");//Changed for testing to get files to build and run
    printf("\033[0m"); //resets back to original text color
    while ((read = getline(&line, &len, stdin)) != -1) {
        
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        
        if (strcmp(line, "bye") == 0) {
            printf("\033[0;95m"); //makes text pink
            printf("Closing program\n");
            printf("\033[0m"); //resets back to original text color
            break;
        }

        separate_token(&myStack, line, stringList, intList); 
        print_forth(&myStack);
    }

    

    free(line);
    return 0;
}