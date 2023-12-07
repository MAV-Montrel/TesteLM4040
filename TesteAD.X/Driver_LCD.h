#ifndef DRIVER_LCD_H
#define	DRIVER_LCD_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    void DRV_LCD_Data(uint8_t data);
    void DRV_LCD_Cmd(uint8_t cmd);
    void DRV_LCD_Clear(void);
    void DRV_LCD_SetCursor(uint8_t linha, uint8_t coluna);
    void DRV_LCD_Init(void);
    void DRV_LCD_WriteChar(uint8_t data);
    void DRV_LCD_WriteString(uint8_t *data);
    void DRV_LCD_ShiftRight(void);
    void DRV_LCD_ShiftLeft(void);
    void DRV_LCD_BLK(bool state); 
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

