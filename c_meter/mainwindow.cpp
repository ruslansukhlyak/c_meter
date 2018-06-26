#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_buttstart_clicked()
{
    //FT_DEVICE_LIST_INFO_NODE *devInfo;
    FT_STATUS ftStatus;
    //FT_HANDLE ftHandle;
    DWORD numDevs;

    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK)
    {
        ui->label->setText("Количество устройств");

    }
    else
    {
        ui->label->setText("Ошибка CreateDeviceInfoList");

    }

}

void MainWindow::on_buttstop_clicked()
{
    ui->label->setText("Нажата кнопка стоп");
}

void MainWindow::on_buttstart_pressed()
{
    ui->label->setText("Зажата кнопка старт");
}

