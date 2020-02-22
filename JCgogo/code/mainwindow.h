#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include "qobject.h"
#include "rpgobj.h"
#include "world.h"
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QString>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    void SceneControl();
    string coverablepath();
    void setBGM();

protected slots:
    void MonsterMove();//响应时钟事件的函数
    void roundone();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();//存档并退出
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int MonsterControl1=0;
    World _FZs;
    World * _crnt_world = NULL;
    World _game;
    World _game1;
    World _game2;
    World _game3;
    World _game4;
    World _game5;
    World _gamepk1;
    World _gamepk2;
    World _gamepk3;
    QTimer *timer;

/*
private:
    Ui::MainWindow *ui;
    World _Game;*/
};

#endif // MAINWINDOW_H
