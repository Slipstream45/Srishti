#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "cartridge.h"
#define swapEndian16(x) __builtin_bswap16(x)
#define swapEndian32(x) __builtin_bswap32(x)

bool load_cart(const char *filename, uint8_t **rom_data, uint32_t *rom_size){
    FILE *fp = fopen(filename, "rb");
    if(!fp){
        perror("Error opening ROM\n");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    *rom_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *rom_data = (uint8_t*)malloc(*rom_size);
    fread(*rom_data, 1, *rom_size, fp);
    fclose(fp);
    return true;
}

void read_cart_hdr(uint8_t *rom_data, MDHeader *hdr){
    memcpy(hdr->console_name, &rom_data[0x100], 16);
    memcpy(hdr->copyright, &rom_data[0x110], 16);
    memcpy(hdr->game_name_do, &rom_data[0x120], 48);
    memcpy(hdr->game_name_gl, &rom_data[0x150], 48);
    memcpy(hdr->game_type, &rom_data[0x180], 4);
    memcpy(hdr->code_ver_no, &rom_data[0x182], 12);
    memcpy(hdr->region, &rom_data[0x1F0], 16);
}

