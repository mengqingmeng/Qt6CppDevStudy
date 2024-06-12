#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_mygraphicsView = new MyGraphicsView();

    ui->gridLayout->addWidget(m_mygraphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
