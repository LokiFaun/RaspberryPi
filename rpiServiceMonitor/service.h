#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QStringList>
#include <QWaitCondition>

namespace rpi
{

class Service : public QThread
{
    Q_OBJECT
public:
    Service(QString const & name, unsigned int id, unsigned int timeout, QObject * pParent = NULL);

    QString getName() const;
    QString getArguments() const;
    unsigned int getId() const;
    unsigned int getTimeout() const;
    bool IsRunning();

    void setArguments(const QStringList &args);

    void keepAlive();
    void stop();

signals:
    void Timeout(unsigned int id);

private:

    virtual void run();

    QString m_Name;
    QStringList m_Arguments;
    unsigned int m_Id;
    unsigned int m_Timeout;
    bool m_IsRunning;
    QMutex m_CSShutdown;
    QMutex m_CSKeepAlive;
    QWaitCondition m_WaitKeepAlive;
};

}

#endif // SERVICE_H
