#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
const int N = 9;


double fxi[N];
double xi[2*N-1] = {0,1,2,4,7,9,13,16,20,25,31,36,42,49,57,64};

int main(){

  for(int i = 0; i < 16;i++)
  {
      fxi[i] = sqrt(xi[i]);
  }

   freopen("sqrt_out3(64).txt", "w", stdout);

    printf("xi       yi    (i from 0 to 20)\n");
    for(int i = 0; i <16;i++){
        printf("%.4f   %.4f\n",xi[i],fxi[i]);
    }
   fclose(stdout);
    return 0;
}
