#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <bits/stdc++.h>
#include <unistd.h>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QAudioOutput>

using namespace std;

pair<int,int> point1={0,0},point2={35,35},fill_point={0,0};
vector<pair<int,int>> poly_points;
int s_time=0.5;
//vector<vector<int>> arr(800,vector<int>(800,0));

set<pair<pair<int,int>,int>> s;
//vector<vector<int>> trans;


vector<vector<int>> background(70,vector<int>(70));
//background[i][j]=2;

//wheel
vector<pair<int,int>> first_wheel={{28,34},{29,34},{30,34},{30,35},{30,36},{29,36},{28,36},{28,35}};
vector<pair<int,int>> second_wheel={{39,34},{40,34},{41,34},{41,35},{41,36},{40,36},{39,36},{39,35}};
vector<int> wheel_color={70,70,70,4,4,4,20,20};



void MainWindow::myDelay(){
    QCoreApplication::processEvents();
    QThread::msleep(1);//in milisecond
}

QImage img=QImage(700,700,QImage::Format_RGB888);

void MainWindow::setColor(int x,int y,int c){
    //    int val=ui->spinBox->value();
    int val=10;
    int xval=y*val;
    int yval=x*val;
    for(int i=xval;i<xval+val;i++){
        for(int j=yval;j<yval+val;j++){
            if(c==0){
                img.setPixel(j,i,qRgb(0,0,0));
            }
            else if(c==1){
                img.setPixel(j,i,qRgb(0,255,0));
            }
            else if(c==2){
                img.setPixel(j,i,qRgb(204,0,0));
            }
            else if(c==3){
                img.setPixel(j,i,qRgb(0,102,0));
            }
            else if(c==4){
                img.setPixel(j,i,qRgb(153,153,0));
            }
            else if(c==5){
                img.setPixel(j,i,qRgb(51,102,0));
            }
            else if(c==6){
                img.setPixel(j,i,qRgb(76,255,100));
            }
            else if(c==7){
                img.setPixel(j,i,qRgb(100,100,10));
            }
            else if(c==8){
                img.setPixel(j,i,qRgb(200,55,10));
            }
            else if(c==9){
                img.setPixel(j,i,qRgb(100,150,100));
            }
            else if(c==10){
                img.setPixel(j,i,qRgb(143,95,61));
            }
            else if(c==11){
                img.setPixel(j,i,qRgb(128,128,128));
            }
            else if(c==12){
                img.setPixel(j,i,qRgb(255,255,0));
            }
            else if(c==13){
                img.setPixel(j,i,qRgb(255,255,255));
            }else if(c==14){
                img.setPixel(j,i,qRgb(0,0,0));
            }else if(c==15){
                img.setPixel(j,i,qRgb(72,62,73));
            }else if(c==16){
                img.setPixel(j,i,qRgb(135, 206, 235));
            }else if(c==17){
                img.setPixel(j,i,qRgb(149, 53, 83));
            }else if(c==18){
                img.setPixel(j,i,qRgb(225, 102, 102));
            }else if(c==19){
                img.setPixel(j,i,qRgb(255, 153, 51));
            }else if(c==20){
                img.setPixel(j,i,qRgb(153, 0, 76));
            }
            else if(c==21){
                img.setPixel(j,i,qRgb(243,43,7));
            }
            else if(c==22){
                img.setPixel(j,i,qRgb(0,0,140));
            }else if(c==31){
                img.setPixel(j,i,qRgb(255,255,0));
            }
            else if(c==32){
                img.setPixel(j,i,qRgb(0,0,0));
            }else if(c==69){
                img.setPixel(j,i,qRgb(135,206,235));
            }
            else if(c==70){
                img.setPixel(j,i,qRgb(0,0,255));
            }
            else if(c==71){
                img.setPixel(j,i,qRgb(92, 64, 51));
            }
            else if(c==101){
                img.setPixel(j,i,qRgb(68, 66, 64));
            }
        }
    }
//    ui->frame->setPixmap(QPixmap::fromImage(img));

}

//QImage img=QImage(700,700,QImage::Format_RGB888);
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
    if(ui->polygon->isChecked()){
        poly_points.push_back(point2);
    }
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
//void MainWindow::on_set_point1_clicked()
//{
//    if(ui->draw_line->isChecked()){
//        p1.setX(ui->frame->x);
//        p1.setY(ui->frame->y);
//    }
//}

//void MainWindow::on_set_point2_clicked()
//{
//    if(ui->draw_line->isChecked()){
//        p2.setX(ui->frame->x);
//        p2.setY(ui->frame->y);
//    }
//}

//void MainWindow::on_Draw_clicked()
//{
//    int r0=ui->circle_radius->value();
//    QPainter painter(&img);
//    QPen pen;
//    pen.setWidth(1);
//    pen.setColor(Qt::red);
//    if(ui->draw_circle->isChecked()){
//        p1.setX(ui->frame->x);
//        p1.setY(ui->frame->y);
//        painter.setPen(pen);
//        painter.drawEllipse(p1,r0,r0);
//    }
//    if(ui->draw_line->isChecked()){
//        painter.setPen(Qt::red);
//        painter.drawLine(p1,p2);
//    }
//    ui->frame->setPixmap(QPixmap::fromImage(img));
//}

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
    poly_points.clear();
//    trans.clear();

    //to clear the map
//    for(int i=0;i<arr.size();i++){
//        for(int j=0;j<arr[0].size();j++){
//            arr[i][j]=0;
//        }
//    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

//to create the grid
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


void MainWindow::on_spinBox_textChanged()
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



