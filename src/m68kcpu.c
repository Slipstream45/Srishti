#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "m68kcpu.h"
#include "bus.h"

uint32_t ea_calc(M68K *cpu, uint8_t mode, uint32_t reg, uint32_t size){
    switch(mode){
        case 0:   //cmpi.b/w/l  #0x1111,d1
            if(size==8){
                return cpu->d[reg] & 0xFF;
            }
            if(size==16){
                return cpu->d[reg] & 0xFFFF;
            }
            if(size==32){
                return cpu->d[reg];
            }
        case 1:   //cmpi.b/w/l  #0x1111,a1
            if(size==8){
                return cpu->a[reg] & 0xFF;
            }
            if(size==16){
                return cpu->a[reg] & 0xFFFF;
            }
            if(size==32){
                return cpu->a[reg];
            }
        case 2:  //cmpi.b  #0xda,(a1) (8b), cmpi.w #0xbabe (16b), cmpi.l #0xcafe11 (32b)
            if(size==8){
                return bus_read8(cpu->a[reg]);
            }
            if(size==16){
                return bus_read16(cpu->a[reg]);
            }
            if(size==32){
                return bus_read32(cpu->a[reg]);
            }
        case 3:   //cmpi.b/w/l  #0x1111,(a1)+
            //SP (REG-A7) is always aligned to word boundary (16b) even for a byte read (8b)
            uint32_t value = 0;
            if(size==8){
                value = bus_read8(cpu->a[reg]);
                if(reg==7){
                    cpu->a[reg] +=2;
                    return value;
                } else{
                    cpu->a[reg] += 1;
                    return value;
                }
            }
            if(size==16){
                uint16_t data16 = bus_read16(cpu->a[reg]);
                cpu->a[reg] += 2;
                return data16;
            }
            if(size==32){
                uint32_t data32 = bus_read32(cpu->a[reg]);
                cpu->a[reg] += 4;
                return data32;
            }
        case 4:   //cmpi.b/w/l  #0x1111,-(a1)
            if(size==8){
                if(reg==7){
                    cpu->a[reg] -=2;
                    return bus_read8(cpu->a[reg]);
                } else{
                    cpu->a[reg] -= 1;
                    return bus_read8(cpu->a[reg]);
                }
            }
            if(size==16){
                cpu->a[reg] -= 2;                
                uint16_t data16 = bus_read16(cpu->a[reg]);
                return data16;
            }
            if(size==32){
                cpu->a[reg] -= 4;                
                uint32_t data32 = bus_read32(cpu->a[reg]);
                return data32;
            }
        case 5: //cmpi.w  #0x1111,0x140(a1) 
            //(d16,An) or d16(An) - d16 is 16b SIGNED int
            uint32_t address = cpu->a[reg];
            offset = int32_t(offset)
            uint32_t final_address = address + (int32_t)offset;
            if(size==8){
                return bus_read8(final_address);
            }
            if(size==16){
                return bus_read16(final_address);
            }
            if(size==32){
                return bus_read32(final_address);
            }
            




















        
            
