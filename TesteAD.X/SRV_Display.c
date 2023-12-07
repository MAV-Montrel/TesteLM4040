#include "SRV_Display.h"
#include "Driver_LCD.h"

Display_t *telaDisplay;

void SRV_Display_UpdateTela(Display_t * tela)
{
    telaDisplay = tela;
}

void writeTela(void)
{
    if(telaDisplay != NULL)
    {
//        int i;
//        for (i = 1; i <= 2; i++) 
//        {
//            int k;
//            for (k = 1; k <= 16; k++) 
//            {
//                SRV_Display_WriteChar(i,k,telaDisplay->tela[i-1][k-1]);
//            }
//        }
        SRV_Display_Write(1,1,(uint8_t*)(&telaDisplay->tela[0][0]));
        SRV_Display_Write(2,1,(uint8_t*)(&telaDisplay->tela[1][0]));
        
    }
}

void SRV_Display_Init(void)
{
    DRV_LCD_Init();
    SRV_Display_Clear();
    SRV_Display_SetCursor(1,1);
    SRV_Display_BLK_ON();
    
    telaDisplay = NULL;
}

void SRV_Display_Run(void)
{
    writeTela();
}

void SRV_Display_Write(uint8_t linha,uint8_t coluna, uint8_t *data)
{
    DRV_LCD_SetCursor(linha,coluna);
    DRV_LCD_WriteString(data);
}

void SRV_Display_WriteChar(uint8_t linha,uint8_t coluna, uint8_t data)
{
    DRV_LCD_SetCursor(linha,coluna);
    DRV_LCD_WriteChar(data);
}

void SRV_Display_Clear(void)
{
    DRV_LCD_Clear();
}

void SRV_Display_SetCursor( uint8_t linha, uint8_t coluna)
{
    DRV_LCD_SetCursor(linha,coluna);
}

void SRV_Display_BLK_ON(void)
{
   DRV_LCD_BLK(1); 
}
void SRV_Display_BLK_OFF(void)
{
   DRV_LCD_BLK(0); 
}


void SRV_Display_Refresh(void)
{
  DRV_LCD_Init();  
}