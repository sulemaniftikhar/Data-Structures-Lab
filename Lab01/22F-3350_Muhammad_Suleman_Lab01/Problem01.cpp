#include <iostream>

using namespace std;
// function prototypes
int *inputArray(int &size);
void swapArrays(int *&arr1, int *&arr2, int &size1, int &size2);
void displayArray(int *arr, int size);

int main()
{
    int size1 = 100;
    int *arr1 = inputArray(size1);

    int size2 = 100;
    int *arr2 = inputArray(size2);

    cout << "Before swapping:" << endl;
    cout << "Array 1" << endl;
    displayArray(arr1, size1);

    cout << "Array 2" << endl;
    displayArray(arr2, size2);

    swapArrays(arr1, arr2, size1, size2);

    cout << "After swapping:" << endl;
    cout << "Array 1" << endl;
    displayArray(arr1, size1);

    cout << "Array 2" << endl;
    displayArray(arr2, size2);

    delete[] arr1;
    delete[] arr2;

    system("pause");
    return 0;
}
// takes input form user
int *inputArray(int &size)
{
    int *arr = new int[size];
    int i = 0;
    int value;
    cout << "Enter elements for array (enter -1 to stop): ";
    cin >> value;
    while (value != -1)
    {
        arr[i++] = value;
        cin >> value;
    }
    size = i;
    return arr;
}

// swap array data
void swapArrays(int *&arr1, int *&arr2, int &size1, int &size2)
{
    int *temp = arr1;
    arr1 = arr2;
    arr2 = temp;

    int tempSize = size1;
    size1 = size2;
    size2 = tempSize;
}
// outputs array
void displayArray(int *arr, int size)
{
    cout << "Array Data: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}