#ifndef PANEL_STATUS_H
#define PANEL_STATUS_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QMap>
#include <QLabel>

namespace Ui {
class PanelStatus;
}

class PanelStatus : public QWidget
{
    Q_OBJECT

public:
    explicit PanelStatus(QWidget *parent = 0);
    ~PanelStatus();
    bool connectState;
    QMap<QString, QString> configuration;
    void sendMessage(QString message) {emit messageOut(message.toUtf8());}


public slots:
    void initialize(QMap<QString, QString> config);
    void updateConnectionState(bool state) {connectState = state;}
    void parseMessage(QByteArray);

signals:
    void initializePanel(QMap<QString, QString>);
    void messageIn(QByteArray);
    void messageOut(QByteArray);
    void panelStatus(QString);
    void connectionState(bool);
    void getConnectionState();

private slots:

private:
    Ui::PanelStatus *ui;
    QGraphicsPixmapItem *aiBackground;
    QGraphicsPixmapItem *aiCompassBackground;
    QGraphicsPixmapItem *aiDial;
    QGraphicsPixmapItem *aiCompass;
    QGraphicsScene *aiScene;
    QGraphicsScene *leftScene;
    QGraphicsScene *rightScene;
    QGraphicsEllipseItem *leftStick;
    QGraphicsEllipseItem *rightStick;
    QGraphicsTextItem *altitudeText;
    QGraphicsTextItem *batteryText;
    QGraphicsTextItem *pitchText;
    QGraphicsTextItem *rollText;
    float roll;
    float pitch;
    float posThrottle;
    float posYaw;
    float posPitch;
    float posRoll;
    float altitude;
    float heading;
    int motorArmed;
    int altitudeHold;
    int motorCount;
    QString flightConfig;
    QList<int> motorPower;
    QList<float> receiverChannel;
    float batteryPower;
    int flightMode;


    float scale(float value, float inputMin, float inputMax, float outputMin, float outputMax);
    void movePitchRoll(float rollAngle, float pitchAngle);
    void updateButton(QLabel *button, QString text, QString color);
    void updateMotors();
    void updateSticks();
    void updateButtons();
    void updateTextStatus();
};

#endif // PANEL_STATUS_H
