/* 
 * File:   Convert.h
 * Author: flavio.luciano
 *
 * Created on 17 de Setembro de 2020, 08:28
 */

#ifndef CONVERT_H
#define	CONVERT_H

#include <stdint.h>
#include <stdio.h>



#ifdef	__cplusplus
extern "C" {
#endif

  void Convert_ftochar(float n, char* res);
  void Convert_uint8tochar ( uint8_t x  , char* y);
  
  void Convert_uint16touint8char ( uint16_t x  , uint8_t* y);


#ifdef	__cplusplus
}
#endif

#endif	/* CONVERT_H */

