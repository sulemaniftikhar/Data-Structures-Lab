#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    srand(time(0));
    int arr1[1000];
    int arr2[1000];
    int arr3[50];
    int arr4[50];
    int max;
    int min;
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

    cout << "\nArray 1 of size 1000\n"
         << endl;
    auto startTime = high_resolution_clock::now();
    max = findMax(arr1, 1000);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Max: " << duration.count() << " nanoseconds" << endl;

    startTime = high_resolution_clock::now();
    max = findMin(arr1, 1000);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Min: " << duration.count() << " nanoseconds" << endl;

    cout << "\nArray 2 of size 1000\n"
         << endl;
    startTime = high_resolution_clock::now();
    max = findMax(arr2, 1000);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Max: " << duration.count() << " nanoseconds" << endl;

    startTime = high_resolution_clock::now();
    max = findMin(arr2, 1000);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Min: " << duration.count() << " nanoseconds" << endl;

    cout << "\nArray 3 of size 50\n"
         << endl;
    startTime = high_resolution_clock::now();
    max = findMax(arr3, 50);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Max: " << duration.count() << " nanoseconds" << endl;

    startTime = high_resolution_clock::now();
    max = findMin(arr3, 50);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Min: " << duration.count() << " nanoseconds" << endl;

    cout << "\nArray 4 of size 50\n"
         << endl;
    startTime = high_resolution_clock::now();
    max = findMax(arr4, 50);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Max: " << duration.count() << " nanoseconds" << endl;

    startTime = high_resolution_clock::now();
    max = findMin(arr4, 50);
    endTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Duration of finding Min: " << duration.count() << " nanoseconds" << endl;

    cout << "Time: " << __TIME__ << endl;

    return 0;
}