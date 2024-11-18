#include <iostream>
#include <string>

using namespace std;

class Record
{
private:
    string name;
    int regNum;
    int marks[3];
    int totalMarks;

public:
    void setData();
    void calTotalMarks();
    void getData();
};

int main()
{
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Record *students = new Record[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter details for student " << i + 1 << endl;
        students[i].setData();
        students[i].calTotalMarks();
    }
    cout << "\nStudent Records:" << endl;
    for (int i = 0; i < N; i++)
    {
        students[i].getData();
    }
    cout << "Time: " << __TIME__ << endl;

    delete[] students;
    students = nullptr;
    system("pause");
    return 0;
}

void Record::setData()
{
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter registration number: ";
    cin >> regNum;
    cout << "Enter marks for three subjects: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> marks[i];
    }
}
void Record::getData()
{
    cout << "Name: " << name << endl;
    cout << "Registration Number: " << regNum << endl;
    cout << "Marks for three subjects: ";
    for (int i = 0; i < 3; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
    cout << "Total Marks: " << totalMarks << endl;
}
void Record::calTotalMarks()
{
    totalMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        totalMarks += marks[i];
    }
}