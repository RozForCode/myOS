// for boatloader to think it is a kernel
// it should have a special number in the assembly file
// 0x1badb002
#include <cinttypes>
void kernelMain(void *multiboot_structure, unsigned int magicnumber)
{

    // while(1):
}