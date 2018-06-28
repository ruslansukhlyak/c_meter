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
    priznak = 1;
    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    QString textlabel = "Количество подключенных устройств - " + QString::number(numDevs,10);
    if (ftStatus == FT_OK)
    {
        ui->label->setText(textlabel);

    }
    else
    {
        ui->label->setText("Ошибка CreateDeviceInfoList");
    }
}

void MainWindow::on_buttstop_clicked()
{
    bool flag = 0;
    if(priznak == 1)
    {
        if (numDevs > 0)
        {
            // Выделение памяти для списка на основе количества устройств numDevs:
            devInfo = new FT_DEVICE_LIST_INFO_NODE[numDevs];
            // Получение device information list:
            ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);
            if (ftStatus == FT_OK)
            {
                for (int i = 0; i < numDevs; i++)
                {
                    if (devInfo[i].ID == 0x04036001) /*(devInfo[i].Description == "FT232R USB UART")*/
                    {
                        ui->label->setText("Подключен FT232R USB UART");
                        devchoice = i;
                        flag = 1;


                        ftStatus = FT_Open(devchoice, &ftHandle);
                        if (ftStatus != FT_OK)
                        {
                            // ошибка FT_Open
                            QString textlabel = "FT_Open error - " + QString::number(ftStatus);
                            ui->label->setText(textlabel);
                        }
                        ftStatus = FT_SetBaudRate(ftHandle, 256000); // установка скорости 256000 бод
                        if (ftStatus != FT_OK)
                        {
                            ui->label->setText("ошибка FT_SetBaudRate");
                        }
                        ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);
                        if (ftStatus != FT_OK)
                        {
                            ui->label->setText("ошибка FT_SetDataCharacteristics");
                        }

                    }
                    else
                    {
                        if( flag == 0 )
                        {
                            ui->label->setText("FT232R USB UART не найден");
                        }
                    }
                }
            }
        }
        else
        {
            ui->label->setText("Не подключено ни одного устройства");
        }
    }
    else
    {
        ui->label->setText("Сначала нажмите кнопку обновления");
    }
}


void MainWindow::on_getfreqbutton_clicked()
{

    if(devchoice != -1)
    {
        for(int i = 0; i < 10; i++)
        {
            if(!trans_data_to_dev(2))
            {
                ui->getfreqlabel->setText("Не удалось отправить команду");
            }
            if(get_data32b())
            {
                QString textlabel = "Принятые данные - " + QString::number(rxbuffer,10);
                ui->getfreqlabel->setText(textlabel);
            }
            else
            {
                ui->getfreqlabel->setText("Не удалось принять данные");
            }

        }
    }
    else
    {
        ui->getfreqlabel->setText("Нет FT232R USB UART");
    }
}
