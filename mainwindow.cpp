#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::FramelessWindowHint);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    ui->toggleButton->setChecked(false);
    ui->resetButton->click();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::updateTime()
{
    auto seconds = second_count % 60;
    auto minutes = second_count / 60;
    auto hours = (minutes / 60) % 10;
    minutes %= 60;
    second_count += 1;

    auto output = QString(" %1:%2:%3")
            .arg(hours)
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));

    ui->timeBox->setText(output);
}


void MainWindow::on_toggleButton_toggled(bool checked)
{
    if (checked)
        timer->start(1000);
    else
        timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    second_count = 0;
    updateTime();
}

void MainWindow::on_closeButton_clicked()
{
    close();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX() - m_nMouseClick_X_Coordinate,
         event->globalY() - m_nMouseClick_Y_Coordinate);
}
