#include <stdio.h>
#include <stdlib.h>
#include "roman_numerals.h"
#include <string.h>
//struct {
//   int key;
//   char *romanNumeralText;
//}romanNumeralDictionary[] = {
//   {1, "I"},
//   {5, "V"},
//   {10, "X"}
//};

typedef struct {
	int key;
	char *romanNumeralText;
} RomanNumeralDictionary_t;

RomanNumeralDictionary_t RomanNumeralDictionary[] = { // Used to look up for common values
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

char *to_roman_numeral(int number) {
	char *romanNumeralResult = malloc(sizeof(char) * 45); // Get the number sent and allocate in memory in order to use
	int dictionaryIndex = 0; // USED to index into the array
	sprintf(romanNumeralResult, ""); /*The sprintf function returns the number of characters stored in the array s,
	not including the terminating null character. */

//	for (int i = 0; i<=number; i++) {
	while (number > 0) {

		if (number >= RomanNumeralDictionary[dictionaryIndex].key) { // if received value is equal or bigger
			sprintf(romanNumeralResult,"%s%s", romanNumeralResult,RomanNumeralDictionary[dictionaryIndex].romanNumeralText);

			number = number - RomanNumeralDictionary[dictionaryIndex].key; // substract the current value
		}
		else {
			dictionaryIndex++;
		}
	}

	return romanNumeralResult;
}
