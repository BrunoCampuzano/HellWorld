


#include <stdio.h>
#include <stdlib.h>
#include "leap.h"

int is_leap_year(int number)
{

   int a,b, c, leap;
   a = number % 4;
   b = number % 100;
   c = number % 400;

   if(((a == 0)&& (b != 0)) || (c == 0))
   {
      leap = 1;
   }
   else
   {
      leap = 0;
   }

   return leap;

}
