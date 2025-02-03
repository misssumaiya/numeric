
#include<bits/stdc++.h>
using namespace std;

#define M 10
class GaussJordanElimination {
private:
    float a[M][M];
    int n;

public:
    GaussJordanElimination(int size, float matrix[M][M]) {
        n = size;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                a[i][j] = matrix[i][j];
            }
        }
    }
    void PrintMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                cout << fixed << setprecision(1) << a[i][j] << " ";
            cout << endl;
        }
    }
    int PerformOperation() {
        int i, j, k = 0, c, flag = 0;
        float pro;
        for (i = 0; i < n; i++) {
            if (a[i][i] == 0) {
                c = 1;
                while ((i + c) < n && a[i + c][i] == 0)
                    c++;
                if ((i + c) == n) {
                    flag = 1;
                    break;
                }
                for (j = i, k = 0; k <= n; k++)
                    swap(a[j][k], a[j + c][k]);
            }

            for (j = 0; j < n; j++) {
                if (i != j) {
                    pro = a[j][i] / a[i][i];
                    for (k = 0; k <= n; k++)
                        a[j][k] = a[j][k] - a[i][k] * pro;
                }
            }
        }
        return flag;
    }
    int CheckConsistency(int flag) {
        int i, j;
        float sum;
        flag = 3;

        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++)
                sum += a[i][j];
            if (sum == a[i][j])
                flag = 2;
        }
        return flag;
    }
    void PrintResult(int flag) {
        cout << "Result is : ";
        if (flag == 2)
            cout << "Infinite Solutions Exist" << endl;
        else if (flag == 3)
            cout << "No Solution Exists" << endl;
        else {
            for (int i = 0; i < n; i++)
                cout << a[i][n] / a[i][i] << " ";
            cout << endl;
        }
    }
    void Solve() {
        int flag = 0;
        flag = PerformOperation();
        if (flag == 1)
            flag = CheckConsistency(flag);
        cout << "Final Augmented Matrix is:" << endl;
        PrintMatrix();
        PrintResult(flag);
    }
};

int main() {
    /*
         2y + z = 4
         x + y + 2z = 6
         2x + y + z = 7
    */

    float matrix[M][M] = {
        { 0, 2, 1, 4 },
        { 1, 1, 2, 6 },
        { 2, 1, 1, 7 }
    };

    GaussJordanElimination gj(3, matrix);
    gj.Solve();

    return 0;
}
