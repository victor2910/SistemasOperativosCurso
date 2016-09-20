#include <iostream>
#include <cstdlib>
#include <sys/time.h>

void inicializar(int n, double **&A,double **&B,double **&C){
  A = new double*[n];
  B = new double*[n];
  C = new double*[n];
  for(int i=0;i<n;i++){
    A[i] = new double[n];
    B[i] = new double[n];
    C[i] = new double[n];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      A[i][j] = 1.0;
      B[i][j] = 1.0;
    }
  }
}

void multiplicar(int n, double **&A,double **&B, double **&C){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j] = 0.0;
      for(int k=0;k<n;k++){
        C[i][j] = C[i][j] + A[i][k]*B[k][j];
      }
    }
  }
}

void decir(std::string s){
  std::cout << s << std::endl;
}

int main(int argc, char **argv){
  int n = atoi(argv[1]);
  double **A, **B, **C;
  struct timeval start, end;
  //srand(time(NULL));
  inicializar(n,A,B,C);
  gettimeofday(&start, NULL);
  multiplicar(n,A,B,C);
  gettimeofday(&end, NULL);
  double delta = ((end.tv_sec  - start.tv_sec) * 1000000u +
         end.tv_usec - start.tv_usec) / 1.e6;
  std::cout << "Tiempo en segundos: " << delta << std::endl;

  return 0;
}
