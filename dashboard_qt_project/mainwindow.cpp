#include "mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    speed(84), leftOn(false), rightOn(false)
{
    setFixedSize(1280, 360);
    // Background
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(":/images/background.png").scaled(size()));
    backgroundLabel->setGeometry(0,0,width(),height());

    // Car (center)
    carLabel = new QLabel(this);
    carLabel->setPixmap(QPixmap(":/images/car.png").scaled(220,120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    carLabel->setGeometry((width()-220)/2, height()-160, 220, 120);
    carLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Speed big text (left)
    speedLabel = new QLabel(this);
    QFont f; f.setPointSize(72); f.setBold(true);
    speedLabel->setFont(f);
    speedLabel->setText(QString::number(speed));
    speedLabel->setGeometry(60, 70, 220, 140);
    speedLabel->setStyleSheet("color: #111; background: transparent;");

    // Speed limit sign (center top)
    speedLimitLabel = new QLabel(this);
    speedLimitLabel->setPixmap(QPixmap(":/images/50.png").scaled(80,80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    speedLimitLabel->setGeometry((width()-80)/2 - 10, 40, 80, 80);
    speedLimitLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Left and right signal icons near car
    leftSignalLabel = new QLabel(this);
    leftSignalLabel->setPixmap(QPixmap(":/images/solsinyal.png").scaled(48,48));
    leftSignalLabel->setGeometry((width()/2)-160, height()-120, 48, 48);
    leftSignalLabel->setAttribute(Qt::WA_TranslucentBackground);
    leftSignalLabel->setVisible(false);

    rightSignalLabel = new QLabel(this);
    rightSignalLabel->setPixmap(QPixmap(":/images/sagsinyal.png").scaled(48,48));
    rightSignalLabel->setGeometry((width()/2)+120, height()-120, 48, 48);
    rightSignalLabel->setAttribute(Qt::WA_TranslucentBackground);
    rightSignalLabel->setVisible(false);

    // Mode (hizsabit)
    modeLabel = new QLabel(this);
    modeLabel->setPixmap(QPixmap(":/images/hizsabit.png").scaled(60,60));
    modeLabel->setGeometry(width()-150, height()-130, 60, 60);
    modeLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Timer to simulate speed and blink signals
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSpeed);
    timer->start(800);
}

void MainWindow::updateSpeed()
{
    // simulate speed change
    speed += (qrand()%11) - 5;
    if (speed < 0) speed = 0;
    if (speed > 220) speed = 220;
    speedLabel->setText(QString::number(speed));

    // Blink signals periodically
    static int tick = 0;
    tick++;
    if (tick % 8 == 0) {
        leftOn = !leftOn;
        leftSignalLabel->setVisible(leftOn);
    }
    if (tick % 12 == 0) {
        rightOn = !rightOn;
        rightSignalLabel->setVisible(rightOn);
    }

    // change speed limit image depending on speed (simple logic)
    if (speed < 60) {
        speedLimitLabel->setPixmap(QPixmap(":/images/50.png").scaled(80,80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        speedLimitLabel->setPixmap(QPixmap(":/images/70.png").scaled(80,80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
