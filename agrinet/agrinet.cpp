
/*
ID: yang.su1
PROG:agrinet
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("agrinet.in");
    outFile.open("agrinet.out");
    int N;
    int A[101][101];
    inFile>>N;
    int i,j,w,n,J;
    for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
           inFile>>A[i][j];
    for(i=1;i<=N;i++)
        A[i][0]=0;
    A[1][0]=1;
    int max;
    int min;
    max=0;
    min=100001;
    for(w=1;w<=N;w++){
        for(i=1;i<=N;i++)
            if(A[i][0]==1)
                for(j=1;j<=N;j++)
                    if(A[j][0]!=1)
                        if(min>A[i][j]){
                            min=A[i][j];
                            J=j;
                            }
        A[J][0]=1;
        if(min!=100001)
            max+=min;
        min=100001;
        }
    outFile<<max<<endl;        
} 
