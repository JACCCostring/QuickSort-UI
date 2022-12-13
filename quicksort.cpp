#include "quicksort.h"

quicksort::quicksort(QObject *parent) : QObject(parent){}

void quicksort::generateElements(QString numElements)
{
    int numElem = numElements.toInt();
    //creating new threaded obj
    heavyLifting *worker = new heavyLifting(numElem, 0);
    //connecting signals fo threaded obj
    connect(worker, &heavyLifting::finished, this, [=](){ //lambda
        m_elements = worker->returnElementsValues();
        worker->returnElementsValues().clear();
        emit elementsChanged(); //to notify pattern changed UI
    });
    //start thread
    worker->start();
}

void quicksort::clearElements()
{
    m_elements.clear();
}

void quicksort::startSorting()
{
    int arr_size = m_elements.size();
    int newArr[arr_size];

    for(int i = 0; i <= arr_size; i++) //init... array
        newArr[i] = 0;

    //transfering data from Qt container to std array
    for(int i = 0; i< arr_size; i++)
        newArr[i] = m_elements[i].toInt();
    //calling to sort elements
    quickSort(newArr, 0, arr_size);
    getArrayBack(newArr, arr_size);
    //emiting signal that is ready to read again in QML side
    emit elementsChanged();
}

void quicksort::swapElements(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int quicksort::partition(int arr[], int start, int end)
{
    int pivotIndex = start;
    int pivotValue = arr[end];
    //loop
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivotValue)//if i element is  < then pivotValue then
        {
            swapElements(arr, i, pivotIndex);//swaping
            pivotIndex++;//move pivotIndex to next position
        }
    }
    swapElements(arr, pivotIndex, end); //swaping pivotValue with last pivotIndex position
    return pivotIndex;
}

void quicksort::getArrayBack(int arr[], int siz)
{
    clearElements();

    for(int i = 0; i <= siz; i++)
        m_elements.append(arr[i]);

    for(int i = 0; i <= siz; i++) //init.. array all elements to 0 before using it
        arr[i] = 0;
}

void quicksort::quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int index = partition(arr, start, end); //getting pivot index
    quickSort(arr, start, index - 1); //recursivly call quicksort from start to index
    quickSort(arr, index + 1, end); //recursivly call quicksort from index to end
}

const QVariantList &quicksort::elements() const
{
    return m_elements;
}
