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
#ifndef SDDS_CSTRING_H 
#define SDDS_CSTRING_H

namespace sdds {

    void strCpy(char* des, const char* src);
    void strnCpy(char* des, const char* src, int len);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    int strLen(const char* s);
    const char* strStr(const char* str1, const char* str2);
    void strCat(char* des, const char* src);

};

#endif



