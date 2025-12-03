#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void inputMatrix(float m[MAX_SIZE][MAX_SIZE], int& rows, int& cols, int matrixIndex);

void displayMatrix(float m[MAX_SIZE][MAX_SIZE], int rows, int cols);

void displaySideBySide(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2);

void multiplyMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE], int& r3, int& c3);

void addMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE]);

void subtractMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE]);

float determinant(float m[MAX_SIZE][MAX_SIZE], int n);

void sortMatrix(float m[MAX_SIZE][MAX_SIZE], int rows, int cols);

void mySwap(float& a, float& b);

int main()
{
    float m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE];
    int r1, c1, r2, c2;

    inputMatrix(m1, r1, c1, 1);
    inputMatrix(m2, r2, c2, 2);

    cout << "--- Matrices Side by Side ---\n";
    displaySideBySide(m1, r1, c1, m2, r2, c2);

    cout << "--- Product of Matrices ---\n";
    if (c1 == r2)
    {
        float product[MAX_SIZE][MAX_SIZE];
        int r3, c3;
        multiplyMatrices(m1, r1, c1, m2, r2, c2, product, r3, c3);
        displayMatrix(product, r3, c3);
    }
    else
    {
        cout << "Product of Matrices is not defined" << endl;
    }

    cout << "--- Addition ---\n";
    if (r1 == r2 && c1 == c2)
    {
        float sum[MAX_SIZE][MAX_SIZE];
        addMatrices(m1, r1, c1, m2, r2, c2, sum);
        displayMatrix(sum, r1, c1);
    }
    else
    {
        cout << "Addition can not be performed" << endl;
    }

    cout << "--- Difference ---\n";
    if (r1 == r2 && c1 == c2)
    {
        float diff[MAX_SIZE][MAX_SIZE];
        subtractMatrices(m1, r1, c1, m2, r2, c2, diff);
        displayMatrix(diff, r1, c1);
    }
    else
    {
        cout << "Subtraction can not be performed" << endl;
    }

    cout << "--- Determinant of Matrix 1 ---\n";
    if (r1 == c1)
    {
        // Make a copy because determinant function might modify it (Gaussian elimination)
        float temp[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<r1; i++) for(int j=0; j<c1; j++) temp[i][j] = m1[i][j];
        cout << "Determinant: " << determinant(temp, r1) << endl;
    }
    else
    {
        cout << "Determinant can't be found (Not square)\n";
    }

    cout << "--- Determinant of Matrix 2 ---\n";
    if (r2 == c2)
    {
        float temp[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<r2; i++) for(int j=0; j<c2; j++) temp[i][j] = m2[i][j];
        cout << "Determinant: " << determinant(temp, r2) << endl;
    }
    else
    {
        cout << "Determinant can't be found (Not square)\n";
    }

    cout << "--- Sorted Matrix 1 ---\n";
    float m1_sorted[MAX_SIZE][MAX_SIZE];
    for(int i=0; i<r1; i++) for(int j=0; j<c1; j++) m1_sorted[i][j] = m1[i][j];
    sortMatrix(m1_sorted, r1, c1);
    displayMatrix(m1_sorted, r1, c1);

    cout << "--- Sorted Matrix 2 ---\n";
    float m2_sorted[MAX_SIZE][MAX_SIZE];
    for(int i=0; i<r2; i++) for(int j=0; j<c2; j++) m2_sorted[i][j] = m2[i][j];
    sortMatrix(m2_sorted, r2, c2);
    displayMatrix(m2_sorted, r2, c2);

    return 0;
}

void mySwap(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void inputMatrix(float m[MAX_SIZE][MAX_SIZE], int& rows, int& cols, int matrixIndex)
{
    cout << "Enter rows of matrix " << matrixIndex << ": ";
    cin >> rows;
    cout << "Enter col of matrix " << matrixIndex << ": ";
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter matrix" << matrixIndex << "[" << i << "][" << j << "]:";
            cin >> m[i][j];
        }
    }
}

void displayMatrix(float m[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void displaySideBySide(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2)
{
    int maxRows = (r1 > r2) ? r1 : r2;

    for (int i = 0; i < maxRows; i++)
    {
        if (i < r1)
        {
            for (int j = 0; j < c1; j++)
            {
                cout << m1[i][j] << " ";
            }
        }
        else
        {
            for (int j = 0; j < c1; j++) cout << "  ";
        }

        cout << "\t";

        if (i < r2)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << m2[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void multiplyMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE], int& r3, int& c3)
{
    r3 = r1;
    c3 = c2;
    
    for (int i = 0; i < r3; i++)
    {
        for (int j = 0; j < c3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void addMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void subtractMatrices(float m1[MAX_SIZE][MAX_SIZE], int r1, int c1, float m2[MAX_SIZE][MAX_SIZE], int r2, int c2, float result[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

float determinant(float m[MAX_SIZE][MAX_SIZE], int n)
{
    
    float det = 1;
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        while (pivot < n && m[pivot][i] == 0) pivot++;
        
        if (pivot == n) return 0;
        
        if (pivot != i)
        {
            for(int k=0; k<n; k++) mySwap(m[i][k], m[pivot][k]);
            det *= -1;
        }
        
        det *= m[i][i];
        
        for (int j = i + 1; j < n; j++)
        {
            if (m[j][i] != 0)
            {
                float factor = m[j][i] / m[i][i];
                for (int k = i; k < n; k++)
                {
                    m[j][k] -= factor * m[i][k];
                }
            }
        }
    }
    return det;
}

void sortMatrix(float m[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    float temp[MAX_SIZE * MAX_SIZE];
    int k = 0;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[k++] = m[i][j];
        }
    }
    
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                mySwap(temp[j], temp[j + 1]);
            }
        }
    }
    
    k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = temp[k++];
        }
    }
}