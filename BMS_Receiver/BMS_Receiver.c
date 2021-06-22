/*--------------------------------------------------------------------------------
---    \file       BMS_Receiver.c
---   \author      Naveen Balachandar (RBEI/ECK3) 
---
---     \brief     proj file to recive and process stream data
------------------------------------------------------------------------------------*/
/*------ standard includes -------*/
#include <stdio.h>
#include <stdlib.h>

/*------ Project includes -------*/
#include "BMS_Receiver.h"


void receiveConsoleData_v()
{
  char rxBuffer[1000] = {0};
  int i;
  char *ret;
  for (i=0;i<74;i++)
  {
  //scanf("%s", rxBuffer);
  gets (rxBuffer);
  //printf("Receiver data processing");  
  printf("rx data is %s\n", rxBuffer);
    
  ret = strstr(rv_data, "{"temperature":");
    printf("rx temp data is %s\n", ret);
  }
}


int  main()
{
 // printf("Receiver data processing");
  receiveConsoleData_v();
  return 0;
}

