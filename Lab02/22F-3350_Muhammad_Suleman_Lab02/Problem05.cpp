#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    srand(time(0));
    int arr1[1000];
    int arr2[1000];
    int arr3[50];
    int arr4[50];
    for (int i = 0; i < 50; i++)
    {
        arr3[i] = rand() % 100;
        arr4[i] = rand() % 100;
    }
    for (int i = 0; i < 1000; i++)
    {
        arr1[i] = 1000 - i;
        arr2[i] = 1000 - i;
    }

    auto startBubbleSort = high_resolution_clock::now();
    bubbleSort(arr1, 1000);
    auto endBubbleSort = high_resolution_clock::now();
    auto bubbleSortDuration = duration_cast<nanoseconds>(endBubbleSort - startBubbleSort);

    auto startInsertionSort = high_resolution_clock::now();
    insertionSort(arr2, 1000);
    auto endInsertionSort = high_resolution_clock::now();
    auto insertionSortDuration = duration_cast<nanoseconds>(endInsertionSort - startInsertionSort);

    cout << "Execution time for Bubble Sort: " << bubbleSortDuration.count() << " nanoseconds" << endl;
    cout << "Execution time for Insertion Sort: " << insertionSortDuration.count() << " nanoseconds" << endl;

    startBubbleSort = high_resolution_clock::now();
    bubbleSort(arr3, 50);
    endBubbleSort = high_resolution_clock::now();
    bubbleSortDuration = duration_cast<nanoseconds>(endBubbleSort - startBubbleSort);

    startInsertionSort = high_resolution_clock::now();
    insertionSort(arr4, 50);
    endInsertionSort = high_resolution_clock::now();
    insertionSortDuration = duration_cast<nanoseconds>(endInsertionSort - startInsertionSort);

    cout << "Execution time for Bubble Sort: " << bubbleSortDuration.count() << " nanoseconds" << endl;
    cout << "Execution time for Insertion Sort: " << insertionSortDuration.count() << " nanoseconds" << endl;
    cout << "Time: " << __TIME__ << endl;

    return 0;
}