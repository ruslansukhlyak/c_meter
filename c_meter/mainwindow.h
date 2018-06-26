#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include "..\ftd2xx.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_buttstart_clicked();

    void on_buttstop_clicked();

    void on_buttstart_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
