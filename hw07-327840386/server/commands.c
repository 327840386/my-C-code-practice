#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

/*
* This function is called when the "help" command is entered.
* It writes a response to the response buffer.
* The argument is the rest of the string after the command name.
*/
int help(char* arg, char* response) {
    if (strlen(arg) == 0) {
        // No argument provided, return list of available commands
        sprintf(response, "Available commands: help, calc, sort");
    } else if (strcmp(arg, "calc") == 0) {
        sprintf(response, "Calculates the result of a op b. Usage: calc a op b");
    } else if (strcmp(arg, "sort") == 0) {
        sprintf(response, "Sorts a list of numbers. Usage: sort n1 n2 n3 …");
    } else {
        // Command not recognized
        sprintf(response, "This command does not exist");
    }
    return 0;
}

/*
* This function is called when the "calc" command is entered.
* It writes a response to the response buffer.
* The argument is the rest of the string after the command name.
*/
int calc(char* arg, char* response) {
    int a, b, result;
    char op;

    sscanf(arg, "%d%c%d", &a, &op, &b);

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                result = 0; // ignore division by zero
            }
            break;
        default:
            result = 0; // handle invalid operation
    }

    sprintf(response, "%d", result);
    return 0;
}

/*
* This function is called when the "sort" command is entered.
* It writes a response to the response buffer.
* The argument is the rest of the string after the command name.
*/
int sort(char* arg, char* response) {
    int num_args = 0;
    char* args[256];
    char* token = strtok(arg, " ");
    while (token != NULL) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    // Convert arguments to integers
    int nums[num_args];
    for (int i = 0; i < num_args; i++) {
        nums[i] = atoi(args[i]);
    }

    // Bubble sort algorithm
    for (int i = 0; i < num_args - 1; i++) {
        for (int j = 0; j < num_args - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // Convert sorted integers back to strings
    strcpy(response, "");
    for (int i = 0; i < num_args; i++) {
        char num_str[20];
        sprintf(num_str, "%d ", nums[i]);
        strcat(response, num_str);
    }

    return 0;
}

/*
* This function processes the command in the buffer and writes the response to the response buffer.
* It uses the commandFunc array to find the function to call based on the command name.
* The command name is the first word in the buffer, and the rest of the buffer is the argument to the command.
*/
int process(char* buf, char* response) {
    CommandFunc commands[] = {help, calc, sort}; // Add more commands here
    char* commandNames[] = {"help", "calc", "sort"}; // Add more command names here
    int numCommands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < numCommands; i++) {
        if (strncmp(buf, commandNames[i], strlen(commandNames[i])) == 0) {
            // Get the rest of the string after the command name, ignoring leading whitespace
            char* arg = buf + strlen(commandNames[i]);
            // Skip leading whitespace
            while (*arg == ' ') {
                arg++;
            }
            // strip the newline character from the end of the argument
            if (arg[strlen(arg) - 1] == '\n') {
                arg[strlen(arg) - 1] = '\0';
            }
            return commands[i](arg, response); // Call the command function
        }
    }

    return -1; // Invalid command
}