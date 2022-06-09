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
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>

namespace sdds {

    class Text;

    class Line {
        char* m_value{ nullptr };
        operator const char* ()const;
        Line() {};
        Line& operator=(const char*);
        ~Line();
         friend class TextFile;
    };

    class TextFile {
       Line* m_textLines{ nullptr };
       char* m_filename{ nullptr };
       unsigned m_noOfLines;
       unsigned m_pageSize;
       void setFilename(const char* fname, bool isCopy = false);
       void setNoOfLines();
       void loadText();
       void saveAs(const char* fileName)const;
       void setEmpty();

    public:
         TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
        };
        std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
        std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif 
