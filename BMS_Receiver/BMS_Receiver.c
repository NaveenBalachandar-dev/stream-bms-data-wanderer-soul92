/*--------------------------------------------------------------------------------
---    \file       BMS_Receiver.c
---   \author      Naveen Balachandar (RBEI/ECK3) 
---
---     \brief     proj file to recive and process stream data
------------------------------------------------------------------------------------*/
/*------ standard includes -------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*------ Project includes -------*/
#include "BMS_Receiver.h"


void receiveConsoleData_v()
{
  char rxBuffer[1000] = {0};
  int i;
  char *ret;
   char *ret2;
  for (i=0;i<74;i++)
  {
 /*Reading recived data from console*/
  gets (rxBuffer);
    
  printf("rx data is %s\n", rxBuffer);
  
  /*Decoding Temperature data*/      
  ret = strstr(rxBuffer, "\"temperature\": ");
  if (ret != NULL)
  {
   printf("rx temp data is %s\n", ret);
   ret2 = strtok(ret, ": ");
   printf("rx temp2 data is %s\n", ret2);
   }
   //ret2 = strtok(rxBuffer, ": ");
 // printf("rx temp2 data is %s\n", ret);
  }
}


int  main()
{
 // printf("Receiver data processing");
  receiveConsoleData_v();
  return 0;
  
}

