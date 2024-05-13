#include "Top.h"

Top::Top()
{
	index = 0;
}

Top::~Top()
{
	//nth
}

void Top::upInx()
{
	if (index != 4)
	{
		index++;
	}
	else index = 0;
}

void Top::downInx()
{
	if (index != 0)
	{
		index--;
	}
	else index = 4;
}

QString Top::give_top()
{
	return tab[index];
}
