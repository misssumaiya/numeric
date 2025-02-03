#include<bits/stdc++.h>
using namespace std;

class LagrangeInterpolator {
public:
    vector<double> x = {1, 2, 3};
    vector<double> y = {2, 3, 4};

    double interpolate(double targetX) {
        int n = x.size();
        double ans = 0.0;

        for (int i = 0; i < n; i++) {
            double term = y[i];

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    term *= (targetX - x[j]) / (x[i] - x[j]);
                }
            }
            ans += term;
        }
        return ans;
    }
};

int main() {

    LagrangeInterpolator interpolator;

    double value = 2.5;
    double expectedValueForY = interpolator.interpolate(value);

    cout << "Interpolated value at x = " << value << " is " << expectedValueForY << endl;

    return 0;
}
