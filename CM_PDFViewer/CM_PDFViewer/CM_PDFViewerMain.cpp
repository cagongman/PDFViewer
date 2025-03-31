#include "CM_PDFViewerMain.h"
#include <QtPdf/QPdfPageNavigator>


CM_PDFViewerMain::CM_PDFViewerMain(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

CM_PDFViewerMain::~CM_PDFViewerMain()
{}
