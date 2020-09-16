#include "qtportdebug.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("tc_CN");
    a.installTranslator(&translator);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    QTPortDebug w;

    w.show();

    return a.exec();
}
