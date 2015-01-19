#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(800,600);
    imageWidget = new ImageWidget();
    imageWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCentralWidget(imageWidget);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}


void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);

    operationMenu = new QMenu(tr("&Operation"), this);
    operationMenu->addAction(greyscaleAct);
    operationMenu->addAction(brightnessAct);
    operationMenu->addAction(revokeAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(operationMenu);
    menuBar()->addMenu(helpMenu);
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    greyscaleAct = new QAction(tr("&Grey Scale"), this);
    connect(greyscaleAct, SIGNAL(triggered()), imageWidget, SLOT(greyScale()));

    brightnessAct = new QAction(tr("&Brightness"), this);
    connect(brightnessAct, SIGNAL(triggered()), imageWidget, SLOT( brightness()));

    revokeAct = new QAction(tr("&Revoke"), this);
    connect(revokeAct, SIGNAL(triggered()), imageWidget, SLOT(revokeOrigin()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::openFile()
{
    QString fileName;
    QFileDialog* fd = new QFileDialog(this, tr("Open image File"), ".", tr("Image files(*.jpg *.png)"));
    fd->setFileMode(QFileDialog::ExistingFiles);
    fd->setViewMode(QFileDialog::Detail);

    if (fd->exec() == QDialog::Accepted)
    {
        imageWidget->load(fd->selectedFiles().first());
    }
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About"),
                       tr("<p>Contact: silangquan@gmail.com</p>"));
}
