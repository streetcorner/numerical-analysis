#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 5;

double x[N]={0.2,0.4,0.6,0.8,1.0};
double fx[N] = {0.98,0.92,0.81,0.64,0.38};
double xi[12];
double yi[12];
double h[N];
double l[N];//lamda
double m[N];//miu
double d[N];
double dd1[N];//一阶方差
double dd2[N];
double b[N];//beta
double M[N];//M
double Y[N];//y

void cal_divided_difference()
{
    for(int i = 0; i < N-1;i++){
        dd1[i] = (fx[i+1]-fx[i])/(x[i+1]- x[i]);
        //printf("%f\n",dd1[i+1]);
    }
    for(int i = 0; i < N-2;i++){
        dd2[i] = (dd1[i+1]-dd1[i])/(x[i+2]- x[i]);
    }
}

void init_matrix()
{
    //calculate h
    for(int i = 0; i < N-1;i++){
        h[i] = x[i+1]-x[i];
        //printf("%f\n",dd1[i+1]);
    }

    //calculate l,m(lamuda,miu)
    l[0] = 0; //第二种边界条件（自然边界条件）
    m[N-1] = 0;
    for(int i = 1; i < N-1;i++){ //除了0和n-1，计算中间的
       l[i] = h[i]/(h[i-1]+h[i]);
       m[i] = h[i-1]/(h[i-1]+h[i]);
    }

     //calculate d
    d[0] =0; //第二种边界条件（自然边界条件）
    d[N-1] =0;
    for(int i = 1; i < N-1;i++){
        d[i] = 6*dd2[i-1];
    }
}
void sol_matrix()
{
    //cal b
    b[0] = l[0] / 2;
    for(int i = 1; i < N-1;i++){
        b[i] = l[i] /(2-m[i]*b[i-1]);
    }

    //cal Y
    Y[0] = d[0]/2;
    for(int i = 1; i < N;i++){
        Y[i] = (d[i] - m[i]*Y[i-1])/(2- m[i]*b[i-1]);
    }
    //cal M
    M[N-1] = Y[N-1];
    for(int i = N-2; i >=0;i--){
        M[i] = Y[i] - b[i]*M[i+1];
    }
}

double spline_inter(double t)
{
    double y;
    if(t>= x[0]&&t<=x[1]){//j=0
        y = M[0]* ((x[1]-t)*(x[1]-t)*(x[1]-t)/6/h[0])
            + M[1]* ((t-x[0])*(t-x[0])*(t-x[0])/6/h[0])
            +(fx[0]-M[0]*h[0]*h[0]/6)*((x[1]-t)/h[0])
            +(fx[1]-M[1]*h[0]*h[0]/6)*((t-x[0])/h[0]);
    }
    if(t>= x[1]&&t<=x[2]){//j=0
        y = M[1]* ((x[2]-t)*(x[2]-t)*(x[2]-t)/6/h[1])
            + M[2]* ((t-x[1])*(t-x[1])*(t-x[1])/6/h[1])
            +(fx[1]-M[1]*h[1]*h[1]/6)*((x[2]-t)/h[1])
            +(fx[2]-M[2]*h[1]*h[1]/6)*((t-x[1])/h[1]);
    }
    if(t>= x[2]&&t<=x[3]){//j=0
        y = M[2]* ((x[3]-t)*(x[3]-t)*(x[3]-t)/6/h[2])
            + M[3]* ((t-x[2])*(t-x[2])*(t-x[2])/6/h[2])
            +(fx[2]-M[2]*h[2]*h[2]/6)*((x[3]-t)/h[2])
            +(fx[3]-M[3]*h[2]*h[2]/6)*((t-x[2])/h[2]);
    }
    if(t>= x[3]&&t<=x[4]){//j=0
        y = M[3]* ((x[4]-t)*(x[4]-t)*(x[4]-t)/6/h[3])
            + M[4]* ((t-x[3])*(t-x[3])*(t-x[3])/6/h[3])
            +(fx[3]-M[3]*h[3]*h[3]/6)*((x[4]-t)/h[3])
            +(fx[4]-M[4]*h[3]*h[3]/6)*((t-x[3])/h[3]);
    }
    return y;
}

int main(){

    cal_divided_difference();
    init_matrix();
    sol_matrix();

    for(int i = 0;i<12;i++){
        xi[i] = 0.2+0.08*(double)(i);
    }
    freopen("spline_out.txt", "w", stdout);

    printf("xi       yi    (i from 0 to 12)\n");
    for(int i = 0; i <=10;i++){
        printf("%.2f   %.2f\n",xi[i],spline_inter(xi[i]));
    }
    fclose(stdout);
    return 0;
}
