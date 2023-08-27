#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays into one sorted array in descending order
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the left and right subarrays
    vector<int> left_arr(n1);
    vector<int> right_arr(n2);

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the main array in descending order
    while (i < n1 && j < n2) {
        if (left_arr[i] >= right_arr[j]) { // Changed the comparison operator to >=
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left and right subarrays
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// Recursive function to perform Merge Sort in descending order
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort the left and right halves recursively
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array in descending order: ";
    printArray(arr);

    return 0;
}
