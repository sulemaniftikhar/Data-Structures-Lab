#include <iostream>

using namespace std;

// function prototypes
int maxByPointer(int *arr, int size, int *Max);
int minByPointer(int *arr, int size, int *Min);
int maxByReference(int *arr, int size, int &Max);
int minByReference(int *arr, int size, int &Min);

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

    // by pointer variables
    int max_val;
    int min_val;
    int *max = &max_val;
    int *min = &min_val;
    cout << "Maximum value by Pointer: " << maxByPointer(arr, size, max) << endl;
    cout << "Minimum value by Pointer: " << minByPointer(arr, size, min) << endl;

    // by reference variables
    int max1;
    int min1;
    cout << "Maximum value by reference: " << maxByReference(arr, size, max1) << endl;
    cout << "Minimum value by reference: " << minByReference(arr, size, min1) << endl;

    // deallocate memory
    delete[] arr;

    return 0;
}

// finding maximum by pointer
int maxByPointer(int *arr, int size, int *Max)
{
    *Max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > *Max)
        {
            *Max = arr[i];
        }
    }
    return *Max;
}

// finding minimum by pointer
int minByPointer(int *arr, int size, int *Min)
{
    *Min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < *Min)
        {
            *Min = arr[i];
        }
    }
    return *Min;
}

// finding maximum by reference
int maxByReference(int *arr, int size, int &Max)
{
    Max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

// finding minimum by reference
int minByReference(int *arr, int size, int &Min)
{
    Min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}