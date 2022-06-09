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
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"


using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* LineValue) {
        delete[] m_value;
        m_value = new char[strLen(LineValue) + 1];
        strCpy(m_value, LineValue);
        return *this;
    }

    Line::~Line() {
        if (m_value) {
            delete[] m_value;
        }
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (isCopy) {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        char NewLine;
        ifstream readfile(m_filename);
        if (readfile.is_open()) {
            while (readfile) {
                NewLine = readfile.get();
                if (NewLine == '\n')
                    m_noOfLines++;
            }
            m_noOfLines++;
        }
        else {
            delete[] m_filename;
            m_filename = nullptr;
        }

        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {
        if (m_filename) {
            unsigned indcounting = 0;
            string textofLine;
            if (m_textLines) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }
            m_textLines = new Line[m_noOfLines];
            ifstream fileRead(m_filename);
            if (fileRead.is_open()) {
                while (getline(fileRead, textofLine)) {
                m_textLines[indcounting].m_value = new char[strLen(textofLine.c_str()) + 1];
                strCpy(m_textLines[indcounting].m_value, textofLine.c_str());
                 indcounting++;
                }
            }
            m_noOfLines = indcounting;
        }
    }

    void TextFile::saveAs(const char* fileName)const {
        ofstream fout(fileName);
        if (fout.is_open()) {
            for (unsigned m = 0; m < m_noOfLines; m++) {
                fout << m_textLines[m] << endl;
            }
        }
    }

    void TextFile::setEmpty() {
        if (m_textLines) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }
        if (m_filename) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfLines = 0;
    }

    TextFile::TextFile(unsigned pageSize) {
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        setEmpty();
        m_pageSize = pageSize;
        if (filename && filename[0] != '\0') {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& src) {
        setEmpty();
        m_pageSize = src.m_pageSize;
        if (src.m_filename && src.m_noOfLines > 0) {
            setFilename(src.m_filename, true);
            m_textLines = new Line[src.m_noOfLines];
            for (unsigned m
                = 0; m < src.m_noOfLines; m++) {
                m_textLines[m].m_value = new char[strLen(src.m_textLines[m].m_value) + 1];
                strCpy(m_textLines[m].m_value, src.m_textLines[m].m_value);
            }
            m_noOfLines = src.m_noOfLines;
            saveAs(m_filename);
        }
    }

    TextFile& TextFile::operator=(const TextFile& src) {
        if (this != &src) {
            delete[] m_textLines;
            m_textLines = nullptr;
            if (src.m_textLines) {
                m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];
                unsigned m = 0;
                while (m < m_noOfLines) {
                    m_textLines[m].m_value = new char[strLen(src.m_textLines[m].m_value) + 1];
                    strCpy(m_textLines[m].m_value, src.m_textLines[m].m_value);
                    m++;
                }
                saveAs(m_filename);
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr)const {
        if (m_filename && m_filename[0] != '\0') {
            unsigned fLine = 0;
            char m;
            ostr << m_filename << endl;
            for (int fLine = 0; fLine < strLen(m_filename); fLine++) {
                ostr << '=';
            }
            ostr << endl;

            for (fLine = 0; fLine < m_noOfLines && fLine < m_pageSize; fLine++) {
                ostr << m_textLines[fLine] << endl;
            }
            if (fLine < m_noOfLines) {
                do {
                    ostr << "Hit ENTER to continue...";
                    cin.get(m);
                    for (unsigned n = 0; n < m_pageSize && fLine < m_noOfLines; n++) {
                        ostr << m_textLines[fLine] << endl;
                        fLine++;
                    }
                } while (fLine < m_noOfLines);
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string m_fileName;
        istr >> m_fileName;
        m_filename = new char[strLen(m_fileName.c_str()) + 1];
        strCpy(m_filename, m_fileName.c_str());
        istr.ignore(30000, '\n');
        setNoOfLines();
        loadText();
        return istr;
    }
    const char* TextFile::operator[](unsigned struofindex)const {
        if (m_filename && m_filename[0] != '\0') {
            if (struofindex >= m_noOfLines)
                struofindex -= m_noOfLines;
        }
        return (m_textLines[struofindex].m_value);
    }
    TextFile::operator bool()const {
        return (m_textLines);
    }
    const char* TextFile::name()const {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }
}