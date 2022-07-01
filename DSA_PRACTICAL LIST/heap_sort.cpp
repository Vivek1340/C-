#include<iostream>
using namespace std;

void heapify(int heap[], int pos, int size)
{
    int largest = pos;
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;

    if (l < size && heap[l] > heap[largest])
        largest = l;
    if (r < size && heap[r] > heap[largest])
        largest = r;
    if (largest != pos)
    {
        swap(heap[largest], heap[pos]);
        heapify(heap, largest, size);
    }
}

void heapSort(int heap[], int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--) // building the heap
    {
        heapify(heap, i, size);
    }

    for (int j = size - 1; j > 0; j--)
    {
        swap(heap[0], heap[j]);
        heapify(heap, 0, j);
    }

    cout << "Sorted Array" << endl;
    for (int k = 0; k < size; k++)
        cout << heap[k] << "\t";
}
int main(){

    int heap[]={-12,-3,-4,1,4,9,4,7,8};
    int size = sizeof(heap)/sizeof(int);
    heapSort(heap,size);
    return 0;
}