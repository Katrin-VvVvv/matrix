#include <iostream>
using namespace std;

int** createMatrix(int n) {
    int** m = new int* [n];
    for (int i = 0; i < n; i++)
        m[i] = new int[n];
    return m;
}

void deleteMatrix(int** m, int n) {
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
}

void inputMatrix(int** m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
}

void printMatrix(int** m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void rotate90(int** m, int n) {
    int** temp = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = m[n - 1 - j][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = temp[i][j];
    deleteMatrix(temp, n);

int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Размер матрицы: ";
    cin >> n;
    int** mat = createMatrix(n);
    cout << "Введите матрицу:\n";
    inputMatrix(mat, n);
    int cmd;
    while (true) {
        cout << "\n1-90°  2-maxSum  3-magic  0-выход: ";
        cin >> cmd;
        if (cmd == 1) {
            rotate90(mat, n);
            printMatrix(mat, n);
        }
        else if (cmd == 2) {
            int k;
            cout << "k=";
            cin >> k;
            cout << "Max sum=" << maxSubSum(mat, n, k) << endl;
        }
        else if (cmd == 3) {
            cout << (isMagic(mat, n) ? "Magic" : "Not magic") << endl;
        }
        else if (cmd == 0) break;
    }
    deleteMatrix(mat, n);
    return 0;
}
