#include "frmmain.h"
#include <QApplication>
#include "myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    myHelper::SetUTF8Code();    
    frmMain w;
    w.show();

    return a.exec();
}
