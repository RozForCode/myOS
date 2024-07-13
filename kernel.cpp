// for boatloader to think it is a kernel
// it should have a special number in the assembly file
// 0x1badb002
#include <cinttypes>
void printf(char *str)
{
    unsigned short *videoMemory = (unsigned short *)0xb8000;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        videoMemory[i] = (videoMemory[i] & 0xFF00) | str[i];
    }
}
// so that compiler doesn't change the filename
// and linker can work properly
extern "C" void kernelMain(void *multiboot_structure, unsigned int magicnumber)
{

    // while(1):
}