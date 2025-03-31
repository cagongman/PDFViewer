#include "CM_PDFViewerMain.h"
#include <QtPdf/QPdfPageNavigator>
#include <QtPdf/QPdfDocument>
#include <QtPdfWidgets/QPdfView>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMenuBar>


CM_PDFViewerMain::CM_PDFViewerMain(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    m_pdfDocument = new QPdfDocument(this);
    m_pdfView = new QPdfView(this);
    m_pdfView->setDocument(m_pdfDocument);

    QWidget* central = ui.centralWidget;
    QVBoxLayout* layout = new QVBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_pdfView);

    QMenu* fileMenu = menuBar()->addMenu(tr("file"));
    QAction* openAction = new QAction(tr("open..."), this);
    fileMenu->addAction(openAction);

    connect(openAction, &QAction::triggered, this, &CM_PDFViewerMain::openPdfFile);
}

void CM_PDFViewerMain::openPdfFile() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("PDF open"), "", tr("PDF file (*.pdf)"));
    if (!filePath.isEmpty()) {
        m_pdfDocument->load(filePath);
    }
}

CM_PDFViewerMain::~CM_PDFViewerMain()
{}
