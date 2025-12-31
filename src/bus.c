#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "bus.h"

extern uint8_t *rom;
extern uint8_t *ram;

uint8_t bus_read8(uint32_t address){
    address &= 0x00FFFFFF;
    if(address<0x00400000){
        uint32_t temp= rom[address];
        return temp;
    }
    if(address>=0x00400000 && address<=0x007FFFFF){
        //Sega CD and 32X
        return 0;
    }
    if(address>=0x00800000 && address<=0x009FFFFF){
        //32X ?
        return 0;
    }
    if(address>=0x00A00000 && address<=0x00A0FFFF){
        //Z80 Implementation
        return 0;
    }
    if(address>=0x00A10000 && address<=0x00A10001){
        //Version Register
        return 0;
    }
    if(address>=0x00A00002 && address<=0x00A10003){
        //Control 1 data
        return 0;
    }
    if(address>=0x00A10004 && address<=0x00A10005){
        //Control 2 data
        return 0;
    }
    if(address>=0x00A10006 && address<=0x00A10007){
        //Expansion Port Data
        return 0;
    }
    if(address>=0x00A10008 && address<=0x00A10009){
        //Control 1 control
        return 0;
    }
    if(address>=0x00A1000A && address<=0x00A1000B){
        //Control 2 control
        return 0;
    }
    if(address>=0x00A1000C && address<=0x00A1000D){
        //Expansion Port Control
        return 0;
    }
    if(address>=0x00A1000E && address<=0x00A1000F){
        //Control 1 serial transmit
        return 0;
    }
    if(address>=0x00A10010 && address<=0x00A10011){
        //Control 1 serial receive
        return 0;
    }
    if(address>=0x00A10012 && address<=0x00A10013){
        //Control 1 serial control
        return 0;
    }
    if(address>=0x00A10014 && address<=0x00A10015){
        //Control 2 serial transmit
        return 0;
    }
    if(address>=0x00A10016 && address<=0x00A10017){
        //Control 2 serial receive
        return 0;
    }
    if(address>=0x00A10018 && address<=0x00A10019){
        //Control 2 serial control
        return 0;
    }
    if(address>=0x00A1001A && address<=0x00A1001B){
        //Expansion port serial transmit
        return 0;
    }
    if(address>=0x00A1001C && address<=0x00A1001D){
        //Expansion port serial receive
        return 0;
    }
    if(address>=0x00A1001E && address<=0x00A1001F){
        //Expansion port serial control
        return 0;
    }
    if(address>=0x00A10020 && address<=0x00A10FFF){
        //Reserved
        return 0;
    }
    if(address==0x00A11000){
        //Memory mode register
        return 0;
    }
    if(address>=0x00A11002 && address<=0x00A110FF){
        //Reserved
        return 0;
    }
    if(address>=0x00A11100 && address<=0x00A11101){
        //Z80 Bus Req
        return 0;
    }
    if(address>=0x00A11102 && address<=0x00A111FF){
        //Reserved
        return 0;
    }
    if(address>=0x00A11200 && address<=0x00A11201){
        //Z80 reset
        return 0;
    }
    if(address>=0x00A11202 && address<=0x00A13FFF){
        //Reserved
        return 0;
    }
    if(address>=0x00A14000 && address<=0x00A14003){
        //TMSS Register
        return 0;
    }
    if(address>=0x00A14004 && address<=0x00BFFFFF){
        //Reserved
        return 0;
    }
    if(address>=0x00C00000 && address<=0x00C00001){
        //VDP Data
        return 0;
    }
    if(address>=0x00C00002 && address<=0x00C00003){
        //VDP Data (mirror)
        return 0;
    }
    if(address>=0x00C00004 && address<=0x00C00005){
        //VDP Control
        return 0;
    }
    if(address>=0x00C00006 && address<=0x00C00007){
        //VDP Control (mirror)
        return 0;
    }
    if(address>=0x00C00008 && address<=0x00C00009){
        //VDP HV counter
        return 0;
    }
    if(address>=0x00C0000A && address<=0x00C00010){
        //Reserved
        return 0;
    }
    if(address==0x00C00011){
        //PSG Output
        return 0;
    }
    if(address>=0x00C00012 && address<=0x00FEFFFF){
        //Reserved
        return 0;
    }
    if(address>=0x00FF0000 && address<=0x00FFFFFF){
        //68000 RAM
        uint32_t temp = ram[address & 0xFFFF];
        return temp;
    }
    return 0;
}

