#ifndef SERVICE_H
#define SERVICE_H

#pragma once

#include <QObject>
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
        explicit Service(QString const & name, unsigned int id, unsigned int timeout, QString const & config, QObject * pParent = NULL);

        virtual ~Service()
        {
        }

        QString name() const;
        QString getArguments() const;
        unsigned int id() const;
        unsigned int timeout() const;
        bool IsRunning();

        void setArguments(const QStringList & args);

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
        QString m_ConfigFile;
        bool m_IsRunning;
        QMutex m_CSShutdown;
        QMutex m_CSKeepAlive;
        QWaitCondition m_WaitKeepAlive;
    };
}

#endif // SERVICE_H

