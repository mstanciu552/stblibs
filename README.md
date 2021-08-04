# stblibs
Repository with STB libraries.

## How to use
Pick a library. Copy the header file into your project and include it.
**Before** you include it make sure you define a macro that says you also want the implementation.
Example:
```c
#define CLILIB_IMPLEMENTATION
#include "stb_clilib.h"
```

## Libraries
1. [clilib.h](https://github.com/mstanciu552/stblibs/blob/main/stb_clilib.h)
**Header**
```c
#define CLILIB_IMPLEMENTATION
```
This library is used for easier handling of arguments(for CLI).
It has 4 simple functions.
- clilib_init
**No arguments.**
- declare_flags
name - the name of the argument
desc - the description of the argument
callback - a callback function to be executed 
- parse_flags
**Function to parse and execute specified args.**
- clilib_free
**No arguments.**
