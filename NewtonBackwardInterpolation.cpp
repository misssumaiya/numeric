#include <bits/stdc++.h>
using namespace std;

class NewtonBackwardInterpolation {
private:
    int n;
    float x[10];
    float y[10][10];

public:

    NewtonBackwardInterpolation(int n, float x_values[], float y_values[]){
        this->n = n;
        for (int i = 0; i < n; i++){
            x[i] = x_values[i];
            y[i][0] = y_values[i];
        }
    }
    float p_cal(float p, int i){
        float temp = p;
        for (int j = 1; j < i; j++) {
            temp = temp * (p + j);
        }
        return temp;
    }
    int fact(int n){
        int f = 1;
        for (int i = 2; i <= n; i++){
            f *= i;
        }
        return f;
    }
    void build_difference_table(){
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--){
                y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
            }
        }
    }
    void display_difference_table(){
        for (int i = 0; i < n; i++) {
            cout << setw(4) << x[i] << "\t";
            for (int j = 0; j < n - i; j++)
                cout << setw(4) << y[i][j] << "\t";
            cout << endl;
        }
    }
    float interpolate(float value){
        float h = x[1] - x[0];
        float p = (value - x[n - 1]) / h;
        float sum = y[n - 1][0];
        for (int i = 1; i < n; i++) {
            sum += (p_cal(p, i) * y[n - 1][i]) / fact(i);
        }

        return sum;
    }
};

int main(){

    int n = 4;
    float x[] = { 45, 50, 55, 60 };
    float y[] = { 0.7071, 0.7660, 0.8192, 0.8660 };

    NewtonBackwardInterpolation newtonInterp(n, x, y);

    newtonInterp.build_difference_table();

    cout << "Backward Difference Table:" << endl;
    newtonInterp.display_difference_table();

    float value = 56;
    float result = newtonInterp.interpolate(value);

    cout << "\nValue at " << value << " is " << result << endl;

    return 0;
}

