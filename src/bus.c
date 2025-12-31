#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "bus.h"

extern uint8_t *rom;
extern uint8_t *ram;

uint8_t bus_read8(uint32_t address)
