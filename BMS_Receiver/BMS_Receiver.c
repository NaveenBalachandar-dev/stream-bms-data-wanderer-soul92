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

char* substring(char *destination, const char *source, int beg, int n);

void receiveConsoleData_v()
{
  char rxBuffer[1000] = {0};
  int i;
  char *ret;
   //char *ret2;
  int start =15;
  int len =2;
  char destination[25];
  for (i=0;i<74;i++)
  {
 /*Reading recived data from console*/
  gets (rxBuffer);
    
  printf("rx data is %s\n", rxBuffer);
  
  /*Decoding Temperature data*/      
  ret = strstr(rxBuffer, "\"temperature\": ");
  if (ret != NULL)
  {
   //printf("rx temp data is %s\n", ret);
   substring(destination, ret, start, len);
   //ret2 = strtok(ret, ": ");
   printf("rx temp2 data is %s\n", destination);
  }
    
  /*Decoding soc data*/      
  ret = strstr(rxBuffer, "\"soc\": ");
  if (ret != NULL)
  {
   start =7;
   //printf("rx temp data is %s\n", ret);
   substring(destination, ret, start, len);
   //ret2 = strtok(ret, ": ");
   printf("rx soc data is %s\n", destination);
  }  
    
    
    
   //ret2 = strtok(rxBuffer, ": ");
 // printf("rx temp2 data is %s\n", ret);
  }
}

// Function to implement substring function in C
char* substring(char *destination, const char *source, int beg, int n)
{
    // extracts `n` characters from the source string starting from `beg` index
    // and copy them into the destination string
    while (n > 0)
    {
        *destination = *(source + beg);
 
        destination++;
        source++;
        n--;
    }
 
    // null terminate destination string
    *destination = '\0';
 
    // return the destination string
    return destination;
}
int  main()
{
 // printf("Receiver data processing");
  receiveConsoleData_v();
  return 0;
  
}

