#ifndef SRV_DISPLAY_H
#define	SRV_DISPLAY_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "Utilities.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    void SRV_Display_Init(void);
    void SRV_Display_Run(void);
    void SRV_Display_Clear(void);
    void SRV_Display_BLK_ON(void);
    void SRV_Display_BLK_OFF(void);
    void SRV_Display_Refresh(void);
    void SRV_Display_SetCursor( uint8_t linha, uint8_t coluna);    
    void SRV_Display_WriteChar(uint8_t linha,uint8_t coluna, uint8_t data);
    void SRV_Display_Write(uint8_t linha,uint8_t coluna, uint8_t *data);
    void SRV_Display_UpdateTela(Display_t * tela);
   

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

