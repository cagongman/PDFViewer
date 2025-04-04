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
    m_currentPage = 0;

    m_prevPageBtn = new QPushButton("Prev", this);
    m_nextPageBtn = new QPushButton("Next", this);
    m_pageLabel = new QLabel("Page 0 / 0", this);

    QVBoxLayout* mainLayout = new QVBoxLayout(ui.centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(m_pdfView);

    QHBoxLayout* navLayout = new QHBoxLayout;
    navLayout->addWidget(m_prevPageBtn);
    navLayout->addWidget(m_pageLabel);
    navLayout->addWidget(m_nextPageBtn);
    mainLayout->addLayout(navLayout);

    auto nav = m_pdfView->pageNavigator();

    connect(m_prevPageBtn, &QPushButton::clicked, this, [this]() {
        if (!m_pdfDocument) return;
        if (m_currentPage > 0) {
            m_currentPage--;
            m_pdfView->pageNavigator()->jump(m_currentPage, QPointF(0, 0));
            updatePageLabel();
        }
    });

    connect(m_nextPageBtn, &QPushButton::clicked, this, [this]() {
        if (!m_pdfDocument) return;
        if (m_currentPage < m_pdfDocument->pageCount() - 1) {
            m_currentPage++;
            m_pdfView->pageNavigator()->jump(m_currentPage, QPointF(0, 0));
            updatePageLabel();
        }
    });

    QMenu* fileMenu = menuBar()->addMenu(tr("file"));
    QAction* openAction = new QAction(tr("open..."), this);
    fileMenu->addAction(openAction);

    connect(openAction, &QAction::triggered, this, &CM_PDFViewerMain::actionOpenPdfFile);
}

void CM_PDFViewerMain::actionOpenPdfFile() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("PDF open"), "", tr("PDF file (*.pdf)"));

    if (filePath.isEmpty()) 
        return;

    m_pdfDocument->load(filePath);
}

void CM_PDFViewerMain::actionPreviousPage() {

}

void CM_PDFViewerMain::actionNextPage() {

}

void CM_PDFViewerMain::updatePageLabel() {
    if (!m_pdfDocument || m_pdfDocument->pageCount() == 0)
        return;
    m_pageLabel->setText(QString("Page %1 / %2").arg(m_currentPage + 1).arg(m_pdfDocument->pageCount()));
}

CM_PDFViewerMain::~CM_PDFViewerMain()
{}
