#include <iostream>
#include <cstdlib>
#include <sys/time.h>

void imprimirMatriz(double **matrix,int row,int columns){
  std::cout << std::endl;
  /*Imprimiendo*/
  for(int i = 0; i < row; i++){
    for(int j = 0; j < columns; j++){
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void inicializar(int p,int q,int r, double **&A,double **&B,double **&C){
  A = new double*[p];
  B = new double*[q];
  C = new double*[p];

  for(int i=0;i<p;i++)
    A[i] = new double[q];

  for(int i=0;i<q;i++)
    B[i] = new double[r];

  for(int i=0;i<p;i++)
    C[i] = new double[r];

  for(int i = 0; i < p; i++)
    for(int j = 0; j < q; j++)
      A[i][j] = 1.0;

  for(int i = 0; i < q; i++)
    for(int j = 0; j < r; j++)
      B[i][j] = 1.0;

}

void multiplicar(int p,int q,int r, double **&A,double **&B, double **&C){
  for(int i=0;i<p;i++){
    for(int j=0;j<r;j++){
      C[i][j] = 0.0;
      for(int k=0;k<q;k++){
        C[i][j] = C[i][j] + A[i][k]*B[k][j];
      }
    }
  }
}

void decir(std::string s){
  std::cout << s << std::endl;
}

int main(int argc, char **argv){
  int p = atoi(argv[1]);
  int q = atoi(argv[2]);
  int r = atoi(argv[3]);

  double **A, **B, **C;
  struct timeval start, end;
  //srand(time(NULL));
  inicializar(p,q,r,A,B,C);
  gettimeofday(&start, NULL);
  multiplicar(p,q,r,A,B,C);
  gettimeofday(&end, NULL);
  double delta = ((end.tv_sec  - start.tv_sec) * 1000000u +
         end.tv_usec - start.tv_usec) / 1.e6;
  std::cout << "Tiempo en segundos: " << delta << std::endl;
  //imprimirMatriz(A,p,q);
  //imprimirMatriz(B,q,r);
  //imprimirMatriz(C,p,r);

  return 0;
}
