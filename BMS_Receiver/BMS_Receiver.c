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
  static int Temp[30] = {0};
  int soc[30] = {0};
  int chargerate[30] = {0};
  char tempbuffer[30];
  int index =0;
  int index1 =0;
  int index2 =0;
  int max, min;
  
  for (i=0;i<74;i++)
  {
 /*Reading recived data from console*/
  gets (rxBuffer);
    
  //printf("rx data is %s\n", rxBuffer);
  
  /*Decoding Temperature data*/      
  ret = strstr(rxBuffer, "\"temperature\": ");
  if (ret != NULL)
  {
   //printf("rx temp data is %s\n", ret);
   substring(destination, ret, start, len);
   //ret2 = strtok(ret, ": ");
   //printf("rx temp1 data is %s\n", destination);
     Temp[index] = atoi(destination);
     printf("rx temp2 data is %d\n", Temp[index]);
    
     printf("rx index data is %d\n", index);
     index = index + 1;
  }
    
  /*Decoding soc data*/      
  ret = strstr(rxBuffer, "\"soc\": ");
  //index =0;
  if (ret != NULL)
  {
   start =7;
   //printf("rx temp data is %s\n", ret);
   substring(destination, ret, start, len);
   //ret2 = strtok(ret, ": ");
   //printf("rx soc data is %s\n", destination);
    soc[index1++] = atoi(destination);
  }  
    
  /*Decoding charge rate data*/      
  ret = strstr(rxBuffer, "\"charge_rate\": ");
  //index =0;  
  if (ret != NULL)
  {
   start =15;
   //printf("rx temp data is %s\n", ret);
   substring(destination, ret, start, len);
   //ret2 = strtok(ret, ": ");
   //printf("rx charge rate data is %s\n", destination);
    chargerate[index2++]= atoi(destination);
  } 
    
  /*Finding min and max of temperature*/
    /* Assume first element as maximum and minimum */
  
     
    
    
   //ret2 = strtok(rxBuffer, ": ");
  }
   max = Temp[0];
     min = Temp[0];
  
   for(i=1; i<15; i++)
    {
        /* If current element is greater than max */
      if(Temp[i] > max)
      {
       max = Temp[i];
       }

       /* If current element is smaller than min */
       if(Temp[i] < min)
       {
        min = Temp[i];
        }
     }
   printf("rx temp data Min:%dMax:%d",min,max);
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

