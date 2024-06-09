#include "StylePlanner.h"
#include <qfiledialog.h>
#include <iostream>
#include <fstream>


StylePlanner::StylePlanner(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(QSize(915, 575));

    QVBoxLayout* layout = new QVBoxLayout(this);
    ui.scrollCont->setLayout(layout);

    err.setIcon(QMessageBox::Warning);

    displayPixT(); 
    displayPixB();

    load();
}

StylePlanner::~StylePlanner()
{
    save();
    favourities.clear();
}

void StylePlanner::load()
{
    std::fstream wl("C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/Assets/save_fav.txt");
    if (!wl.is_open())
    {
        qWarning("Blad otwarcia pliku");
        return;
    }

    std::string rawpath;
    QString qpath;
    QString qpath2;

    while (std::getline(wl, rawpath))
    {
        if (!rawpath.empty() && rawpath.back() == '\n')
        {
            rawpath.resize(rawpath.size() - 1);
        }
        qpath = qpath.fromStdString(rawpath);
        getline(wl, rawpath);
        if (!rawpath.empty() && rawpath.back() == '\n')
        {
            rawpath.resize(rawpath.size() - 1);
        }
        qpath2 = qpath2.fromStdString(rawpath);
        favourities.push_back(qMakePair(qpath, qpath2));

        QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.scrollCont->layout());

        QHBoxLayout* newlayout = new QHBoxLayout(ui.scrollCont);

        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        QPushButton* but = new QPushButton(ui.scrollCont);
        but->setIcon(icon2);
        but->setFixedSize(50, 50);
        but->setStyleSheet("background-color: rgb(215, 215, 215);");
        newlayout->addWidget(but);

        QLabel* labelTop = new QLabel(ui.scrollCont);
        QPixmap p(qpath);
        labelTop->setPixmap(p.scaled(200, 200));
        labelTop->setProperty("imagePath", qpath);
        labelTop->setFixedSize(200, 200);
        labelTop->setStyleSheet("background-color: rgb(215, 215, 215);");
        newlayout->addWidget(labelTop);

        QLabel* labelBot = new QLabel(ui.scrollCont);
        QPixmap q(qpath2);
        labelBot->setPixmap(q.scaled(200, 200));
        labelBot->setProperty("imagePath", qpath2);
        labelBot->setFixedSize(200, 200);
        labelBot->setStyleSheet("background-color: rgb(215, 215, 215);");
        newlayout->addWidget(labelBot);

        layout->insertLayout(0, newlayout);

        button_to_layout.insert(but, newlayout);


        QObject::connect
        (
            but, &QPushButton::clicked,
            this, &StylePlanner::on_unflagFav
        );
    }
    wl.close();
}

void StylePlanner::save()
{
    std::fstream w("C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/Assets/save_fav.txt", std::ios::out | std::ios::trunc);
    if (!w.is_open())
    {
        qWarning("Blad otwarcia pliku");
        return;
    }

    for (int i = 0; i < favourities.size(); i++)
    {
        w << favourities[i].first.toStdString() << '\n';
        w << favourities[i].second.toStdString() << '\n';

    }
    w.close();
}

void StylePlanner::on_Pbut_clicked()
{
    tops.upInx();
    displayPixT();
}

void StylePlanner::on_Lbut_clicked()
{
    tops.downInx();
    displayPixT();
}

void StylePlanner::displayPixT()
{
    int w = ui.TopPic->width();
    QPixmap p(tops.give());
    ui.TopPic->setPixmap(p.scaled(w, w, Qt::KeepAspectRatio));
    ui.TopPic->setProperty("imagePath", tops.give());
}

