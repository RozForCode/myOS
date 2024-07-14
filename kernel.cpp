// for boatloader to think it is a kernel
// it should have a special number in the assembly file
// 0x1badb002
#include <cinttypes>
#include "types.h"
void printf(char *str)
{
    static uint16_t *videoMemory = (uint16_t *)0xb8000;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        videoMemory[i] = (videoMemory[i] & 0xFF00) | str[i];
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for (constructor *i = &start_ctors; i != &end_ctors; i++)
    {
        (*i)();
    }
}
// so that compiler doesn't change the filename
// and linker can work properly
extern "C" void kernelMain(void *multiboot_structure, uint32_t magicnumber)
{

    while (1)
        ;
}