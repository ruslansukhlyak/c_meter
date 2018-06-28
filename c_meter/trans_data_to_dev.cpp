#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::trans_data_to_dev(UINT32 txbuffer)
{
    UINT8 txbuffer8b;
    DWORD txbyte;//Количество записанных байт в устройство
    for (int i = 0; i < 4; i++)
    {
        txbuffer8b = txbuffer >> (i*8);
        ftStatus = FT_Write(ftHandle, &txbuffer8b, 1, &txbyte);
        if (ftStatus != FT_OK)
        {
            return 0;
        }
    }
    return 1;
}
