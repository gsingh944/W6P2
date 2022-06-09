/*
==================
WORKSHOP #6(Part-1)
==================
NAME- Gurpinder Singh
STUDENT NO.- 140515206
STUDENT Email - gsingh944@myseneca.ca
SECTION CODE- OOP244ZAA
Date : 2021/07/07
Description:  define and create copy constructors,copy assignment,Prevent copying and assignment in a class,
Overload insertion operator so the class can be printed using ostream,
Overload extraction operator so the class can be read using istream
*/
#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"

namespace sdds {

	void strCpy(char* des, const char* src) {

		int m = 0;

		for (m = 0; src[m] != '\0'; m++)
		{
			des[m] = src[m];
		}
		des[m++] = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {

		int m = 0, cpynum = 0;

		for (m = 0; m < len && src[m] != '\0'; m++)
		{
			des[m] = src[m];
			cpynum++;
		}
		if (cpynum < len)
		{
			des[cpynum++] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2) {

		int value = 0;
		int len1, len2;

		len1 = strLen(s1);
		len2 = strLen(s2);

		if (len1 == len2) {
			for (int m = 0; s1[m] != '\0' && s2[m] != '\0'; m++)
			{
				if (s1[m] > s2[m])
				{
					value = 1;
					break;
				}
				else if (s1[m] < s2[m])
				{
					value = -1;
					break;
				}
			}

		}
		return value;
	}

	int strnCmp(const char* s1, const char* s2, int len) {

		int n = 0, value = 0;

		for (n = 0; s1[n] != '\0' && s2[n] != '\0' && n < len; n++)
		{
			if (s1[n] > s2[n])
			{
				value = 1;
				break;
			}
			else if (s1[n] < s2[n])
			{
				value = -1;
				break;
			}
		}
		return value;
	}

	int strLen(const char* s) {

		int x, count = 0;
		for (x = 0; s[x] != '\0'; x++)
		{
			count++;
		}
		return count;
	}

	const char* strStr(const char* str1, const char* str2) {

		int m;
		const char* p = nullptr;
		for (m = 0; str1[m] != '\0'; m++)
		{
			int l = 0;
			bool found = true;
			if (str2[l] == str1[m])
			{

				for (l = 0; str2[l] != '\0' && found == true; l++)
				{
					if (str2[l] != str1[m])
					{
						found = false;
					}
					m++;
				}
			}
			else
			{
				found = false;
			}
			if (found == false)
			{
				m -= l;
			}
			else {
				m -= l;
				p = &str1[m];
				break;
			}
		}
		return p;
	}

	void strCat(char* des, const char* src) {

		int m;
		bool over = false;
		for (m = 0; !over; m++)
		{
			if (des[m] == '\0')
			{
				int k;
				for (k = 0; src[k] != '\0'; k++)
				{
					des[m] = src[k];
					m++;
				}
				des[m] = '\0';
				over = true;
			}
		}
	}

};