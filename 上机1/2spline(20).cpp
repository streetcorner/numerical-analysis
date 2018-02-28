#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 21;

double x[N];
double fx[N];
double xi[41];
double yi[41];
double h[N];
double l[N];//lamda
double m[N];//miu
double d[N];
double dd1[N];//一阶方差
double dd2[N];
double b[N];//beta
double M[N];//M
double Y[N];//y

void init_x_fx()
{
    for(int i = 0 ;i < N;i++){
        x[i] = -1+0.1*i;
    }
    for(int i = 0 ;i < N;i++){
        fx[i] = 1/(1+25*x[i]*x[i]);
    }
}
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
    l[0] = 1; //第一种边界条件（自然边界条件）
    m[N-1] = 1;
    for(int i = 1; i < N-1;i++){ //除了0和n-1，计算中间的
       l[i] = h[i]/(h[i-1]+h[i]);
       m[i] = h[i-1]/(h[i-1]+h[i]);
    }

     //calculate d
    d[0] =(6/h[0])*(dd1[0]-(50.0/26.0/26.0)); //第一种边界条件（自然边界条件）
    d[N-1] =(6/h[N-2])*(-(50.0/26.0/26.0)-dd1[N-2]);
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
    for(int i = 0 ;i<N-1;i++)
    {
        if(t>= x[i]&&t<=x[i+1]){//j=0
            y = M[i]* ((x[1+i]-t)*(x[1+i]-t)*(x[1+i]-t)/6/h[i])
                + M[1+i]* ((t-x[i])*(t-x[i])*(t-x[i])/6/h[i])
                +(fx[i]-M[i]*h[i]*h[i]/6)*((x[1+i]-t)/h[i])
                +(fx[1+i]-M[1+i]*h[i]*h[i]/6)*((t-x[i])/h[i]);
            break;
        }
    }
    return y;
}

int main(){
    init_x_fx();
    cal_divided_difference();
    init_matrix();
    sol_matrix();

    for(int i = 0;i<=40;i++){
        xi[i] = -1+0.05*(double)(i);
    }
    freopen("spline_out2(20).txt", "w", stdout);

    printf("xi       yi    (i from 0 to 40)\n");
    for(int i = 0; i <=40;i++){
        printf("%.4f   %.4f\n",xi[i],spline_inter(xi[i]));
    }
    fclose(stdout);
    return 0;
}
