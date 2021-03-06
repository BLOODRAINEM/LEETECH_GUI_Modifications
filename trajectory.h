#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QObject>
#include <stdint.h>
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QList>

class Trajectory : public QObject
{
    Q_OBJECT
private:
    typedef enum{
        UNKNOWN = 0x00,
        TIMES_RECEIVED = 0x01,
        USIGNAL_RECEIVED = 0x02,
        COORDINATES_RECEIVED = 0x04
    } state_t;
    uint8_t state;

    QString setID;
    uint8_t motorID;
    uint16_t destination;

    int length;
    uint16_t *times;
    uint16_t *uSignal;
    uint16_t *coordinates;

    uint16_t Convert2_8to16(char msb, char lsb);
    void SetArray(uint16_t *array, QByteArray *newData);
    void CleanArrays();


public:
    explicit Trajectory(QObject *parent = 0);
    ~Trajectory();

    QStringList indicators;

    void AddData(const QString indicator, QByteArray newData);
    int AllDataReceived();

    void WriteToFile();

signals:

public slots:

};

#endif // TRAJECTORY_H
