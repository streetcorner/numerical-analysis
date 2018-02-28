#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int n =8;
double Tn;
double a = 0.0,b = 1.0;
double h = (b-a)/(double)n;


double fx(double t)
{
    double fn;
    fn = sqrt(t) * log(t);
   // printf("%f\n",fn);
    return fn;
}

double Tx()//composite trapezoidal
{

    Tn = (fx(0.0001)+fx(b));//a =0.0001但是函数不允许log10(0.0)的参数为0.0
   // printf("%f\n",log(1.0/8));
    for(int i = 1 ;i < n;i++)
    {
        double xi = i*h;
        Tn+= 2*fx(xi);
        //printf("%f\n",Tn);
    }
    Tn *= h/2;
    return Tn;
}

int main()
{
   // printf("%f\n",log10(0.0));//log10(0.0)参数不能为0.0
    printf("The result of composite trapezoidal is %f.\n",Tx());
    printf("The result of fx is %f.\n",(-4.0/9));
    return 0;
}
