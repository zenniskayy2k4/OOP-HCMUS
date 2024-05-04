#pragma once
#include <string>
class CMyTime
{
private:
    int m_Hour;
    int m_Minute;
    int m_Second;
public:
    // Default constructor
    CMyTime();

    // Constructor with parameters
    CMyTime(int, int, int);

    // Copy constructor
    CMyTime(const CMyTime&);

    //Destructor
    ~CMyTime();
public:
    std::string SetValidTime(const CMyTime&) const;

    void Input();
    void Output();

    void operator++();
    void operator--();

    void operator+=(int);
    void operator-=(int);
    
    CMyTime operator+(const CMyTime&) const;
    CMyTime operator-(const CMyTime&) const;

    bool operator>(const CMyTime&) const;
    bool operator<(const CMyTime&) const;
    bool operator>=(const CMyTime&) const;
    bool operator<=(const CMyTime&) const;
    bool operator==(const CMyTime&) const;
};