void StylePlanner::on_addTop_clicked()
{
    if (tops.size() <= 200)
    {
        try
            {
            QString filePath = QFileDialog::getOpenFileName(this, tr("Wybierz zdjecie"), "", tr("Images (*.png *.jpg *.bmp)")); //(tytul okna dialogowego, katalog poczatkowy, filtr plikow)
            if (filePath.isEmpty())                                                                                            //tr() to makro u¿ywane w Qt do t³umaczenia tekstów. Pozwala na ³atwe miêdzynarodowe 
                throw  std::runtime_error("Niewlasciwy plik");                                                                             //t³umaczenia aplikacji. Teksty przekazywane do tr() mog¹ byæ póŸniej przet³umaczone 
                                                                                                                               //na inne jêzyki przy u¿yciu narzêdzi t³umaczeniowych Qt.
            std::string t = filePath.toStdString();
            if (t.find(" ")!=std::string::npos)
                throw  std::runtime_error("Niewlasciwa nazwa pliku (sprawdz czy nie zawiera spacji)");
            QPixmap pixmap(filePath);
            if (pixmap.isNull()) 
                throw  std::runtime_error("Niewlasciwa sciezka pliku");
            tops.add_top(filePath);
            on_Pbut_clicked();
            }
            catch (const std::exception& e)
            {
                qWarning("Nie udalo sie zaladowac obrazu", e.what());

                err.setIcon(QMessageBox::Critical);
                err.setText(e.what());
                err.exec();
                err.setIcon(QMessageBox::Warning);
            }
    }
    else
    {
        err.setText("Maksymalna ilosc przechowywanych ubran na sekcje to 200");
        err.exec();
    }
}

void StylePlanner::on_delTop_clicked()
{
    try
    {
        if (tops.size() < 1)
            throw std::runtime_error("Nie ma zadnych obiektow do usuniecia");
        if (tops.flags() > 0)
            throw std::runtime_error("Nie mozna usunac elementu ktory tworzy zestaw");
        tops.delete_top();
        displayPixT();
    }
    catch (const std::exception& e)
    {
        qWarning("Blad usuwania elementu");
        err.setText(e.what());
        err.exec();
    }
}

void StylePlanner::displayPixB()
{
    int w = ui.BotPic->width();
    QPixmap p(bots.give());
    ui.BotPic->setPixmap(p.scaled(w, w, Qt::KeepAspectRatio));
    ui.BotPic->setProperty("imagePath", bots.give());
}

void StylePlanner::on_PbutB_clicked()
{
    bots.upInx();
    displayPixB();
}

void StylePlanner::on_LbutB_clicked()
{
    bots.downInx();
    displayPixB();
}

void StylePlanner::on_addBot_clicked()
{
    if (bots.size() <= 200)
    {
        try
        {
            QString filePath = QFileDialog::getOpenFileName(this, tr("Wybierz zdjecie"), "", tr("Images (*.png *.jpg *.bmp)")); //(tytul okna dialogowego, katalog poczatkowy, filtr plikow)
            if (filePath.isEmpty())                                                                                            //tr() to makro u¿ywane w Qt do t³umaczenia tekstów. Pozwala na ³atwe miêdzynarodowe 
                throw  std::runtime_error("Niewlasciwy plik");                                                                  //t³umaczenia aplikacji. Teksty przekazywane do tr() mog¹ byæ póŸniej przet³umaczone 
                                                                                                                               //na inne jêzyki przy u¿yciu narzêdzi t³umaczeniowych Qt.
            std::string t = filePath.toStdString();
            if (t.find(" ") != std::string::npos)
                throw  std::runtime_error("Niewlasciwa nazwa pliku (sprawdz czy nie zawiera spacji)");
            QPixmap pixmap(filePath);
            if (pixmap.isNull())
                throw  std::runtime_error("Niewlasciwa sciezka pliku");
            bots.add_bot(filePath);
            on_PbutB_clicked();
        }
        catch (const std::exception& e)
        {
            qWarning("Nie udalo sie zaladowac obrazu", e.what());

            err.setIcon(QMessageBox::Critical);
            err.setText(e.what());
            err.exec();
            err.setIcon(QMessageBox::Warning);
        }
    }
    else
    {
        err.setText("Maksymalna ilosc przechowywanych ubran na sekcje to 200");
        err.exec();
    }
}

