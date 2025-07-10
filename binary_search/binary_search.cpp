#include <iostream>
using namespace std;

int binary_search(int *a, const int x, const int n)
{
    for (int l = 0, r = n - 1; l <= r;)
    {
        int middle = (l + r) / 2;
        if (x > a[middle])
        {
            l = middle + 1;
        }
        if (x < a[middle])
        {
            r = middle - 1;
        }
        if (x == a[middle])
        {
            return middle;
        }
    }
    return -1;
}

int main()
{
    // get size of array from user how many eleement would add
    int n;
    cout << "Enter the size of array you want to search: ";
    cin >> n;
    // create array with  enterd value
    int a[n];

    cout << "Enter " << " " << n << " numbers: ";
    // loop over with determind size to fill the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cout << "Enter the selected number: " << endl;
    cin >> x;
    // alert before search
    cout << "searning... " << endl;
    // result
    int result = binary_search(a, x, n);
    cout << "result is : " << " " << result << endl;
}