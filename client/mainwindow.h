#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <random>
#include <list>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

#include <QMainWindow>
#include <QPainter>
#include <QMovie>
#include <QDebug>

#include <QMouseEvent>
#include <QTimer>




namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private:
  Ui::MainWindow *ui;
  
};

#endif // MAINWINDOW_H
