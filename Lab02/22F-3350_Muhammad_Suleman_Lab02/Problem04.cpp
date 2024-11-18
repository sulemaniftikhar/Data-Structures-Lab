
#include <iostream>

using namespace std;

int main()
{
    int *ptr = new int;
    *ptr = 42;
    delete ptr;

    // this statement will throw dangling ptr exception
    //*ptr = 20;
    if (ptr == nullptr)
    {
        cout << "Not a dangling pointer" << endl;
    }
    else
    {
        cout << "Dangling pointer" << endl;
    }
    cout << "Time: " << __TIME__ << endl;
    system("pause");
    return 0;
}