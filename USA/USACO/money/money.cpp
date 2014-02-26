
/*
ID: yang.su1
PROG:money
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("money.in");
    outFile.open("money.out");
    int V,N,i,j,p,k;
    inFile>>V>>N;
    int inPut[26];
    inPut[0]=0;
    for(i=1;i<=V;i++)
    inFile>>inPut[i];
    long long outPut[26][10003];
    for(i=0;i<=V;i++)
    for(j=0;j<=N;j++)
    outPut[i][j]=0;
    for(i=0;i<=V;i++)
    outPut[i][0]=1;
    for(j=1;j<=N;j++)
    outPut[0][j]=0;
    for(i=1;i<=V;i++)
    for(j=1;j<=N;j++)
    {
                     for(k=0;k<=j/inPut[i];k++)
                     outPut[i][j]+=outPut[i-1][j-k*inPut[i]];
    }
    outFile<<outPut[V][N]<<endl;
    return 0;
}
