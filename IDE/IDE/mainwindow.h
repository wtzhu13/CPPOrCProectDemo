#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionUTF_8_triggered();

    void on_actionGBK_triggered();

    void on_actionOPEN_triggered();

    void on_actionSAVE_AS_triggered();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
