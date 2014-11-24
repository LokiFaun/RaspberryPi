#ifndef DEBUGAPPENDER_H
#define DEBUGAPPENDER_H

class DebugAppender : public IAppender
{
    Q_OBJECT
public:
    explicit DebugAppender(QObject *parent = 0);

signals:

public slots:

};

#endif // DEBUGAPPENDER_H
