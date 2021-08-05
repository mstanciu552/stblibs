// MACROS NEEDE
// #define CLILIB_IMPLEMENTATION -- for adding implementations
// #define VALUE_FLAGS -- for value key paired flags

// Header part
#ifndef CLILIB_H_
#define CLILIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Flag {
  char *name;
  char *desc;
  void (*callback)();
} Flag;
  
void clilib_init(int argc, char **argv);
void declare_flag(char *name, char *desc, void (*callback)());
void create_help_list();
void parse_flags();
void clilib_free();

// Add functions that work for programs that have key value pairs
// as program arguments.
#ifdef VALUE_FLAGS

char *get_flag_value(char *name);

bool declare_bool_flag(char* name, char *desc, bool default_value);
int declare_int_flag(char* name, char *desc, int default_value);
char declare_char_flag(char* name, char *desc, char default_value);
char *declare_string_flag(char* name, char *desc, char *default_value);

#endif

#endif // CLILIB_H_

// Implementation part
#ifdef CLILIB_IMPLEMENTATION
  
Flag **flags;
int flag_count;
char **args;
int arg_count;

void clilib_init(int argc, char **argv) {
  flags = (Flag**) malloc(20 * sizeof(Flag*));
  flag_count = 0;
  arg_count = argc;
  args = argv;
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

void parse_flags() {
  char *current_flag = args[arg_count - 1];
  if (!strcmp(current_flag, "--help")) {
    create_help_list();
  }
  for (int i = 0; i < flag_count; i++) {
    if (!strcmp(current_flag, flags[i]->name)) {
      if (*flags[i]->callback) (*flags[i]->callback)();
    }
  }
}

void clilib_free() {
  free(flags);
  free(args);
}

// Key value pairs implementations
#ifdef VALUE_FLAGS

// Structure
// --<flag_name>=<flag_value>
char *get_flag_value(char *name) {
  char *value = (char*) malloc(strlen(name) * sizeof(char));
  for (int i = 1; i < arg_count; i++) {
    if (strstr(args[i], name)) {
      char* eq = strchr(args[i], '=');
      if (eq) strcpy(value, eq + 1);
    }
  }
  return value;
} 


bool declare_bool_flag(char *name, char *desc, bool default_value) {
  char *value = get_flag_value(name);
  declare_flag(name, desc, NULL);
  if (strlen(value) < 1)
    return default_value;
  else
    return (!strcmp(value, "true") || !strcmp(value, "1")) ? true : false;
}
// TODO Fix this
int declare_int_flag(char *name, char *desc, int default_value) {
  char *value = get_flag_value(name);
  declare_flag(name, desc, NULL);
  if (strlen(value) < 1)
    return default_value;
  else 
    return atoi(value);
}

char declare_char_flag(char *name, char *desc, char default_value) {
  char *value = get_flag_value(name);
  declare_flag(name, desc, NULL);
  if (strlen(value) < 1)
    return default_value;
  else
    return value[0];
}

char *declare_string_flag(char *name, char *desc, char *default_value) {
  char *value = get_flag_value(name);
  declare_flag(name, desc, NULL);
  if (strlen(value) < 1)
    return default_value;
  else
    return value;
}

#endif

#endif
