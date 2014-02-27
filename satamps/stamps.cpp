/*
ID: yang.su1
PROG:stamps
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("stamps.in");
    outFile.open("stamps.out");
    int K,N;
    int v[51];
    int t[2000000]={0};
    int i,j;
    inFile>>K>>N;
    for(i=1;i<=N;i++)
        inFile>>v[i];
    for(i=0;t[i]<=K;i++)
        for(j=1;j<=N;j++)
            t[i+v[j]]=(t[i+v[j]]==0?(t[i]+1):(t[i+v[j]]<t[i]+1?t[i+v[j]]:t[i]+1));
    outFile<<i-1<<endl;
    return 0;
}
