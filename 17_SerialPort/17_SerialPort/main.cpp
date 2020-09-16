#include "serialport.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //根据翻译好的语言包,将ui中的文字翻译成目标语言
//    QTranslator translator;
//    translator.load(":/zh_CN.qm");
//    app.installTranslator(&translator);

    SerialPort w;
    w.show();

    return app.exec();
}
