#include <iostream>
using namespace std;

int iterativeBinarySearch(int arr[],
                          int n,
                          int key,
                          int &comparisons) {

    int low = 0;
    int high = n - 1;

    while(low <= high) {

        comparisons++;

        int mid =
        (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    int arr[] =
    {10, 20, 30, 40, 50, 60, 70};

    int n =
    sizeof(arr) / sizeof(arr[0]);

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int comparisons = 0;

    int result =
    iterativeBinarySearch(
        arr,
        n,
        key,
        comparisons
    );

    if(result != -1)
        cout << "Element found at index "
             << result;

    else
        cout << "Element not found";

    cout << "\nComparisons = "
         << comparisons;

    return 0;
}