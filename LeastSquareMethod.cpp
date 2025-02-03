#include<bits/stdc++.h>
using namespace std;
//y= a0 + a1x
class LeastSquares {
private:
    vector<double> x;
    vector<double> y;
    double a1 = 0.0;
    double a0 = 0.0;
public:
    LeastSquares(vector<double>& xp,  vector<double>& yp) {
        x = xp, y = yp;
    }
    double sum( vector<double>& v) {
        return accumulate(v.begin(), v.end(), 0.0);
    }
    double sum_of_products( vector<double>& v1,  vector<double>& v2)  {
        double result = 0.0;
        for (size_t i = 0; i < v1.size(); ++i) {
            result += v1[i] * v2[i];
        }
        return result;
    }

    void fit() {
        double X1 = sum(x);
        double Y1 = sum(y);
        double XY = sum_of_products(x, y);
        double X2 = sum_of_products(x, x);

        double n = x.size();
        double denominator = n * X2 - X1 * X1;
        a1 = (n * XY - X1 * Y1) / denominator;
        a0 = (Y1 * X2 - X1 * XY) / denominator;
        cout << "The slope: " << a1 << endl;
        cout << "The constant: " << a0 << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);
    // vector<double> x = {1, 2, 4, 6, 8};
    // vector<double> y = {3, 4, 8, 10, 15};
    // LeastSquares ls(x, y);
    // ls.fit();
    // answer should be: slope = 1.68 const = 0.94

    vector<double> x = {160, 162, 164, 166, 168};
    vector<double> y = {52, 55, 57, 60, 61};
    LeastSquares ls(x, y);
    ls.fit();
    // answer should be: slope = 1.15 const = -131.6

    return 0;
}
