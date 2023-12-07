#include "AppTesteLM4040.h"
#include "mcc_generated_files/mcc.h"
#include "SRV_Display.h"
#include "ServiceTimer.h"
#include "mcc_generated_files/memory.h"

typedef struct{
  bool calibrando;
  bool identifica_mudanca;
  bool testando;
  bool aprovado;
  bool reprovado;
}state_t;

state_t state;

typedef struct{
    uint16_t AN2;
    uint16_t AN3;
}LeituraAD_t;

LeituraAD_t LeituraAD;


uint8_t txtLinha1[16];
uint8_t txtLinha2[16];

uint16_t vMax = 0;

uint8_t data[16];

uint16_t dataeeAddr = 0x10;
uint8_t dataeeData = 0x55;

 uint8_t readData;

uint16_t errodif = 0;

uint16_t convertedValueTensao = 0;

uint16_t tensao = 0;

uint16_t tensaoreferencia = 0;

float auxconvert = 0;

float auxreferenica = 0;

float tensaoexibe = 0;

uint16_t difan = 0;

uint16_t erromedido = 0;

bool flag_medindoerro = false;

uint16_t cont_tempo = 0;


uint16_t contTeste = 0;


void AppTesteLM4040_inicialize(void)
{
    SRV_TIMER_Init();
    ADC_Initialize();
    SRV_Display_Init();
    SRV_Display_Clear();
    
    
    
    readData = DATAEE_ReadByte(0x10);
    __delay_ms(300);
     
    if(readData == 0x52){ 
        state.calibrando = false;
        state.aprovado = false;
        state.reprovado = true;
        state.identifica_mudanca = false;
        state.testando = false; 
    }
    else if(readData == 0x41){ 
        state.calibrando = false;
        state.aprovado = true;
        state.reprovado = false;
        state.identifica_mudanca = false;
        state.testando = false; 
    }
    else{        
        state.calibrando = true;
        state.aprovado = false;
        state.reprovado = false;
        state.identifica_mudanca = false;
        state.testando = false;
    }
    
   
    
    
}
void AppTesteLM4040_Run(void)
{
     SRV_Display_Run();
     LeituraAD_run();  
     AtualizaDisplay();     
     AppTesteLM4040_Controller();
     
    //=========================================     
        exibetensao(); // mostra toggle no pino 
    //=========================================    
    
}



void AppTesteLM4040_Controller(void)
{
    
    if(state.calibrando == true)
    {
        state.aprovado = false;
        state.reprovado = false;
        state.identifica_mudanca = false;
        state.testando = false;       
        AppTesteLM4040_Calibrando();      
    } 
    if(state.identifica_mudanca == true)
    {
        state.calibrando = false; 
        state.aprovado = false;
        state.reprovado = false;
        state.testando = false;  
        AppTesteLM4040_IdentificaMudanca();
    } 
    if(state.testando == true)
    {
        state.calibrando = false; 
        state.aprovado = false;
        state.reprovado = false;
        state.identifica_mudanca = false;
        AppTesteLM4040_Testando();
    }
    
    if(Tecla1_GetValue() == 0)
        {
            DATAEE_WriteByte(0x10, 0x00);
            __delay_ms(100);           
        }
    
    
//   //===========================================================
//        difan = LeituraAD.AN3 - LeituraAD.AN2; // calculo diferenca     
//        
//        tensaoexibe = (float)(erromedido) * 1.21;    // tensão em milivolts 
//             
//        //------- faz a tara do valor
//        if(Tecla1_GetValue() == 0)
//        {
//            tensaoreferencia = difan;
//            flag_medindoerro = true;            
//        }
//        //------------------           
//        
//        //-----  verifica erro --------------
//        if(flag_medindoerro)
//        {
//            if(tensaoreferencia >=  difan)
//                erromedido = tensaoreferencia - difan; 
//            if(difan >= tensaoreferencia)
//                erromedido = difan - tensaoreferencia; 
//                     
//            sprintf((char*)data,"E:%03u",erromedido);
//            SRV_Display_Write(2,1,data);   
//        }
//        //----------------------------------
//     //===============================================================   
    
    
}


void AppTesteLM4040_Calibrando(void)
{
    
    static uint32_t tick = 0;
    static uint32_t tickLast = 0;
    
    static uint16_t cont_tempo = 0;
        
     difan = LeituraAD.AN3 - LeituraAD.AN2; // calculo diferenca     
    
	tick = SRV_TIMER_GetTick();
    
	if(tick >= (uint32_t)(tickLast + 1))
	{
		tickLast = tick;
        
        cont_tempo++;
        if(cont_tempo >= 10000)
        {
            tensaoreferencia = difan;          
            state.identifica_mudanca = true;
        }
		
	} 
    
}

void AppTesteLM4040_IdentificaMudanca(void)
{          
     
    difan = LeituraAD.AN3 - LeituraAD.AN2; // calculo diferenca   
    
    if(tensaoreferencia >=  difan)
        erromedido = tensaoreferencia - difan; 
    if(difan >= tensaoreferencia)
        erromedido = difan - tensaoreferencia;  
    
    if(erromedido > 2){
      state.testando = true;  
    }
 
    static uint32_t tick = 0;
    static uint32_t tickLast = 0;
    
    static uint16_t cont_tempo = 0;
    
    tick = SRV_TIMER_GetTick();
    
	if(tick >= (uint32_t)(tickLast + 1))
	{
		tickLast = tick;
        cont_tempo++;
        if(cont_tempo >= 10000)
        {
           state.testando = true; 
           vMax = 0;
        }
        
    }    
    
}

