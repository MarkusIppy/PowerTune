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
QString Auxname1;
QString Auxname2;
QString Modelname;
int Model = 0;
int Logging =3;
int Loggerstat;
int auxval1;
int auxval2;
int auxval3;
int auxval4;
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



void Apexi::Auxcalc (const QString &unitaux1,const qreal &an1V0,const qreal &an2V5,const QString &unitaux2,const qreal &an3V0,const qreal &an4V5)
{
    qreal aux1min = an1V0;
    qreal aux2max = an2V5;
    qreal aux3min = an3V0;
    qreal aux4max = an4V5;
    QString Auxunit1 = unitaux1;
    QString Auxunit2 = unitaux2;
    
    Apexi::calculatorAux(aux1min,aux2max,aux3min,aux4max,Auxunit1,Auxunit2);
}
/*
void Apexi::decodeAux(QByteArray rawmessagedata)
{
    fc_aux_info_t* info=reinterpret_cast<fc_aux_info_t*>(rawmessagedata.data());
    
    
    packageAux[0] = mul[29] * info->AN1 + add[29];
    packageAux[1] = mul[30] * info->AN2 + add[30];
    packageAux[2] = mul[31] * info->AN3 + add[31];
    packageAux[3] = mul[32] * info->AN4 + add[32];
    
    //Analog1
    AN1AN2calc = (((((auxval2-auxval1)*0.2) * (packageAux[0] - packageAux[1]))) + auxval1);
    AN3AN4calc = ((((auxval4-auxval3)*0.2) * (packageAux[2] - packageAux[3])) + auxval3);
    m_dashboard->setauxcalc1(AN1AN2calc);
    m_dashboard->setauxcalc2(AN3AN4calc);
    
}
*/

void Apexi::calculatorAux(qreal aux1min,qreal aux2max,qreal aux3min,qreal aux4max,QString Auxunit1,QString Auxunit2)
{
    auxval1 = aux1min;
    auxval2 = aux2max;
    auxval3 = aux3min;
    auxval4 = aux4max;
    Auxname1 = Auxunit1;
    Auxname2 = Auxunit2;
   // qDebug() << Auxunit1<<auxval1 <<auxval2 <<Auxunit2 << auxval3<<auxval4;
    
}

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
