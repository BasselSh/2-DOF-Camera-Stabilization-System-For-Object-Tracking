#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPixmap"
#include "QImage"
#include "opencv2/opencv.hpp"
#include "QThread"
#include "QDebug"
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B1_clicked();

    void processFrameAndUpdateGUI();

    void plot_response(int x, int y);

    void send();

    void on_pause_clicked();

    void on_effect_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    cv::VideoCapture cap;
    QTimer *timer1;
    QTimer *timer2;
};
#endif // MAINWINDOW_H
