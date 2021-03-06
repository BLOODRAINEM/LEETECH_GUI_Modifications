#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QtWidgets>

#include "controller.h"
#include "fstream"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    ifstream infile;
    ofstream outfile;
    QString filename;
    QString directory;
    int setID;
    int motorID;
    QString coord_mm;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void SetHV(int voltage);
    void SetHVPolarity(QChar p);

private slots:
    void MotorCoordinateChanged(int setID, int motorID, uint16_t newCoordinate);

    void on_ConnectButton_clicked();

    void AutomaticMode_On();

    void on_TestButton_clicked();

    void on_PulsesButton_clicked();

    void on_PeriodSpinBox_valueChanged(const QString &arg1);

    void on_WidthSpinBox_valueChanged(const QString &arg1);

    void on_GoButton_clicked();

    void on_CoordinateLineEdit_textChanged(const QString &arg1);

    void on_ResetOnePushButton_clicked();

    void on_ResetAllPushButton_clicked();

    void on_UpdateCoordinatesButton_clicked();

    void on_SelectEntranceRadio_clicked();

    void on_SelectExit1Radio_clicked();

    void Connected();
    void Disconnected();

    void on_MagnetConnectButton_clicked();

    void MagnetConnected();

    void UpdateMagnetPanel(float u, float i);

    void on_SetMagnetVoltageButton_clicked();

    void on_SetMagnetVoltageLine_textChanged(const QString &arg1);

    void on_SetMagnetCurrentLine_textChanged(const QString &arg1);

    void on_SetMagnetCurrentButton_clicked();

    void on_MagnetOnOffButton_clicked();

private:
    Ui::MainWindow *ui;
    Controller *hardware;
    QDoubleValidator *coordValidator;

    void SetValidators();
    int ValidatePulsesWidth(float width_us);
    int ValidatePulsesPeriod(float period_us);
    int ChooseMotor();
    int ChooseCollimatorSet();
    QString CoordToShow(uint16_t coordinate);
    void UnknownCoordinate(int setID, int motorID);
};

#endif // MAINWINDOW_H
