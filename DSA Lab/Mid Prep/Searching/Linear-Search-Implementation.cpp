#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 13, 7, 10, 34, 57, 20};
    int size = 7;
    int key = 10, pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            pos = 1;
            // pos = i + 1;// for ouput the position too
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << "Found\n";
    }

    return 0;
}