//void MainWindow::on_pushButton_4_clicked()
//{
//    int val=ui->spinBox->value();
//    if(ui->radioButton->isChecked()){
//        point1.first=(ui->frame->y/val);
//        point1.second=(ui->frame->x/val);
//    }
//}


//void MainWindow::on_pushButton_5_clicked()
//{
//    int val=ui->spinBox->value();
//    if(ui->radioButton->isChecked()){
//        point2.first=(ui->frame->y/val);
//        point2.second=(ui->frame->x/val);
//    }
//}


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


//DDA Algorithm
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
//        myDelay();
        setColor(it.first,it.second,2);
//        s.insert({{it.first,it.second},2});
    }

    end=clock();

    double time_taken=double(end-start);
    ui->execution_time->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;

    //for transformation operation
//    if(ui->transformation->isChecked()){
//        for(auto it:points){
//            //        setColor(it.first,it.second,1);
//            trans.push_back({it.first-originX,it.second-originY,2});
//        }
//    }


//    for(auto it:points){
//        //        setColor(it.first,it.second,1);
//        s.insert({{it.first-originX,it.second-originY},2});
//    }

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
        sleep(s_time);
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


void MainWindow::on_cir_polar_clicked()
{
    int centerX=point2.first;
    int centerY=point2.second;
    int r=ui->Radius->value();

    double inc=((double)1/(r));
    double low=3.14/4;
    double high=3.14/2;


    clock_t start,end;
    start=clock();

    int r2=r*r;

    vector<pair<int,int>> points;
    points.push_back({centerX+0,centerY+r});
    points.push_back({centerX+0,centerY-r});
    points.push_back({centerX+r,centerY+0});
    points.push_back({centerX-r,centerY+0});


    for(double it=low;it<=high;it+=inc){
//        int y=sqrt(r2-i*i)+0.5;

        int x=r*cos(it)+0.5;
        int y=r*sin(it)+0.5;
        int i=x;

        if(i>y){
            break;
        }
        points.push_back({centerX+i,centerY+y});
        points.push_back({centerX+i,centerY-y});
        points.push_back({centerX-i,centerY+y});
        points.push_back({centerX-i,centerY-y});
        points.push_back({centerX+y,centerY+i});
        points.push_back({centerX+y,centerY-i});
        points.push_back({centerX-y,centerY+i});
        points.push_back({centerX-y,centerY-i});
    }

    //color the pixels
    for(auto it:points){
        setColor(it.first,it.second,4);
        sleep(s_time);
    }

    end=clock();

    double time_taken=double(end-start);
    ui->exe_time_cir_polar->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},4});
    }
}


void MainWindow::on_cir_midpoint_clicked()
{
    int centerX=point2.first;
    int centerY=point2.second;
    int r=ui->Radius->value();
    int r2=r*r;
    vector<pair<int,int>> points;

    clock_t start,end;
    start=clock();

    int p=1-r;
    int x=0,y=r;

    points.push_back({centerX+0,centerY+r});
    points.push_back({centerX+0,centerY-r});
    points.push_back({centerX+r,centerY+0});
    points.push_back({centerX-r,centerY+0});

    while(x<=y){
        if(p<0){
            p=p+2*(x+1)+1;
            x=x+1;
            y=y;
        }
        else{
            p=p+2*(x+1)+1-2*(y-1);
            x=x+1;
            y=y-1;
        }
        int i=x;
        if(x>y){
            break;
        }
        points.push_back({centerX+i,centerY+y});
        points.push_back({centerX+i,centerY-y});
        points.push_back({centerX-i,centerY+y});
        points.push_back({centerX-i,centerY-y});
        points.push_back({centerX+y,centerY+i});
        points.push_back({centerX+y,centerY-i});
        points.push_back({centerX-y,centerY+i});
        points.push_back({centerX-y,centerY-i});
    }

    //color the pixels
    for(auto it:points){
        setColor(it.first,it.second,5);
        sleep(s_time);
    }

    end=clock();

    double time_taken=double(end-start);
    ui->exe_time_cir_midpoint->setText(QString::number(time_taken)+" ms");


    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},5});
    }
}


//ellipse drawing using Bresenham Midpoint algo
void MainWindow::on_pushButton_4_clicked()
{
    int centerX=point2.first;
    int centerY=point2.second;
    int b=ui->r1->value();
    int a=ui->r2->value();
    vector<pair<int,int>> points;

    clock_t start,end;
    start=clock();

    points.push_back({centerX+0,centerY+b});
    points.push_back({centerX+0,centerY-b});
    points.push_back({centerX+a,centerY+0});
    points.push_back({centerX-a,centerY+0});

    int x=0,y=b;
    int b2=b*b;
    int a2=a*a;
    double d1=b2-a2*b+0.25*a2;

    while(a2*(y-0.5)>b2*(x+1)){
        if(d1<0){
            x++;
            d1+=2*b2*x+b2;
        }
        else{
            x++;
            y--;
            d1+=2*b2*x+b2-2*a2*y;
        }
        points.push_back({centerX+x,centerY+y});
        points.push_back({centerX+x,centerY-y});
        points.push_back({centerX-x,centerY+y});
        points.push_back({centerX-x,centerY-y});
    }

    double d2=b2*pow(x+0.5,2)+a2*pow(y-1,2)-a2*b2;

    while(y>0){
        if(d2<0){
            y--;
            x++;
            d2+=a2*(1-2*y)+2*x*b2;
        }
        else{
            y--;
            d2+=a2*(1-2*y);
        }
        points.push_back({centerX+x,centerY+y});
        points.push_back({centerX+x,centerY-y});
        points.push_back({centerX-x,centerY+y});
        points.push_back({centerX-x,centerY-y});
    }

    //color the pixels
    for(auto it:points){
        setColor(it.first,it.second,6);
        sleep(s_time);
    }

    end=clock();

    double time_taken=double(end-start);
    ui->exe_time_ell_midpoint->setText(QString::number(time_taken)+" ms");


    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},6});
    }
}


