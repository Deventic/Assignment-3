#include <iostream>

using namespace std;

float determinant(float matrix[100][100], int n);

int main()
{
    int a;
    cout << "Enter rows of first matrix:";
    cin >> a;
    const int row1 = a;
    cout << "Enter col of first matrix:";
    cin >> a;
    const int col1 = a;
    cout << "Enter rows of second matrix:";
    cin >> a;
    const int row2 = a;
    cout << "Enter col of second matrix:";
    cin >> a;
    const int col2 = a;

    float matrix1[row1][col1];
    float matrix2[row2][col2];

    // Input

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter matrix1[" << i << "][" << j << "]:";
            cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "Enter matrix2[" << i << "][" << j << "]:";
            cin >> matrix2[i][j];
        }
    }

    cout << '\n';

    // Display
    int biggerrow = (row1 > row2) ? row1 : row2;
    for (int i = 0; i < biggerrow; i++)
    {
        if (i < row1)
        {
            for (int j = 0; j < col1; j++)
            {
                cout << matrix1[i][j] << " ";
            }
        }
        cout << "\t";
        if (i < row2)
        {
            for (int j = 0; j < col2; j++)
            {
                cout << matrix2[i][j] << " ";
            }
        }
        cout << "\n";
    }

    // Product
    if (col1 != row2)
    {
        cout << "Product of Matrices is not defined" << endl;
    }
    else
    {
        const int row3 = row1;
        const int col3 = col2;
        float matrix3[row3][col3];

        for (int i = 0; i < row3; i++)
        {
            for (int j = 0; j < col3; j++)
            {
                matrix3[i][j] = 0;
            }
        }

        for (int i = 0; i < row3; i++)
        {
            for (int j = 0; j < col3; j++)
            {
                for (int k = 0; k < col1; k++)
                {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        cout << '\n';

        cout << "Result" << endl;

        for (int i = 0; i < row3; i++)
        {
            for (int j = 0; j < col3; j++)
            {
                cout << matrix3[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Addition & Subtraction

    if (row1 != row2 && col1 != col2)
    {
        cout << "Addition and Subtraction can not be performed" << endl;
    }
    else
    {
        const int row4 = row1;
        const int col4 = col1;
        float addition[row4][col4];
        float subtraction[row4][col4];

        for (int i = 0; i < row4; i++)
        {
            for (int j = 0; j < col4; j++)
            {
                addition[i][j] = matrix1[i][j] + matrix2[i][j];
                subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        cout << '\n';

        cout << "Addition:\n";

        for (int i = 0; i < row4; i++)
        {
            for (int j = 0; j < col4; j++)
            {
                cout << addition[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';

        cout << "Subtraction\n";

        for (int i = 0; i < row4; i++)
        {
            for (int j = 0; j < col4; j++)
            {
                cout << subtraction[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Determinant

    cout << "Enter rows of first matrix:";
    cin >> a;
    const int row = a;
    cout << "Enter col of first matrix:";
    cin >> a;
    const int col = a;

    if (row != col)
    {
        cout << "Determinant can't be found\n";
    }
    else
    {
        float determatrix[100][100]; // 2D array to hold square matrix
        cout << "Enter elements of the matrix row by row:\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> determatrix[i][j];
            }
        }
        int n = row; // size of square matrix
        cout << "Determinant: " << determinant(determatrix, n) << endl;
    }
}

float determinant(float matrix[100][100], int n) {
    float temp[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp[i][j] = matrix[i][j];

    float det = 1;

    for(int i=0;i<n;i++){
        // Pivoting
        if(temp[i][i] == 0){
            int swapRow = -1;
            for(int k=i+1;k<n;k++){
                if(temp[k][i] != 0){
                    swapRow = k;
                    break;
                }
            }
            if(swapRow == -1) return 0; // determinant is zero
            for(int j=0;j<n;j++) swap(temp[i][j], temp[swapRow][j]);
            det *= -1; // swap changes sign
        }

        det *= temp[i][i];

        // Eliminate below
        for(int k=i+1;k<n;k++){
            float factor = temp[k][i]/temp[i][i];
            for(int j=i;j<n;j++){
                temp[k][j] -= factor*temp[i][j];
            }
        }
    }

    return det;
}