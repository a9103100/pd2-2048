#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <QString>
#include <cstdlib>
#include <time.h>
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    score=0;
    count=0;

    box[0]=ui->label_0;
    box[1]=ui->label_1;
    box[2]=ui->label_2;
    box[3]=ui->label_3;
    box[4]=ui->label_4;
    box[5]=ui->label_5;
    box[6]=ui->label_6;
    box[7]=ui->label_7;
    box[8]=ui->label_8;
    box[9]=ui->label_9;
    box[10]=ui->label_10;
    box[11]=ui->label_11;
    box[12]=ui->label_12;
    box[13]=ui->label_13;
    box[14]=ui->label_14;
    box[15]=ui->label_15;

    bc[0]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(205, 201, 201);}";
    bc[1]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(216, 179, 104);}";
    bc[2]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(255, 127, 80);}";
    bc[3]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(205, 170, 125);}";
    bc[4]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(205, 102, 0);}";
    bc[5]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(255, 106, 106);}";
    bc[6]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(255, 0, 0);}";
    bc[7]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(255, 165, 0);}";
    bc[8]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(135, 206, 235);}";
    bc[9]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(72, 209, 204);}";
    bc[10]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(70, 130, 180);}";
    bc[11]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(102, 205, 170);}";
    bc[12]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(46, 139, 87);}";
    bc[13]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(0, 100, 0);}";
    bc[14]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(85, 107, 47);}";
    bc[15]="QLabel { border-width:1px;border-color:black;border-radius: 10px;background-color: rgb(148, 0, 211);}";

    obstacle[0]="5P";
    obstacle[1]="4P";
    obstacle[2]="3P";
    obstacle[3]="2P";
    obstacle[4]="1P";


    /*int i;
    for(i=0;i<16;i++){
        judge[i]=box[i]->text();
    }
    changecolor();*/
    on_pushButton_clicked();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right){
        right();
    }
    if(event->key()==Qt::Key_Left){
        left();
    }
    if(event->key()==Qt::Key_Up){
        up();
    }
    if(event->key()==Qt::Key_Down){
        down();
    }
    ui->lcdNumber->display(score);
    changecolor();
    check();
}

void Widget::on_pushButton_clicked()
{
    int i;
    score=0;
    count=0;
    for(i=0;i<16;i++){
        box[i]->setText("0");
    }
    for(i=0;i<16;i++){
        if(box[i]->text()=="0"){
            judge[i]="0";
            box[i]->setText(" ");
        }
    }

    srand(time(NULL));
    int Ra,Rb;
    Ra=rand()%16;
    Rb=rand()%16;
    while(Ra==Rb)
        Rb=rand()%16;
    judge[Ra]="2";
    box[Ra]->setText(judge[Ra]);
    judge[Rb]="2";
    box[Rb]->setText(judge[Rb]);
    changecolor();
    ui->lcdNumber->display(score);
    ui->gameover->setText(" ");
    ui->show->setText(" ");
}

void Widget::appear(){
    count=count+1;
    int R, Rc;
    int i;
    int p=0, q=0;
    int choose[20];
    for(i=0;i<20;i++){
        if(i>-1&&i<14)
            choose[i]=2;
        if(i>13&&i<19)
            choose[i]=4;
        if(i==19)
            choose[i]=1;
    }
    if(count<30){
        R=rand()%16;
        while(judge[R]!="0")
            R=rand()%16;
        judge[R]="2";
        box[R]->setText(judge[R]);
    }
    else if(count>=30){
        R=rand()%16;
        while(judge[R]!="0")
            R=rand()%16;
        for(i=0;i<16;i++){
            if(judge[i]=="0")
                p=p+1;
        }
        if(p>0&&p<6){
           Rc=rand()%19;
           if(choose[Rc]==2){
               judge[R]="2";
               box[R]->setText(judge[R]);
           }
           if(choose[Rc]==4){
               judge[R]="4";
               box[R]->setText(judge[R]);
           }
        }
        if(p>5){
            Rc=rand()%20;
            for(i=0;i<16;i++){
                if(judge[i]=="1")
                    q=q+1;
            }
            while(choose[Rc]==1&&q>0)
                Rc=rand()%20;
            if(choose[Rc]==2){
                judge[R]="2";
                box[R]->setText(judge[R]);
            }
            if(choose[Rc]==4){
                judge[R]="4";
                box[R]->setText(judge[R]);
            }
            if(choose[Rc]==1){
                judge[R]="1";
                box[R]->setText(obstacle[0]);
                countdown=0;
            }
        }
    }
}

