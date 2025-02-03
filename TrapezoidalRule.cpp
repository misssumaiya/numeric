#include <iostream>
#include <iomanip>
using namespace std;

class TrapezoidalRule {
private:
    double func(double x) {
        return 1 / (1 + x * x);
    }

public:
    double integrate(double a, double b, int n) {
        double h = (b - a) / n;
        double sum = func(a) + func(b);

        cout << "Iteration-wise calculations:\n";
        cout << fixed << setprecision(3);
        cout << "x\t\t f(x)\n";
        cout << a << "\t\t" << func(a) << endl;

        for (int i = 1; i < n; i++) {
            double x_i = a + i * h;
            double f_xi = func(x_i);
            sum += 2 * f_xi;
            cout << x_i << "\t\t" << f_xi << endl;
        }

        cout << b << "\t\t" << func(b) << endl;

        double result = (h / 2) * sum;
        return result;
    }
};

int main() {

    double a = 0.0, b = 1.0;

    int n = 6;

    TrapezoidalRule solver;
    double result = solver.integrate(a, b, n);

    cout << "\nFinal Value of Integral: " << fixed << setprecision(3) << result << endl;

    return 0;
}
