#pragma once
#include <QDateTime>

class PathGenerator
{
protected:
    QString datePath(const QString &suffix)
    {
        return QDateTime::currentDateTime().toString("dd-MM-yyyy/hh-mm-ss.") + suffix;
    }
};
