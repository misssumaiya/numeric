
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;

class GaussianElimination {
private:
    int n;
    double A[MAXN][MAXN+1];
    double x[MAXN];

public:

    GaussianElimination(int size, double inputMatrix[MAXN][MAXN+1]) {
        n = size;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                A[i][j] = inputMatrix[i][j];
            }
        }
    }
    void partialPivot() {
        for (int i = 0; i < n; i++) {
            int pivot_row = i;
            for (int j = i + 1; j < n; j++) {
                if (abs(A[j][i]) > abs(A[pivot_row][i])) {
                    pivot_row = j;
                }
            }
            if (pivot_row != i) {
                for (int j = i; j <= n; j++) {
                    swap(A[i][j], A[pivot_row][j]);
                }
            }
            for (int j = i + 1; j < n; j++) {
                double factor = A[j][i] / A[i][i];
                for (int k = i; k <= n; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }
    void backSubstitution() {
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0;
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }
            x[i] = (A[i][n] - sum) / A[i][i];
        }
    }
    void solve() {
        partialPivot();
        cout << "\nFinal Augmented Matrix after Gaussian Elimination:\n";
        printMatrix();
        backSubstitution();
    }
    void printMatrix() {
        cout << fixed << setprecision(6);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << setw(10) << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void printSolution() {
        cout << "Solution for the system:\n";
        for (int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << x[i] << endl;
        }
    }
};

int main() {
    int n = 3;
    /*
    3.0X1 + 2.0X2 - 4.0X3 =  3.0
    2.0X1 + 3.0X2 + 3.0X3 = 15.0
    5.0X1 - 3.0X2 +    X3 = 14.0
    */
    double inputMatrix[MAXN][MAXN+1] = {
        {3.0, 2.0, -4.0, 3.0},
        {2.0, 3.0,  3.0, 15.0},
        {5.0, -3.0, 1.0, 14.0}
    };
    GaussianElimination solver(n, inputMatrix);

    solver.solve();

    solver.printSolution();

    return 0;
}