void MainWindow::on_ell_polar_clicked()
{
    int centerX=point2.first;
    int centerY=point2.second;
    int b=ui->r1->value();
    int a=ui->r2->value();
    vector<pair<int,int>> points;

    clock_t start,end;
    start=clock();

    points.push_back({centerX+0,centerY+b});
    points.push_back({centerX+0,centerY-b});
    points.push_back({centerX+a,centerY+0});
    points.push_back({centerX-a,centerY+0});

//    int x=0,y=b;
//    int b2=b*b;
//    int a2=a*a;


    double inc=((double)1)/max(a,b);
    double low=0;
    double high=3.14/2;
    for(double it=low;it<=high;it+=inc){
        int x=a*cos(it)+0.5;
        int y=b*sin(it)+0.5;
        points.push_back({centerX+x,centerY+y});
        points.push_back({centerX+x,centerY-y});
        points.push_back({centerX-x,centerY+y});
        points.push_back({centerX-x,centerY-y});
    }



    //color the pixels
    for(auto it:points){
        setColor(it.first,it.second,7);
        sleep(s_time);
    }

    end=clock();

    double time_taken=double(end-start);
    ui->exe_time_ell_polar->setText(QString::number(time_taken)+" ms");


    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},7});
    }
}


void MainWindow::on_cir_cartesian_clicked()
{
    int centerX=point2.first;
    int centerY=point2.second;
    int r=ui->Radius->value();

//    double inc=((double)1/(r));
    double low=0;
    double high=r;


    clock_t start,end;
    start=clock();

    int r2=r*r;

    vector<pair<int,int>> points;
    points.push_back({centerX+0,centerY+r});
    points.push_back({centerX+0,centerY-r});
    points.push_back({centerX+r,centerY+0});
    points.push_back({centerX-r,centerY+0});


    for(int it=low;it<=high;it++){
                int y=sqrt(r2-it*it)+0.5;

//        int x=r*cos(it)+0.5;
//        int y=r*sin(it)+0.5;
        int i=it;

        if(i>y){
            break;
        }
        points.push_back({centerX+i,centerY+y});
        points.push_back({centerX+i,centerY-y});
        points.push_back({centerX-i,centerY+y});
        points.push_back({centerX-i,centerY-y});
        points.push_back({centerX+y,centerY+i});
        points.push_back({centerX+y,centerY-i});
        points.push_back({centerX-y,centerY+i});
        points.push_back({centerX-y,centerY-i});
    }

    //color the pixels
    for(auto it:points){
        setColor(it.first,it.second,8);
        sleep(s_time);
    }

    end=clock();

    double time_taken=double(end-start);
    ui->exe_time_cir_cartesian->setText(QString::number(time_taken)+" ms");

    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;


    for(auto it:points){
        //        setColor(it.first,it.second,1);
        s.insert({{it.first-originX,it.second-originY},8});
    }
}


void MainWindow::on_draw_poly_clicked()
{
    int n=poly_points.size();
    for(int i=0;i<n;i++){
        point1=poly_points[i];
        point2=poly_points[(i+1)%n];
        //call a line drawing algo
        on_pushButton_7_clicked();
    }
    point1=poly_points[n-2];
    point2=poly_points[n-1];
//    poly_points.clear();
}




//check connected 8
void MainWindow::on_boundary_fill_clicked()
{
//    if(img.pixelIndex()!=qRgb(120,255,50)&&img.pixelIndex()!=qRgb(205,220,57)){

//    }

    fill_point=point2;
    boundary_fill(point2.first,point2.second,qRgb(205,220,57),qRgb(120,255,50));
}


void MainWindow::boundary_fill(int x,int y,QRgb fill_color,QRgb boundary_color){
    int val=ui->spinBox->value();
    int originX=350/val;
    int originY=350/val;
    int mid_point_x=x*val+(val)/2;
    int mid_point_y=y*val+(val)/2;
    if((mid_point_x<0) || (mid_point_x>700) || (mid_point_y<0) || (mid_point_y>700)){
        return ;
    }
    if(img.pixel(mid_point_y,mid_point_x)!=boundary_color&&img.pixel(mid_point_y,mid_point_x)!=fill_color){
        int x_low=x*val;
        int y_low=y*val;
        int x_high=x_low+val;
        int y_high=y_low+val;
//        myDelay();
        for(int i=x_low;i<x_high;i++){
            for(int j=y_low;j<y_high;j++){
                img.setPixel(j,i,fill_color);
            }
        }
        //for translation operation
//        if(ui->transformation->isChecked()){
//            trans.push_back({x-originX,y-originY,9});//9 for boundary fill
//        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
        boundary_fill(x,y+1,fill_color,boundary_color);
        boundary_fill(x,y-1,fill_color,boundary_color);
        boundary_fill(x-1,y,fill_color,boundary_color);
        boundary_fill(x+1,y,fill_color,boundary_color);
        if(ui->connected_8->isChecked()){
            boundary_fill(x+1,y+1,fill_color,boundary_color);
            boundary_fill(x+1,y-1,fill_color,boundary_color);
            boundary_fill(x-1,y+1,fill_color,boundary_color);
            boundary_fill(x-1,y-1,fill_color,boundary_color);
        }
    }

}


