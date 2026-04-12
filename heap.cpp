#include <iostream>
using namespace std;

class MaxHeap
{
    int arr[100];
    int size;

public:
    MaxHeap()
    {
        size = 0;
    }

    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        while (index <= size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[right] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

    void insert(int val)
    {
        size++;
        arr[size] = val;
        heapifyUp(size);
    }

    void heapSort()
    {
        int originalSize = size;
        while (size > 1)
        {
            swap(arr[1], arr[size]);
            size--;
            heapifyDown(1);
        }
        size = originalSize;
    }

    void deleteValue(int value)
    {
        int index = -1;
        for (int i = 1; i <= size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Value not found in heap" << endl;
             return;
        }
        arr[index] = arr[size];
        size--;
        if (index > 1 && arr[index / 2] < arr[index])
        {
            heapifyUp(index);
        }
        else
        {
            heapifyDown(index);
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap before sorting" << endl;
    h.print();
    h.heapSort();
    cout << "Array after sorting";
    h.print();
    h.deleteValue(52);
    h.print();

    return 0;
}