/*
 * clock.c
 *
 *  Created on: May 17, 2018
 *      Author: brunocampuzano
 */

#include <stdio.h>
#include <stdlib.h>
#include "clock.h"


typedef struct {
   int num;
   char numt;
} time_conv;

time_conv array[] = {
   { 0, '0' },
   { 1, '1' },
   { 2, '2' },
   { 3, '3' },
   { 4, '4' },
   { 5, '5' },
   { 6, '6' },
   { 7, '7' },
   { 8, '8' },
   { 9, '9' }
};

void clock(time_text_t time_text, int hour, int minute)
{
   minute = minute + hour * 60;
   hour = 0;
   while(minute < 0)
   {
      minute = minute + 60;
      hour--;
   }
   while(hour < 0)
   {
      hour = hour + 24;
   }

   int adder, tens, tenh;
   adder = minute / 60;
   hour = hour + adder;
   minute = minute % 60;
   tens = minute / 10;
   minute = minute % 10;
   hour = hour % 24;
   tenh = hour / 10;
   hour = hour % 10;

   for(int i = 0; i < 5; i++)
   {
      switch(i)
      {
         case 0:
            time_text[i] = array[tenh].numt;
            break;
         case 1:
            time_text[i] = array[hour].numt;
            break;
         case 2:
            time_text[i] = ':';
            break;
         case 3:
            time_text[i] = array[tens].numt;
            break;
         case 4:
            time_text[i] = array[minute].numt;
            break;
      }
   }
}

void clock_add(time_text_t time_text, int minute_offset)
{
   char minute = time_text[4];
   char tens = time_text[3];
   char hours = time_text[1];
   char tenh = time_text[0];

   int min = cases(minute);
   int ten = cases(tens);
   int hour = cases(hours);
   int thour = cases(tenh);

   min = min + ten * 10;
   hour = hour + thour * 10;
   min = min + hour * 60;
   min = min + minute_offset;

   //   printf("minutos %d, ten %d, hour %d, thour %d",min, ten, hour, thour);
   clock(time_text, 0, min);
}

int cases(char find)
{
   int aux;

   switch(find)
   {
      case '0':
         aux = 0;
         break;
      case '1':
         aux = 1;
         break;
      case '2':
         aux = 2;
         break;
      case '3':
         aux = 3;
         break;
      case '4':
         aux = 4;
         break;
      case '5':
         aux = 5;
         break;
      case '6':
         aux = 6;
         break;
      case '7':
         aux = 7;
         break;
      case '8':
         aux = 8;
         break;
      case '9':
         aux = 9;
         break;
   }
   return aux;
}
