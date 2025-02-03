#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson {
private:

    double tolerance;
    double func(double x){
        return x*x-2;
    }
    double deriveFunc(double x) {
        return 2*x;
    }

public:
    NewtonRaphson(double tolerance){
        this->tolerance = tolerance;
    }

    void newtonRaphson(double initial_guess){
        double x = initial_guess;
        cout << fixed << setprecision(4);
        cout << "Initial guess: " << x << endl;

        double fx = func(x);
        double dfx = deriveFunc(x);
        int iteration = 0;

        while (fabs(fx) > tolerance){
            iteration++;

            if (fabs(dfx) < 1e-6) {
                cout << "Derivative near zero, stopping to avoid division error.\n";
                return;
            }
            x = x - (fx / dfx);
            fx = func(x);
            dfx = deriveFunc(x);

            cout << "Iteration " << iteration << ": x = " << x << ", f(x) = " << fx << ", f'(x) = " << dfx << endl;
        }

        cout << "Root found: " << x << " after " << iteration << " iterations.\n";
    }
};

int main(){

    srand(time(0));
    double tolerance= 1e-4;
    double initial_guess= rand() % 21 - 10;

    NewtonRaphson raphson(tolerance);
    raphson.newtonRaphson(initial_guess);

    return 0;
}

