#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    quint64 second_count;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

private slots:
    void updateTime();
    void on_toggleButton_toggled(bool checked);
    void on_resetButton_clicked();
    void on_closeButton_clicked();
};

#endif // MAINWINDOW_H
