#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CM_PDFViewerMain.h"

class CM_PDFViewerMain : public QMainWindow
{
    Q_OBJECT

public:
    CM_PDFViewerMain(QWidget *parent = nullptr);
    ~CM_PDFViewerMain();

private:
    Ui::CM_PDFViewerMainClass ui;
};
