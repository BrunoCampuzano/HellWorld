#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman_numerals.h"

enum
{
  ARandomCharacterSize = 45	
}

typedef struct
{
   int key;
   char *romanNumeralText;
} RomanNumeralDictionary_t;

RomanNumeralDictionary_t dictionary[] = {
   { 1000, "M" },
   { 900, "CM" },
   { 500, "D" },
   { 400, "CD" },
   { 100, "C" },
   { 90, "XC" },
   { 50, "L" },
   { 40, "XL" },
   { 10, "X" },
   { 9, "IX" },
   { 5, "V" },
   { 4, "IV" },
   { 1, "I" }
};

char *to_roman_numeral(int number)
{
   char *romanNumeralResult = malloc(sizeof(char) * ARandomCharacterSize);
   int dictionaryIndex = 0;
   sprintf(romanNumeralResult, "");

   while(number > 0)
   {
      if(number >= dictionary[dictionaryIndex].key)
      {
         sprintf(romanNumeralResult, "%s%s", romanNumeralResult, dictionary[dictionaryIndex].romanNumeralText);

         number = number - dictionary[dictionaryIndex].key;
      }
      else
      {
         dictionaryIndex++;
      }
   }

   return romanNumeralResult;
}
