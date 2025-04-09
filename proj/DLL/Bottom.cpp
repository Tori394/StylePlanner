#include "Bottom.h"
#include <qfile.h>
#include <qfileinfo.h>
using namespace std;

Bottom::Bottom()
{
	index = 0;
	bottoms.push_back(pieceB{ "add", 0});
	load();
}

Bottom::~Bottom()
{
	save();
	bottoms.clear();
}

void Bottom::upInx()
{
	if (index != bottoms.size() - 1)
	{
		index++;
	}
	else index = 0;
}

void Bottom::downInx()
{
	if (index != 0)
	{
		index--;
	}
	else index = bottoms.size() - 1;
}

void Bottom::add_bot(QString a)
{

	if (!QFile::exists(a))
	{
		qWarning("Plik nie istnieje");
		return;
	}

	QString destination = filePath + QFileInfo(a).fileName();


	if (!QFile::copy(a, destination))
	{
		qWarning("Nie udalo sie zapisac obrazu");
		return;
	}

	bottoms.push_back(pieceB{ destination, 0});

}

void Bottom::delete_bot()
{
	if (!index)
	{
		qWarning("Nie ma zadnych zdjec do usuniecia");
		return;
	}
	else
	{
		QFile file(bottoms[index].name);
		file.remove();
		bottoms.erase(bottoms.begin() + index);
		index--;
	}
}


QString Bottom::give()
{
	return  bottoms[index].name;
}

void Bottom::fav_add()
{
	bottoms[index].flag++;
}

void Bottom::fav_del(QString target)
{
	int i = 1;
	while (i < bottoms.size())
	{
		if (bottoms[i].name == target)
		{
			bottoms[i].flag--;
			return;
		}
		i++;
	}
}

int Bottom::size()
{
	return bottoms.size();
}

int Bottom::flags()
{
	return bottoms[index].flag;
}

void Bottom::save()
{
	std::ofstream wpiszB(savePath.toStdString(), std::ios::out | std::ios::trunc);

	if (!wpiszB.is_open())
	{
		qWarning("Nie udalo sie otworzyc pliku");
		return;
	}

	for (int i = 1; i < bottoms.size(); i++)
	{
		wpiszB << bottoms[i].name.toStdString() << '\n';
		wpiszB << bottoms[i].flag << '\n';
	}

	wpiszB.close();
}

void Bottom::load()
{
	std::fstream wpiszB(savePath.toStdString());

	if (!wpiszB.is_open())
	{
		qWarning("Nie udalo sie otworzyc pliku");
		return;
	}

	string rawpath;
	QString qpath;
	int flag;

	while (std::getline(wpiszB, rawpath))
	{
		if (!rawpath.empty() && rawpath.back() == '\n')
		{
			rawpath.resize(rawpath.size() - 1);
		}
		qpath = qpath.fromStdString(rawpath);
		getline(wpiszB, rawpath);
		if (!rawpath.empty() && rawpath.back() == '\n')
		{
			rawpath.resize(rawpath.size() - 1);
		}
		flag = stoi(rawpath);
		bottoms.push_back(pieceB{ qpath, flag });
	}

	wpiszB.close();
}
