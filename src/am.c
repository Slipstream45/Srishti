#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "am.h"
#include "m68kcpu.h"
#include "bus.h"

uint32_t data_register_direct(M68K *cpu, uint32_t reg, uint32_t size){
    //cmpi.b/w/l  #0x1111,d1
    if(size==8){
        return cpu->d[reg] & 0xFF;
    }
    if(size==16){
         return cpu->d[reg] & 0xFFFF;
    }
    if(size==32){
         return cpu->d[reg];
    }
    return 0;   
}
uint32_t addr_register_direct(M68K *cpu, uint32_t reg, uint32_t size){
    //cmpi.b/w/l  #0x1111,a1
    if(size==8){
        return cpu->a[reg] & 0xFF;
    }
    if(size==16){
        return cpu->a[reg] & 0xFFFF;
    }
    if(size==32){
        return cpu->a[reg];
    }
}
uint32_t addr_register_indirect(M68K *cpu, uint32_t reg, uint32_t size){
    //cmpi.b  #0xda,(a1) (8b), cmpi.w #0xbabe (16b), cmpi.l #0xcafe11 (32b)
    if(size==8){
        return bus_read8(cpu->a[reg]);
    }
    if(size==16){
        return bus_read16(cpu->a[reg]);
    }
    if(size==32){
        return bus_read32(cpu->a[reg]);
    }
}
uint32_t addr_register_post_incr(M68K *cpu uint32_t reg, uint32_t size){
    //cmpi.b/w/l  #0x1111,(a1)+
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
    return 0
}
uint32_t addr_register_pre_decr(M68K *cpu, uint32_t reg, uint32_t size){
    //cmpi.b/w/l  #0x1111,-(a1)
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
}
uint32_t addr_register_displacement(M68K *cpu, uint32_t reg, uint32_t size, uint32_t offset){
    //cmpi.w  #0x1111,0x140(a1)
    //(d16,An) or d16(An) - d16 is 16b SIGNED int
    //(d16) is avl in PC after opcode has been processed pc+2
    int16_t offset = (int16_t)bus_read16(cpu->pc);
    cpu->pc += 2; //THIS IS FUCKING NUTS! MANUALLY UPDATE PC HERE!!!!!
    uint32_t address = cpu->a[reg];
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
}
uint32_t addr_register_indexed(M68K *cpu, uint32_t reg, uint32_t size,){
    //cmpi.w  #0x1111,(d8,a1,d0)
    //ea = d8+d0+0x4, same trick for 0x4
    uint16_t instr = bus_read16(cpu->pc);
    cpu->pc += 2;
    
    
    
    
}
