void Widget::pause(){
    if(countdown>-1&&countdown<6){
        for(int i=0;i<16;i++){
            if(judge[i]=="1"){
                if(countdown!=5){
                    box[i]->setText(obstacle[countdown]);
                    countdown=countdown+1;
                }
                else if(countdown==5){
                    judge[i]="0";
                    box[i]->setText(" ");
                    countdown=-1;
                }
            }
        }
    }
}

void Widget::eachfromright(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            fromright[i][j]=judge[i*4+3-j].toInt();
        }
    }
    /*for(i=0;i<4;i++){
            qDebug()<<fromright[i][0]<<fromright[i][1]<<fromright[i][2]<<fromright[i][3];
    }*/
}

void Widget::right(){
    int i, j, tmp, c;
    eachfromright();
    c=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp=0;
            if(fromright[i][j]!=0){
                tmp=j-1;
                while(tmp>-1){
                    if(fromright[i][tmp]!=0&&fromright[i][tmp]!=fromright[i][tmp+1]){
                        break;
                    }
                    else if(fromright[i][tmp]==0){
                        fromright[i][tmp]=fromright[i][tmp+1];
                        fromright[i][tmp+1]=0;
                        c=c+1;
                    }
                    else if(fromright[i][tmp]!=0&&fromright[i][tmp]==fromright[i][tmp+1]){
                        fromright[i][tmp]=fromright[i][tmp]+fromright[i][tmp+1];
                        fromright[i][tmp+1]=0;
                        c=c+1;
                        score=score+fromright[i][tmp];
                        break;
                    }
                    tmp=tmp-1;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            judge[i*4+3-j]=QString::number(fromright[i][j]);
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="0")
            box[i]->setText(" ");
        if(judge[i]!="0"&&judge[i]!="1")
            box[i]->setText(judge[i]);
    }
    if(c!=0){
        appear();
        pause();
    }
}

void Widget::eachfromleft(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            fromleft[i][j]=judge[i*4+j].toInt();
        }
    }
    /*for(i=0;i<4;i++){
            qDebug()<<fromleft[i][0]<<fromleft[i][1]<<fromleft[i][2]<<fromleft[i][3];
    }*/
}

void Widget::left(){
    int i, j, tmp, c;
    eachfromleft();
    c=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp=0;
            if(fromleft[i][j]!=0){
                tmp=j-1;
                while(tmp>-1){
                    if(fromleft[i][tmp]!=0&&fromleft[i][tmp]!=fromleft[i][tmp+1]){
                        break;
                    }
                    else if(fromleft[i][tmp]==0){
                        fromleft[i][tmp]=fromleft[i][tmp+1];
                        fromleft[i][tmp+1]=0;
                        c=c+1;
                    }
                    else if(fromleft[i][tmp]!=0&&fromleft[i][tmp]==fromleft[i][tmp+1]){
                        fromleft[i][tmp]=fromleft[i][tmp]+fromleft[i][tmp+1];
                        fromleft[i][tmp+1]=0;
                        c=c+1;
                        score=score+fromleft[i][tmp];
                        break;
                    }
                    tmp=tmp-1;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            judge[i*4+j]=QString::number(fromleft[i][j]);
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="0")
            box[i]->setText(" ");
        if(judge[i]!="0"&&judge[i]!="1")
            box[i]->setText(judge[i]);
    }
    if(c!=0){
        appear();
        pause();
    }
}

void Widget::eachfromup(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            fromup[i][j]=judge[i+j*4].toInt();
        }
    }
    /*for(i=0;i<4;i++){
            qDebug()<<fromup[i][0]<<fromup[i][1]<<fromup[i][2]<<fromup[i][3];
    }*/
}

