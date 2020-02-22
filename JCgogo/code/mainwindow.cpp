#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string path = DISK + "://JCgogo//Scene2//BGM3.mp3";
    const char * _path = path.c_str();

    QMediaPlaylist * playlist = new QMediaPlaylist;
    playlist->setCurrentIndex(1);
    playlist->addMedia(QUrl::fromLocalFile(_path));
    playlist->addMedia(QUrl::fromLocalFile(_path));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * player = new QMediaPlayer;

    player->setPlaylist(playlist);
//    player->setMedia(QUrl::fromLocalFile(_path));
    player->setVolume(30);
    player->play();

    _game.initWorld(DISK + "://JCgogo//Scene2//Scene0set.txt");
    _game1.initWorld(DISK + "://JCgogo//Scene2//Scene1set.txt");
    _game2.initWorld(DISK + "://JCgogo//Scene2//Scene2set.txt");
    _gamepk1.initWorld(DISK + "://JCgogo//Scene2//Scenepk1set.txt");
    _gamepk2.initWorld(DISK + "://JCgogo//Scene2//Scenepk2set.txt");
    _gamepk3.initWorld(DISK + "://JCgogo//Scene2//Scenepk3set.txt");

    this->SceneControl();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBGM(){

    QMediaPlayer * player = new QMediaPlayer;

    if(_crnt_world->getPK()==1){

         player->stop();

    }
    else {

        if(SceneNo!=0) player->stop();

        string path = DISK + "://JCgogo//Scene2//BGM3.mp3";
        const char * _path = path.c_str();

        player->setMedia(QUrl::fromLocalFile(_path));
        player->setVolume(30);
        player->play();
    }
}

void MainWindow::paintEvent(QPaintEvent *e){

    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_crnt_world->show(pa);
    pa->end();
    delete pa;    

    QPainter painter2(this);
    stringstream ss;
    ss<<_crnt_world->getjcHP();
    string  s=ss.str();
    string  JCHP="JC HP:"+s;
    QString JCHPshow = QString::fromLocal8Bit(JCHP.c_str());
    painter2.drawText(495, 505, JCHPshow);

    if(_crnt_world->getPK()==1){
        QPainter painter3(this);
        stringstream ss;
        ss<<_crnt_world->getMonsterHP();
        string  s=ss.str();
        string  Monster_HP="Monster HP:"+s;
        QString MonHPshow = QString::fromLocal8Bit(Monster_HP.c_str());
        painter3.drawText(47, 440, MonHPshow);
    }

}

void MainWindow::SceneControl(){
    timer = new QTimer(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    QMediaPlayer * player = new QMediaPlayer;

    if(SceneNo==0){
/*
        player->setMedia(QUrl::fromLocalFile("C://JCgogo//Scene2//BGM1.mp3");
        player->setVolume(10);
        player->play();
*/
        _crnt_world = & _game;
    }
    else if(SceneNo==1){
        _crnt_world = & _game1;
    }
    else if(SceneNo==2){
        _crnt_world = & _game2;

        connect(timer,SIGNAL(timeout()),this,SLOT(MonsterMove()));
        timer->start(100);
        timer->setInterval(2000);
    }
    else if(SceneNo==3){
        timer->stop();
        _crnt_world = & _gamepk1;

        connect(timer,SIGNAL(timeout()),this,SLOT(roundone()));
        timer->start(100);
        timer->setInterval(1000);

    }
    else if(SceneNo==4){
        timer->stop();
        _crnt_world = & _game3;

        connect(timer,SIGNAL(timeout()),this,SLOT(MonsterMove()));
        timer->start(100);
        timer->setInterval(2000);
    }
    else if(SceneNo==5){
        timer->stop();
        _crnt_world = & _gamepk2;

        connect(timer,SIGNAL(timeout()),this,SLOT(roundone()));
        timer->start(100);
        timer->setInterval(1000);
    }
    else if(SceneNo==6){
        timer->stop();
        _crnt_world = & _game4;

        connect(timer,SIGNAL(timeout()),this,SLOT(MonsterMove()));
        timer->start(100);
        timer->setInterval(2000);
    }
    else if(SceneNo==7){
        timer->stop();
        _crnt_world = & _gamepk3;

        connect(timer,SIGNAL(timeout()),this,SLOT(roundone()));
        timer->start(100);
        timer->setInterval(1000);

    }
    else if(SceneNo==8){
        timer->stop();
        _crnt_world = & _game5;
    }

//    setBGM();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_crnt_world->handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_crnt_world->handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_crnt_world->handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_crnt_world->handlePlayerMove(2,1);
    }

    if(this->_crnt_world->getDeath()){
        close();
    }

    if(ChangeSce==1){
        if(SceneNo==4){
            _game3.initWorld(DISK + "://JCgogo//Scene2//Scene3set.txt");
        }
        if(SceneNo==6){
            _game4.initWorld(DISK + "://JCgogo//Scene2//Scene4set.txt");
        }
        if(SceneNo==8){
            _game5.initWorld(DISK + "://JCgogo//Scene2//Scene5set.txt");
        }
        this->SceneControl();
        ChangeSce=0;
    }

    if(this->_crnt_world->getEnd()){
        close();
    }

    this->repaint();
}


void MainWindow::MonsterMove(){
    this->_crnt_world->MonsterMove();
    this->repaint();
    return;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(SceneNo==0) SceneNo=1;

    this->SceneControl();

    this->repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    _crnt_world->saveRecord();

    close();
}

void MainWindow::roundone(){
    this->_crnt_world->roundone();
    this->repaint();
    return;
}

void MainWindow::on_pushButton_clicked()
{
    string path=DISK + "://JCgogo//Scene2//Record.txt";
    const char * in=path.c_str();

    ifstream fin(in);

    if(!fin.is_open()){
        cout<<"Can't find file!!"<<endl;
        return;
    }

    char type[10];
    int PosX,PosY;
    string s;

    while ( getline(fin,s) )
    {
        const char * line=s.c_str();

        sscanf(line,"%s %d %d",&type,&PosX,&PosY);

        if(strcmp(type,"SceneNo")==0){
            SceneNo=PosX;
            break;
        }
    }

    if(SceneNo==1){

    }
    if(SceneNo==2){
        _game2.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==4){
        _game3.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==6){
        _game4.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==8){
        _game5.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==3){
        _gamepk1.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==5){
        _gamepk2.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }
    if(SceneNo==7){
        _gamepk3.initWorld(DISK + "://JCgogo//Scene2//Record.txt");
    }

    this->SceneControl();

    this->repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}
