#include <iostream>
#include <string>

using namespace std;

class Book
{

public:
    int book_no;
    string book_name;
    float price;
    int edition;
    string category;

    Book(int bookNum, string bookName, float pr, int edit, string cat)
    {
        book_no = bookNum;
        book_name = bookName;
        price = pr;
        edition = edit;
        category = cat;
    }
};

class Node
{
public:
    Book *book;
    Node *next;
};

class Stack
{
public:
    Node *top;
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(Book *book)
    {
        Node *newNode = new Node;
        newNode->book = book;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    Book *peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return nullptr;
        }
        return top->book;
    }
};

class LibraryMain
{
private:
    Stack bookStack;

public:
    void addBook(Book *book)
    {
        bookStack.push(book);
    }

    Book *issueBook()
    {
        if (bookStack.isEmpty())
        {
            cout << "No books available in the library" << endl;
            return nullptr;
        }
        Book *book = bookStack.peek();
        bookStack.pop();
        return book;
    }

    int getTotalBooks()
    {
        int count = 0;
        Node *currentNode = bookStack.top;
        while (currentNode != nullptr)
        {
            count++;
            currentNode = currentNode->next;
        }
        return count;
    }
};

class LibraryDepartment
{
private:
    string department;
    int totalBooksCategoryWise;
    Stack issuedBooks;

public:
    LibraryDepartment(string dept) : department(dept), totalBooksCategoryWise(0) {}

    void issueBook(Book *book)
    {
        issuedBooks.push(book);
        totalBooksCategoryWise++;
    }

    void showIssuedBooks()
    {
        cout << "Books issued by " << department << " department:" << endl;
        Node *currentNode = issuedBooks.top;
        while (currentNode != nullptr)
        {
            Book *book = currentNode->book;
            cout << "Book Name: " << book->book_name << endl;
            cout << "Book No: " << book->book_no << endl;
            cout << "Price: " << book->price << endl;
            cout << "Edition: " << book->edition << endl;
            cout << "Category: " << book->category << endl;
            currentNode = currentNode->next;
        }
    }
};

int main()
{
    LibraryMain lib;

    Book *book1 = new Book(1, "Book 1", 10.99, 1, "Category 1");
    Book *book2 = new Book(2, "Book 2", 15.99, 2, "Category 2");
    Book *book3 = new Book(3, "Book 3", 20.99, 1, "Category 1");
    Book *book4 = new Book(4, "Book 4", 12.99, 3, "Category 3");
    Book *book5 = new Book(5, "Book 5", 18.99, 2, "Category 2");

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.addBook(book5);

    Book *issuedBook = lib.issueBook();
    if (issuedBook != nullptr)
    {
        cout << "Book issued:" << endl;
        cout << "Book Name: " << issuedBook->book_name << endl;
        cout << "Book No: " << issuedBook->book_no << endl;
        cout << "Price: " << issuedBook->price << endl;
        cout << "Edition: " << issuedBook->edition << endl;
        cout << "Category: " << issuedBook->category << endl;
        delete issuedBook;
    }

    LibraryDepartment dep1("Department 1");
    LibraryDepartment dep2("Department 2");

    dep1.issueBook(book1);
    dep1.issueBook(book2);
    dep2.issueBook(book3);
    dep2.issueBook(book4);

    dep1.showIssuedBooks();
    dep2.showIssuedBooks();

    return 0;
}