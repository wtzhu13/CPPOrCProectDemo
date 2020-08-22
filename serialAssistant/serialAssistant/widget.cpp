/*******************************************************************************
 *  All rights reserved, Copyright (C) wtzhu
 * -----------------------------------------------------------------------------
 * [File Name]: 			widget.cpp
 * [Description]: 			Logical function of App
 *
 * [Author]: 				Fred
 * [Date Of Creation]:      2020/08/22
 * [e-mail]:                wtzhu_13@163.com
 * [Note]:
 *
 * ------------------------------------------------------------------------------
 * Date					Author				Modifications
 * ------------------------------------------------------------------------------
 * 2020-08				Fred                Created
 *******************************************************************************/

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList serialNamePortList;

    serialPort = new QSerialPort(this);

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialPortReadyRead_Slot()));

    // 遍历电脑中可用的COM口，并赋值到list中
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        serialNamePortList << info.portName();
    }

    // 将可用串口放到下拉框中
    ui->serialPortNum->addItems(serialNamePortList);
}

Widget::~Widget()
{
    delete ui;
}

/******************************************
 * 函数名：
 * 参数:
 * 返回值：
 * 功能：
 ******************************************/
void Widget::on_pushButtonOpen_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity checkBits;

    // 初始化波特率
    if(ui->baudRate->currentText() == "4800"){
        baudRate = QSerialPort::Baud4800;
    }else if (ui->baudRate->currentText() == "9600") {
        baudRate = QSerialPort::Baud9600;
    }else if (ui->baudRate->currentText() == "115200") {
        baudRate = QSerialPort::Baud115200;
    }

    // 初始化数据位
    if(ui->dataCb->currentText() == "6"){
        dataBits = QSerialPort::Data6;
    }else if(ui->dataCb->currentText() == "7"){
        dataBits = QSerialPort::Data7;
    }else if(ui->dataCb->currentText() == "8"){
        dataBits = QSerialPort::Data8;
    }

    // 初始化停止位
    if(ui->stopCb->currentText() == "1"){
        stopBits = QSerialPort::OneStop;
    }else if(ui->stopCb->currentText() == "1.5"){
        stopBits = QSerialPort::OneAndHalfStop;
    }else if(ui->stopCb->currentText() == "2"){
        stopBits = QSerialPort::TwoStop;
    }

    // 初始化校验位
    checkBits = QSerialPort::NoParity;

    // 设置串口
    serialPort->setPortName(ui->serialPortNum->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(checkBits);

    if(serialPort->open(QIODevice::ReadWrite) == true){
        QMessageBox::information(this, "提示", "成功");
    }else {
        QMessageBox::critical(this, "提示", "失败");
    }
}

/******************************************
 * 函数名：
 * 参数:
 * 返回值：
 * 功能：关闭串口
 ******************************************/
void Widget::on_pushButtonClose_clicked()
{
    serialPort->close();
}

/******************************************
 * 函数名：
 * 参数:
 * 返回值：
 * 功能：发送
 ******************************************/
void Widget::on_pushButtonSend_clicked()
{
    serialPort->write(ui->lineEditSend->text().toLocal8Bit().data());
}

/******************************************
 * 函数名：
 * 参数:
 * 返回值：
 * 功能：清空
 ******************************************/
void Widget::on_pushButtonClear_clicked()
{
    serialPort->clear();
}

/******************************************
 * 函数名：
 * 参数:
 * 返回值：
 * 功能：接受串口数据
 ******************************************/
void Widget::serialPortReadyRead_Slot()
{
    QString buf;
    buf = QString(serialPort->readAll());
    ui->plainTextEditReceive->appendPlainText(buf);
}
