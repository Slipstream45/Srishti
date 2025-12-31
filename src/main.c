#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "cartridge.h"
#include "m68kcpu.h"
uint8_t *rom = NULL;
uint8_t *ram = NULL;

int main(int argc, const char **argv){
    if(argc<2){
        printf("Usage: ./m68k <rom_file>\n");
        return 1;
    }
    ram = (uint8_t*)malloc(65535);
    uint32_t size=0;
    
    if(!load_cart(argv[1], &rom, &size)){
        perror("Unable to load the ROM\n");
        return 1;
    }
    printf("ROM loaded: Size: %d bytes\n", size);
    MDHeader hdr;
    read_cart_hdr(rom, &hdr);
    
    printf("Console: %.16s\n", hdr.console_name);
    printf("Copyright: %.16s\n", hdr.copyright);
    printf("Title: %.20s\n", hdr.game_name_gl);
    printf("Version: %s\n", hdr.code_ver_no);
    printf("Region: %.120s\n", hdr.region);

    bus_write16(0xFF0020, 0xBABE);
    uint16_t test = bus_read16(0xFF0020);
    printf("System Bus test (RAM): Wrote 0xBABE, Read 0x%x\n", test);

    return 0;
}
