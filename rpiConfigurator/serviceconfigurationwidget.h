#ifndef SERVICECONFIGURATIONWIDGET_H__
#define SERVICECONFIGURATIONWIDGET_H__

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class ServiceConfigurationWidget : public QWidget
{
    Q_OBJECT
public:
    ServiceConfigurationWidget(int nr);
    virtual ~ServiceConfigurationWidget();

protected slots:
    void removeService();
    void onIdInputChanged(QString const & newValue);
    void onNameInputChanged(QString const & newValue);
    void onTimeoutInputChanged(QString const & newValue);

signals:
    void idChanged(QWidget * pSender, int id);
    void nameChanged(QWidget * pSender, QString const & name);
    void timeoutChanged(QWidget * pSender, unsigned int timeout);
    void removed(QWidget * pSender);

private:
    QLineEdit * m_pIdBlock;
    QLineEdit * m_pNameBlock;
    QLineEdit * m_pTimeoutBlock;
    QPushButton * m_pRemoveButton;
};

#endif // SERVICECONFIGURATIONWIDGET_H__
