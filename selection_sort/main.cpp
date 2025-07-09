#include <iostream>
using namespace std;

void selectionSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[j]) {
                j = k;
            }
        }
        // Swap the smallest found element with the current element
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main() {
    int a[5] = {100, 9, 57, 68, 10};

    cout << "Before sort: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    selectionSort(a, 5);

    cout << "After sort: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
