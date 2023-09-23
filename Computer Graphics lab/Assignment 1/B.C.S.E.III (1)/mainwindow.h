#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
//#include<bits/stdc++.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

//    void on_Draw_clicked();

//    void on_set_point1_clicked();

//    void on_set_point2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_textChanged(const QString &arg1);


    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

//    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void setColor(int x,int y,int c);

    void on_pushButton_7_clicked();

    void on_Bresenham_line_clicked();

//    void setPoints(vector<pair<int,int>> &points,int color);

    void on_cir_polar_clicked();

    void on_cir_midpoint_clicked();

    void on_pushButton_4_clicked();

    void on_ell_polar_clicked();

    void on_cir_cartesian_clicked();

    void on_draw_poly_clicked();

    void on_boundary_fill_clicked();

    void boundary_fill(int x,int y,QRgb fill_color,QRgb boundary_color);

    void on_flood_fill_clicked();

    void flood_fill(int x,int y,QRgb old_color);

    void on_scanline_clicked();
    void myDelay();

    void on_translation_clicked();

    void on_scaling_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int,int);
};

#endif // MAINWINDOW_H
