#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMovie>
#include <QDebug>
#
#include <pyrite/client.h>


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
