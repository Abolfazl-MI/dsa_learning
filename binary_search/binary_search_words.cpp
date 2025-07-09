#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 
int binary_search(const vector<string> &books, const string &target)
{
    int left = 0;
    int r = books.size() - 1;
    while (left <= r)
    {
        int mid = left + (r - left) / 2;
        if (books[mid] == target)
        {
            return mid;
        }
        else if (books[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<string> books = {
        "Apple", "Banana", "Carrot", "Mango", "Zebra"};
    string input;
    cout << "Enter book name to search: ";
    getline(cin, input);

    int result = binary_search(books, input);

    if (result != -1)
    {
        cout << "Book found at index: " << result << endl;
    }
    else
    {
        cout << "Book not found." << endl;
    }

    return 0;
}