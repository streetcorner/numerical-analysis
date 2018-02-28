#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double a = 0.0,b = 1.0;
double h;
double S[100];
double C[100];
double R[100];

double fx(double t)
{
    double fn;
    fn = sqrt(t) * log(t);  //log ==ln
    return fn;
}

void Sx(double h,double n)//composite Simpson
{

    S[0] = fx(0.0001)+fx(b);//a =0.0001因为函数不允许log10(0.0)的参数为0.0
    //printf("%f\n",Sn);
    for(int i = 0 ;i < n;i++)
    {
        double xi1 = (double)i*h;
        double xi2 =xi1+h/2.0;
        if(i ==0){
            S[0]+= 4.0*fx(xi2);
           // printf("i ==0  %f\n",Sn);
        }
        else{
            S[0] += 4.0*fx(xi2);
            S[0] += 2.0*fx(xi1);
           // printf("else %f\n",Sn);
        }
    }
    S[0] *= h/6.0;
   // printf("*1/6  else %f\n",Sn);
        //printf("%f\n",Tn);
    for(int i =1;i < n;i++)
        S[i]=-1.0/14*S[i-1];
}

void Cx(double h,double n)
{
    for(int i =1;i < n-1;i++)
    {
        C[i] = 16.0/15*S[i+1]-1.0/15*S[i];
    }
}
void Rx(double h,double n)
{
    for(int i =1;i < n-2;i++)
    {
        R[i] = 16.0/15*C[i+1]-1.0/15*C[i];
    }
}
int main()
{
    printf("The result of fx is %f.\n",(-4.0/9));
    printf("The result of composite Simpson:");



   for(int i = 2; i <10;i++)   //n==i
   {
        h= (b-a)/(double)i;
        Sx(h,i);
        Cx(h,i);
        Rx(h,i);
         for(int j = 0; j < i-3;j++)
       {
           printf("when n = %d,Rn I=%f  \n",i,C[j]);
       }
      // printf("when n = %d, I=%f  \n",i,Sx(h,i));
   }
    return 0;
}
