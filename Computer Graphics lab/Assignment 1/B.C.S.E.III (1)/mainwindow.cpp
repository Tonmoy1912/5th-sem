#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> point1,point2;
//vector<vector<int>> arr(800,vector<int>(800,0));

set<pair<pair<int,int>,int>> s;

QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y)
{
//    int val=ui->spinBox->value();
//    int xpos=ui->frame->x/val;
//    img.setPixel(x,y,qRgb(255,255,0));
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::showMousePosition(QPoint &pos)
{
    int val=ui->spinBox->value();
//    int positionX=((pos.x()-350)/val);
//    int positionY=-((pos.y()-350)/val);

//    if(pos.x()-350<0){
//        positionX=positionX-1;
//    }
//    else{
//        positionX=positionX+1;
//    }
//    if(pos.y()-350<0){
//        positionY=positionY+1;
//    }
//    else{
//        positionY=positionY-1;
//    }

    int originX=350/val;
    int originY=350/val;
    int curX=pos.x()/val;
    int curY=pos.y()/val;
    int positionX=curX-originX;
    int positionY=-(curY-originY);

    ui->mouse_movement->setText(" X : "+QString::number(positionX)+", Y : "+QString::number(positionY));
}
void MainWindow::Mouse_Pressed()
{
    int val=ui->spinBox->value();
    int xval=(ui->frame->x/val)*val;
    int yval=(ui->frame->y/val)*val;
    //maintain the seleted point to draw line
    point1=point2;
    //to rotate the axis at 90
    point2.first=(ui->frame->y/val);
    point2.second=(ui->frame->x/val);
    //to fill the pixel
    for(int i=xval;i<xval+val;i++){
        for(int j=yval;j<yval+val;j++){
            img.setPixel(i,j,qRgb(255,255,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

    //to print the pixel coordinate
//    int positionX=((ui->frame->x-350)/val);
//    int positionY=-((ui->frame->y-350)/val);

//    if(ui->frame->x-350<0){
//        positionX=positionX-1;
//    }
//    else{
//        positionX=positionX+1;
//    }
//    if(ui->frame->y-350<0){
//        positionY=positionY+1;
//    }
//    else{
//        positionY=positionY-1;
//    }

    int originX=350/val;
    int originY=350/val;
    int curX=ui->frame->x/val;
    int curY=ui->frame->y/val;
    int positionX=curX-originX;
    int positionY=-(curY-originY);

    ui->mouse_pressed->setText(" X : "+QString::number(positionX)+", Y : "+QString::number(positionY));
    point(ui->frame->x,ui->frame->y);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
}

void MainWindow::on_show_axes_clicked()
{
    int val=ui->spinBox->value();
    int low=(350/val)*val;
    int high=(350/val)*val+val;

//    if(ui->show_axes->isChecked())
//    {
//        ui->x_axis->show();
//        ui->y_axis->show();
//    }
//    else{
//        ui->x_axis->hide();
//        ui->y_axis->hide();
//    }

    if(ui->show_axes->isChecked()){
        for(int i=0;i<img.width();i++)
        {
            for(int j=low;j<=high;j++){
                img.setPixel(i,j,qRgb(0,255,0));
                img.setPixel(j,i,qRgb(0,255,0));
                //if(arr[i/val][j/val])
            }

        }
        //to recolor the colored point
//        for(int i=0;i<img.width();i+=val){
//            if(arr[i][low/val]){
//                setColor(i,low/val,arr[i][low/val]);
//            }
//            if(arr[low/val][i]){
//                setColor(low/val,i,arr[low/val][i]);
//            }
//        }
    }
    else{
        for(int i=0;i<img.width();i++)
        {
            for(int j=low;j<=high;j++){
                img.setPixel(i,j,qRgb(0,0,0));
                img.setPixel(j,i,qRgb(0,0,0));

            }

        }
        int val=ui->spinBox->value();

        //to recolor the colored point
//        for(int i=0;i<img.width();i+=val){
//            if(arr[i][low/val]){
//                setColor(i,low/val,arr[i][low/val]);
//            }
//            if(arr[low/val][i]){
//                setColor(low,i,arr[low/val][i]);
//            }
//        }

        for(int j=0;j<img.height();j+=val)
        {
            for(int i=0;i<img.width();i++)
            {
                img.setPixel(i,j,qRgb(0,0,255));
            }
        }
        for(int j=0;j<img.height();j+=val)
        {
            for(int i=0;i<img.width();i++)
            {
                img.setPixel(j,i,qRgb(0,0,255));
            }
        }

//        ui->frame->setPixmap(QPixmap::fromImage(img));
    }




    ui->frame->setPixmap(QPixmap::fromImage(img));


}
void MainWindow::on_set_point1_clicked()
{
    if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
}

void MainWindow::on_set_point2_clicked()
{
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    }
}

void MainWindow::on_Draw_clicked()
{
    int r0=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        painter.setPen(pen);
        painter.drawEllipse(p1,r0,r0);
    }
    if(ui->draw_line->isChecked()){
        painter.setPen(Qt::red);
        painter.drawLine(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }

    s.clear();

    //to clear the map
//    for(int i=0;i<arr.size();i++){
//        for(int j=0;j<arr[0].size();j++){
//            arr[i][j]=0;
//        }
//    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
//    string s=arg1;
//    int val=stoi(s);
    int val=ui->spinBox->value();

    for(int j=0;j<img.height();j+=val)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,255));
        }
    }
    for(int j=0;j<img.height();j+=val)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(j,i,qRgb(0,0,255));
        }
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
//    on_pushButton_clicked();

    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));

    on_pushButton_2_clicked();//to create the grid



    on_show_axes_clicked();//to create the axis

    //to redraw the previous lines
    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;

    for(auto it:s){
        setColor(it.first.first+originX,it.first.second+originY,it.second);
    }
}




