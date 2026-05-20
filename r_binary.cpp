#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[],
                          int low,
                          int high,
                          int key,
                          int &comparisons) {

    if(low > high)
        return -1;

    comparisons++;

    int mid =
    (low + high) / 2;

    if(arr[mid] == key)
        return mid;

    else if(key < arr[mid])

        return recursiveBinarySearch(
            arr,
            low,
            mid - 1,
            key,
            comparisons
        );

    else

        return recursiveBinarySearch(
            arr,
            mid + 1,
            high,
            key,
            comparisons
        );
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
    recursiveBinarySearch(
        arr,
        0,
        n - 1,
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