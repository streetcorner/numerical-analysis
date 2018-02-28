#include<iostream>
using namespace std;

double f(double x, double y){
    return -y+x+1;
}
double R_K(double x,double y,double h){
    double K1,K2,K3,K4;
    K1 = f(x,y);
    K2 = f(x+h/2 ,y+h/2*K1);
    K3 = f(x+h/2 ,y+h/2*K2);
    K4 = f(x+h/2 ,y+h  *K3);
    return y + h/6 *(K1 + 2*K2 + 2*K3 + K4);
}
double Adams1(double *px, double* py, double h){
    return py[3] + h/24*( 55* f(px[3],py[3]) - 59* f(px[2],py[2]) + 37* f(px[1],py[1]) - 9* f(px[0],py[0]) );
}
double Adams2(double *px, double* py, double h){
    return py[3] + h/24*( 9* f(px[4],py[4]) + 19* f(px[3],py[3]) - 5* f(px[2],py[2]) + 9* f(px[1],py[1]) );
}
int main(){
    double x[100],y[100],h;
    int i = 0 , j = 0 ;
    cout<<"Please input h:";
    cin>>h;
    cout<<"Please input x[0],y[0]:";
    cin>>x[i]>>y[i];
    i++;
    for( ; i < 4; i++){
        x[i] = x[i-1] + h;
        y[i] = R_K(x[i-1],y[i-1],h);
    }
    for( ; i < 20; i++){
        x[i] = x[i-1] + h;
        y[i] = Adams1(x+i-4,y+i-4,h);
        y[i] = Adams2(x+i-4,y+i-4,h);
    }
    for( j = 0 ; j < i ; j++ ){
        cout<<"x["<<j<<"] = "<<x[j]<<"  y["<<j<<"] = "<<y[j]<<endl;
    }


}

