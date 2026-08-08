#include <iostream>
using namespace std;

// Callback for ascending order
bool ascending(int a, int b)
{
    return a < b;
}

// Callback for descending order
bool descending(int a, int b)
{
    return a > b;
}

// Merge two sorted portions
void merge(int arr[], int left, int mid, int right,
           bool (*callback)(int, int))
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int size = right - left + 1;
    int* temp = new int[size];

    while (i <= mid && j <= right)
    {
        if (callback(arr[i], arr[j]))
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Remaining elements from left half
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Remaining elements from right half
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    delete[] temp;
}

// Merge Sort
void mergeSort(int arr[], int left, int right,
               bool (*callback)(int, int))
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, callback);
    mergeSort(arr, mid + 1, right, callback);

    merge(arr, left, mid, right, callback);
}

// Print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int size = sizeof(arr) / sizeof(arr[0]);

    int option = 2;

    if (option == 1)
        mergeSort(arr, 0, size - 1, ascending);
    else
        mergeSort(arr, 0, size - 1, descending);

    printArray(arr, size);

    return 0;
}
