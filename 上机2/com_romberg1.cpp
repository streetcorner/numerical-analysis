#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double T[100];//梯形
double S[100];//辛普森
double C[100];//柯特斯
double R[100];//龙贝格

double a = 0.0,b = 1.0;
double h=1;

double fx(double t)
{
    double fn;
    fn = sqrt(t) * log(t);  //log ==ln
   // printf("%f\n",fn);
    return fn;
}

void Tx(double n)//composite trapezoidal
{
    //T[0]= (fx(0.0000001)+fx(b))*1.0/2;//a =0.0001但是函数不允许log10(0.0)的参数为0.0
    for(int i = 1 ; i< n;i++)//要看后面一个
    {
       // double xi3 = (xi1+xi2)/2.0;
        T[i]=0.0;
        for(int j= 1;j < n;j++) //j为二分的次数
        {
            double xi;
            for(int k = 1; k < pow(2.0,j);k+=2) //k为分子，（1/2），（1/4，3/4）
            {
                xi = k/pow(2.0,j);
                T[i]+=fx(xi);
            }
            T[i] *= 1.0/(2.0*j);
            T[i]+= 1.0/2*T[i-1];

          //  printf("T1 %f\n",T[1]);
             printf("T2 %f\n",T[2]);
        }
    }
}
void Sx(double n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        S[i]= 4.0/3*T[i+1]-1.0/3*T[i];
    }
}

void Cx(double n)
{
    for(int i = 0; i < n-2 ; i++)
    {
        C[i]= 16.0/15*S[i+1]-1.0/15*S[i];
    }
}
void Rx(double n)
{
    for(int i = 0; i < n-3 ; i++)
    {
        R[i]= 64.0/63*C[i+1]-1.0/63*C[i];
    }
}
int main()
{
    printf("The result of fx is %f.\n",(-4.0/9));
    printf("The result of composite romberg:\n");

    double i = 8;

       Tx((double)i);
       Sx((double)i);
       Cx((double)i);
       Rx((double)i);
        for(int j = 0; j < i;j++)
       {
           //printf("when n = %d,Tn I=%f  \n",i,T[j]);
       }
        for(int j = 0; j < i-1;j++)
       {
          // printf("when n = %d,Sn I=%f  \n",i,S[j]);
       }
        for(int j = 0; j < i-2;j++)
       {
          // printf("when n = %d,Cn I=%f  \n",i,C[j]);
       }
       for(int j = 0; j < i-3;j++)
       {
           //printf("when n = %d,Rn I=%f  \n",i,R[j]);
       }




    return 0;
}
