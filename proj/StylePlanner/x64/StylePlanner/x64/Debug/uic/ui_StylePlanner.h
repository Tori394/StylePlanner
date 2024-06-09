/********************************************************************************
** Form generated from reading UI file 'StylePlanner.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEPLANNER_H
#define UI_STYLEPLANNER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StylePlannerClass
{
public:
    QWidget *centralWidget;
    QTabWidget *Zakladki;
    QWidget *tab_3;
    QPushButton *PbutB;
    QPushButton *addBot;
    QPushButton *delBot;
    QPushButton *LbutB;
    QPushButton *addTop;
    QLabel *BotPic;
    QPushButton *delTop;
    QLabel *TopPic;
    QPushButton *Lbut;
    QPushButton *Pbut;
    QPushButton *flagFav;
    QWidget *tab_4;
    QScrollArea *scrollArea;
    QWidget *scrollCont;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StylePlannerClass)
    {
        if (StylePlannerClass->objectName().isEmpty())
            StylePlannerClass->setObjectName("StylePlannerClass");
        StylePlannerClass->resize(922, 622);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StylePlannerClass->sizePolicy().hasHeightForWidth());
        StylePlannerClass->setSizePolicy(sizePolicy);
        StylePlannerClass->setMinimumSize(QSize(0, 0));
        StylePlannerClass->setAutoFillBackground(false);
        StylePlannerClass->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"background: url(C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/wood_background.jpg);\n"
"}"));
        centralWidget = new QWidget(StylePlannerClass);
        centralWidget->setObjectName("centralWidget");
        Zakladki = new QTabWidget(centralWidget);
        Zakladki->setObjectName("Zakladki");
        Zakladki->setGeometry(QRect(0, 0, 921, 621));
        Zakladki->setAutoFillBackground(false);
        Zakladki->setStyleSheet(QString::fromUtf8("\n"
"QTabWidget::pane {\n"
"  border: 0px;\n"
"  top: 1px; \n"
"} \n"
"\n"
"QTabBar::tab {\n"
"  border: 1px solid lightgray; \n"
"  padding: 5px;\n"
"  background: url(C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/wood_tab.jpg);\n"
"\n"
"} \n"
"\n"
"QTabBar::tab:selected { \n"
"  margin-bottom: 1px;\n"
"  background: url(C:/Users/Studia/Desktop/AplikacjaOkienkowaJIPP/bin/wood_tab_open.jpg); \n"
"\n"
"}\n"
""));
        Zakladki->setTabPosition(QTabWidget::TabPosition::East);
        Zakladki->setTabShape(QTabWidget::TabShape::Rounded);
        Zakladki->setIconSize(QSize(30, 30));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        PbutB = new QPushButton(tab_3);
        PbutB->setObjectName("PbutB");
        PbutB->setGeometry(QRect(590, 390, 31, 24));
        PbutB->setAutoFillBackground(false);
        PbutB->setStyleSheet(QString::fromUtf8(""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-seek-forward")));
        PbutB->setIcon(icon);
        addBot = new QPushButton(tab_3);
        addBot->setObjectName("addBot");
        addBot->setGeometry(QRect(590, 440, 31, 31));
        addBot->setAutoFillBackground(false);
        addBot->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("list-add")));
        addBot->setIcon(icon1);
        delBot = new QPushButton(tab_3);
        delBot->setObjectName("delBot");
        delBot->setGeometry(QRect(590, 480, 31, 31));
        delBot->setAutoFillBackground(false);
        delBot->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        delBot->setIcon(icon2);
        delBot->setFlat(false);
        LbutB = new QPushButton(tab_3);
        LbutB->setObjectName("LbutB");
        LbutB->setGeometry(QRect(260, 390, 31, 24));
        LbutB->setAutoFillBackground(false);
        LbutB->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("media-seek-backward")));
        LbutB->setIcon(icon3);
        addTop = new QPushButton(tab_3);
        addTop->setObjectName("addTop");
        addTop->setGeometry(QRect(590, 200, 31, 31));
        addTop->setAutoFillBackground(false);
        addTop->setStyleSheet(QString::fromUtf8(""));
        addTop->setIcon(icon1);
        BotPic = new QLabel(tab_3);
        BotPic->setObjectName("BotPic");
        BotPic->setGeometry(QRect(340, 310, 201, 201));
        BotPic->setFrameShape(QFrame::Shape::Box);
        BotPic->setScaledContents(true);
        delTop = new QPushButton(tab_3);
        delTop->setObjectName("delTop");
        delTop->setGeometry(QRect(590, 240, 31, 31));
        delTop->setAutoFillBackground(false);
        delTop->setStyleSheet(QString::fromUtf8(""));
        delTop->setIcon(icon2);
        TopPic = new QLabel(tab_3);
        TopPic->setObjectName("TopPic");
        TopPic->setGeometry(QRect(340, 70, 201, 201));
        TopPic->setFrameShape(QFrame::Shape::Box);
        TopPic->setScaledContents(true);
        Lbut = new QPushButton(tab_3);
        Lbut->setObjectName("Lbut");
        Lbut->setGeometry(QRect(260, 150, 31, 24));
        Lbut->setAutoFillBackground(false);
        Lbut->setStyleSheet(QString::fromUtf8(""));
        Lbut->setIcon(icon3);
        Pbut = new QPushButton(tab_3);
        Pbut->setObjectName("Pbut");
        Pbut->setGeometry(QRect(590, 150, 31, 24));
        Pbut->setAutoFillBackground(false);
        Pbut->setStyleSheet(QString::fromUtf8(""));
        Pbut->setIcon(icon);
        flagFav = new QPushButton(tab_3);
        flagFav->setObjectName("flagFav");
        flagFav->setGeometry(QRect(420, 20, 51, 31));
        flagFav->setAutoFillBackground(false);
        flagFav->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("emblem-favorite")));
        flagFav->setIcon(icon4);
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("edit-select-all")));
        Zakladki->addTab(tab_3, icon5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        scrollArea = new QScrollArea(tab_4);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 10, 841, 581));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: rgb(180, 119, 66);\n"
"}\n"
"\n"
"QScrollBar {\n"
"    background-color: rgb(221, 221, 221);\n"
"}\n"
"QWidget\n"
"{\n"
" background-color: rgb(180, 119, 66);\n"
"}\n"
"QScrollBar:vertical { background-color: rgb(221, 221, 221); width: 15px; }\n"
"QScrollBar::handle:vertical { background-color: rgb(160, 160, 160); }\n"
"QScrollBar:horizontal { background-color: rgb(221, 221, 221); height: 15px; }\n"
"QScrollBar::handle:horizontal { background-color: rgb(160, 160, 160); }"));
        scrollArea->setWidgetResizable(true);
        scrollCont = new QWidget();
        scrollCont->setObjectName("scrollCont");
        scrollCont->setGeometry(QRect(0, 0, 839, 579));
        scrollArea->setWidget(scrollCont);
        Zakladki->addTab(tab_4, icon4, QString());
        StylePlannerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StylePlannerClass);
        statusBar->setObjectName("statusBar");
        StylePlannerClass->setStatusBar(statusBar);

        retranslateUi(StylePlannerClass);

        Zakladki->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StylePlannerClass);
    } // setupUi

    void retranslateUi(QMainWindow *StylePlannerClass)
    {
        StylePlannerClass->setWindowTitle(QCoreApplication::translate("StylePlannerClass", "StylePlanner", nullptr));
        PbutB->setText(QString());
        addBot->setText(QString());
        delBot->setText(QString());
        LbutB->setText(QString());
        addTop->setText(QString());
        BotPic->setStyleSheet(QString());
        BotPic->setText(QString());
        delTop->setText(QString());
        TopPic->setStyleSheet(QString());
        TopPic->setText(QString());
        Lbut->setText(QString());
        Pbut->setText(QString());
        flagFav->setText(QString());
        Zakladki->setTabText(Zakladki->indexOf(tab_3), QCoreApplication::translate("StylePlannerClass", "\342\200\216 \342\200\216 \342\200\216 \342\200\216 \342\200\216 ", nullptr));
        Zakladki->setTabText(Zakladki->indexOf(tab_4), QCoreApplication::translate("StylePlannerClass", "\342\200\216 \342\200\216 \342\200\216 \342\200\216 \342\200\216 \342\200\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StylePlannerClass: public Ui_StylePlannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEPLANNER_H
