#include "inst_none.h"
#include <iostream>
using namespace std;


const int matrixSize = 6;
const int blockingFactor = 2;
int a[matrixSize][matrixSize];
int b[matrixSize][matrixSize];
int c[matrixSize][matrixSize];

int main() {
    int i, j, k, jj, kk, r;
    // Initialise the matrices arbitrarily
    for (i=0; i < matrixSize; i++){
        for (j=0; j < matrixSize; j++) {
            b[i][j] = i + j; 
            c[i][j] = i - j; 
            a[i][j] = 0;
        }
    }
    
    // Work out a = b * c, using a blocking algorithm
    jj = 0;
    kk = 0;
    while (jj < matrixSize) {
        while (kk < matrixSize) {
            for (i=0; i < matrixSize; i++){
                for (j=jj; j < jj + blockingFactor; j++) {
                    r = 0;
                    for (k=kk; k < kk + blockingFactor; k++) {
                        INST_R(b[i][k]);
                        cout << "INST_R(b["<<i<<"]["<<k<<"])" << endl;
                        INST_R(c[k][j]);
                        cout << "INST_R(c["<<k<<"]["<<j<<"])" << endl;
                        r += b[i][k] * c[k][j];
                    }
                    INST_R(a[i][j]);
                    cout << "INST_R(a["<<i<<"]["<<j<<"])" << endl;
                    a[i][j] = a[i][j] + r;
                    INST_W(a[i][j]);
                    cout << "INST_W(a["<<i<<"]["<<j<<"])" << endl;
                }
            }
            kk += blockingFactor;
        }
        kk = 0;
        jj += blockingFactor;
    }
    
    // Display the product
    for (i=0; i < matrixSize; i++) {
        for (j=0; j < matrixSize; j++){
            // cerr << a[i][j] << ' ';
        }
        cerr << endl;
    }
    return 0;
}
