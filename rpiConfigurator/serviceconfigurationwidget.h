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

    void setConfiguration(int id, QString const & name, unsigned int timeout);

protected slots:
    void removeService();
    void onIdInputChanged(QString const & newValue);
    void onNameInputChanged(QString const & newValue);
    void onTimeoutInputChanged(QString const & newValue);

signals:
    void idChanged(int nr, int id);
    void nameChanged(int nr, QString const & name);
    void timeoutChanged(int nr, unsigned int timeout);
    void removed(QWidget * pSender, int nr);

private:
    int m_Number;
    QLineEdit * m_pIdBlock;
    QLineEdit * m_pNameBlock;
    QLineEdit * m_pTimeoutBlock;
    QPushButton * m_pRemoveButton;
};

#endif // SERVICECONFIGURATIONWIDGET_H__
