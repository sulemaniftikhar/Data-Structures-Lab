#include <iostream>

using namespace std;

// function prototypes
int **createMatrix();
void inputMatrix(int **matrix);
void addition(int **matrix1, int **matrix2, int **result);
void multiplication(int **matrix1, int **matrix2, int **result);
void displayMatrix(int **matrix);
void deallocateMemory(int **matrix);

int main()
{

    int **matrix1 = createMatrix();
    int **matrix2 = createMatrix();
    int **resultMatrix = createMatrix();

    cout << "Input Matrix 1" << endl;
    inputMatrix(matrix1);

    cout << "Input Matrix 2" << endl;
    inputMatrix(matrix2);

    addition(matrix1, matrix2, resultMatrix);

    cout << "Result of Matrix Addition:" << endl;
    displayMatrix(resultMatrix);

    multiplication(matrix1, matrix2, resultMatrix);

    cout << "Result of Matrix Multiplication:" << endl;
    displayMatrix(resultMatrix);

    deallocateMemory(matrix1);
    deallocateMemory(matrix2);
    deallocateMemory(resultMatrix);

    system("pause");
    return 0;
}

// alocatte memory
int **createMatrix()
{
    int **matrix = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = new int[3];
    }
    return matrix;
}

// takes input from user
void inputMatrix(int **matrix)
{
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// perform addition
void addition(int **matrix1, int **matrix2, int **result)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// perform multiplication
void multiplication(int **matrix1, int **matrix2, int **result)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// display 2D array in Matrix form
void displayMatrix(int **matrix)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// deallocates memory
void deallocateMemory(int **matrix)
{
    for (int i = 0; i < 3; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}