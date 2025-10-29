#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void updateSpeed();

private:
    QLabel *backgroundLabel;
    QLabel *speedLabel;
    QLabel *speedLimitLabel;
    QLabel *carLabel;
    QLabel *leftSignalLabel;
    QLabel *rightSignalLabel;
    QLabel *modeLabel;

    QTimer *timer;
    int speed;
    bool leftOn;
    bool rightOn;
};

#endif // MAINWINDOW_H
