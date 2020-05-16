#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_roomInfo_clicked();

    void on_pushButton_addUser_clicked();

    void on_pushButton_delUser_clicked();

    void on_pushButton_clearOrder_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};
#endif // WIDGET_H
