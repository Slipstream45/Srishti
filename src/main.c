#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "cartridge.h"

int main(int argc, const char **argv){
    if(argc<2){
        printf("Usage: ./m68k <rom_file>\n");
        return 1;
    }
    uint8_t *rom;
    uint32_t size;
    
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

    return 0;
}
