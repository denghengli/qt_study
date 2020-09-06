#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataconfig : public QObject
{
    Q_OBJECT
public:
    explicit dataconfig(QObject *parent = 0);
    QMap<int, QVector<QVector<int> > > mData;//键值对

signals:

public slots:
};

#endif // DATACONFIG_H
