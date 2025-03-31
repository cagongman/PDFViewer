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

    /*connect(m_prevPageBtn, &QPushButton::clicked, this, [this]() {
        if (m_currentPage > 0) {
            m_currentPage--;
            m_pdfView->setPage(m_currentPage);
            updatePageLabel();
        }
        });

    connect(m_nextPageBtn, &QPushButton::clicked, this, [this]() {
        if (m_currentPage < m_pdfDocument->pageCount() - 1) {
            m_currentPage++;
            m_pdfView->setPage(m_currentPage);
            updatePageLabel();
        }
        });*/

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

    int pageCount = m_pdfDocument->pageCount();
    for (int i = 0; i < pageCount; ++i) {
        QImage image = m_pdfDocument->render(i, QSize(800, 1200));
        QLabel* label = new QLabel;
        label->setPixmap(QPixmap::fromImage(image));
    }
}

void CM_PDFViewerMain::actionPreviousPage() {

}

void CM_PDFViewerMain::actionNextPage() {

}

CM_PDFViewerMain::~CM_PDFViewerMain()
{}
