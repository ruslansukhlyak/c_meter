#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::get_data32b()
{
    DWORD BytesReceived;
    unsigned __int8 qwe;
    unsigned __int32 qwe32 = 0, temp;
    //cout << "Ожидание 32-разрядных данных" << endl;
    for (int i = 0; i < 4; i++)
    {
        ftStatus = FT_Read(ftHandle, &qwe, sizeof(qwe), &BytesReceived);
        if (ftStatus != FT_OK)
        {
            return 0;
        }
        temp = 0;
        temp = qwe;
        temp = temp << i * 8;
        qwe32 = temp | qwe32;

    }

    rxbuffer = qwe32;
    qwe32 = 0;
    return 1;
}
