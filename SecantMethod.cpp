#include <bits/stdc++.h>
using namespace std;

class SecantMethod {

private:
    double x1, x2, tolerance;
    int maxIt;
    double func(double x){
        return x * x - 2;
    }

    void randomG(){
        srand(time(0));
        do {
            x1 = rand() % 101 - 50;
            x2 = rand() % 101 - 50;
        } while (func(x1) * func(x2) > 0 || fabs(x1 - x2) < 1e-6);
        cout << "Initial values: [" << x1 << ", " << x2 << "]" << endl;
    }

public:

    SecantMethod(double tolerance, int maxIt = 100){
        this->tolerance = tolerance;
        this->maxIt = maxIt;
        randomG();
    }

    void secantMethod(){
        double x0, prevX0;
        double f1, f2;

        for (int iteration = 0; iteration < maxIt; iteration++){
            f1 = func(x1);
            f2 = func(x2);

            x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);

            cout << fixed << setprecision(5) << "Iteration " << iteration + 1 << ": " << x0 << endl;

            if (fabs(x0 - x2) < tolerance || fabs(func(x0)) < tolerance){
                cout << fixed << setprecision(4) << "Converged to root: " << x0 << endl;
                return;
            }

            x1 = x2;
            x2 = x0;
        }
        cout << "Max iterations reached without convergence." << endl;
    }
};

int main() {

    double tolerance = 1e-4;
    SecantMethod secant(tolerance);
    secant.secantMethod();

    return 0;
}

