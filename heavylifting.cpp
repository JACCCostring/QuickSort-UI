#include "heavylifting.h"

heavyLifting::heavyLifting(int dataSize, QObject *parent) :
    QThread(parent),
    mDataSize(dataSize)
{}

QVariantList &heavyLifting::returnElementsValues()
{
    return m_elements;
}

void heavyLifting::run()
{
    for(int i = 0; i< mDataSize; i++){
        m_elements.append(arc4random_uniform(MAX_HEIGHT));
    }
}
