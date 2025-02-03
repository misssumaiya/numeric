#include <bits/stdc++.h>
using namespace std;

class NewtonForward {
private:
    int n;
    double x[10];
    double y[10][10];
public:
    NewtonForward(int n,double x_values[],double y_values[]) {
        this->n=n;
        for (int i=0; i< n;i++) {
            x[i]=x_values[i];
            y[i][0]=y_values[i];
        }
    }
    double p_cal(double p, int i) {
        double temp=p;
        for (int j= 1;j<i;j++) {
            temp=temp * (p - j);
        }
        return temp;
    }
    int fact(int n) {
        int f=1;
        for (int i = 2;i<= n; i++) {
            f*= i;
        }
        return f;
    }
    void build_difference_table() {
        for (int i = 1;i < n;i++) {
            for (int j=0; j < n - i; j++) {
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
            }
        }
    }
    void display_difference_table() {
        for (int i= 0;i < n; i++) {
            cout<<setw(4) << x[i] << "\t";
            for (int j = 0; j < n - i; j++)
                cout<<setw(4)<< y[i][j] << "\t";
          cout << endl;
        }
    }
    double interpolate(double value) {
        double p=(value - x[0])/(x[1] - x[0]);
        double sum = y[0][0];
        for (int i = 1; i < n; i++) {
            sum += (p_cal(p, i) * y[0][i]) / fact(i);
        }
        return sum;
    }
};

int main() {
    int n = 4;
    double x[] = {1,3,5,7};
    double y[] = { 24,120,336,720};

    NewtonForward newton(n, x, y);
    newton.build_difference_table();
    cout << "Forward Difference Table:" << endl;
    newton.display_difference_table();
    double value = 4.75;
    double result = newton.interpolate(value);
    cout <<"\nValue at " << value << " is " << result << endl;

    return 0;
}


