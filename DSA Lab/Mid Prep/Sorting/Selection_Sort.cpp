#include <iostream>
void swap(int& a, int& b) {
    int temp = a;
    a = b;       
    b = temp;     
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx; 

    for (i = 0; i < n - 1; i++) {

        min_idx = i;

        
        for (j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(arr[min_idx], arr[i]); 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
}


int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Example array

    int n = sizeof(arr) / sizeof(arr[0]); 

    std::cout << "Original array: ";
    printArray(arr, n); // Print the array before sorting

    selectionSort(arr, n); // Call the selectionSort function to sort the array

    std::cout << "Sorted array: ";
    printArray(arr, n); // Print the array after sorting

    return 0; // Indicate successful execution
}
