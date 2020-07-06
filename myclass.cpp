#include "myclass.h"
#include <QDebug>

#include <sys/stat.h>

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

void MyClass::SendText()
{
    emit sig_disp("text form c++");
}

bool IsPathExist(const std::wstring& s)
{
    struct _stat64i32 buffer;
    char timebuf[26];
    int result = _wstat(s.c_str(), &buffer);

    // Output some of the statistics:
    printf("File size     : %ld\n", buffer.st_size);
    if (S_IFDIR == (buffer.st_mode & S_IFDIR)) {
        printf("File mode     : Dir\n");
    }
    else if (S_IFREG == (buffer.st_mode & S_IFREG)) {
        printf("File mode     : Regular\n");
    }
    else {
        printf("File mode     : %d\n", buffer.st_mode);
    }
    printf("Drive         : %c:\n", buffer.st_dev + 'A');
    errno_t err = ctime_s(timebuf, 26, &buffer.st_mtime);
    if (err)
    {
        printf("Invalid arguments to ctime_s.\n");
    }
    printf("Time modified : %s\n", timebuf);

    return (result == 0);
}
void MyClass::testSlot2()
{
    qDebug() << IsPathExist(L"C:\\Users\\li\\Desktop\\测试");
    qDebug() << "text from QML call";
}
