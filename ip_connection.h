#ifndef IP_CONNECTION_H
#define IP_CONNECTION_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "tests.h"

class Tests;

class IP_Connection : public QObject
{
    Q_OBJECT
public:
    explicit IP_Connection(QObject *parent = 0);
    ~IP_Connection();

signals:
    void Connected();
    void Disconnected();
    void dataReceived();

private:
    QString IP_Address;
    int port;
    QTcpSocket *socket;

    int Delay_waitForConnected;
    int Delay_waitForBytesWritten;
    int Delay_waitForReadyRead;

    bool _Connected;

    void IP_Init();

private slots:
    void sdisconnected();

public:
    friend Tests;

    bool IsConnected();
    bool PCB_Connect();
    void PCB_Disconnect();

    void PCB_SendData(QString);
    QByteArray PCB_ReceiveData();
    void SetIPAddress(QString);
    QByteArray readAll();

};

#endif // IP_CONNECTION_H
