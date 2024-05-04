#pragma once
class CIntArray
{
private:
	int* m_Array;
	int m_Length;
public:
	CIntArray();
	//CIntArray(int*, int);
	~CIntArray();
	CIntArray(int);
	CIntArray(const CIntArray&);
public:
	void InputArray();
	void OutputArray();
	CIntArray Remove();
	CIntArray Remove(int);
	CIntArray Remove(int, int);
	CIntArray Replace(int, int);
	CIntArray AddHead(int);
	CIntArray AddTail(int);
	CIntArray Insert(int, int);
	int Max();
	int Min();
	CIntArray Ascending();
	CIntArray Descending();
	bool IsSymmetry();
	CIntArray MoveForward();
	CIntArray MoveForward(int);
	CIntArray MoveBehind();
	CIntArray MoveBehind(int);
	CIntArray Invert();
	int Appearance(int);
};


