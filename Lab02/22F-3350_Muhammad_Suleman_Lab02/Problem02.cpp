#include <iostream>

using namespace std;

int lengthOfStr(char *str)
{
    const char *ptr;
    int len = 0;

    for (ptr = str; *ptr != '\0'; ptr++)
    {
        len++;
    }
    return len;
}

char *concatenateStr(char *str1, char *str2)
{
    int len1 = 0;
    int len2 = 0;

    // finding lengths of strings
    len1 = lengthOfStr(str1);
    len2 = lengthOfStr(str2);

    char *result = new char[len1 + len2 + 1];

    // concatenation  of strings
    int i = 0;
    for (; i < len1; i++)
    {
        result[i] = str1[i];
    }
    for (int j = 0; j < len2; j++, i++)
    {
        result[i] = str2[j];
    }
    result[i] = '\0';

    return result;
}

void reverseStr(char *str)
{
    char *start = str;
    char *end = str;

    while (*end != '\0')
    {
        end++;
    }
    end--;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    char *str1 = "Hello";
    cout << "String1: " << str1 << endl;
    cout << "Length of String1: " << lengthOfStr(str1) << endl;
    char *str2 = "World";
    cout << "String2: " << str2 << endl;
    cout << "Length of String2: " << lengthOfStr(str2) << endl;

    char *str3 = concatenateStr(str1, str2);
    cout << "String3: " << str3 << endl;
    cout << "Length of String3: " << lengthOfStr(str3) << endl;
    cout << "Time: " << __TIME__ << endl;

    delete[] str3;
    str3 = nullptr;

    system("pause");
    return 0;
}