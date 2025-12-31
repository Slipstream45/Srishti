#ifndef M68KCPU_H
#define M68KCPU_H
#include<stdint.h>
//16 32b GPR (D7-D0, A7-A0)
//32b PC
//8b CCR

typedef struct{
    uint32_t d[8];
    
    uint32_t a[8];

    uint32_t pc;
    uint16_t sr;

    //a7 is stk ptr, sr affects if it's usp or ssp
    uint32_t usp;
    uint32_t ssp;
} M68K;


#endif
