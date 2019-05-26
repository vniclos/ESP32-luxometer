#ifndef  _GLOBAL_H
#define  _GLOBAL_H

BH1750  g_dev_LuxMeter;      // default 
//BH1750 g_dev_LuxMeter (0x23); // usual address
//BH1750 g_dev_LuxMeter (0x5C); // other usual address


uint16_t g_dev_LuxMeter_luxValue =0; // read value
char     g_dev_LuxMeter_luxValueMsg[LEN_LUXVALUEMSG];
uint16_t g_dev_LuxMeter_luxlevelValue =0; // value steep scaled  
char     g_dev_LuxMeter_luxlevelMsg[LEN_LUXLEVELMSG]="/0";

#endif
