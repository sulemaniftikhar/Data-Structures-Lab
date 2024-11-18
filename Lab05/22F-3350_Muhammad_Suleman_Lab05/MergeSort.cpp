#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &vec, int begin, int end)
{
    int mid = (begin + end) / 2;

    int size1 = mid - begin + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = vec[begin++];
    }
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = vec[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = begin;

    while (k < size1 && k < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            vec[k++] = arr1[i++];
        }
        else
        {
            vec[k++] = arr2[j++];
        }
    }
    while (k < size1)
    {
        vec[k++] = arr1[i++];
    }
    while (k < size2)
    {
        vec[k++] = arr2[j++];
    }
}

void mergeSORT(vector<int> &vec, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = (begin + end) / 2;
    mergeSORT(vec, begin, mid);
    mergeSORT(vec, mid + 1, end);

    Merge(vec, begin, end);
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < 10; i++)
    {
        cout << vec[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1;
    for (int i = 10; i >= 1; i--)
    {
        vec1.push_back(i * 10);
    }

    printVec(vec1);
    mergeSORT(vec1, 0, 9);
    printVec(vec1);

    return 0;
}

/*
void Merge(vector<int> &vec, int begin, int end)
{
    int mid = (begin + end) / 2;

    int size1 = mid - begin + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    // Populate arr1
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = vec[begin + i];
    }

    // Populate arr2 using the correct index (not incrementing begin)
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = vec[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = begin;

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j]) // Change the condition to <=
        {
            vec[k++] = arr1[i++];
        }
        else
        {
            vec[k++] = arr2[j++];
        }
    }
    while (i < size1)
    {
        vec[k++] = arr1[i++];
    }
    while (j < size2)
    {
        vec[k++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}
*/