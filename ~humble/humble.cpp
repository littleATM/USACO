
/*
ID: yang.su1
PROG:humble
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("humble.in");
    outFile.open("humble.out");
    int K,N;
    int A[102];
    int i,j,w,k,min,I;
    inFile>>K>>N;
    for(i=1;i<=N;i++)
        inFile>>A[i];
    long long Q[100002];
    int B[102];
    for(i=1;i<=K;i++)
        B[i]=0;
    Q[0]=1;
    for(w=1;w<=N;w++){
        min=Q[B[1]]*A[1];
        for(i=1;i<=K;i++)
            min=(min<Q[B[i]]*A[i]?min:Q[B[i]]*A[i]);
        Q[w]=min;
        for(i=1;i<=K;i++)
            if(Q[B[i]]*A[i]==min)
                B[i]++;       
        }
     outFile<<Q[N]<<endl;    
} 
