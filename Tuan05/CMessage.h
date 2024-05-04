#pragma once
#include <string>
#include <vector>
#include <fstream>
class CMyDate {
private:
    int m_Year;
    int m_Month;
    int m_Day;
public:
    CMyDate();
    void Input(std::ifstream&);
    void Output(std::ofstream&) const;
    bool operator<(const CMyDate&) const;
    friend class CListMessage;
};

class CMyTime {
private:
    int m_Hour;
    int m_Minute;
    int m_Second;
public:
    CMyTime();
    void Input(std::ifstream&);
    void Output(std::ofstream&) const;
    bool operator<(const CMyTime&) const;

    friend class CListMessage;
};
class CMessage
{
private:
    std::string m_Number;
    int m_Vote = 0;
    CMyDate m_Date;
    CMyTime m_Time;

public:
    void Input(std::ifstream&);
    void Output();

    friend class CListMessage;
};

class CListMessage: public CMessage{
private:
    std::vector<CMessage> m_Messages;
    int m_Amount = 0;
public:
    //CListMessage();
    ~CListMessage();
    void Input();

    void Output();

    std::vector <int> FindCode();

    std::vector <std::string> FindPhone();
    std::vector <CMyDate> FindDay();
    std::vector <CMyTime> FindTime();
    void Top10();
};