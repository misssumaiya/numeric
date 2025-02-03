#include <bits/stdc++.h>
using namespace std;

class NewtonDividedDifference{
private:
    int n;
    float x[10];
    float y[10][10];

public:

    NewtonDividedDifference(int n, float x[], float y[]){
        this->n = n;
        for (int i = 0; i < n; i++){
            this->x[i] = x[i];
            this->y[i][0] = y[i];
        }
    }
    float proterm(int i, float value){
        float pro = 1;
        for (int j = 0; j < i; j++) {
            pro = pro * (value - x[j]);
        }
        return pro;
    }
    void dividedDiffTable() {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
            }
        }
    }
    float applyFormula(float value) {
        float sum = y[0][0];
        for (int i = 1; i < n; i++) {
            sum = sum + (proterm(i, value) * y[0][i]);
        }
        return sum;
    }
    void printDiffTable() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                cout << setprecision(4) << y[i][j] << "\t ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;
    float value = 7;
    float x[] = {5, 6, 9, 11};
    float y[] = {12, 13, 14, 16};

    NewtonDividedDifference ndd(n, x, y);

    ndd.dividedDiffTable();

    cout << "Divided Difference Table:"<<endl;
    ndd.printDiffTable();

    cout << "\nValue at " << value << " is " << ndd.applyFormula(value) << endl;

    return 0;
}

