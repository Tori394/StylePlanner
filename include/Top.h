#pragma once
#include "API.h"
#include <qstring.h>

class EXPORT_API Top
{
public:
	Top();
	~Top();

	void upInx();
	void downInx();
	QString give_top();

private:
	QString tab[5] = {"1", "2", "3", "4", "5"};
	int index;
};