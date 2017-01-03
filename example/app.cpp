/* source file for app class */

#include "app.h"

// constructor
PSX_App::PSX_App()
{

    __ramsize    = 0x00200000; // force 2MB of RAM
    __stacksize  = 0x00004000; // force 16KB of stack

    CurrentBuffer = 0; // keep track of the current buffer
}

