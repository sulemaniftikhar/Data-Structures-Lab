#include <iostream>

using namespace std;

int BinarySearch(int *arr, int low, int high, int search)
{
    if (low <= high)
    {
        // error in case if size goes high;
        int mid = low + (high - low) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] > search)
        {
            return BinarySearch(arr, low, mid - 1, search);
        }
        else
        {
            return BinarySearch(arr, mid + 1, high, search);
        }
    }
    return -1;
}

int main()
{
    int arr[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    cout << BinarySearch(arr, 0, 20, 10) << endl;

    return 0;
}