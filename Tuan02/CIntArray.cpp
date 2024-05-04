#include "CIntArray.h"
#include <iostream>
using namespace std;
#define loop(i,x,n) for (int i = x; i < n; ++i)
#define loopReverse(i,x,n) for (int i = (n); i >= (x); i--)
CIntArray::CIntArray() {
	m_Array = NULL;
	m_Length = 0;
}
CIntArray::CIntArray(int length) {
	m_Length = length;
	m_Array = new int[m_Length];
	for (int i = 0; i < m_Length; ++i) {
		m_Array[i] = 0;
	}
}
CIntArray::CIntArray(const CIntArray& other) {
	m_Length = other.m_Length;
	m_Array = new int[m_Length];
	for (int i = 0; i < m_Length; ++i) {
		m_Array[i] = other.m_Array[i];
	}
}
CIntArray::~CIntArray() {
	delete[] m_Array;
}
void CIntArray::InputArray() {
	srand(time_t(NULL));
	int startIndex = 0, endIndex = 0;
	cout << "Enter the start index of value domain of array: "; cin >> startIndex;
	cout << "Enter the end index of value domain of array: "; cin >> endIndex;
	loop(i, 0, m_Length) {
		m_Array[i] = rand() % abs(endIndex - startIndex + 1) + startIndex;
	}
}
void CIntArray::OutputArray() {
	loop(i, 0, m_Length) {
		cout << m_Array[i];
		if (i < m_Length - 1) cout << " ";
	}
}
CIntArray CIntArray::Remove() {
	CIntArray uniqueArray(*this);
	if (uniqueArray.m_Length <= 1)
		return uniqueArray;
	for (int i = uniqueArray.m_Length - 1; i >= 0; --i) {
		for (int j = 0; j < i;) {
			if (uniqueArray.m_Array[i] == uniqueArray.m_Array[j]) {
				loop(k, j + 1, uniqueArray.m_Length) {
					uniqueArray.m_Array[k - 1] = uniqueArray.m_Array[k];
				}
				uniqueArray.m_Length--;
				break;
			}
			j++;
		}
	}
	return uniqueArray;
}
CIntArray CIntArray::Remove(int pos) {
	CIntArray removeIndex(*this);
	int index = pos;
	if (pos >= 0 && pos < m_Length) {
		loop(i, pos + 1, m_Length) {
			removeIndex.m_Array[i - 1] = removeIndex.m_Array[i];
		}
		removeIndex.m_Length--;
	}
	else {
		cout << "Invalid index!" << endl;
		return *this;
	}
	return removeIndex;
}
CIntArray CIntArray::Remove(int n, int k) {
	CIntArray removeGap(*this);
	int startIndex = k;
	int endIndex = k + n - 1;
	if (startIndex < 0 || endIndex >= removeGap.m_Length || startIndex > endIndex || n < 0) {
		cout << "Invalid index!" << endl;
		return *this;
	}
	for (int i = endIndex + 1; i < removeGap.m_Length; ++i) {
		removeGap.m_Array[i - n] = removeGap.m_Array[i];
	}
	removeGap.m_Length -= n;
	return removeGap;
}
CIntArray CIntArray::Replace(int old_val, int new_val) {
	CIntArray newArray(*this);
	loop(i, 0, newArray.m_Length) {
		if (newArray.m_Array[i] == old_val) {
			newArray.m_Array[i] = new_val;
		}
	}
	return newArray;
}
CIntArray CIntArray::AddHead(int value) {
	CIntArray newArray(m_Length + 1);
	newArray.m_Array[newArray.m_Length - 1] = 0;
	loop(i, 1, newArray.m_Length) {
		newArray.m_Array[i] = m_Array[i - 1];
	}
	newArray.m_Array[0] = value;
	return newArray;
}
CIntArray CIntArray::AddTail(int value) {
	CIntArray newArray(*this);
	newArray.m_Length++;
	newArray.m_Array[newArray.m_Length - 1] = value;
	return newArray;
}

