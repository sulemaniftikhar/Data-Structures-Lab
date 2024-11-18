#include <iostream>

using namespace std;

// function prototypes
int max(int *arr, int size);
int min(int *arr, int size);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum value: " << max(arr, size) << endl;
    cout << "Minimum value: " << min(arr, size) << endl;

    delete[] arr;

    system("pause");
    return 0;
}

// finding max
int max(int *arr, int size)
{
    int Max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

// finding min
int min(int *arr, int size)
{
    int Min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}