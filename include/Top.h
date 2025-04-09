#pragma once
#include "API.h"
#include <vector>
#include <qstring.h>
#include <fstream>
#include <iostream>

struct piece
{
	QString name;
	int flag;
};

class EXPORT_API Top
{
public:
	Top();
	~Top();

	void upInx();
	void downInx();
	void add_top(QString a);
	void delete_top();
	QString give();
	void fav_add();
	void fav_del(QString);
	int size();
	int flags();
	
	void save();
	void load();

private:
	std::vector<piece> tops;
	int index;
	QString filePath = "Assets/Tops/";
	QString savePath = filePath + "save_names.txt";
};