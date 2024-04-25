#include <stdio.h>
#include <thread>
using namespace std;
// Kernel definition
void VecAdd(int* A, int* B, int* C, int i)
{
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
    //VecAdd<<<1, N>>>(A, B, C);
    thread* ths[N];
    for (int i=0; i<100; i++){
        ths[i]=new thread(VecAdd, A, B, C, i);
    }
    for (int i=0; i<100; i++){
        ths[i]->join();
    }
    printVec(C, N);

}