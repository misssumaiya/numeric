#include<bits/stdc++.h>
using namespace std;

class Bisection {
private:
    double a;
    double b;
    double tolerance;

    double fnc(double x) {
        return x*x*x*x-x-10;
    }
    void randomGenerator() {
        do {
            a=rand()%101- 50;
            b=rand()%101-50;
        } while (fnc(a)*fnc(b)>= 0);
        cout << "Initial interval:" << a << ", " <<b<<endl;
    }
public:
    Bisection(double tolerance) {
        randomGenerator();
        this->tolerance = tolerance;
    }
    void bisection() {
        double c=a;
        int maxIterations=1000;
        int iteration=0;
        while((b-a)>tolerance && iteration < maxIterations) {
            c=(a + b)/2;
            if(fnc(c)==0.0) {
                break;
            } else if(fnc(c)*fnc(a)<0) {
                b=c;
            } else {
                a=c;
            }
            cout <<"Iteration "<<iteration+ 1<<": a = " << a <<", b = " << b<< ", c = " << c << endl;
            iteration++;
        }

        cout<<fixed<<setprecision(3)<<"Root: "<<c<< endl;
    }
};

int main() {
    double tolerance=1e-3;

    Bisection bisect(tolerance);
    bisect.bisection();

    return 0;
}

