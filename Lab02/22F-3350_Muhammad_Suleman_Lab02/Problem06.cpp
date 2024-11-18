#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    string rollNum;
    int marks;

public:
    // method getters and setters
    void setName(string name)
    {
        this->name = name;
    }
    void setRollNum(string rollNum)
    {
        this->rollNum = rollNum;
    }
    void setMarks(int marks)
    {
        this->marks = marks;
    }

    string getName()
    {
        return name;
    }
    string getRollNum()
    {
        return rollNum;
    }
    int getMarks()
    {
        return marks;
    }
};

int main()
{
    int numOfStudents;
    cout << "Enter the number of students: ";
    cin >> numOfStudents;

    Student *students = new Student[numOfStudents];

    for (int i = 0; i < numOfStudents; i++)
    {
        string name;
        string rollNum;
        int marks;

        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Roll Number: ";
        getline(cin, rollNum);
        cout << "Marks: ";
        cin >> marks;

        students[i].setName(name);
        students[i].setRollNum(rollNum);
        students[i].setMarks(marks);
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: " << students[i].getName() << endl;
        cout << "Roll Number: " << students[i].getRollNum() << endl;
        cout << "Marks: " << students[i].getMarks() << endl
             << endl;
    }

    delete[] students;
    students = nullptr;

    system("pause");
    return 0;
}