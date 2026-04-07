#include <iostream>
#include <vector>
using namespace std;

// Binary Search
int binarySearch(vector<int> arr, int tar) // Iterative
{
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // Optimization
        if (tar > arr[mid])
        {
            st = mid + 1;
        }
        else if (tar < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binarySearch2(vector<int> arr, int tar, int str, int end) // Recursion
{
    if (str <= end)
    {
        int mid = str + (end - str) / 2;
        if (tar > arr[mid])
        { // 2nd half
            return binarySearch2(arr, tar, mid + 1, end);
        }
        else if (tar < arr[mid])
        {
            return binarySearch2(arr, tar, str, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// Insertion Sort
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] < curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; // replacing the current in its correct position
    }
}

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}

// Selection Sort
void SelectionSort(int arr[], int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i; // unsorted part of array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

// Merge Sort
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, st, mid, end);
    }
}

// Print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    // int tar1 = 12;

    // // cout << binarySearch2(arr1, tar1, 0, arr1.size() - 1) << endl;

    // vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    // int tar2 = 0;

    // // cout << binarySearch(arr2, tar2) << endl;

    // int n = 5;
    // int arr[] = {4, 1, 5, 2, 3};

    // cout << "Before Insertion sort: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // InsertionSort(arr, n);

    // cout << "After Insertion sort: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // int n = 5;
    // int arr[] = {4, 1, 5, 2, 3};
    // printArray(arr, n);
    // bubbleSort(arr, n);
    // InsertionSort(arr, n);
    // printArray(arr, n);

    vector<int> arr = {12, 31, 35, 8, 32, 17};
    for (int val : arr)
    {
        cout << val << " ";
    }
        cout << endl;
    mergeSort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}