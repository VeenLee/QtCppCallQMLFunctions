#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

void MyClass::SendText()
{
    emit sig_disp("text form c++");
}
