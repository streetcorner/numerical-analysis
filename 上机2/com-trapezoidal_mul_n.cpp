#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int n;
double Tn;
double a = 0.0,b = 1.0;
double h;


double fx(double t)
{
    double fn;
    fn = sqrt(t) * log(t);  //log ==ln
   // printf("%f\n",fn);
    return fn;
}

double Tx(double h,double n)//composite trapezoidal
{

    Tn = (fx(0.0000001)+fx(b));//a =0.0001但是函数不允许log10(0.0)的参数为0.0

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
    printf("The result of fx is %f.\n",(-4.0/9));
    printf("The result of composite trapezoidal:\n");

   for(int i = 2 ; i <20;i++)   //n==i
   {
       h= (b-a)/(double)i;
       printf("when n = %d, I=%f  \n",i,Tx(h,i));
   }


    return 0;
}