void AppTesteLM4040_Testando(void)
{          
    
    
    
    difan = LeituraAD.AN3 - LeituraAD.AN2; // calculo diferenca  
    
    if(tensaoreferencia >=  difan)
        erromedido = tensaoreferencia - difan; 
    if(difan >= tensaoreferencia)
        erromedido = difan - tensaoreferencia;  
    
    tensaoexibe = (float)(erromedido) * 1.21;    // tensão em milivolts 
    
    
    if(erromedido > vMax)
    {
       vMax = erromedido;
    }
    
 
    static uint32_t tick = 0;
    static uint32_t tickLast = 0;
    
    
    
    tick = SRV_TIMER_GetTick();
    
	if(tick >= (uint32_t)(tickLast + 1))
	{
		tickLast = tick;
        cont_tempo++;
        if(cont_tempo >= 40000)
        {
            if(vMax > 10)
            {
               state.reprovado = true; 
               DATAEE_WriteByte(0x10, 0x52);
               __delay_ms(300);
            }
            else if(vMax <= 10)
            {
               state.aprovado = true;                
               DATAEE_WriteByte(0x10, 0x41);
               __delay_ms(300);
            }  
        }
        
    }    
    
}



void LeituraAD_run(void)
{
    //-------------------------------
    //----- Leitura AN3
    //-------------------------------
     ADC_StartConversion(channel_AN3); 
     while(!ADC_IsConversionDone());  

     LeituraAD.AN3 =  ADC_GetConversionResult(); 
    //------------------------------ 
    //------ Leitura media AN2        
     LeituraAD.AN2 = ServiceAD_Media();        
    //-------------------------------- 
}

void AtualizaDisplay (void)
{
    static uint32_t tick = 0;
    static uint32_t tickLast = 0;
      
 
	tick = SRV_TIMER_GetTick();
    
	if(tick >= (uint32_t)(tickLast + 500))
	{
		tickLast = tick;
        
        
        if(state.calibrando == true)
        {
            sprintf((char*)(txtLinha1),"  Calibrando..");  
            SRV_Display_Write(1,1,txtLinha1); 
            sprintf((char*)(txtLinha2),"AD:%u AR:%u ",difan,tensaoreferencia);             
            SRV_Display_Write(2,1,txtLinha2); 
        }
        if(state.identifica_mudanca == true)
        {
            sprintf((char*)(txtLinha1),"Posicione a PCB");   
            SRV_Display_Write(1,1,txtLinha1);
            sprintf((char*)(txtLinha2),"AD:%u AR:%u ",difan,tensaoreferencia);
            SRV_Display_Write(2,1,txtLinha2); 
        }
        if(state.testando == true)
        {
            sprintf((char*)(txtLinha1),"  Testando     "); 
            SRV_Display_Write(1,1,txtLinha1); 
            sprintf((char*)(txtLinha2),"E:%03u M:%.3fmV",vMax,tensaoexibe);             
            SRV_Display_Write(2,1,txtLinha2); 
        }
        if(state.aprovado == true)
        {
            sprintf((char*)(txtLinha1),"  Aprovado     ");    
            SRV_Display_Write(1,1,txtLinha1); 
            sprintf((char*)(txtLinha2),"               ");             
            SRV_Display_Write(2,1,txtLinha2); 
        }
        if(state.reprovado == true)
        {
            sprintf((char*)(txtLinha1),"  Reprovado    "); 
            SRV_Display_Write(1,1,txtLinha1); 
            sprintf((char*)(txtLinha2),"               ");             
            SRV_Display_Write(2,1,txtLinha2); 
        }
	} 
    
}


void exibetensao(void)
{
    static uint32_t tick = 0;
	static uint32_t tickLast = 0;
    
 
	tick = SRV_TIMER_GetTick();
    
	if(tick >= (uint32_t)(tickLast + 1))
	{
		tickLast = tick;
			       
        Teste_Toggle();
		
	} 
    
    
}


uint16_t ServiceAD_Media(void)
{
    #define MEAN_SIZE 20
    uint16_t conversion,i=0;
    uint16_t valueMean = 0;
    uint32_t valueAux = 0;
    uint16_t timeout = 0;
    
     uint8_t index = 0;
    
    static uint16_t mean[MEAN_SIZE] = {0}; // vetor do mesmo tamanho do buffer da media;
    static uint8_t accumulated = 0;
 
      ADC_StartConversion(channel_AN2);               
        
     while(!ADC_IsConversionDone());  
   
    conversion =  ADC_GetConversionResult();      
    
    
    mean[accumulated] = conversion;
    accumulated++;
           if(accumulated >= MEAN_SIZE)
               accumulated = 0;
    
    for (index = 0; index < MEAN_SIZE; index++) 
            {
                valueAux = valueAux + mean[index];
            }
            
            valueMean = (uint16_t)(valueAux / MEAN_SIZE);
            valueAux = 0;
    
    return  valueMean;
    
}