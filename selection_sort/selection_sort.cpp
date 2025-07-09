#include <iostream>
using namespace std;

void selectionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < a[j])
            {
                j = k;
            }
        }
        // Swap the smallest found element with the current element
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    // get size of array from user how many eleement would add
    int n;
    cout << "Enter the size of array you want to sort: ";
    cin >> n;
    // create array with  enterd value
    int a[n];

    cout << "Enter " << " " << n << " numbers: ";
    // loop over with determind size to fill the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //alert before sorting
    cout << "Before sort: ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;
    // sorting
    selectionSort(a, n);
    //after
    cout << "after sort: ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;

    return 0;
}