void Widget::up(){
    int i, j, tmp, c;
    eachfromup();
    c=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp=0;
            if(fromup[i][j]!=0){
                tmp=j-1;
                while(tmp>-1){
                    if(fromup[i][tmp]!=0&&fromup[i][tmp]!=fromup[i][tmp+1]){
                        break;
                    }
                    else if(fromup[i][tmp]==0){
                        fromup[i][tmp]=fromup[i][tmp+1];
                        fromup[i][tmp+1]=0;
                        c=c+1;
                    }
                    else if(fromup[i][tmp]!=0&&fromup[i][tmp]==fromup[i][tmp+1]){
                        fromup[i][tmp]=fromup[i][tmp]+fromup[i][tmp+1];
                        fromup[i][tmp+1]=0;
                        c=c+1;
                        score=score+fromup[i][tmp];
                        break;
                    }
                    tmp=tmp-1;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            judge[i+j*4]=QString::number(fromup[i][j]);
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="0")
            box[i]->setText(" ");
        if(judge[i]!="0"&&judge[i]!="1")
            box[i]->setText(judge[i]);
    }
    if(c!=0){
        appear();
        pause();
    }
}

void Widget::eachfromdown(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            fromdown[i][j]=judge[i+4*(3-j)].toInt();
        }
    }
    /*for(i=0;i<4;i++){
            qDebug()<<fromdown[i][0]<<fromdown[i][1]<<fromdown[i][2]<<fromdown[i][3];
    }*/
}

void Widget::down(){
    int i, j, tmp, c;
    eachfromdown();
    c=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp=0;
            if(fromdown[i][j]!=0){
                tmp=j-1;
                while(tmp>-1){
                    if(fromdown[i][tmp]!=0&&fromdown[i][tmp]!=fromdown[i][tmp+1]){
                        break;
                    }
                    else if(fromdown[i][tmp]==0){
                        fromdown[i][tmp]=fromdown[i][tmp+1];
                        fromdown[i][tmp+1]=0;
                        c=c+1;
                    }
                    else if(fromdown[i][tmp]!=0&&fromdown[i][tmp]==fromdown[i][tmp+1]){
                        fromdown[i][tmp]=fromdown[i][tmp]+fromdown[i][tmp+1];
                        fromdown[i][tmp+1]=0;
                        c=c+1;
                        score=score+fromdown[i][tmp];
                        break;
                    }
                    tmp=tmp-1;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            judge[i+4*(3-j)]=QString::number(fromdown[i][j]);
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="0")
            box[i]->setText(" ");
        if(judge[i]!="0"&&judge[i]!="1")
            box[i]->setText(judge[i]);
    }
    if(c!=0){
        appear();
        pause();
    }
}

void Widget::check(){
    int i, j, c;
    c=0;
    for(i=0;i<16;i++){
        if(judge[i]=="0")
            c=c+1;
    }
    eachfromleft();
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(fromleft[i][j]==fromleft[i][j+1]||fromleft[i][j]==fromleft[i+1][j])
                c=c+1;
        }
    }
    for(i=0;i<3;i++){
        if(fromleft[i][3]==fromleft[i+1][3])
            c=c+1;
        if(fromleft[3][i]==fromleft[3][i+1])
            c=c+1;
    }
    if(c==0){
        ui->gameover->setText("GameOver");
        ui->show->setText("Press Restart button to play again!");
    }
    for(i=0;i<16;i++){
        if(judge[i]=="2048"){
            ui->gameover->setText("You Win!");
            ui->show->setText("Your next goal is to get to the 4096 tile!");
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="4096"){
            ui->gameover->setText("You Win!");
            ui->show->setText("Your next goal is to get to the 8192 tile!");
        }
    }
    for(i=0;i<16;i++){
        if(judge[i]=="8192"){
            ui->gameover->setText("You Win!");
            ui->show->setText("Your next goal is to get to the 16384 tile!");
        }
    }
}

void Widget::changecolor(){
    int i, a, b;
    for(i=0;i<16;i++){
        a=judge[i].toInt();
        if(a!=0&&a!=1){
            b=log2(a);
            box[i]->setStyleSheet(bc[b]);
        }
        if(a==1)
            box[i]->setStyleSheet(bc[15]);
        if(a==0)
            box[i]->setStyleSheet(bc[0]);
    }
}

void Widget::on_pushButton_2_clicked()
{
    exit(0);
}
