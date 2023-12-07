/* 
 * File:   AppTesteLM4040.h
 * Author: flavio.luciano
 *
 * Created on November 6, 2020, 12:36 PM
 */

#ifndef APPTESTELM4040_H
#define	APPTESTELM4040_H

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

void AppTesteLM4040_inicialize(void);
void AppTesteLM4040_Run(void);
void AppTesteLM4040_Controller(void);


void AppTesteLM4040_Calibrando(void);
void AppTesteLM4040_IdentificaMudanca(void);
void AppTesteLM4040_Testando(void);




uint16_t ServiceAD_Media(void);
void exibetensao(void);
void LeituraAD_run(void);
void AtualizaDisplay (void);

#endif	/* APPTESTELM4040_H */

