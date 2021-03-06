#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "command.h"

extern char *optarg;
extern int optind;

/**
 * @brief The cli mode processing function
 * 
 * @param argc
 * @param argv 
 * @return int 0 if normal
 */
int cli(int argc, char *argv[]) {
    InputHandler handler;
    initInputHandler(&handler);
    /**
     * We start at optind -1 because the cli option requires at least one argument 
     * 
     */
    for (optind = optind - 1; optind < argc; optind++) {
        handleInput(&handler, argv[optind], strlen(argv[optind]));
    }
    destroyInputHandler(&handler);
    return 0;
}