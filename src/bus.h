#ifndef BUS_H
#define BUS_H
#include<stdint.h>

extern uint8_t *rom;
extern uint8_t *ram;

uint16_t bus_read16(uint32_t address);
uint32_t bus_read32(uint32_t address);
uint8_t  bus_read8(uint32_t address);

void bus_write16(uint32_t address, uint16_t data, uint16_t size);
void bus_write32(uint32_t address, uint32_t data, uint32_t size);
void bus_write8(uint32_t address, uint8_t data, uint8_t size)

//unknown case
uint32_t bus_read(uint32_t address, uint32_t size);
void bus_write(uint32_t address, uint32_t data, uint32_t size)



#endif
