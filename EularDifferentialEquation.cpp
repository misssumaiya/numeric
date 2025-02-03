#include<bits/stdc++.h>
#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

class EulerMethod {

private:
    double func(double x, double y){
        return (x + y + x * y);
    }

public:

    EulerMethod() {
    }
    void euler(double x0, double y0, double h, double x){
        double y = y0;
        cout << fixed << setprecision(6);
        cout << "Step-wise Iterations:\n";
        while (x0 < x) {
            cout << "x = " << x0 << ", y = " << y << endl;
            y = y + h * func(x0, y);
            x0 = x0 + h;
        }
        cout << "\nApproximate solution at x = " << x << " is " << y << endl;
    }
};
int main() {

    double x0 = 0;
    double y0 = 1;
    double h = 0.025;

    double x = 0.1;

    EulerMethod solver;

    solver.euler(x0, y0, h, x);

    return 0;
}
