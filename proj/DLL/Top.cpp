#include "Top.h"
#include <qfile.h>
#include <qfileinfo.h>
using namespace std;

Top::Top()
{
	index = 0;
	tops.push_back(piece{ "add", 0 });
	load();
}

Top::~Top()
{
	save();
	tops.clear();
}

void Top::upInx()
{
	if (index != tops.size() - 1)
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
	else index = tops.size() - 1;
}

void Top::add_top(QString a)
{

	if (!QFile::exists(a)) 
	{
		qWarning("Plik nie istnieje");
		return;
	}

	QString destination = filePath + QFileInfo(a).fileName();
	

	if (!QFile::copy(a, destination)) 
	{
		qWarning("Failed to save image");
		return;
	}

	tops.push_back(piece{ destination, 0});

}

void Top::delete_top()
{
	if (!index)
	{
		qWarning("Nie ma zadnych zdjec do usuniecia");
		return;
	}
	else
	{
		QFile file(tops[index].name);
		file.remove();
		tops.erase(tops.begin() + index);
		index--;
	}
}


QString Top::give()
{
	return  tops[index].name;
}

void Top::fav_add()
{
	tops[index].flag++;
}

void Top::fav_del(QString target)
{
	int i = 1;
	while (i < tops.size())
	{
		if (tops[i].name == target)
		{
			tops[i].flag--;
			return;
		}
		i++;
	}
}

int Top::size()
{
	return tops.size();
}

int Top::flags()
{
	return tops[index].flag;
}

void Top::save()
{
	std::ofstream wpisz(savePath.toStdString(), std::ios::out | std::ios::trunc);

	if (!wpisz.is_open()) 
	{
		qWarning("Failed to open save file");
		return;
	}

	for (int i = 1; i < tops.size(); i++)
	{
		wpisz << tops[i].name.toStdString() << '\n';
		wpisz << tops[i].flag << '\n';
	}

	wpisz.close();
}

void Top::load()
{
	std::fstream wpisz(savePath.toStdString());

	if (!wpisz.is_open())
	{
		qWarning("Failed to open file");
		return;
	}

	string rawpath;
	QString qpath;
	int flag;

	while(std::getline(wpisz, rawpath))
	{
		if (!rawpath.empty() && rawpath.back() == '\n')
		{
			rawpath.resize(rawpath.size() - 1);
		}
		qpath = qpath.fromStdString(rawpath);
		getline(wpisz, rawpath);
		if (!rawpath.empty() && rawpath.back() == '\n')
		{
			rawpath.resize(rawpath.size() - 1);
		}
		flag = stoi(rawpath);
		tops.push_back(piece{ qpath, flag});
	}

	wpisz.close();
}
