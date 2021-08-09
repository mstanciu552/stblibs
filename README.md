# stblibs
Repository with STB libraries.

## How to use
Pick a library. Copy the header file into your project and include it.
**Before** you include it make sure you define a macro that says you also want the implementation.

## Libraries
1. [stb_clilib.h](https://github.com/mstanciu552/stblibs/blob/main/stb_clilib.h)
**Header**
```c
#define CLILIB_IMPLEMENTATION
#define VALUE_FLAGS // optional
#include "stb_clilib.h"
```
This library is used for easier handling of arguments(for CLI).

- clilib_init -- must be called before using anything else
**No arguments.**

- declare_flags

name - the name of the argument
desc - the description of the argument
callback - a callback function to be executed 

- parse_flags

**Function to parse and execute specified args callback function.**

**IF** the flag **VALUE_FLAGS** is set these functions can also be used.

- declare_{int,bool,char,char*}_flag

name - the name of the argument
desc - the description of the argument
default_value - value that is returned if the flag is not set

- clilib_free -- must be called at the end

**No arguments.**

2. [stb_structures](https://github.com/mstanciu552/stblibs/blob/main/stb_structures.h)
**Headers**
```c
#define STRUCTURES_IMPLEMENTATION
#include "stb_structures.h"
```
