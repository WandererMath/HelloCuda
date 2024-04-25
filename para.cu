#include <stdio.h>

// Kernel definition
__global__ void VecAdd(int* A, int* B, int* C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
    //printf("threadIDx: %d\n", i);
}


void initVec(int* A, int n){
    for(int i=0; i<n;i++){
        A[i]=i;
    }
}

void printVec(int* A, int n){
    for(int i=0; i<n;i++){
        printf("Element %d:  %d\n", i, A[i]);
    }
}

int main()
{
    const int N=100;
    int A[N];
    int B[N];
    int C[N];

    initVec(A, N);
    initVec(B,N);
    // Kernel invocation with N threads
    VecAdd<<<1, N>>>(A, B, C);
    printVec(C, N);

}