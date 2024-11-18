#include <iostream>

using namespace std;

// function prototypes
void bubbleSort(int *arr, int size);
void displayArray(int *arr, int size);

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

    cout << "Array before sorting: ";
    displayArray(arr, size);

    bubbleSort(arr, size);

    cout << "Array after sorting: ";
    displayArray(arr, size);

    delete[] arr;

    system("pause");
    return 0;
}

// bubble sort algorithm
void bubbleSort(int *arr, int size)
{
    bool swapping;
    for (int i = 0; i < size - 1; i++)
    {
        swapping = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapping = true;
            }
        }
        if (swapping == false)
        {
            break;
        }
    }
}

// function to display array
void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}