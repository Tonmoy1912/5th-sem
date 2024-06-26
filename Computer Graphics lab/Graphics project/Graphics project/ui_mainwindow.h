/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *Bresenham_line;
    QLabel *label;
    QLabel *execution_time;
    QPushButton *cir_polar;
    QLabel *label_2;
    QSpinBox *Radius;
    QPushButton *cir_midpoint;
    QLabel *label_4;
    QLabel *label_6;
    QSpinBox *r1;
    QSpinBox *r2;
    QPushButton *pushButton_4;
    QPushButton *ell_polar;
    QLabel *exe_time_cir_polar;
    QLabel *exe_time_cir_midpoint;
    QLabel *exe_time_ell_polar;
    QLabel *exe_time_ell_midpoint;
    QLabel *exe_time_cir_cartesian;
    QPushButton *cir_cartesian;
    QPushButton *draw_poly;
    QPushButton *boundary_fill;
    QCheckBox *connected_8;
    QCheckBox *polygon;
    QPushButton *flood_fill;
    QPushButton *scanline;
    QPushButton *draw_background;
    QSpinBox *speed;
    QLabel *speed_label;
    QPushButton *start;
    QPushButton *stop;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *speedUp;
    QPushButton *speedDown;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1007, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new my_label(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName("mouse_movement");
        mouse_movement->setGeometry(QRect(710, 40, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(710, 20, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName("mouse_pressed");
        mouse_pressed->setGeometry(QRect(830, 40, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(850, 10, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName("x_axis");
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName("y_axis");
        y_axis->setGeometry(QRect(230, -70, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName("show_axes");
        show_axes->setGeometry(QRect(710, 0, 91, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(710, 80, 101, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(900, 100, 80, 18));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(830, 80, 42, 22));
        spinBox->setValue(10);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(900, 80, 80, 18));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(720, 130, 80, 18));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(810, 130, 80, 18));
        Bresenham_line = new QPushButton(centralWidget);
        Bresenham_line->setObjectName("Bresenham_line");
        Bresenham_line->setGeometry(QRect(900, 130, 80, 18));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(730, 150, 71, 20));
        execution_time = new QLabel(centralWidget);
        execution_time->setObjectName("execution_time");
        execution_time->setGeometry(QRect(810, 150, 111, 31));
        execution_time->setFrameShape(QFrame::Panel);
        cir_polar = new QPushButton(centralWidget);
        cir_polar->setObjectName("cir_polar");
        cir_polar->setGeometry(QRect(700, 200, 80, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(710, 170, 71, 20));
        Radius = new QSpinBox(centralWidget);
        Radius->setObjectName("Radius");
        Radius->setGeometry(QRect(750, 170, 42, 22));
        Radius->setValue(5);
        cir_midpoint = new QPushButton(centralWidget);
        cir_midpoint->setObjectName("cir_midpoint");
        cir_midpoint->setGeometry(QRect(700, 220, 80, 18));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(710, 260, 21, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(840, 200, 21, 20));
        r1 = new QSpinBox(centralWidget);
        r1->setObjectName("r1");
        r1->setGeometry(QRect(730, 260, 42, 22));
        r1->setMinimum(0);
        r1->setValue(5);
        r2 = new QSpinBox(centralWidget);
        r2->setObjectName("r2");
        r2->setGeometry(QRect(860, 200, 42, 22));
        r2->setValue(5);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(820, 260, 80, 18));
        ell_polar = new QPushButton(centralWidget);
        ell_polar->setObjectName("ell_polar");
        ell_polar->setGeometry(QRect(830, 230, 80, 18));
        exe_time_cir_polar = new QLabel(centralWidget);
        exe_time_cir_polar->setObjectName("exe_time_cir_polar");
        exe_time_cir_polar->setGeometry(QRect(790, 200, 31, 21));
        exe_time_cir_polar->setFrameShape(QFrame::Panel);
        exe_time_cir_midpoint = new QLabel(centralWidget);
        exe_time_cir_midpoint->setObjectName("exe_time_cir_midpoint");
        exe_time_cir_midpoint->setGeometry(QRect(790, 230, 21, 21));
        exe_time_cir_midpoint->setFrameShape(QFrame::Panel);
        exe_time_ell_polar = new QLabel(centralWidget);
        exe_time_ell_polar->setObjectName("exe_time_ell_polar");
        exe_time_ell_polar->setGeometry(QRect(920, 220, 61, 31));
        exe_time_ell_polar->setFrameShape(QFrame::Panel);
        exe_time_ell_midpoint = new QLabel(centralWidget);
        exe_time_ell_midpoint->setObjectName("exe_time_ell_midpoint");
        exe_time_ell_midpoint->setGeometry(QRect(920, 260, 61, 31));
        exe_time_ell_midpoint->setFrameShape(QFrame::Panel);
        exe_time_cir_cartesian = new QLabel(centralWidget);
        exe_time_cir_cartesian->setObjectName("exe_time_cir_cartesian");
        exe_time_cir_cartesian->setGeometry(QRect(780, 260, 31, 21));
        exe_time_cir_cartesian->setFrameShape(QFrame::Panel);
        cir_cartesian = new QPushButton(centralWidget);
        cir_cartesian->setObjectName("cir_cartesian");
        cir_cartesian->setGeometry(QRect(700, 240, 80, 18));
        draw_poly = new QPushButton(centralWidget);
        draw_poly->setObjectName("draw_poly");
        draw_poly->setGeometry(QRect(770, 290, 80, 18));
        boundary_fill = new QPushButton(centralWidget);
        boundary_fill->setObjectName("boundary_fill");
        boundary_fill->setGeometry(QRect(770, 310, 80, 18));
        connected_8 = new QCheckBox(centralWidget);
        connected_8->setObjectName("connected_8");
        connected_8->setGeometry(QRect(700, 310, 81, 18));
        polygon = new QCheckBox(centralWidget);
        polygon->setObjectName("polygon");
        polygon->setGeometry(QRect(710, 280, 81, 18));
        flood_fill = new QPushButton(centralWidget);
        flood_fill->setObjectName("flood_fill");
        flood_fill->setGeometry(QRect(910, 320, 80, 18));
        scanline = new QPushButton(centralWidget);
        scanline->setObjectName("scanline");
        scanline->setGeometry(QRect(860, 300, 80, 18));
        draw_background = new QPushButton(centralWidget);
        draw_background->setObjectName("draw_background");
        draw_background->setGeometry(QRect(700, 340, 281, 51));
        speed = new QSpinBox(centralWidget);
        speed->setObjectName("speed");
        speed->setGeometry(QRect(960, 160, 42, 22));
        speed->setValue(3);
        speed_label = new QLabel(centralWidget);
        speed_label->setObjectName("speed_label");
        speed_label->setGeometry(QRect(950, 180, 51, 20));
        start = new QPushButton(centralWidget);
        start->setObjectName("start");
        start->setGeometry(QRect(750, 410, 80, 18));
        stop = new QPushButton(centralWidget);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(840, 410, 80, 18));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(720, 440, 113, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(830, 440, 131, 20));
        speedUp = new QPushButton(centralWidget);
        speedUp->setObjectName("speedUp");
        speedUp->setGeometry(QRect(750, 390, 81, 21));
        speedDown = new QPushButton(centralWidget);
        speedDown->setObjectName("speedDown");
        speedDown->setGeometry(QRect(840, 390, 91, 21));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(720, 460, 113, 20));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(830, 460, 131, 20));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(720, 480, 113, 20));
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(830, 480, 131, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1007, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_axes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Create Grid", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Create Axis", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Parametric ", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "DDA", nullptr));
        Bresenham_line->setText(QCoreApplication::translate("MainWindow", "Bresenham", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Execution TIme", nullptr));
        execution_time->setText(QString());
        cir_polar->setText(QCoreApplication::translate("MainWindow", "Circle Polar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        cir_midpoint->setText(QCoreApplication::translate("MainWindow", "Circle Midpoint", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "r1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "r2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Ellipse Midpoint", nullptr));
        ell_polar->setText(QCoreApplication::translate("MainWindow", "Ellipse Polar", nullptr));
        exe_time_cir_polar->setText(QString());
        exe_time_cir_midpoint->setText(QString());
        exe_time_ell_polar->setText(QString());
        exe_time_ell_midpoint->setText(QString());
        exe_time_cir_cartesian->setText(QString());
        cir_cartesian->setText(QCoreApplication::translate("MainWindow", "Circle Cartesian", nullptr));
        draw_poly->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        boundary_fill->setText(QCoreApplication::translate("MainWindow", "Boundary fill", nullptr));
        connected_8->setText(QCoreApplication::translate("MainWindow", "Connected 8", nullptr));
        polygon->setText(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        flood_fill->setText(QCoreApplication::translate("MainWindow", "Flood fill", nullptr));
        scanline->setText(QCoreApplication::translate("MainWindow", "Scanline", nullptr));
        draw_background->setText(QCoreApplication::translate("MainWindow", "MOVING BACKGROUND WITH FIXED CAR", nullptr));
        speed_label->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "press \"S\" to start", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "press \"O\" to stop", nullptr));
        speedUp->setText(QCoreApplication::translate("MainWindow", "speed up", nullptr));
        speedDown->setText(QCoreApplication::translate("MainWindow", "speed down", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "press \"U\" to speed up", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "press \"N\" to speed down", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "press \"M\" to Music", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "press \"B\" to mute ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
