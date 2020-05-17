#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include "global.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
