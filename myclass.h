#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QVariant>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

    void SendText();

signals:
    void sig_disp(QVariant strInfo);

public slots:
    void testSlot2();

};

#endif // MYCLASS_H
