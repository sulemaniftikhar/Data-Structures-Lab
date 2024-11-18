#include <iostream>

using namespace std;

void findIntersection(int array1[], int size1, int array2[], int size2, int result[], int &size3)
{
    size3 = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (array1[i] == array2[j])
            {
                bool isDuplicate = false;
                for (int k = 0; k < size3; k++)
                {
                    if (array1[i] == result[k])
                    {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate)
                {
                    result[size3++] = array1[i];
                }
                break;
            }
        }
    }
}

int main()
{
    int array1[] = {1, 7, 3, 4, 5, 6, 9};
    int array2[] = {5, 3, 5, 7};
    int array3[100];
    int size1 = 7;
    int size2 = 4;
    int size3;

    findIntersection(array1, size1, array2, size2, array3, size3);

    cout << "Intersection: ";
    for (int i = 0; i < size3; i++)
    {
        cout << array3[i] << " ";
    }
    cout << endl;

    cout << "Time: " << __TIME__ << endl;
    system("pause");
    return 0;
}