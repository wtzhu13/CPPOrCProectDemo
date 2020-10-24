## serialAssistant

使用方式：直接打开AppPackage，双击EXE文件即可运行，已经打包好。

源代码在serialAssistan目录下，直接用qt打开.pro工程即可查看。

### 代码说明

#### UI界面设计

![](D:\CppAndC\CPPOrCProectDemo\serialAssistant\images\UI.png)

用到的空控件：PushButton、ComboBox、LineEdit、PlainTextEdit、Label和弹簧及一些布局控件。

直接从左边拖拽到右边放到指定的位置即可。需要注意的时接受框PlainTextEdit需要设置为只读模式。



#### 逻辑思路

##### 串口号的获取

```cpp
QStringList serialNamePortList;
// 遍历电脑中可用的COM口，并赋值到list中
foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
    serialNamePortList << info.portName();
}
// 将可用串口放到下拉框中
ui->serialPortNum->addItems(serialNamePortList);
```

	1. 定义一个QStringList存放电脑上发现的串口号。
 	2. 通过foreach顺序遍历序列数据，并将串口名放进QStringList中。
 	3. 将QStringLIst添加到ComboBox中，这样下拉框就可以选择。



##### 连接

```c++
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
```

1. 打开串口需要设置几个串口的参数，基本的就是波特率，数据位，停止位，校验位和串口号。
2. 通过下拉款中的参数初始化参数，参数通过判断赋值。
3. 通过提示框提示是否打开。

##### 数据的接受

```
serialPort = new QSerialPort(this);
connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialPortReadyRead_Slot()));
```

1. 连接信号糟，当有数据发送过来的时候触发。

```c++
QString buf;
buf = QString(serialPort->readAll());
ui->plainTextEditReceive->appendPlainText(buf);
```

2. 自定义槽函数，通过一个buf接受发送过来的数据，并显示到接受信息框中。

##### 数据的发送

```C++
serialPort->write(ui->lineEditSend->text().toLocal8Bit().data());
```

将发送框中输入的数据获取并转换为八位的数据，并写进串口。

##### 关闭和清除

```C++
serialPort->close();
serialPort->clear();
```

直接使用API提供的就好。