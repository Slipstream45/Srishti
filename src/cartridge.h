#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

typedef struct{
    char console_name[16];
    char copyright[16];
    char game_name_do[48];
    char game_name_gl[48];
    char game_type[4];
    char code_ver_no[12];
    uint16_t checksum;
    char io_support[16];
    uint32_t rom_start_addr;
    uint32_t rom_end_addr;
    uint32_t ram_end_addr;
    char support[16];
    char modem[16];
    char notes[16];
    char region[16];
} MDHeader;

bool load_cart(const char *filename, uint8_t **rom_data, uint32_t *rom_size);
void read_cart_hdr(uint8_t *rom_data, MDHeader *hdr);

#endif
    
