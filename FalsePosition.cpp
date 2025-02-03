#include<bits/stdc++.h>
using namespace std;
class Falseposition{
private:
    double a;
    double b;
    double tolerance;
    double func(double x){
    return x*x*x-x*x+5;

    }
    void randomGenerator(){
    srand(time(0));
    do{
       a = rand()%101-50;
       b = rand()%101-50;
    }while(func(a)*func(b)>=0);
    cout<<"initial vale: "<<"["<<a<<","<<b<<"]"<<endl;
    }
public:
    Falseposition(double tolerance){
    randomGenerator();
    this->tolerance=tolerance;
    }
void falseposition(){
int maxIteration = 100;
double c=a;
double c_prev = a;
for(int i=0;i<maxIteration;i++){

c = (a*func(b) - b*func(a))/(func(b) - func(a));
if(fabs(c-c_prev)<tolerance){
        cout<<"converged to tolerance after "<< i+1 <<" iteration";
    break;
}
if(fabs(func(c))<tolerance){
    cout<<"f(c) is sufficiently close to 0 after "<< i+1 <<" iteration";
    break;
}

 if(func(c)*func(a)<0){
    b = c;
}
else{
    a = c;
}
 cout << "Iteration " << i+ 1 << ": a = " << a << ", b = " << b << ", c = " << c << endl;
c_prev = c;
}
cout<<fixed<<setprecision(3)<<"approximate root:"<<c<<endl;
}

};
int main(){
    double tolerance = 1e-3;
Falseposition fposition(tolerance);
fposition.falseposition();
}
