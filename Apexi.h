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

    Q_INVOKABLE void writeDashfile(const QString &gauge1,const QString &gauge2,const QString &gauge3,const QString &gauge4,const QString &gauge5,const QString &gauge6);
        
private:
    DashBoard *m_dashboard;
    
};


#endif // APEXI_H

