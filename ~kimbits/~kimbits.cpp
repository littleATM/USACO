/*
ID: yang.su1
PROG:kimbits
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("kimbits.in");
    outFile.open("kimbits.out");
    unsigned int N,L,I;
    inFile>>N>>L>>I;
    unsigned int i,j,k,w;
    unsigned int a[33][33]={0};
    for(i=0;i!=33;i++){
        a[i][0]=1;
        a[0][i]=1;
        }
    for(i=1;i!=33;i++)
        for(j=1;j!=33;j++)
            a[j][i]=a[j-1][i]+a[j-1][i-1];
    for(i=N;i>=1;i--){
        if(a[i-1][L]<I){
            outFile<<1;
            I-=a[i-1][L];
            L--;
            }
        else
            outFile<<0;  
        }
    outFile<<endl;
    return 0;
    } 
