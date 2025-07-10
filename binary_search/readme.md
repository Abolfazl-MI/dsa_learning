## Binary Search Algorithm Documentation
This document explains the binary search algorithm implemented in  C++ code. Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

## Prerequisites
For binary search to work correctly, the array `a` **must be sorted in ascending order**. If the array is not sorted, the algorithm will not guarantee correct results.

`binary_search` Function Breakdown

The `binary_search` function takes three arguments:

* `int *a`: A pointer to the integer array where the search will be performed.

* `const int x`: The integer value that needs to be found in the array.

* `const int n`: The total number of elements in the array.

Let's break down its logic step-by-step:
Let's break down its logic step-by-step:

## Step 1: Initialization of Pointersfor 
``` cpp
(int l = 0, r = n - 1; l <= r;)
```
- `l` (left pointer): Initialized to `0`, representing the first index of the current search segment.

- `r` (right pointer): Initialized to `n - 1`, representing the last index of the current search segment.

- The loop continues as long as `l` is less than or equal to `r`.
This condition ensures that the search segment is valid (i.e., the left boundary has not crossed the right boundary).

## Step 2: Calculate the Middle Elementint 
```cpp
    int middle = (l + r) / 2;
```
- In each iteration, the `middle` index of the current search segment is calculated. This is the core idea of dividing the search space in half.

## Step 3: Compare Target with Middle ElementThe 

algorithm then compares the target value `x` with the element at the `middle` index (`a[middle]`). There are three possible outcomes:

### Case 1: Target is Greater than Middle Element
```cpp
if (x > a[middle])
{
    l = middle + 1;
}
```
- If `x` is greater than `a[middle]`, it means x (if present) must be in the right half of the current segment.
- The `l` pointer is updated to `middle + 1`, effectively discarding the left half (including the `middle` element) from the next search.

### Case 2: Target is Less than Middle Element
```cpp
if (x < a[middle])
{
    r = middle - 1;
}
```
- If `x`is less than `a[middle]`, it means `x` `(if present)` must be in the left half of the current segment.
- The `r` pointer is updated to `middle - 1`, effectively discarding the right half (including the middle element) from the next search.

### Case 3: Target is Equal to Middle Element
```cpp
if (x == a[middle])
{
    return middle;
}
```
- If `x` is equal to `a[middle]`, the target element has been found!
- The function immediately returns the `middle` index, which is the position of x in the array.

## Step 4: Element Not Found
```cpp
return -1;
```
- If the loop finishes (i.e., `l` becomes greater than `r`), it means the search segment has become invalid, and the target element `x` was not found in the array.
- In this case, the function returns `-1` to indicate that the element is not present.

## Main Function Breakdown
The `main` function handles user interaction and calls the `binary_search` function:

1.  **Get Array Size:**

    ```cpp
    int n;
    cout << "Enter the size of array you want to search: ";
    cin >> n;
    ```

    * Prompts the user to enter the desired size of the array (`n`) and reads it.

2.  **Create Array:**

    ```cpp
    int a[n];
    ```

    * Declares a variable-length array `a` of size `n`. (Note: Variable-length arrays are a C99 feature and a GCC extension in C++. For standard C++, `std::vector` or dynamic allocation with `new` is preferred).

3.  **Fill Array:**

    ```cpp
    cout << "Enter " << " " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ```

    * Prompts the user to enter `n` numbers and fills the array `a` with these inputs. **It is crucial that the user enters these numbers in sorted order for binary search to work correctly.**

4.  **Get Target Number:**

    ```cpp
    int x;
    cout << "Enter the selected number: " << endl;
    cin >> x;
    ```

    * Prompts the user to enter the number `x` they want to search for.

5.  **Perform Search and Display Result:**

    ```cpp
    cout << "searning... " << endl;
    int result = binary_search(a, x, n);
    cout << "result is : " << " " << result << endl;
    ```

    * Prints a "searching..." message.

    * Calls the `binary_search` function with the array `a`, target `x`, and size `n`.

    * Stores the returned index (or `-1`) in the `result` variable.

    * Prints the final `result`.

