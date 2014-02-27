/*
ID: yang.su1
PROG:inflate
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("inflate.in");
    outFile.open("inflate.out");
    int M,N;
    inFile>>M>>N;
    int p[10001];
    int t[10001];
    int pmax[120000];
    int i,j,k,w,imax,sum;
    for(i=1;i<=N;i++)
        inFile>>p[i]>>t[i];
    for(i=1;i<=M;i++)
        pmax[i]=0;
    for(i=0;i<=M;i++)
        for(j=1;j<=N;j++)
            pmax[i+t[j]]=(pmax[i+t[j]]>(pmax[i]+p[j])?pmax[i+t[j]]:(pmax[i]+p[j]));
    outFile<<pmax[M]<<endl;
    return 0;      
}
