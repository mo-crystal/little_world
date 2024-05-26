#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->stackedWidget->setStyleSheet("background-color: transparent;");
  prt::client c("127.0.0.1", 8080);
  c.async();
 
}

MainWindow::~MainWindow()
{
  delete ui;
}