//create axis
void MainWindow::on_pushButton_3_clicked()
{
    for(int i=0;i<img.width();i++)
    {
        img.setPixel(i,350,qRgb(0,255,0));
        img.setPixel(350,i,qRgb(0,255,0));
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::setColor(int x,int y,int c){
    int val=ui->spinBox->value();
    int xval=x*val;
    int yval=y*val;
    for(int i=xval;i<xval+val;i++){
        for(int j=yval;j<yval+val;j++){
            if(c==1){
                img.setPixel(j,i,qRgb(255,255,0));
            }
            else if(c==2){
                img.setPixel(j,i,qRgb(120,255,50));
            }
            else if(c==3){
                img.setPixel(j,i,qRgb(0,0,255));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_4_clicked()
{
    int val=ui->spinBox->value();
    if(ui->radioButton->isChecked()){
        point1.first=(ui->frame->y/val);
        point1.second=(ui->frame->x/val);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    int val=ui->spinBox->value();
    if(ui->radioButton->isChecked()){
        point2.first=(ui->frame->y/val);
        point2.second=(ui->frame->x/val);
    }
}


//void MainWindow::setPoints(vector<pair<int,int>> &points,int color){
//    for(auto it:points){
//        setColor(it.first,it.second,color);
//    }
//}


void MainWindow::on_pushButton_6_clicked()
{
    int x1=point1.first,y1=point1.second;
    int x2=point2.first,y2=point2.second;
//    float m=float(y1-y2)/float(x1-x2);
    vector<pair<int,int>> points;

    clock_t start,end;
//    time(&start);
    start=clock();
//    bool flag=true;

    if(x1==x2){
        int low=min(y1,y2);
        int high=max(y1,y2);
        for(int y=low;y<=high;y++){
//            setColor(x1,y,1);
            points.push_back({x1,y});
            //to track the set point
//            arr[x1][y]=1;
        }
    }
    else if(abs(y1-y2)<=abs(x1-x2)){
        int low=min(x1,x2);
        int high=max(x1,x2);
        float m=float(y1-y2)/float(x1-x2);
        for( int ix=low; ix<=high; ix++ )
        {

            //float fy = y0 + float(yn-y0)/float(xn-x0)*ix; 		// round to nearest whole integer
            float fy=m*(ix-x1)+y1;
            int iy = (int)(fy+0.5);
//            setColor(ix,iy,1);
            points.push_back({ix,iy});
            //to track the set point
//            arr[ix][iy]=1;
        }
    }
    else{
        int low=min(y1,y2);
        int high=max(y1,y2);
        float m=float(y1-y2)/float(x1-x2);
        for(int iy=low;iy<=high;iy++){
            float fx=(iy-y1)/m+x1;
            int ix=(int)(fx+0.5);
//            setColor(ix,iy,1);
            points.push_back({ix,iy});
            //to track the set point
//            arr[ix][iy]=1;
        }
    }

//    time(&end);
//    end=clock();
//    double time_taken=double(end-start)*1000;
//    ui->execution_time->setText(QString::number(time_taken)+" ms");

//    setPoints(points,1);
    for(auto it:points){
        setColor(it.first,it.second,1);
//        s.insert({{it.first,it.second},1});
    }

    end=clock();
    double time_taken=double(end-start);
    ui->execution_time->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
//        setColor(it.first,it.second,1);
         s.insert({{it.first-originX,it.second-originY},1});
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    int x0=point1.first,y0=point1.second;
    int xn=point2.first,yn=point2.second;

    vector<pair<int,int>> points;

    bool flag=true;

    clock_t start,end;
//    time(&start);
    start=clock();

    if(x0==xn){
        int low=min(y0,yn);
        int high=max(y0,yn);
        for(int y=low;y<=high;y++){
//            setColor(xn,y,2);
            points.push_back({xn,y});
            //to track the set point
//            arr[xn][y]=2;
        }
//        return ;
        flag=false;
    }
    else if(y0==yn){
        int low=min(x0,xn);
        int high=max(x0,xn);
        for(int x=low;x<=high;x++){
//            setColor(x,yn,2);
            points.push_back({x,yn});
            //to track the set point
//            arr[x][yn]=2;
        }
//        return ;
        flag=false;
    }




    if(flag){
        float dx = float(xn - x0); // total span in x
        float dy = float(yn - y0); // total span in y
        //    float y = float(y0);
        //    float x = float(x0);

        float Dx, Dy, x, y; // incremental steps in x & y
        // determine if slope m GT or LT 1
        if( abs(dx) >= abs(dy) )
        {
            Dx = 1;
            Dy = dy/dx;// floating division, but only done once per line
            if(x0<xn){
                x=x0;
                y=y0;
            }
            else{
                x=xn;
                y=yn;
            }
        }
        else
        {
            Dx = dx/dy;
            Dy = 1;
            if(y0<yn){
                x=x0;
                y=y0;
            }
            else{
                x=xn;
                y=yn;
            }
        }

        int ix, iy; // pixel coords
        for( int k=0; k<=abs(((abs(dx)>abs(dy))? dx:dy)); k++ )
        {
            ix = int(x + 0.5); // round to nearest pixel coordinate
            iy = int(y + 0.5);
//            setColor(ix,iy,2);
            points.push_back({ix,iy});
            //to track the set point
            //        arr[ix][iy]=2;
            x += Dx;	// floating point calculations
            y += Dy;
        }
    }

//    time(&end);
//    end=clock();

//    double time_taken=double(end-start)*1000;
//    ui->execution_time->setText(QString::number(time_taken)+" ms");

//    setPoints(points,2);
    for(auto it:points){
        setColor(it.first,it.second,2);
//        s.insert({{it.first,it.second},2});
    }

    end=clock();

    double time_taken=double(end-start);
    ui->execution_time->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},2});
    }

}


void MainWindow::on_Bresenham_line_clicked()
{
    int x0=point1.first,y0=point1.second;
    int xn=point2.first,yn=point2.second;

    vector<pair<int,int>> points;

    clock_t start,end;
    start=clock();

    if(point1.first>point2.first){
//        swap(point1.first,point2.first);
//        swap(point1.second,point2.second);
        swap(x0,xn);
        swap(y0,yn);
    }

    if(abs(xn-x0)>=abs(yn-y0)){
        int dx=xn-x0;
        int dy=yn-y0;
        int dx2=2*dx;
        int dy2=2*dy;
        int dp=dy2-dx2;
        int dn=dy2+dx2;
        int p0=dy2-dx;
        int yk=y0;
        bool isNegSlop;
        if(yn>=y0){
            isNegSlop=false;
        }
        else{
            isNegSlop=true;
        }
        for(int xk=x0;xk<=xn;xk++){
//            setColor(xk,yk,3);
            points.push_back({xk,yk});
            if(isNegSlop){
                if(p0<0){
                    yk--;
                    p0=p0+dn;
                }
                else{
                    //                yk++;
                    p0=p0+dy2;
                }
            }
            else{
                if(p0<0){
                    p0=p0+dy2;
                }
                else{
                    yk++;
                    p0=p0+dp;
                }
            }

        }
    }
    else{
        swap(x0,y0);
        swap(xn,yn);
        if(x0>xn){
            swap(x0,xn);
            swap(y0,yn);
        }
        int dx=xn-x0;
        int dy=yn-y0;
        int dx2=2*dx;
        int dy2=2*dy;
        int dp=dy2-dx2;
        int dn=dy2+dx2;
        int p0=dy2-dx;
        int yk=y0;
        bool isNegSlop;
        if(yn>=y0){
            isNegSlop=false;
        }
        else{
            isNegSlop=true;
        }
        for(int xk=x0;xk<=xn;xk++){
//            setColor(yk,xk,3);
            points.push_back({yk,xk});
            if(isNegSlop){
                if(p0<0){
                    yk--;
                    p0=p0+dn;
                }
                else{
                    //                yk++;
                    p0=p0+dy2;
                }
            }
            else{
                if(p0<0){
                    p0=p0+dy2;
                }
                else{
                    yk++;
                    p0=p0+dp;
                }
            }

        }
    }

//    end=clock();

//    double time_taken=double(end-start)*1000;
//    ui->execution_time->setText(QString::number(time_taken)+" ms");

    //    setPoints(points,2);
    for(auto it:points){
        setColor(it.first,it.second,3);
//        s.insert({{it.first,it.second},3});
    }

    end=clock();

    double time_taken=double(end-start);
    ui->execution_time->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},3});
    }
}

