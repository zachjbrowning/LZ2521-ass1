#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dict.h"

#define MAX 8192



static char **tokenise(char *s, int *ntokens);
static int getCommand(char *buf);

static void runSearch(Dict d, char **tokens);
static void runList(Dict d, char **tokens);
static void runHelp(Dict d, char **tokens);

static bool validateSearch(char **tokens);
static bool validateNoArgs(char **tokens);

/*
        Command types!!
*/

#define NUM_COMMANDS 4

typedef struct command {
    char *code;
    int numArgs;
    void (*fn)(Dict, char **);
    bool (*validateArgs)(char **);
    char *argHint;
    char *helpMsg;
} Command;

static Command COMMANDS[NUM_COMMANDS] = {
    {"s", 1, runSearch, validateSearch, "<string>", "search for a verb"},
    {"l", 0, runList, validateNoArgs, "", "list most frequently searched verbs"},
    {"q", 0, NULL, validateNoArgs, "", "quit"},
    {"?", 0, runHelp, validateNoArgs, "", "show this message"},
};

/*
    Main function
*/

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Invalid arguments. Correct usage:  '%s [filename].\n'", argv[0]);
        return 0;
    }

    FILE *translations = fopen(argv[1], "r");
    if (translations == NULL) {
        printf("Invalid filename.\n");
        return 0;
    }

    Dict dictionary = buildDict(translations);
    fclose(translations);

    if (dictionary == NULL) {
        printf("Please implememnt Part 1 to use translator.\n");
        return 0;
    }

    bool done = false;
    char cmd[MAX] = {0};

    while (!done && getCommand(cmd)) {

        int ntokens = 0;
        char **tokens = tokenise(cmd, &ntokens);
        char *cmd = tokens[0];

        if (strcmp(cmd, "q") == 0) done = true;
        else {
            bool isValid = false;

            for (int i = 0; i < NUM_COMMANDS; i++) {
                if (strcmp(cmd, COMMANDS[i].code) == 0) {
                    isValid = true;

                    if (ntokens - 1 == COMMANDS[i].numArgs && COMMANDS[i].validateArgs(tokens)) {
                        COMMANDS[i].fn(dictionary, tokens);
                    } else {
                        printf("Usage: %s %s\n", COMMANDS[i].code, COMMANDS[i].argHint);
                    }
                }
            } 
            if (!isValid) printf("Unkown command '%s'\n", cmd);
        }
        free(tokens);
    }

    freeDict(dictionary);
}



/*
        RUN COMMANDS
*/
static void runSearch(Dict d, char **tokens) {
    char query[MAX];
    sscanf(tokens[1], "%s", query);
    searchDict(d, query);
}
static void runList(Dict d, char **tokens) {
    listFrequent(d);
}

static void runHelp(Dict d, char **tokens) {
    printf("Commands:\n");
    for (int i = 0; i < NUM_COMMANDS; i++) {
        printf("%5s %-24s %s\n", COMMANDS[i].code, COMMANDS[i].argHint,
                                 COMMANDS[i].helpMsg);
    }
    printf("\n");
}

/*
        VALIDATE COMMANDS
*/
static bool validateSearch(char **tokens) {
    return true;
}

static bool validateNoArgs(char **tokens) {
    return true;
}


/*
    Helpers
*/

static int getCommand(char *buf) {
    printf("> ");
	return (fgets(buf, MAX, stdin) != NULL);  
}

static char **tokenise(char *s, int *ntokens) {
    char p;

    // count number of tokens
    *ntokens = 0;
    p = ' ';
    for (char *c = s; *c != '\0'; p = *c, c++) {
        if (p == ' ' && *c != ' ') {
            (*ntokens)++;
        }
    }

    char **tokens = malloc((*ntokens + 1) * sizeof(char *));
    int i = 0;
    p = ' ';
    for (char *c = s; *c != '\0'; p = *c, c++) {
        if ((p == '\0' || p == ' ') && *c != ' ') {
            tokens[i++] = c;
        } else if (p != ' ' && (*c == ' ' || *c == '\n')) {
            *c = '\0';
        }
    }
    tokens[i] = NULL;
    
    return tokens;
}