void StylePlanner::on_delBot_clicked()
{
    try
    {
        if (bots.size() < 1)
            throw std::runtime_error("Nie ma zadnych obiektow do usuniecia");
        if (bots.flags() > 0)
            throw std::runtime_error("Nie mozna usunac elementu ktory tworzy zestaw");
        bots.delete_bot();
        displayPixB();
    }
    catch (const std::exception& e)
    {
        qWarning("Blad usuwania elementu");
        err.setText(e.what());
        err.exec();
    }
}

void StylePlanner::on_flagFav_clicked()
{
    if (tops.give() == "add" || bots.give() == "add")
    {
        err.setText("Nie mozna dodac zestawu bez wybrania dwoch elementow");
        err.exec();
        return;
    }

    if (favourities.size() >= 300)
    {
        err.setText("Posiadasz juz za duzo zestawow (max. 300)");
        err.exec();
        return;
    }

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.scrollCont->layout());

    QHBoxLayout* newlayout = new QHBoxLayout(ui.scrollCont);

    QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
    QPushButton* but = new QPushButton(ui.scrollCont);
    but->setIcon(icon2);
    but->setFixedSize(50, 50);
    but->setStyleSheet("background-color: rgb(215, 215, 215);");
    newlayout->addWidget(but);
    
    QLabel* labelTop = new QLabel(ui.scrollCont);
    QPixmap p(tops.give());
    labelTop->setPixmap(p.scaled(200, 200));
    labelTop->setProperty("imagePath", tops.give());
    labelTop->setFixedSize(200, 200);
    labelTop->setStyleSheet("background-color: rgb(215, 215, 215);");
    newlayout->addWidget(labelTop);
    tops.fav_add();

    QLabel* labelBot = new QLabel(ui.scrollCont);
    QPixmap q(bots.give());
    labelBot->setPixmap(q.scaled(200, 200));
    labelBot->setProperty("imagePath", bots.give());
    labelBot->setFixedSize(200, 200);
    labelBot->setStyleSheet("background-color: rgb(215, 215, 215);");
    newlayout->addWidget(labelBot);
    bots.fav_add();

    layout->insertLayout(0, newlayout);

    button_to_layout.insert(but, newlayout);

    favourities.push_back(qMakePair(tops.give(), bots.give()));

    QObject::connect
    (
        but, &QPushButton::clicked,
        this, &StylePlanner::on_unflagFav
        );
}


std::vector<QPair<QString, QString>>::const_iterator findPair(const std::vector<QPair<QString, QString>>& favourites, const QString& topImagePath, const QString& botImagePath) {
    for (auto it = favourites.begin(); it != favourites.end(); ++it) {
        if (it->first == topImagePath && it->second == botImagePath) {
            return it;
        }
    }
    return favourites.end();
}



void StylePlanner::on_unflagFav()
{
    QPushButton* but = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* layout = button_to_layout.take(but);

    QString topImagePath;
    QString botImagePath;

    QLayoutItem* item = layout->itemAt(1);
    if (QLabel* label = qobject_cast<QLabel*>(item->widget()))
    {
        topImagePath = label->property("imagePath").toString();
    }
    item = layout->itemAt(2);
    if (QLabel* label = qobject_cast<QLabel*>(item->widget()))
    {
        botImagePath = label->property("imagePath").toString();
    }

    while (layout->count() != 0)
    {
        QLayoutItem* item = layout->takeAt(0);
        delete item->widget();
        delete item;
    }
    delete layout;

    auto it = findPair(favourities, topImagePath, botImagePath);
    if (it != favourities.end()) {
        favourities.erase(it);
    }

    tops.fav_del(topImagePath);
    bots.fav_del(botImagePath);
}