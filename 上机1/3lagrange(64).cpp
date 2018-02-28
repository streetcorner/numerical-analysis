#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 9;

double x[N];
double fx[N];
double l[N];//lk
double xi[2*N-1] = {0,1,2,4,7,9,13,16,20,25,31,36,42,49,57,64};


void init_x_fx()
{
    for(int i = 0 ;i < N;i++){
        fx[i] = (double)(i);
    }
    for(int i = 0 ;i < N;i++){
        x[i] = fx[i]*fx[i];
    }
}


double lagrange_inter(double t)
{
    double Lk = 0.0;
    for(int i = 0 ;i<N;i++) //cal lK;
    {
        double up= 1.0,down=1.0;
        for(int j = 0 ;j<N;j++)//initialize up
        {
            if(i!=j){
                up *=(t-x[j]);
            }
        }
        for(int j = 0 ;j<N;j++)//initialize down
        {
            if(i!=j){
               down*=(x[i]-x[j]);
            }
        }
        l[i] = up/down;
        Lk+=l[i]*fx[i];
    }
    return Lk;
}

int main(){

    init_x_fx();

   // freopen("lagrange_out3.txt", "w", stdout);
    printf("xi       yi    (i from 0 to 20)\n");
    for(int i = 0; i <16;i++){
       printf("%.4f   %.4f\n",xi[i],lagrange_inter(xi[i]));
        //printf("%.4f   %.4f\n",x[i],fx[i]);
    }
   // fclose(stdout);
    return 0;
}