CIntArray CIntArray::Insert(int value, int k) {
	CIntArray newArray(m_Length + 1);
	int newSize = newArray.m_Length;
	newArray.m_Array[newSize - 1] = 0;
	if (k > 0 && k < newSize - 1) {
		loop(i, 0, k) {
			newArray.m_Array[i] = m_Array[i];
		}
		loopReverse(i, k + 1, newSize - 1) {
			newArray.m_Array[i] = m_Array[i - 1];
		}
	}
	else {
		if (k <= 0) newArray = AddHead(value);
		if (k > m_Length) newArray = AddTail(value);
	}
	
	newArray.m_Array[k] = value;
	return newArray;
}

int CIntArray::Max() {
	int max_val = m_Array[0];
	for (int i = 0; i < m_Length; i++) {
		if (max_val < m_Array[i])
			max_val = m_Array[i];
	}
	return max_val;
}
int CIntArray::Min() {
	int min_val = m_Array[0];
	for (int i = 0; i < m_Length; i++) {
		if (min_val > m_Array[i])
			min_val = m_Array[i];
	}
	return min_val;
}

CIntArray CIntArray::Ascending() {
	for (int gap = m_Length / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < m_Length; i += 1)
		{
			int temp = m_Array[i];

			int j = 0;
			for (j = i; j >= gap && m_Array[j - gap] > temp; j -= gap)
				m_Array[j] = m_Array[j - gap];

			m_Array[j] = temp;
		}
	}
	return *this;
}
CIntArray CIntArray::Descending() {
	for (int gap = m_Length / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < m_Length; i += 1)
		{
			int temp = m_Array[i];

			int j = 0;
			for (j = i; j >= gap && m_Array[j - gap] < temp; j -= gap)
				m_Array[j] = m_Array[j - gap];

			m_Array[j] = temp;
		}
	}
	return *this;
}
bool CIntArray::IsSymmetry() {
	for (int i = 0; i < m_Length / 2; i++) {
		if (m_Array[i] != m_Array[m_Length - i - 1])
			return false;
	}
	return true;
}
CIntArray CIntArray::MoveForward() {
	CIntArray moveArray(*this);
	int last = moveArray.m_Array[m_Length - 1];
	loopReverse(i, 0, m_Length - 1) {
		moveArray.m_Array[i] = moveArray.m_Array[i - 1];
	}
	moveArray.m_Array[0] = last;
	return moveArray;
}
CIntArray CIntArray::MoveForward(int step) {
	CIntArray moveArray(*this);
	if (step % m_Length == 0) {
		return moveArray;
	}
	else if (step > m_Length) step -= m_Length;
	loop(i, 0, step) {
		moveArray.m_Array[step + i] = m_Array[i];
	}
	loop(i, step, m_Length) {
		moveArray.m_Array[i - step] = m_Array[i];
	}
	return moveArray;
}
CIntArray CIntArray::MoveBehind() {
	CIntArray moveArray(*this);
	int first = moveArray.m_Array[0];
	loop(i, 0, m_Length) { // sai
		moveArray.m_Array[i] = moveArray.m_Array[i + 1];
	}
	moveArray.m_Array[m_Length - 1] = first;
	return moveArray;
}
CIntArray CIntArray::MoveBehind(int step) {
	CIntArray moveArray(*this);
	if (step % m_Length == 0) {
		return moveArray;
	}
	else if (step > m_Length) step -= m_Length;
	loop(i, 0, step) {
		moveArray.m_Array[m_Length - step + i] = m_Array[i];
	}
	loop(i, step, m_Length) {
		moveArray.m_Array[i - step] = m_Array[i];
	}
	return moveArray;
}
CIntArray CIntArray::Invert() {
	CIntArray invertArr(*this);
	loop(i, 0, m_Length / 2) {
		int temp = invertArr.m_Array[i];
		invertArr.m_Array[i] = invertArr.m_Array[m_Length - i - 1];
		invertArr.m_Array[m_Length - i - 1] = temp;
	}
	return invertArr;
}

int CIntArray::Appearance(int key) {
	int cnt = 0;
	loop(i, 0, m_Length) {
		if (m_Array[i] == key) {
			cnt++;
		}
	}
	return cnt;
}