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
  for (i=0;i<100;i++)
  {
  scanf("%s", rv_data);
  printf("Receiver data processing");  
  printf("data is %s\n", rv_data);
  }
}


int  main()
{
 // printf("Receiver data processing");
  receiveConsoleData_v();
  return 0;
}

