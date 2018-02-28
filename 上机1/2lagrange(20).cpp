#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 21;

double x[N];
double fx[N];
double l[N];//lk
double xi[2*N-1];
double yi[2*N -1];

void init_x_fx()
{
    for(int i = 0 ;i < N;i++){
        x[i] = -1+0.2*i;
    }
    for(int i = 0 ;i < N;i++){
        fx[i] = 1/(1+25*x[i]*x[i]);
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
    for(int i = 0;i<=40;i++){
        xi[i] = -1+0.05*(double)(i);
    }
    freopen("lagrange_out2(20).txt", "w", stdout);

    printf("xi       yi    (i from 0 to 20)\n");
    for(int i = 0; i <=40;i++){
        printf("%.4f   %.4f\n",xi[i],lagrange_inter(xi[i]));
        //printf("%.4f   %.4f\n",x[i],fx[i]);
    }
    fclose(stdout);
    return 0;
}
