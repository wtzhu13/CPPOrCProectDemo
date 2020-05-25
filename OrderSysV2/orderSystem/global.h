#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include <QtDebug>

extern int globalIndex;
extern QString userName;
extern QString userID;

class GlobalFunc
{
public:
    GlobalFunc();
    ~GlobalFunc();
    static void saveLog();
};

#endif // GLOBAL_H
