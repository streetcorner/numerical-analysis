#include<iostream>
#include<cmath>
using namespace std;

#define n 3

double LieZhuYuan(double A[n+1][n+1],double b[n+1]){
    double det = 1;
    int k,i,j,ik;
    double maxd,temp;
    for(k = 1; k < n ;k++ ){
        maxd = 0.0,ik = 0;
        for(i = k; i <= n ;i++){
          if(abs(A[i][k]) > maxd){
            maxd = abs(A[i][k]);
            ik = i;
          }
        }
        if(A[ik][k] == 0) return 0;
        if(ik != k){
            for(j = k; j <= n ; j++){
                temp = A[k][j];
                A[k][j] = A[ik][j];
                A[ik][j] = temp;
            }
            temp = b[k];
            b[k] = b[ik];
            b[ik] = temp;
            det = -det;
        }
        for(i = k+1; i <= n ;i++){
            A[i][k] = A[i][k]/A[k][k];

            for(j = k+1; j<=n ;j++){
                A[i][j] = A[i][j] - A[i][k] * A[k][j];
            }
            b[i] = b[i] - A[i][k] * b[k];
        }
        det = A[k][k] * det;
    }
    /*
    for(i=1; i<=n; i++){
        for(j=i;j<=n;j++){
            cout<<"A["<<i<<"]["<<j<<"] = "<<A[i][j]<<" ";
        }
        cout<<endl;
    }
   */
    if(A[n][n] == 0) return 0;
    b[n] = b[n] / A[n][n];
    for( i = n-1 ; i >= 1 ; i--){
        for(j = i+1 ; j<=n ; j++){
            b[i] = b[i] - A[i][j] * b[j];
        }
        b[i] = b[i]/A[i][i];
    }
    det = A[n][n] * det;
    return det;
}

int main(){

    double A[n+1][n+1] = {
                           {0.000,0.000,0.000,0.000},
                           {0.000,0.001,2.000,3.000},
                           {0.000,-1.000,3.712,4.623},
                           {0.000,-2.000,1.072,5.643},
                         };
    double b[n+1] = { 0.000, 1.000, 2.000, 3.000 },det;

    det = LieZhuYuan( A, b);
    cout<<"x ="<<endl;
    for( int i = 1 ; i <= n ;i ++)
        cout<<""<<b[i]<<" "<<endl;
    cout<<endl<<"The det is "<<det<<endl;
}



