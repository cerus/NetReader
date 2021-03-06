#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>

class DataScanSocket;
class QThread;
class Classifier;
class QTcpSocket;
class QString;
class Calculation : public QObject
{    
    Q_OBJECT
private slots:
    void calc();
    void stoprunning();
    void statesave();
    //void changeClassifier();       // change the classifier to use
    void setPara(int traintrials);
    void setObj(QString objlabel);

signals:
    void Printstatus(const QString& );

public:
    Calculation(DataScanSocket *tcpsocket, int trials, QString& fip, ushort fport, QObject *parent = 0 );
    ~Calculation();
    bool m_running;

private:
    int            m_objlabel;
    bool           m_saving;
    bool           m_train;
    bool           m_test;
    DataScanSocket *dsocket;
    unsigned int   m_samplesize;
    int            m_trials;       // number of trials used for training
    double         *m_trainData;   // store data of several trials which have been preprocessed, samples * features
    double         *m_classTag;    // class tag for each sample
    Classifier     *m_classifier;  // classifier used
    QTcpSocket     *m_feedbackSocket;  // send result of classification to users
    QString        m_fipadd;
    ushort         m_fport;

//    void removeEog_filter();
};
#endif // CALCULATION_H
