#include "Apexi.h"
#include "dashboard.h"
#include "connect.h"
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QBitArray>
#include <QByteArrayMatcher>
#include <QFile>
#include <QTextStream>



QByteArray rawmessagedata;
QByteArray fullFuelBase;
qreal AN1AN2calc;
qreal AN3AN4calc;
qreal test;

//QBitArray flagArray;
QString Logfile;

QString Modelname;
int Model = 0;
int Logging =3;
int Loggerstat;
;
int requestIndex = 0; //ID for requested data type Power FC
int expectedbytes;
int Bytes;
int Protocol = 0;


Apexi::Apexi(QObject *parent)
    : QObject(parent)
    , m_dashboard(Q_NULLPTR)
{
}

Apexi::Apexi(DashBoard *dashboard, QObject *parent)
    : QObject(parent)
    , m_dashboard(dashboard)
{
}
/*
 *   if (Protocol == 1)
    {
        switch (requestIndex){
        // Old Apexi Structure
        case 0:
            //Init Platform (This returns the Platform String )
            Apexi::writeRequestPFC(QByteArray::fromHex("F3020A"));
            expectedbytes = 11;
            break;
        case 1:
            //Apexi::getSensorStrings();
            Apexi::writeRequestPFC(QByteArray::fromHex("690294"));
            expectedbytes = 83;
            break;
            
            // Live Data
        case 2:
            //Apexi::getAdvData();
            Apexi::writeRequestPFC(QByteArray::fromHex("F0020D"));
            expectedbytes = 33;
            break;
            
        case 3:
            //Apexi::getMapIndices();
            Apexi::writeRequestPFC(QByteArray::fromHex("680295"));
            expectedbytes = 5;
            break;
        case 4:
            //Apexi::getSensorData();
            Apexi::writeRequestPFC(QByteArray::fromHex("6A0293"));
            expectedbytes = 21;
            break;
        case 5:
            //Apexi::getBasic();
            Apexi::writeRequestPFC(QByteArray::fromHex("660297"));
            expectedbytes = 23;
            break;
        case 6:
            //Apexi::getAux();
            Apexi::writeRequestPFC(QByteArray::fromHex("0002FD"));
            expectedbytes = 7;
            
            break;
        }
    }
    
    m_timer.start(1000); //Set timout to 1 second 
}
*/


void Apexi::writeDashfile(const QString &gauge1,const QString &gauge2,const QString &gauge3,const QString &gauge4,const QString &gauge5,const QString &gauge6)
{
//Creates the dashboard file for the Apexi Dash

    QString filename="UserDashApexi.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) )

    {
        QTextStream stream( &file );
        stream << gauge1 << endl;
        stream << gauge2 << endl;
        stream << gauge3 << endl;
        stream << gauge4 << endl;
        stream << gauge5 << endl;
        stream << gauge6 << endl;
    }

    QString filename2="/home/pi/UserDashboards/UserDashApexi.txt";
    QFile file2( filename2 );
    if ( file2.open(QIODevice::ReadWrite  | QIODevice::Truncate | QIODevice::Text) )

    {
        QTextStream stream( &file2 );
        stream << gauge1 << endl;
        stream << gauge2 << endl;
        stream << gauge3 << endl;
        stream << gauge4 << endl;
        stream << gauge5 << endl;
        stream << gauge6 << endl;
    }


}
