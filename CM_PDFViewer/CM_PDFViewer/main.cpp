#include "CM_PDFViewerMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CM_PDFViewerMain w;
    w.show();
    return a.exec();
}
