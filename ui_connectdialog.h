/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connectdialog
{
public:
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxDT;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayoutDT;
    QGridLayout *gridLayoutDT;
    QListWidget *listWidgetDT;
    QGroupBox *groupBoxT8K;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayoutT8K;
    QGridLayout *gridLayoutT8K;
    QListWidget *listWidgetT8K;
    QPushButton *pushButtonConnect;

    void setupUi(QDialog *connectdialog)
    {
        if (connectdialog->objectName().isEmpty())
            connectdialog->setObjectName(QStringLiteral("connectdialog"));
        connectdialog->setWindowModality(Qt::WindowModal);
        connectdialog->resize(577, 140);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(57);
        sizePolicy.setVerticalStretch(140);
        sizePolicy.setHeightForWidth(connectdialog->sizePolicy().hasHeightForWidth());
        connectdialog->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_3 = new QWidget(connectdialog);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 561, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        groupBoxDT = new QGroupBox(horizontalLayoutWidget_3);
        groupBoxDT->setObjectName(QStringLiteral("groupBoxDT"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        groupBoxDT->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(groupBoxDT);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 23, 160, 82));
        horizontalLayoutDT = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayoutDT->setObjectName(QStringLiteral("horizontalLayoutDT"));
        horizontalLayoutDT->setContentsMargins(5, 5, 5, 5);
        gridLayoutDT = new QGridLayout();
        gridLayoutDT->setObjectName(QStringLiteral("gridLayoutDT"));
        listWidgetDT = new QListWidget(horizontalLayoutWidget_2);
        listWidgetDT->setObjectName(QStringLiteral("listWidgetDT"));

        gridLayoutDT->addWidget(listWidgetDT, 0, 1, 1, 1);


        horizontalLayoutDT->addLayout(gridLayoutDT);


        horizontalLayout->addWidget(groupBoxDT);

        groupBoxT8K = new QGroupBox(horizontalLayoutWidget_3);
        groupBoxT8K->setObjectName(QStringLiteral("groupBoxT8K"));
        groupBoxT8K->setFont(font);
        horizontalLayoutWidget = new QWidget(groupBoxT8K);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 23, 161, 82));
        horizontalLayoutT8K = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayoutT8K->setObjectName(QStringLiteral("horizontalLayoutT8K"));
        horizontalLayoutT8K->setContentsMargins(5, 5, 5, 5);
        gridLayoutT8K = new QGridLayout();
        gridLayoutT8K->setObjectName(QStringLiteral("gridLayoutT8K"));
        listWidgetT8K = new QListWidget(horizontalLayoutWidget);
        listWidgetT8K->setObjectName(QStringLiteral("listWidgetT8K"));

        gridLayoutT8K->addWidget(listWidgetT8K, 0, 1, 1, 1);


        horizontalLayoutT8K->addLayout(gridLayoutT8K);


        horizontalLayout->addWidget(groupBoxT8K);

        pushButtonConnect = new QPushButton(horizontalLayoutWidget_3);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setEnabled(true);

        horizontalLayout->addWidget(pushButtonConnect);


        retranslateUi(connectdialog);

        QMetaObject::connectSlotsByName(connectdialog);
    } // setupUi

    void retranslateUi(QDialog *connectdialog)
    {
        connectdialog->setWindowTitle(QApplication::translate("connectdialog", "Dialog", 0));
        groupBoxDT->setTitle(QApplication::translate("connectdialog", "Device", 0));
        groupBoxT8K->setTitle(QApplication::translate("connectdialog", "T8K", 0));
        pushButtonConnect->setText(QApplication::translate("connectdialog", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class connectdialog: public Ui_connectdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
