#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>
#include "imagewidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createMenus();
    void createActions();

    QMenu *fileMenu;
    QMenu *operationMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *exitAct;

    QAction *greyscaleAct;
    QAction *brightnessAct;
    QAction *revokeAct;
    QAction *aboutAct;

    ImageWidget *imageWidget;

private slots:
    void openFile();
    void about();

};

#endif // MAINWINDOW_H
