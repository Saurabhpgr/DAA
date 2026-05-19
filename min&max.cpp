#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Start time measurement
    clock_t start = clock();

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++) {

        if(arr[i] > max) {
            max = arr[i];
        }

        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // End time measurement
    clock_t end = clock();

    double execution_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nMaximum Element = " << max;
    cout << "\nMinimum Element = " << min;

    cout << "\nExecution Time = "
         << execution_time
         << " seconds\n";

    return 0;
}