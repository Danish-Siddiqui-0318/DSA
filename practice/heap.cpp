#include <iostream>
using namespace std;

class MaxHeap
{
    int arr[100];
    int size;

public:
    // MaxHeap()
    // {
    //     size = 0;
    // }
    MaxHeap()
    {
        size = 0;
    }

    void insert()
    {
        size++;
        arr[size] = val;
        int i = size;
        // headpify Up
        while (i > 1 && arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    // insert(int val)
    // {
    //     size++;
    //     arr[size] = val;
    //     int i = size;
    //     while (i > 1 && arr[i / 2])
    //     {
    //         swap(arr[i], arr[i / 2]);
    //         i = i / 2;
    //     }
    // }
    // // Heapify Down
    // void heapify(int i)
    // {
    //     while (true)
    //     {
    //         int left = i * 2;
    //         int right = i * 2 + 1;
    //         int largest = i;

    //         if (left <= size && arr[left] > arr[largest])
    //         {
    //             largest = left;
    //         }

    //         if (right <= size && arr[right] > arr[largest])
    //         {
    //             largest = right;
    //         }
    //         if (largest == 1)
    //         {
    //             break;
    //         }
    //         swap(arr[i], arr[largest]);
    //         i = largest;
    //     }
    // }
    // headpify down
    void heapify(int i)
    {
        while (true)
        {
            int left = i * 2;
            int right = i * 2 + 1;
            int largest = i;
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (largest == i)
            {
                break;
            }
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    // void deleteRoot()
    // {
    //     if (size == 0)
    //     {
    //         return;
    //     }
    //     arr[1] = arr[size];
    //     size--;
    //     heapify(1);
    // }
    void deleteRoot()
    {
        if (size == 0)
        {
            return;
        }
        arr[1] = arr[size];
        size--;
        heapify(1);
    }

    // void heapSort()
    // {
    //     int tempSize = size;
    //     while (size > 1)
    //     {
    //         swap(arr[1], arr[size]);
    //         size--;
    //         heapify(1);
    //     }
    //     size = tempSize;
    // }
    void heapSort()
    {
        int tempSize = size;
        while (size > 1)
        {
            swap(arr[1], arr[size]);
            size--;
            heapify(1);
        }
        size = tempSize;
    }

    // void print()
    // {
    //     for (int i = 1; i <= size; i++)
    //     {
    //         cout << arr[i]<<endl;
    //     }
    // }

    void print()
    {
        for (int val : arr)
        {
            cout << arr[val] << endl;
        }
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

    cout << "Heap: ";
    h.print();

    h.heapSort();
    cout << "Sorted: ";
    h.print();

    return 0;
}
