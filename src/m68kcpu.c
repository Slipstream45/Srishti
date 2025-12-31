#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "m68kcpu.h"

uint32_t ea_calc(M68K *cpu, uint8_t mode, uint32_t reg, uint32_t size){
    switch(mode){
        case 000:   //cmpi.w  #0x1111,d1
            return cpu->d[reg];
        case 001:   //cmpi.w  #0x1111,a1
            return cpu->a[reg];
        case 010:   //cmpi.w  #0x1111,(a1)
            return *(cpu->a[reg]);
        case 011:   //cmpi.w  #0x1111,(a1)+
            {
                uint32_t temp = 
            }
        case 100:   //cmpi.w  #0x1111,-(a1)
            {
            }
        
            
