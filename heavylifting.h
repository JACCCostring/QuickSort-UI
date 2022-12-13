#ifndef HEAVYLIFTING_H
#define HEAVYLIFTING_H

#include <QVariantList>
#include <QThread>
#include <random>
#include <QObject>

#define MAX_HEIGHT 200

class heavyLifting : public QThread
{
    Q_OBJECT
public:
    explicit heavyLifting(int dataSize = 0, QObject *parent = nullptr);
    //method
    QVariantList &returnElementsValues();
protected:
    void run() override;

private:
    QVariantList m_elements;
    int mDataSize;
};

#endif // HEAVYLIFTING_H
