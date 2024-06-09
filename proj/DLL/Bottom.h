#pragma once
#include "API.h"
#include <vector>
#include <qstring.h>
#include <fstream>
#include <iostream>

struct pieceB
{
	QString name;
	int flag;
};

class EXPORT_API Bottom
{
public:
	Bottom();
	~Bottom();

	void upInx();
	void downInx();
	void add_bot(QString a);
	void delete_bot();
	QString give();
	void fav_add();
	void fav_del(QString);
	int size();
	int flags();

	void save();
	void load();

private:
	std::vector<pieceB> bottoms;
	int index;
	QString filePath = "C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/Assets/Bottoms/";
	QString savePath = filePath + "save_names.txt";
};