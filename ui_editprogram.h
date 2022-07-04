/********************************************************************************
** Form generated from reading UI file 'editprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROGRAM_H
#define UI_EDITPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_editprogram
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *editprogram)
    {
        if (editprogram->objectName().isEmpty())
            editprogram->setObjectName(QStringLiteral("editprogram"));
        editprogram->resize(402, 173);
        textEdit = new QTextEdit(editprogram);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 261, 151));
        QFont font;
        font.setPointSize(11);
        textEdit->setFont(font);
        pushButtonSave = new QPushButton(editprogram);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(290, 20, 101, 31));
        pushButtonCancel = new QPushButton(editprogram);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(290, 60, 101, 31));

        retranslateUi(editprogram);

        QMetaObject::connectSlotsByName(editprogram);
    } // setupUi

    void retranslateUi(QDialog *editprogram)
    {
        editprogram->setWindowTitle(QApplication::translate("editprogram", "Dialog", 0));
        textEdit->setHtml(QApplication::translate("editprogram", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">XPRG 0 35 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">XLEV 2000 18 300 0 0 1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">XCYC 13</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style="
                        "\" font-size:16pt;\">XSAV melting</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p></body></html>", 0));
        pushButtonSave->setText(QApplication::translate("editprogram", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        pushButtonCancel->setText(QApplication::translate("editprogram", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class editprogram: public Ui_editprogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROGRAM_H
