#pragma once
#include "CProduct.h"
#include "CElectronic.h"
#include "CTerracotta.h"
#include "CFood.h"
#include "CMyDate.h"
#include <set>
#include <chrono>
class CStore : public CProduct
{
private:
	vector <CProduct*> m_listProduct;
public:
	CStore();
	CStore(const CStore&);
	~CStore();
	void Input();
	void Output();
	void ViewExpDate();
	void Delete();
	void Buy();
	void ViewQuantity();
	CMyDate getCurrentDate();
};

