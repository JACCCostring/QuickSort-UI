#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include <QVariantList>
#include <random>
#include "heavylifting.h"

class quicksort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList elements READ elements NOTIFY elementsChanged)
public:
    explicit quicksort(QObject *parent = nullptr);
    //Q_INVOKABLE methods
    Q_INVOKABLE void generateElements(QString);
    Q_INVOKABLE void clearElements();
    Q_INVOKABLE void startSorting();
    //getter
    const QVariantList &elements() const;

private:
    //normal std methods
    void quickSort(int [], int, int);
    void swapElements(int [], int, int);
    int partition(int [], int, int);
    void getArrayBack(int [], int);

signals:
    void elementsChanged();

private:
    QVariantList m_elements;
};

#endif // QUICKSORT_H
