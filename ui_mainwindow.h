/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTableWidget *tableWidgetOldCoef;
    QTableWidget *tableWidgetNewCoef;
    QGroupBox *groupBoxMeasuredTemp;
    QTableWidget *tableWidgetMeasuredTemp;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonConnect;
    QFrame *line;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonExcerpt;
    QLabel *labelStatus;
    QMenuBar *menuBar;
    QMenu *menuMelting_Calibrator;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 310);
        MainWindow->setMinimumSize(QSize(680, 310));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 10, 289, 245));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        tableWidgetOldCoef = new QTableWidget(groupBox);
        if (tableWidgetOldCoef->columnCount() < 2)
            tableWidgetOldCoef->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidgetOldCoef->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetOldCoef->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidgetOldCoef->rowCount() < 6)
            tableWidgetOldCoef->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetOldCoef->setVerticalHeaderItem(5, __qtablewidgetitem7);
        tableWidgetOldCoef->setObjectName(QStringLiteral("tableWidgetOldCoef"));
        tableWidgetOldCoef->setGeometry(QRect(10, 30, 123, 205));
        QFont font1;
        font1.setPointSize(10);
        tableWidgetOldCoef->setFont(font1);
        tableWidgetOldCoef->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetOldCoef->setTextElideMode(Qt::ElideRight);
        tableWidgetOldCoef->setShowGrid(true);
        tableWidgetOldCoef->setCornerButtonEnabled(true);
        tableWidgetOldCoef->horizontalHeader()->setDefaultSectionSize(60);
        tableWidgetOldCoef->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetOldCoef->verticalHeader()->setVisible(false);
        tableWidgetOldCoef->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetNewCoef = new QTableWidget(groupBox);
        if (tableWidgetNewCoef->columnCount() < 2)
            tableWidgetNewCoef->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidgetNewCoef->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidgetNewCoef->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        if (tableWidgetNewCoef->rowCount() < 6)
            tableWidgetNewCoef->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetNewCoef->setVerticalHeaderItem(5, __qtablewidgetitem15);
        tableWidgetNewCoef->setObjectName(QStringLiteral("tableWidgetNewCoef"));
        tableWidgetNewCoef->setGeometry(QRect(150, 30, 123, 205));
        tableWidgetNewCoef->setFont(font1);
        tableWidgetNewCoef->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableWidgetNewCoef->setColumnCount(2);
        tableWidgetNewCoef->horizontalHeader()->setDefaultSectionSize(60);
        tableWidgetNewCoef->verticalHeader()->setVisible(false);
        groupBoxMeasuredTemp = new QGroupBox(centralWidget);
        groupBoxMeasuredTemp->setObjectName(QStringLiteral("groupBoxMeasuredTemp"));
        groupBoxMeasuredTemp->setGeometry(QRect(10, 10, 181, 245));
        groupBoxMeasuredTemp->setFont(font);
        tableWidgetMeasuredTemp = new QTableWidget(groupBoxMeasuredTemp);
        if (tableWidgetMeasuredTemp->columnCount() < 2)
            tableWidgetMeasuredTemp->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        if (tableWidgetMeasuredTemp->rowCount() < 6)
            tableWidgetMeasuredTemp->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetMeasuredTemp->setVerticalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(0, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(1, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(3, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(4, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        tableWidgetMeasuredTemp->setItem(5, 0, __qtablewidgetitem29);
        tableWidgetMeasuredTemp->setObjectName(QStringLiteral("tableWidgetMeasuredTemp"));
        tableWidgetMeasuredTemp->setGeometry(QRect(12, 29, 152, 205));
        tableWidgetMeasuredTemp->setFont(font1);
        tableWidgetMeasuredTemp->setMidLineWidth(0);
        tableWidgetMeasuredTemp->setAutoScrollMargin(16);
        tableWidgetMeasuredTemp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetMeasuredTemp->horizontalHeader()->setDefaultSectionSize(75);
        tableWidgetMeasuredTemp->horizontalHeader()->setMinimumSectionSize(75);
        tableWidgetMeasuredTemp->verticalHeader()->setVisible(false);
        tableWidgetMeasuredTemp->verticalHeader()->setHighlightSections(true);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(510, 30, 152, 161));
        groupBox_2->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonConnect = new QPushButton(groupBox_2);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        pushButtonConnect->setFont(font2);

        verticalLayout->addWidget(pushButtonConnect);

        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButtonStart = new QPushButton(groupBox_2);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        pushButtonStart->setFont(font3);

        verticalLayout->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(groupBox_2);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setFont(font3);

        verticalLayout->addWidget(pushButtonStop);

        pushButtonWrite = new QPushButton(groupBox_2);
        pushButtonWrite->setObjectName(QStringLiteral("pushButtonWrite"));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        pushButtonWrite->setFont(font4);

        verticalLayout->addWidget(pushButtonWrite);

        pushButtonExcerpt = new QPushButton(groupBox_2);
        pushButtonExcerpt->setObjectName(QStringLiteral("pushButtonExcerpt"));
        pushButtonExcerpt->setFont(font4);

        verticalLayout->addWidget(pushButtonExcerpt);

        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(500, 230, 181, 25));
        QFont font5;
        font5.setPointSize(9);
        labelStatus->setFont(font5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 20));
        menuMelting_Calibrator = new QMenu(menuBar);
        menuMelting_Calibrator->setObjectName(QStringLiteral("menuMelting_Calibrator"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMelting_Calibrator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetOldCoef->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\213\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetNewCoef->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\265", 0));
        groupBoxMeasuredTemp->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 T8K", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetMeasuredTemp->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetMeasuredTemp->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\342\204\203", 0));

        const bool __sortingEnabled = tableWidgetMeasuredTemp->isSortingEnabled();
        tableWidgetMeasuredTemp->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetMeasuredTemp->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetMeasuredTemp->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetMeasuredTemp->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetMeasuredTemp->item(3, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetMeasuredTemp->item(4, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetMeasuredTemp->item(5, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "6", 0));
        tableWidgetMeasuredTemp->setSortingEnabled(__sortingEnabled);

        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\273\321\216\321\207\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0));
        pushButtonStart->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", 0));
        pushButtonStop->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", 0));
        pushButtonWrite->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\272\320\276\321\215\321\204\321\204.", 0));
        pushButtonExcerpt->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\321\200\320\266\320\272\320\260", 0));
        labelStatus->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\237\321\200\320\270\320\261\320\276\321\200 \320\275\320\265 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275", 0));
        menuMelting_Calibrator->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
