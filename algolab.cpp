#include <iostream>
using namespace std;
#include <algorithm>

void removeDuplicates(int arr[], int &n) {
    if (n == 0 || n == 1) return;

    sort(arr, arr + n);

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];

    n = j;


    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {
    int arr[] = {1, 2, 2, 4, 4, 5, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, n);

    return 0;
}

