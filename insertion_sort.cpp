#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<"\n give a number to search ";
    int toSearch;
    cin >> toSearch;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == toSearch)
        {
            cout << "Value is found";
            break;
        }
        else
        {
            cout << "Value is not found";
            break;
        }
    }

    return 0;
}