uint16_t bus_read16(uint32_t address){
    address &=0x00FFFFFF;
    if(address<0x00400000){
        uint32_t temp =  (rom[address]<<8) | (rom[address+1]);
        return temp;
    }
    if(address>=0x00400000 && address<=0x007FFFFF){
        //Sega CD and 32X
        return 0;
    }
    if(address>=0x00800000 && address<=0x009FFFFF){
        //32X ?
        return 0;
    }
    if(address>=0x00A00000 && address<=0x00A0FFFF){
        //Z80 Implementation
        return 0;
    }
    if(address>=0x00A10000 && address<=0x00A10001){
        //Version Registr
        return 0;
    }
    if(address>=0x00A00002 && address<=0x00A10003){
        //Control 1 data
        return 0;
    }
    if(address>=0x00A10004 && address<=0x00A10005){
        //Control 2 data
        return 0;
    }
    if(address>=0x00A10006 && address<=0x00A10007){
        //Expansion Port Data
        return 0;
    }
    if(address>=0x00A10008 && address<=0x00A10009){
        //Control 1 control
        return 0;
    }
    if(address>=0x00A1000A && address<=0x00A1000B){
        //Control 2 control
        return 0;
    }
    if(address>=0x00A1000C && address<=0x00A1000D){
        //Expansion Port Control
        return 0;
    }
    if(address>=0x00A1000E && address<=0x00A1000F){
        //Control 1 serial transmit
        return 0;
    }
    if(address>=0x00A10010 && address<=0x00A10011){
        //Control 1 serial receive
        return 0;
    }
    if(address>=0x00A10012 && address<=0x00A10013){
        //Control 1 serial control
        return 0;
    }
    if(address>=0x00A10014 && address<=0x00A10015){
        //Control 2 serial transmit
        return 0;
    }
    if(address>=0x00A10016 && address<=0x00A10017){
        //Control 2 serial receive
        return 0;
    }
    if(address>=0x00A10018 && address<=0x00A10019){
        //Control 2 serial control
        return 0;
    }
    if(address>=0x00A1001A && address<=0x00A1001B){
        //Expansion port serial transmit
        return 0;
    }
    if(address>=0x00A1001C && address<=0x00A1001D){
        //Expansion port serial receive
        return 0;
    }
    if(address>=0x00A1001E && address<=0x00A1001F){
        //Expansion port serial control
        return 0;
    }
    if(address>=0x00A10020 && address<=0x00A10FFF){
        //Reserved
        return 0;
    }
    if(address==0x00A11000){
        //Memory mode register
        return 0;
    }
    if(address>=0x00A11002 && address<=0x00A110FF){
        //Reserved
        return 0;
    }
    if(address>=0x00A11100 && address<=0x00A11101){
        //Z80 Bus Req
        return 0;
    }
    if(address>=0x00A11102 && address<=0x00A111FF){
        //Reserved
        return 0;
    }
    if(address>=0x00A11200 && address<=0x00A11201){
        //Z80 reset
        return 0;
    }
    if(address>=0x00A11202 && address<=0x00A13FFF){
        //Reserved
        return 0;
    }
    if(address>=0x00A14000 && address<=0x00A14003){
        //TMSS Register
        return 0;
    }
    if(address>=0x00A14004 && address<=0x00BFFFFF){
        //Reserved
        return 0;
    }
    if(address>=0x00C00000 && address<=0x00C00001){
        //VDP Data
        return 0;
    }
    if(address>=0x00C00002 && address<=0x00C00003){
        //VDP Data (mirror)
        return 0;
    }
    if(address>=0x00C00004 && address<=0x00C00005){
        //VDP Control
        return 0;
    }
    if(address>=0x00C00006 && address<=0x00C00007){
        //VDP Control (mirror)
        return 0;
    }
    if(address>=0x00C00008 && address<=0x00C00009){
        //VDP HV counter
        return 0;
    }
    if(address>=0x00C0000A && address<=0x00C00010){
        //Reserved
        return 0;
    }
    if(address==0x00C00011){
        //PSG Output
        return 0;
    }
    if(address>=0x00C00012 && address<=0x00FEFFFF){
        //Reserved
        return 0;
    }
    if(address>=0x00FF0000 && address<=0x00FFFFFF){
        //68000 RAM
        uint32_t temp = (ram[address]<<8) | (ram[address+1]);
        return temp;
    }
    return 0;
}



















