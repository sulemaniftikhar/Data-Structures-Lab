#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Optimized Bubble Sort
long bubbleSort(int arr[], int n)
{
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
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
    return comparisons;
}

// Selection Sort
long selectionSort(int arr[], int n)
{
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return comparisons;
}

// Optimized Insertion Sort
long insertionSort(int arr[], int n)
{
    long comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparisons += (j >= 0);
        arr[j + 1] = key;
    }
    return comparisons;
}

void randomDataset(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void sortAndPrint(int dataset[], int size)
{
    int *bubbleData = new int[size];
    int *selectionData = new int[size];
    int *insertionData = new int[size];

    for (int i = 0; i < size; i++)
    {
        bubbleData[i] = dataset[i];
        selectionData[i] = dataset[i];
        insertionData[i] = dataset[i];
    }

    long bubbleComparisons = bubbleSort(bubbleData, size);
    long selectionComparisons = selectionSort(selectionData, size);
    long insertionComparisons = insertionSort(insertionData, size);

    cout << "Dataset size: " << size << endl;
    cout << "Bubble Sort: " << bubbleComparisons << " comparisons" << endl;
    cout << "Selection Sort: " << selectionComparisons << " comparisons" << endl;
    cout << "Insertion Sort: " << insertionComparisons << " comparisons" << endl;
    cout << endl;

    delete[] bubbleData;
    delete[] selectionData;
    delete[] insertionData;
}

int main()
{
    srand(time(0));
    int sizes[] = {50, 100, 1000, 100000};

    for (int size : sizes)
    {
        int *dataset = new int[size];
        randomDataset(dataset, size);

        sortAndPrint(dataset, size);

        delete[] dataset;
    }

    return 0;
}