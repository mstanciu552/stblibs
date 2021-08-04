// Header part
#ifndef CLILIB_H_
#define CLILIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flag {
  char *name;
  char *desc;
  void (*callback)();
} Flag;
  
void clilib_init();
void declare_flag(char *name, char *desc, void (*callback)());
void create_help_list();
void parse_flags(int argc, char **argv);
void clilib_free();

#endif // CLILIB_H_

// Implementation part
#ifdef CLILIB_IMPLEMENTATION
  
Flag **flags;
int flag_count;

void clilib_init() {
  flags = (Flag**) malloc(20 * sizeof(Flag*));
  flag_count = 0;
}

void declare_flag(char *name, char *desc, void (*callback)()) {
  flags[flag_count] = (Flag*) malloc(sizeof(Flag));
  flags[flag_count]->name = name;
  flags[flag_count]->desc = desc;
  flags[flag_count]->callback = callback;
  flag_count++;
}

void create_help_list() {
  for (int i = 0; i < flag_count; i++) {
    printf("%s\n\t%s\n", flags[i]->name, flags[i]->desc);
  }
}

void parse_flags(int argc, char **argv) {
  char *current_flag = argv[argc - 1];
  if (!strcmp(current_flag, "--help")) {
    create_help_list();
  }
  for (int i = 0; i < flag_count; i++) {
    if (!strcmp(current_flag, flags[i]->name)) {
      (*flags[i]->callback)();
    }
  }
}

void clilib_free() {
  free(flags);
}

#endif
