#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double a = 0.0,b = 1.0;
double h;

double fx(double t)
{
    double fn;
    fn = sqrt(t) * log(t);  //log ==ln
    return fn;
}

double Sx(double h,double n)//composite Simpson
{
    double Sn;
    Sn = fx(0.0001)+fx(b);//a =0.0001因为函数不允许log10(0.0)的参数为0.0
    //printf("%f\n",Sn);
    for(int i = 0 ;i < n;i++)
    {
        double xi1 = (double)i*h;
        double xi2 =xi1+h/2.0;
        if(i ==0){
            Sn += 4.0*fx(xi2);
           // printf("i ==0  %f\n",Sn);
        }
        else{
            Sn += 4.0*fx(xi2);
            Sn += 2.0*fx(xi1);
           // printf("else %f\n",Sn);
        }
    }
    Sn *= h/6.0;
   // printf("*1/6  else %f\n",Sn);
        //printf("%f\n",Tn);
    return Sn;
}

int main()
{
    printf("The result of fx is %f.\n",(-4.0/9));
    printf("The result of composite Simpson:\n");
   for(int i = 2; i <20;i++)   //n==i
   {
       h= (b-a)/(double)i;
       printf("when n = %d, I=%f  \n",i,Sx(h,i));
   }
    return 0;
}
