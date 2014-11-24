#ifndef ABSTRACTAPPENDER_H
#define ABSTRACTAPPENDER_H

#include <QObject>

class AbstractAppender : public QObject
{
  Q_OBJECT
public:
  explicit AbstractAppender(QObject *parent = 0);

signals:

public slots:

};

#endif // ABSTRACTAPPENDER_H
