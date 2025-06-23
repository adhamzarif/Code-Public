#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 13, 7, 10, 34, 57, 20};
    int size = 7;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "After Sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}