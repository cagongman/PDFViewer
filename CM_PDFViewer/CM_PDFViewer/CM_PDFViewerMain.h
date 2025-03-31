#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CM_PDFViewerMain.h"
#include <QtPdfWidgets/QPdfView>
#include <QtPdf/QPdfDocument>
#include <QPushButton>
#include <QLabel>

class CM_PDFViewerMain : public QMainWindow
{
    Q_OBJECT

public:
    CM_PDFViewerMain(QWidget *parent = nullptr);
    ~CM_PDFViewerMain();

private:
    Ui::CM_PDFViewerMainClass ui;

    QPdfDocument* m_pdfDocument;
    QPdfView* m_pdfView;
    
    int m_currentPage;

    QPushButton* m_prevPageBtn;
    QPushButton* m_nextPageBtn;
    QLabel* m_pageLabel;

private slots:
    void actionOpenPdfFile();
    void actionPreviousPage();
    void actionNextPage();
};
