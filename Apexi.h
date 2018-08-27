#ifndef APEXI_H
#define APEXI_H

#include <QObject>

class DashBoard;

class Apexi : public QObject
{
    Q_OBJECT
    
private:

public:
    explicit Apexi(QObject *parent = 0);
    explicit Apexi(DashBoard *dashboard, QObject *parent = 0);
    Q_INVOKABLE void Auxcalc (const QString &unitaux1,const qreal &an1V0,const qreal &an2V5,const QString &unitaux2,const qreal &an3V0,const qreal &an4V5);
    Q_INVOKABLE void writeDashfile(const QString &gauge1,const QString &gauge2,const QString &gauge3,const QString &gauge4,const QString &gauge5,const QString &gauge6);
        
private:
    DashBoard *m_dashboard;

public slots:

    void calculatorAux(qreal aux1min,qreal aux2max,qreal aux3min,qreal aux4max,QString Auxunit1,QString Auxunit2);


    
};


#endif // APEXI_H

