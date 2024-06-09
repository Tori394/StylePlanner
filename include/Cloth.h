#pragma once
#include "API.h"
#include <vector>
#include <qstring.h>

class EXPORT_API Cloth
{
public:
	Cloth();
	~Cloth();

	void upInx();
	void downInx();
	void add_top(QString a);
	void delete_top();
	QString give();
	
	void save();
	void load();

private:
	std::vector<QString> clothes;
	int index;
	QString filePath = "C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/Assets/Tops/";
	QString savePath = filePath + "save_names.txt";
};