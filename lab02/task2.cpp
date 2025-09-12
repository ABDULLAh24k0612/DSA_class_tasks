
#include <iostream>
using namespace std;

class Matrix {
private:
    int** mat;
    int rows, cols;

    void allocate(int r, int c) {
        rows = r;
        cols = c;
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }
    }

public:
    Matrix(int r, int c) {
        allocate(r, c);
    }

    void fillMatrix() {
        cout << "Enter values row by row:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void resize(int newR, int newC, int fillVal) {
        int** newMat = new int*[newR];
        for (int i = 0; i < newR; i++) {
            newMat[i] = new int[newC];
            for (int j = 0; j < newC; j++) {
                if (i < rows && j < cols)
                    newMat[i][j] = mat[i][j];
                else
                    newMat[i][j] = fillVal;
            }
        }

        for (int i = 0; i < rows; i++) delete[] mat[i];
        delete[] mat;

        mat = newMat;
        rows = newR;
        cols = newC;
    }

    void transpose() {
        int** trans = new int*[cols];
        for (int i = 0; i < cols; i++) {
            trans[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                trans[i][j] = mat[j][i];
            }
        }

        for (int i = 0; i < rows; i++) delete[] mat[i];
        delete[] mat;

        mat = trans;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void printMatrix() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = mat[i][j];
                if ((i + j) % 2 == 1) val += 2;
                cout << val << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] mat[i];
        delete[] mat;
    }
};

int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    Matrix M(r, c);
    M.fillMatrix();
    cout << "Original Matrix:\n";
    M.printMatrix();

    M.transpose();
    cout << "Transposed:\n";
    M.printMatrix();

    M.resize(r + 1, c + 1, 0);
    cout << "Resized:\n";
    M.printMatrix();

    return 0;
}
