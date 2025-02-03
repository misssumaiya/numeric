#include<bits/stdc++.h>
using namespace std;

class SimpsonsRule {
private:
    double a, b;
    int n;

    double func(double x) {
        return log(x);
    }

public:

    SimpsonsRule(double lower, double upper, int intervals) {
        a = lower;
        b = upper;
        n = intervals;
        if (n % 2 != 0) {
            cout << "Warning: Simpson's rule requires an even number of intervals. Increasing n by 1.\n";
            n++;
        }
    }

    double solve() {
        double h = (b - a) / n;
        double sum = func(a) + func(b);

        cout << fixed << setprecision(4);
        cout << "x          f(x)\n";

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            double fx = func(x);
            cout << x << "   " << fx << endl;

            if (i % 2 == 0) {
                sum += 2 * fx;
            } else {
                sum += 4 * fx;
            }
        }
        double result = (h / 3) * sum;
        return result;
    }
};

int main() {
    double a = 4, b = 5.2;
    int n = 6;

    SimpsonsRule simpsons(a, b, n);
    double result = simpsons.solve();

    cout << "Approximate integral: " << result << endl;

    return 0;
}
