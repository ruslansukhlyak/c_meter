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

private:
    Ui::MainWindow *ui;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    FT_STATUS ftStatus;
    FT_HANDLE ftHandle;
    DWORD numDevs;
    bool priznak = 0;
};

#endif // MAINWINDOW_H
