#include "Convert.h"

void Convert_ftochar ( float x  , char* y){
		
		int valor = 0;
        
        int aux = 0;
		
		valor = (int)x;
        aux = x * 10;
		
		//coleta a parte inteira
//		y[0] = ((valor / 1000))+48;
//		y[1] = ((valor / 100)%10)+48;
//		y[2] = ((valor / 10)%10)+48;
//		y[3] = (valor % 10)+48;
//		//coloca a virgula
//		y[4] = ',';
//		//coleta depois da virgula
//		y[5] = ((x - valor) * 10)+48;
//		y[6] = ((int)((int)(((x - valor) * 10) *10))%10)+48;
        
        
     
		y[0] = ((valor / 100)%10)+48;
		y[1] = ((valor / 10)%10)+48;
		y[2] = (valor % 10)+48;
		//coloca a virgula
		y[3] = '.';
		//coleta depois da virgula        
        y[4] =  (aux - (valor * 10))+48;

        if(y[0] == '0')
        {
            y[0] = ' ';
        }
		
}

void Convert_uint8tochar ( uint8_t x  , char* y)
{
    y[0] = ((x) / 100)+48;
    y[1] = ((x % 100)/10)+48;
    y[2] = (x % 10)+48;
    
    if(y[0] == '0')
    {
        y[0] = ' ';
    }
}

void Convert_uint16touint8char ( uint16_t x  , uint8_t* y)
{
    y[0] = ((x) / 100)+48;
    y[1] = ((x % 100)/10)+48;
    y[2] = (x % 10)+48;
    
    if(y[0] == '0')
    {
        y[0] = ' ';
    }
}