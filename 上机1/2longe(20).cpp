#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 41;

double x[N];
double fx[N];

void init_x_fx()
{
    for(int i = 0 ;i < N;i++){
        x[i] = -1+0.05*i;
    }
    for(int i = 0 ;i < N;i++){
        fx[i] = 1/(1+25*x[i]*x[i]);
    }
}

int main(){
    init_x_fx();

    freopen("longe_out(20).txt", "w", stdout);
    printf("x       y    (i from 0 to 40)\n");

    for(int i = 0; i <N;i++){
        printf("%.4f   %.4f\n",x[i],fx[i]);
    }
    fclose(stdout);
    return 0;

}