void MainWindow::on_flood_fill_clicked()
{
    int val=ui->spinBox->value();
    int x=point2.first;
    int y=point2.second;
    int x_low=x*val;
    int y_low=y*val;
    int x_high=x_low+val;
    int y_high=y_low+val;
    for(int i=x_low;i<x_high;i++){
        for(int j=y_low;j<y_high;j++){
            img.setPixel(j,i,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
    flood_fill(point2.first,point2.second,qRgb(0,0,0));
}


void MainWindow::flood_fill(int x,int y,QRgb old_color){
    int val=ui->spinBox->value();
    int mid_point_x=x*val+(val)/2;
    int mid_point_y=y*val+(val)/2;
    if((mid_point_x<0) || (mid_point_x>700) || (mid_point_y<0) || (mid_point_y>700)){
        return ;
    }
    QRgb fill_color=qRgb(121,85,72);
    if(img.pixel(mid_point_y,mid_point_x)==old_color/*||img.pixel(mid_point_y,mid_point_x)==qRgb(255,255,0)*/){
        int x_low=x*val;
        int y_low=y*val;
        int x_high=x_low+val;
        int y_high=y_low+val;
        for(int i=x_low;i<x_high;i++){
            for(int j=y_low;j<y_high;j++){
                img.setPixel(j,i,fill_color);
            }
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
        flood_fill(x,y+1,old_color);
        flood_fill(x,y-1,old_color);
        flood_fill(x-1,y,old_color);
        flood_fill(x+1,y,old_color);
        if(ui->connected_8->isChecked()){
            flood_fill(x+1,y+1,old_color);
            flood_fill(x+1,y-1,old_color);
            flood_fill(x-1,y+1,old_color);
            flood_fill(x-1,y-1,old_color);
        }
    }

}

void MainWindow::on_scanline_clicked()
{
    QRgb boundary_color=qRgb(120,255,50);
    int val=ui->spinBox->value();
    int high=700/val;
    vector<int> arr;
    vector<pair<int,int>> temp=poly_points;
//    sort(temp.begin(),temp.end());
//    int y_high=700/val;
    for(int i=0;i<high;i++){
        int j=0;
        while(j<high){
            int mid_point_x=i*val+(val)/2;
            int mid_point_y=j*val+(val)/2;
            //either on the edge or vertex
            if(img.pixel(mid_point_y,mid_point_x)==boundary_color){
//                arr.push_back(j);
//                int t=j;
//                while(img.pixel((t+1)*val+val,mid_point_x)==boundary_color){
//                    t++;
//                }
//                if(t!=j){//horizontal line break
//                    j=t;
//                    continue;
//                }
                int k=0;
                int n=temp.size();
                while(k<n){
                    if(temp[k].first==i&&temp[k].second==j){
                        break;
                    }
                    k++;
                }
                if(k>=n){//not a vertex
                    arr.push_back(j);
//                    int t=j;
//                    while(img.pixel((t)*val+val/2,mid_point_x)==boundary_color){
//                        t++;
//                    }
//                    if(t!=j){//horizontal line break
//                        j=t;
//                        continue;
//                    }
                }
                else{//is a vertex
                    arr.push_back(j);

                    pair<int,int> left,right;
                    if(k==0){
                        left=temp.back();
                    }
                    else{
                        left=temp[k-1];
                    }
                    if(k==n-1){
                        right=temp[0];
                    }
                    else{
                        right=temp[k+1];
                    }
                    if(right.second<left.second){
                        swap(right.first,left.first);
                        swap(right.second,left.second);
                    }
                    int decision_val=(right.first-i)*(left.first-i);
                    if(decision_val>0){//two edges are on same side
                        arr.push_back(j);
//                        int t=j;
//                        while(img.pixel((t)*val+val/2,mid_point_x)==boundary_color){
//                            t++;
//                        }
//                        if(t!=j){//horizontal line break
//                            j=t;
//                            continue;
//                        }
                    }
//                    else if(decision_val==0){//horizontal line(require odd number of horizontal node)
//                        if(i==right.first&&right.second>j){
//                            j=right.second;
//                            continue;//skip to the right end of the horizontal line
//                        }
//                    }
//                    else{
//                        int t=j;
//                        while(img.pixel((t)*val+val/2,mid_point_x)==boundary_color){
//                            t++;
//                        }
//                        if(t!=j){//horizontal line break
//                            j=t;
//                            continue;
//                        }
//                    }
                }
            }

            j++;
        }
        j=0;
        int n=arr.size();
        n=n-n%2;
        while(j<n){//n is always even
            int left=arr[j++];
            int right=arr[j++];
            for(int k=left+1;k<right;k++){
                int mid_point_x=i*val+(val)/2;
                int mid_point_y=k*val+(val)/2;
                if(img.pixel(mid_point_y,mid_point_x)!=boundary_color){
                    myDelay();
                    setColor(i,k,5);
                }
            }
        }
        arr.clear();
    }
}


//void MainWindow::on_translation_clicked()
//{
//    int val=ui->spinBox->value();
//    int X=-ui->transY->value();
//    int Y=ui->transX->value();
//    pair<int,int> boundary_fill_origin=point2;

//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation

//    vector<pair<int,int>> arr;
//    int originX=350/val;
//    int originY=350/val;
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    //to get the translated value
//    for(int i=0;i<arr.size();i++){
//        int x=arr[i].first;
//        int y=arr[i].second;
//        int translatedX=x+X;
//        int translatedY=y+Y;
//        arr[i]={translatedX,translatedY};
//    }
//    //to get the actual pixel position
//    for(int i=0;i<arr.size();i++){
//        poly_points[i]={arr[i].first+originX,arr[i].second+originY};
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    //to transformed the boundary fill origin
//    int x=boundary_fill_origin.first-originX;
//    int y=boundary_fill_origin.second-originY;
//    int translatedX=x+X;
//    int translatedY=y+Y;
//    pair<int,int> translated_boundary_fill_origin={translatedX+originX,translatedY+originY};

//    point1=point2;
//    point2=translated_boundary_fill_origin;
//    on_boundary_fill_clicked();
//}


//void MainWindow::on_scaling_clicked()
//{
//    int val=ui->spinBox->value();
//    int X=ui->transY->value();
//    int Y=ui->transX->value();
//    pair<int,int> boundary_fill_origin=point2;

//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation

//    vector<pair<int,int>> arr;
//    int originX=350/val;
//    int originY=350/val;
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    //to get the translated value
//    for(int i=0;i<arr.size();i++){
//        int x=arr[i].first;
//        int y=arr[i].second;
//        int translatedX=x*X;
//        int translatedY=y*Y;
//        arr[i]={translatedX,translatedY};
//    }
//    //to get the actual pixel position
//    for(int i=0;i<arr.size();i++){
//        poly_points[i]={arr[i].first+originX,arr[i].second+originY};
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    //to transformed the boundary fill origin
//    int x=boundary_fill_origin.first-originX;
//    int y=boundary_fill_origin.second-originY;
//    int translatedX=x*X;
//    int translatedY=y*Y;
//    pair<int,int> translated_boundary_fill_origin={translatedX+originX,translatedY+originY};

//    point1=point2;
//    point2=translated_boundary_fill_origin;
//    on_boundary_fill_clicked();
//}


//void MainWindow::on_shear_clicked()
//{
//    int val=ui->spinBox->value();
//    int X=-ui->transY->value();
//    int Y=-ui->transX->value();
//    pair<int,int> boundary_fill_origin=point2;

//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation

//    vector<pair<int,int>> arr;
//    int originX=350/val;
//    int originY=350/val;
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    //to get the translated value
//    for(int i=0;i<arr.size();i++){
//        int x=arr[i].first;
//        int y=arr[i].second;
//        int translatedX=x+X*y;
//        int translatedY=y+Y*x;
//        arr[i]={translatedX,translatedY};
//    }
//    //to get the actual pixel position
//    for(int i=0;i<arr.size();i++){
//        poly_points[i]={arr[i].first+originX,arr[i].second+originY};
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    //to transformed the boundary fill origin
//    int x=boundary_fill_origin.first-originX;
//    int y=boundary_fill_origin.second-originY;
//    int translatedX=x+X*y;
//    int translatedY=y+Y*x;
//    pair<int,int> translated_boundary_fill_origin={translatedX+originX,translatedY+originY};

//    point1=point2;
//    point2=translated_boundary_fill_origin;
//    on_boundary_fill_clicked();
//}


//void MainWindow::on_rotation_clicked()
//{
//    int val=ui->spinBox->value();
////    int X=-ui->transY->value();
////    int Y=-ui->transX->value();
//    pair<int,int> boundary_fill_origin=point1;
//    double angle=ui->angle->value();
//    //converting into radian
//    angle=(22*angle)/(7*180);
//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation

//    vector<pair<int,int>> arr;
////    int originX=350/val;
////    int originY=350/val;
//    int originX=point2.first;
//    int originY=point2.second;
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    //to get the translated value
//    for(int i=0;i<arr.size();i++){
//        int x=arr[i].first;
//        int y=arr[i].second;
//        int translatedX=x*cos(angle)-y*sin(angle)+0.5;
//        int translatedY=y*cos(angle)+x*sin(angle)+0.5;
//        arr[i]={translatedX,translatedY};
//    }
//    //to get the actual pixel position
//    for(int i=0;i<arr.size();i++){
//        poly_points[i]={arr[i].first+originX,arr[i].second+originY};
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    //to transformed the boundary fill origin
//    int x=boundary_fill_origin.first-originX;
//    int y=boundary_fill_origin.second-originY;
//    int translatedX=x*cos(angle)-y*sin(angle)+0.5;
//    int translatedY=y*cos(angle)+x*sin(angle+0.5);
//    pair<int,int> translated_boundary_fill_origin={translatedX+originX,translatedY+originY};

//    point1=point2;
//    point2=translated_boundary_fill_origin;
//    on_boundary_fill_clicked();
//    point1=translated_boundary_fill_origin;
//    point2={originX,originY};
//}


//void MainWindow::on_reflect_clicked()
//{
//    int val=ui->spinBox->value();
////    int X=-ui->transY->value();
////    int Y=-ui->transX->value();
//    pair<int,int> boundary_fill_origin=point2;

//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation

//    vector<pair<int,int>> arr;
//    int originX=350/val;
//    int originY=350/val;
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    //to get the translated value
//    for(int i=0;i<arr.size();i++){
//        int x=arr[i].first;
//        int y=arr[i].second;
//        int translatedX;
//        int translatedY;
//        if(ui->radioX->isChecked()){
//            translatedX=-x;
//            translatedY=y;
//        }
//        else{
//            translatedX=x;
//            translatedY=-y;
//        }
//        arr[i]={translatedX,translatedY};
//    }
//    //to get the actual pixel position
//    for(int i=0;i<arr.size();i++){
//        poly_points[i]={arr[i].first+originX,arr[i].second+originY};
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    //to transformed the boundary fill origin
//    int x=boundary_fill_origin.first-originX;
//    int y=boundary_fill_origin.second-originY;
//    int translatedX;
//    int translatedY;
//    if(ui->radioX->isChecked()){
//        translatedX=-x;
//        translatedY=y;
//    }
//    else{
//        translatedX=x;
//        translatedY=-y;
//    }
//    pair<int,int> translated_boundary_fill_origin={translatedX+originX,translatedY+originY};

//    point1=point2;
//    point2=translated_boundary_fill_origin;
//    on_boundary_fill_clicked();
//}




//void MainWindow::on_composite_a_clicked()
//{
//    pair<int,int> boundary_fill_origin=point1;
//    int originX=point2.first;
//    int originY=point2.second;
//    int X=ui->transY->value();
//    int Y=ui->transX->value();
//    double angle=ui->angle->value();
//    //converting into radian
//    angle=(22*angle)/(7*180);
//    //to clear the screen
//    on_spinBox_textChanged();
//    //new implementation
//    vector<pair<int,int>> arr;
//    vector<vector<double>> rot={{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
//    vector<vector<int>> trans={{X,0,0},{0,Y,0},{0,0,1}};
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    int n=arr.size();
//    for(int t=0;t<n;t++){
//        vector<int> point={arr[t].first,arr[t].second,1};
//        vector<int> transformedPoint(3);
//        //for rotation
//        for(int i=0;i<3;i++){
//            double ans=0;
//            for(int j=0;j<3;j++){
//                ans+=rot[i][j]*point[j];
//            }
//            transformedPoint[i]=ans+0.5;
//        }
//        point=transformedPoint;
//        for(int i=0;i<3;i++){
//            int ans=0;
//            for(int j=0;j<3;j++){
//                ans+=trans[i][j]*point[j];
//            }
//            transformedPoint[i]=ans;
//        }
//        point=transformedPoint;
//        arr[t].first=point[0];
//        arr[t].second=point[1];
//    }
//    //to get the actual pixel position
//    for(int i=0;i<n;i++){
//        poly_points[i].first=arr[i].first+originX;
//        poly_points[i].second=arr[i].second+originY;
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//    vector<int> point={boundary_fill_origin.first-originX,boundary_fill_origin.second-originY,1};
//    vector<int> transformedPoint(3);
//    //for rotation
//    for(int i=0;i<3;i++){
//        double ans=0;
//        for(int j=0;j<3;j++){
//            ans+=rot[i][j]*point[j];
//        }
//        transformedPoint[i]=ans;
//    }
//    point=transformedPoint;
//    for(int i=0;i<3;i++){
//        int ans=0;
//        for(int j=0;j<3;j++){
//            ans+=trans[i][j]*point[j];
//        }
//        transformedPoint[i]=ans;
//    }
//    point=transformedPoint;
//    point2.first=point[0]+originX;
//    point2.second=point[1]+originY;
//    on_boundary_fill_clicked();
//    point1=point2;//set the boundary fill origin
//    point2={originX,originY};
//}


//void MainWindow::on_composite_b_clicked()
//{
//    int val=ui->spinBox->value();
//    int originX=350/val;
//    int originY=350/val;
//    pair<int,int> pointA={point1.first-originX,point1.second-originY},pointB={point2.first-originX,point2.second-originY};
//    pair<int,int> boundary_fill_origin=fill_point;
//    int dx=(pointA.first-pointB.first);
//    int dy=(pointA.second-pointB.second);
//    vector<vector<int>> trans_back={{1,0,pointA.first},{0,1,pointA.second},{0,0,1}};
//    vector<vector<int>> trans={{1,0,-pointA.first},{0,1,-pointA.second},{0,0,1}};
//    vector<vector<int>> reflect={{1,0,0},{0,-1,0},{0,0,1}};
//    double angle;
//    if(dx==0){
//        angle=11/((double)7);
//    }
//    else{
//        angle=atan(((double)dy)/dx);
//    }
//    vector<vector<double>> rot_back={{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
//    angle=-angle;
//    vector<vector<double>> rot={{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
//    vector<pair<int,int>> arr;
//    //to clear the screen
////    on_spinBox_textChanged();
//    //to get the points in cartesian coordinate system
//    for(auto it:poly_points){
//        arr.push_back({it.first-originX,it.second-originY});
//    }
//    if(abs(dx)==abs(dy)){
//        int n=arr.size();
//        int X=pointA.first;
//        int Y=pointA.second;
//        for(int i=0;i<n;i++){
//            arr[i].first=arr[i].first-X;
//            arr[i].second=arr[i].second-Y;
//            swap(arr[i].first,arr[i].second);
//            arr[i].first=-arr[i].first;
//            arr[i].second=-arr[i].second;
//            arr[i].first=arr[i].first+X;
//            arr[i].second=arr[i].second+Y;
//        }
//        for(int i=0;i<n;i++){
//            poly_points[i].first=arr[i].first+originX;
//            poly_points[i].second=arr[i].second+originY;
//        }
//        //to draw the transformed polygon
//        on_draw_poly_clicked();
//        return ;
//    }
//    int n=arr.size();
//    for(int t=0;t<n;t++){
//        vector<int> point={arr[t].first,arr[t].second,1};
//        vector<int> transformedPoint(3);
//        //translation
//        for(int i=0;i<3;i++){
//            int ans=0;
//            for(int j=0;j<3;j++){
//                ans+=trans[i][j]*point[j];
//            }
//            transformedPoint[i]=ans;
//        }
//        point=transformedPoint;
//        //rotation
//        for(int i=0;i<3;i++){
//            double ans=0;
//            for(int j=0;j<3;j++){
//                ans+=rot[i][j]*point[j];
//            }
//            transformedPoint[i]=ans+0.5;
//        }
//        point=transformedPoint;
//        //reflection
//        for(int i=0;i<3;i++){
//            int ans=0;
//            for(int j=0;j<3;j++){
//                ans+=reflect[i][j]*point[j];
//            }
//            transformedPoint[i]=ans;
//        }
//        point=transformedPoint;
//        //rotate_back
//        for(int i=0;i<3;i++){
//            double ans=0;
//            for(int j=0;j<3;j++){
//                ans+=rot_back[i][j]*point[j];
//            }
//            transformedPoint[i]=ans+0.5;
//        }
//        point=transformedPoint;
//        //translate back
//        for(int i=0;i<3;i++){
//            int ans=0;
//            for(int j=0;j<3;j++){
//                ans+=trans_back[i][j]*point[j];
//            }
//            transformedPoint[i]=ans;
//        }
//        point=transformedPoint;
//        arr[t].first=point[0];
//        arr[t].second=point[1];
//    }
//    //to get the actual pixel position
//    for(int i=0;i<n;i++){
//        poly_points[i].first=arr[i].first+originX;
//        poly_points[i].second=arr[i].second+originY;
//    }
//    //to draw the transformed polygon
//    on_draw_poly_clicked();
//}



//.................Graphics Project..................................

void MainWindow::grass(){
    for(int i=0;i<70;i++){
        for(int j=20;j<50;j++){
            background[i][j]=1;//green
        }
    }
}


void MainWindow::road(){
    for(int i=0;i<70;i++){
        for(int j=29;j<42;j++){
            background[i][j]=11;//gray
        }
    }
}

void MainWindow::center_line(){
    int flag=0;
    for(int i=0;i<70;i+=12){

        if(flag==0){
            for(int x=i;x<=i+5;x++){
                background[x][35]=13;//white
            }
            flag=1;
        }
        else{
            for(int x=i;x<=i+5;x++){
                background[x][35]=12;//yellow
            }
            flag=0;
        }
    }
}

void MainWindow::car(){
    for(int i=30;i<=39;i++){
        for(int j=25;j<=28;j++){
            //background[i][j]=21;
            setColor(i,j,21);
        }
    }
    for(int i=31;i<=33;i++){
        for(int j=26;j<=28;j++){
            //background[i][j]=22;
            setColor(i,j,22);
        }
    }
    for(int i=36;i<=38;i++){
        for(int j=26;j<=28;j++){
            //background[i][j]=22;
            setColor(i,j,22);
        }
    }
    for(int i=26;i<=43;i++){
        for(int j=29;j<=34;j++){
            //background[i][j]=21;
            setColor(i,j,21);
        }
    }

    //For wheels........................
//    for(int i=28;i<=30;i++){
//        for(int j=34;j<=36;j++){
//            //background[i][j]=14;
//            setColor(i,j,14); // black
//        }
//    }

//    for(int i=39;i<=41;i++){
//        for(int j=34;j<=36;j++){
//            //background[i][j]=14;
//            setColor(i,j,14);//black
//        }
//    }
    for(int i=0;i<8;i++){
        setColor(first_wheel[i].first,first_wheel[i].second,wheel_color[i]);
        setColor(second_wheel[i].first,second_wheel[i].second,wheel_color[i]);
    }
    setColor(29,35,0);
    setColor(40,35,0);
}

void MainWindow::building(int val1,int val2,int val3){
    int s=5;

    for(int i=s;i<s+10;i++){
        for(int j=15;j<=28;j++){
            if((i>=s+1&&i<=s+2&&j>=21&&j<=22)||(i>=s+7&&i<=s+8&&j>=21&&j<=22)||(i>=s+1&&i<=s+2&&j>=16&&j<=18)||(i>=s+7&&i<=s+8&&j>=16&&j<=18))
                background[i][j]=32;//black
            else
//                background[i][j]=31;//yellow
                  background[i][j]=val1;
        }
    }
    s+=20;
    for(int i=s;i<s+10;i++){
        for(int j=19;j<=28;j++){
            if((i>=s+1&&i<=s+2&&j>=21&&j<=23)||(i>=s+7&&i<=s+8&&j>=21&&j<=23))
                background[i][j]=32;//black
            else
//                background[i][j]=31;//yellow
                  background[i][j]=val2;
        }
    }
    s+=20;
    for(int i=s;i<s+10;i++){
        for(int j=15;j<=28;j++){
            if((i>=s+1&&i<=s+2&&j>=21&&j<=22)||(i>=s+7&&i<=s+8&&j>=21&&j<=22)||(i>=s+1&&i<=s+2&&j>=16&&j<=18)||(i>=s+7&&i<=s+8&&j>=16&&j<=18))
                background[i][j]=32;//black
            else
//                background[i][j]=31;//yellow
                  background[i][j]=val3;
        }
    }
}

void MainWindow::sky(){
    for(int i=0;i<70;i++){
        for(int j=0;j<20;j++){
            background[i][j]=16;//sky_color
        }
    }
}

void MainWindow::sky_birds(){
    int flag=0;
    for(int x=5;x<65;x+=10){
        if(flag==0){
            for(int i=x;i<=x+2;i++){
                for(int j=2;j<3;j++){
                    background[i][j]=15;//yellow
                }
            }
            for(int i=x+3;i<=x+5;i++){
                for(int j=3;j<4;j++){
                    background[i][j]=15;//yellow
                }
            }
            for(int i=x+6;i<=x+8;i++){
                for(int j=2;j<3;j++){
                    background[i][j]=15;//yellow
                }
            }
            for(int i=x+4;i<x+5;i++){
                for(int j=4;j<5;j++){
                    background[i][j]=15;//yellow
                }
            }
            flag=1;
        }else{
            for(int i=x;i<=x+2;i++){
                for(int j=7;j<8;j++){
                    background[i][j]=17;//yellow
                }
            }
            for(int i=x+3;i<=x+5;i++){
                for(int j=8;j<9;j++){
                    background[i][j]=17;//yellow
                }
            }
            for(int i=x+6;i<=x+8;i++){
                for(int j=7;j<8;j++){
                    background[i][j]=17;//yellow
                }
            }
            for(int i=x+4;i<x+5;i++){
                for(int j=9;j<10;j++){
                    background[i][j]=17;//yellow
                }
            }
            flag=0;
        }

    }
}

void MainWindow::addLake() {

    //Define embankment for aesthethics
    for(int i=0;i<=69;i++){
        background[i][50] = 71;
    }

    // Boundaries of the lake---------------->X&Y coordinates
    int startX = 0; // Starting x-coordinate
    int endX = 69;   // Ending x-coordinate
    int startY = 51; // Starting y-coordinate
    int endY = 69;   // Ending y-coordinate

    // Fill the lake area with blue water
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            background[i][j] = 10; // 69 for blue water
        }
    }

    // Dark blue lines at random locations in the lake
    int numLines = 40;
    for (int line = 0; line < numLines; line++) {
        int randomX = startX + rand() % (endX - startX + 1);
        int randomY = startY + rand() % (endY- startY + 1);
        background[randomX][randomY] = 101; //minerals color
        //background[randomX+(rand() % (randomX))][randomY+(rand() % (randomY))] = 70;
    }
}

void MainWindow::draw_background(){

    for(int i=0;i<70;i++){
        for(int j=0;j<70;j++){
            //cout<<i<<" "<<j<<endl;
            setColor(i,j,background[i][j]);
        }
    }
}

// speed controlling............
int global_speed = 1;
int MainWindow::get_speedValue(){
    int val=ui->speed->value();
    return val;
}

void MainWindow::translation(int val){
    vector<vector<int>> temp(70,vector<int>(70));
//    int val=ui->speed->value();
    for(int i=0;i<70;i++){
        for(int j=0;j<70;j++){
            int trans=(i+val)%70;
            temp[trans][j]=background[i][j];
        }
    }
    background=temp;
    vector<int> temp_wheel_color(8);
    for(int i=0;i<8;i++){
        temp_wheel_color[i]=wheel_color[(i+val)%8];
    }
    wheel_color=temp_wheel_color;


    //building color changing........
//    int val1 = (rand() % (20 - 18 + 1)) + 18;
//    int val2 = (rand() % (20 - 18 + 1)) + 18;
//    int val3 = (rand() % (20 - 18 + 1)) + 18;
//    building(val1,val2,val3);
}


void MainWindow::on_draw_background_clicked()
{
    grass();
    road();
    sky();
    sky_birds();
    addLake();
    center_line();
    building(18,19,20);
    draw_background();
    ui->frame->setPixmap(QPixmap::fromImage(img));


    car();
    ui->frame->setPixmap(QPixmap::fromImage(img));
//    for(int i=0;i<1000;i++){
//        myDelay();
//        int val = get_speedValue();
//        translation(val);
//        draw_background();
//        car();
//        ui->frame->setPixmap(QPixmap::fromImage(img));

//    }
}

void MainWindow::on_start_clicked()
{
    setMusic();
    while(true){
        myDelay();
        translation(global_speed);
        draw_background();
        car();
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_stop_clicked()
{
    while(true){
        myDelay();
        translation(0);
        draw_background();
        car();
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_speedUp_clicked()
{
    global_speed++;
    while(true){
        myDelay();
        translation(global_speed);
        draw_background();
        car();
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_speedDown_clicked()
{
    global_speed--;
    while(true){
        myDelay();
        translation(global_speed);
        draw_background();
        car();
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}


// keyboard event ...........................................
QMediaPlayer *player = new QMediaPlayer;
QAudioOutput *output = new QAudioOutput;
void MainWindow::keyPressEvent(QKeyEvent * event){
    cout<<(char)event->key()<<endl;
    if(event->key()== Qt::Key_S){
        on_start_clicked();
    }
    if(event->key()== Qt::Key_O){
//        player->pause();
       on_stop_clicked();
    }
    if(event->key()== Qt::Key_U){
        on_speedUp_clicked();
    }
    if(event->key()== Qt::Key_N){
        on_speedDown_clicked();
    }
    if(event->key()== Qt::Key_Q){
        on_draw_background_clicked();
    }
    if(event->key()== Qt::Key_M){
        setMusic();
    }
    if(event->key()== Qt::Key_B){
        player->pause();
    }
//    if(MainWindow.close()){
//        player->pause();
//    }
}

//for music.....
void MainWindow::checkMusic(){
    if(global_speed==0){
       player->pause();
    }
}

void MainWindow::setMusic(){
        player->setAudioOutput(output);
        player->setSource(QUrl("qrc:/sounds/bg3.mp3"));

        output->setVolume(0.5); // <--- floating numbers. from 0 - 1

        player->play();

}
