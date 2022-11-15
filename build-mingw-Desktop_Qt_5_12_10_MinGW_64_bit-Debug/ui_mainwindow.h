/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *Corr_X;
    QCheckBox *Corr_Y;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *effect;
    QPushButton *pause;
    QPushButton *B1;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *Butt_X;
    QCheckBox *Butt_Y;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *err_plot_x;
    QCustomPlot *err_plot_y;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_8;
    QCustomPlot *plot_x;
    QCustomPlot *plot_y;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(795, 565);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAcceptDrops(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMaximumSize(QSize(135, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Corr_X = new QCheckBox(groupBox_8);
        Corr_X->setObjectName(QString::fromUtf8("Corr_X"));

        horizontalLayout_6->addWidget(Corr_X);

        Corr_Y = new QCheckBox(groupBox_8);
        Corr_Y->setObjectName(QString::fromUtf8("Corr_Y"));

        horizontalLayout_6->addWidget(Corr_Y);


        verticalLayout_5->addWidget(groupBox_8);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(pushButton_4);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_5);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMaximumSize(QSize(1000000, 1000000));
        label->setFrameShape(QFrame::Box);
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        effect = new QPushButton(groupBox);
        effect->setObjectName(QString::fromUtf8("effect"));

        horizontalLayout->addWidget(effect);

        pause = new QPushButton(groupBox);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout->addWidget(pause);

        B1 = new QPushButton(groupBox);
        B1->setObjectName(QString::fromUtf8("B1"));

        horizontalLayout->addWidget(B1);


        verticalLayout_3->addWidget(groupBox);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tab_4->setMinimumSize(QSize(767, 463));
        horizontalLayout_3 = new QHBoxLayout(tab_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy5);
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_4->addWidget(pushButton_6);

        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Butt_X = new QCheckBox(groupBox_7);
        Butt_X->setObjectName(QString::fromUtf8("Butt_X"));

        horizontalLayout_5->addWidget(Butt_X);

        Butt_Y = new QCheckBox(groupBox_7);
        Butt_Y->setObjectName(QString::fromUtf8("Butt_Y"));

        horizontalLayout_5->addWidget(Butt_Y);


        verticalLayout_4->addWidget(groupBox_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        err_plot_x = new QCustomPlot(groupBox_6);
        err_plot_x->setObjectName(QString::fromUtf8("err_plot_x"));

        verticalLayout_6->addWidget(err_plot_x);

        err_plot_y = new QCustomPlot(groupBox_6);
        err_plot_y->setObjectName(QString::fromUtf8("err_plot_y"));

        verticalLayout_6->addWidget(err_plot_y);


        horizontalLayout_3->addWidget(groupBox_6);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_7 = new QHBoxLayout(tab);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy5.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy5);
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_7->addWidget(pushButton_5);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);

        verticalLayout_7->addWidget(label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        horizontalLayout_7->addWidget(groupBox_4);

        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_8 = new QVBoxLayout(groupBox_9);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        plot_x = new QCustomPlot(groupBox_9);
        plot_x->setObjectName(QString::fromUtf8("plot_x"));

        verticalLayout_8->addWidget(plot_x);

        plot_y = new QCustomPlot(groupBox_9);
        plot_y->setObjectName(QString::fromUtf8("plot_y"));

        verticalLayout_8->addWidget(plot_y);


        horizontalLayout_7->addWidget(groupBox_9);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 795, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Connection:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Arduino Com port :", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Transmit ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Stand By", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Digital Correction", nullptr));
        Corr_X->setText(QApplication::translate("MainWindow", "X", nullptr));
        Corr_Y->setText(QApplication::translate("MainWindow", "Y", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Snapshot", nullptr));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Show boxes", nullptr));
        effect->setText(QApplication::translate("MainWindow", "Capture", nullptr));
        pause->setText(QApplication::translate("MainWindow", "Project", nullptr));
        B1->setText(QApplication::translate("MainWindow", "Play", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Control Panel", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Tools:", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Initialize", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Welcome", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Record", nullptr));
        Butt_X->setText(QApplication::translate("MainWindow", "X", nullptr));
        Butt_Y->setText(QApplication::translate("MainWindow", "Y", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Plots", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Error Acquisition Toolbox", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Plot", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Welcome", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Plots", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Response Acquisitio Toolbox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
