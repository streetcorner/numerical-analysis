#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 5;

double x[N]={0.2,0.4,0.6,0.8,1.0};
double fx[N] = {0.98,0.92,0.81,0.64,0.38};
double xi[12];
double yi[12];
double dd1[N];//Ò»½×·½²î
double dd2[N];
double dd3[N];
double dd4[N];

void cal_divided_difference()
{
    for(int i = 0; i < N-1;i++)
    {
        dd1[i] = (fx[i+1]-fx[i])/(x[i+1]- x[i]);
        //printf("%f\n",dd1[i+1]);
    }
    for(int i = 0; i < N-2;i++)
    {
        dd2[i] = (dd1[i+1]-dd1[i])/(x[i+2]- x[i]);
    }
    for(int i = 0; i < N-3;i++)
    {
        dd3[i] = (dd2[i+1]-dd2[i])/(x[i+3]- x[i]);
    }
    for(int i = 0; i < N-4;i++)
    {
        dd4[i] = (dd3[i+1]-dd3[i])/(x[i+4]- x[i]);
    }
}
double newton_inter(double t)
{
    double y;
    y = fx[0]
        +dd1[0]*(t-x[0])
        +dd2[0]*(t-x[0])*(t-x[1])
        +dd3[0]*(t-x[0])*(t-x[1])*(t-x[2])
        +dd4[0]*(t-x[0])*(t-x[1])*(t-x[2])*(t-x[3]);
    return y;
}

int main(){
    cal_divided_difference();

    for(int i = 0;i<12;i++){
        xi[i] = 0.2+0.08*(double)(i);
    }
    freopen("newton_out.txt", "w", stdout);
    printf("xi       yi    (i from 0 to 12)\n");

    for(int i = 0; i <12;i++){
        printf("%.2f   %.2f\n",xi[i],newton_inter(xi[i]));
    }
     fclose(stdout);
    return 0;

}
