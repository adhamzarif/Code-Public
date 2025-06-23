#include <iostream>
using namespace std;

// Custom swap function
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // place pivot in the correct position
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Main function
int main()
{
    int arr[] = {5, 13, 7, 10, 34, 57, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
