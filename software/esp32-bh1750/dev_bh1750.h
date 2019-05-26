#ifndef DEV_BH1750_H
#define DEV_BH1750_H


const char g_dev_bh1750_MSG_00003[] ="3 Night, without artificial lighting";
const char g_dev_bh1750_MSG_00020[] ="20 night, very dark street";
const char g_dev_bh1750_MSG_00040[] ="40 sunset, dark street";
const char g_dev_bh1750_MSG_00100[] ="100 very dark ovecast,light streets";
const char g_dev_bh1750_MSG_00200[] ="200 Dark cloudy day";
const char g_dev_bh1750_MSG_00400[] ="400 Sunrise, sunset, offices";
const char g_dev_bh1750_MSG_01000[] ="1000 Overcast day";
const char g_dev_bh1750_MSG_10000[] ="10000 Sunny, great shading";
const char g_dev_bh1750_MSG_25000[] ="25000 Sunny not direct sun";
const char g_dev_bh1750_MSG_32000[] ="32000  Sunny, direct sun";
const char g_dev_bh1750_MSG_32001[] =">32000  Sunny, bright half day";

void fnc_dev_bh1750_message()
{
  int iPrevious = 0;
  if (g_dev_LuxMeter_luxValue <= 3)
  {
    iPrevious = 3;

    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00003);
  }
  else if (g_dev_LuxMeter_luxValue <= 20 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 20;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00020);
  }
  else if (g_dev_LuxMeter_luxValue <= 40 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 40;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00040);
  }
  else if (g_dev_LuxMeter_luxValue <= 100 && g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 100;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00100);
  }
  else if (g_dev_LuxMeter_luxValue <= 200 && g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 200;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00200);
  }
  else if (g_dev_LuxMeter_luxValue <= 400 && g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 400;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_00400);
  }
  else if (g_dev_LuxMeter_luxValue <= 1000 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 1000;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_01000);
  }
  else if (g_dev_LuxMeter_luxValue <= 10000 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 10000;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_10000);
  }
  else if (g_dev_LuxMeter_luxValue <= 25000 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 25000;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_25000);
  }
  else if (g_dev_LuxMeter_luxValue <= 32000 &&  g_dev_LuxMeter_luxValue> iPrevious)
  {
    iPrevious = 32000;
    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) ," % s", g_dev_bh1750_MSG_32000);
  }
  else if ( g_dev_LuxMeter_luxValue> iPrevious)
  {

    snprintf(g_dev_LuxMeter_luxlevelMsg, sizeof(g_dev_LuxMeter_luxlevelMsg) , " % s", g_dev_bh1750_MSG_32001);
  }
}


void fnc_dev_bh1750_Setup()
{
  /*
  Initializacion modes this change the resolution an time
  DEFINE                             LUX RESOLUTION   TIME
  BH1750_CONTINUOUS_LOW_RES_MOD      4                16ms
  BH1750_CONTINUOUS_HIGH_RES_MODE    1                120ms (Default mode)
  BH1750_CONTINUOUS_HIGH_RES_MODE_2: 0.5              120ms
  BH1750_ONE_TIME_LOW_RES_MODE       4                16ms
  BH1750_ONE_TIME_HIGH_RES_MODE      1                120ms
  BH1750_ONE_TIME_HIGH_RES_MODE_2    0.5lux           120ms
  */
  Wire.begin(PIN_SDA, PIN_SLC );
  g_dev_LuxMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE);

}



void fnc_dev_bh1750_Read() {
  {
    /*
    uint16_t g_dev_LuxMeter_luxValue =0; // read value
    char     g_dev_LuxMeter_luxValueMsg[LEN_LUXVALUEMSG];
    uint16_t g_dev_LuxMeter_luxlevelValue =0; // value steep scaled
    char     g_dev_LuxMeter_luxlevelMsg[LEN_LUXLEVELMSG]=" / 0";
    */
    g_dev_LuxMeter_luxValue = g_dev_LuxMeter.readLightLevel();

    fnc_dev_bh1750_message();


    Serial.print("Light: ");
    Serial.print(g_dev_LuxMeter_luxValue);
    Serial.print(" lx, level: ");
    Serial.println(g_dev_LuxMeter_luxlevelMsg);

  }
}
#endif
