#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    int idx = -1;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[++idx] << "  ";
    }
    cout << endl;

    return 0;
}