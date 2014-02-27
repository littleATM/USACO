
/*
ID: yang.su1
PROG:preface
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int I=0;
int V=0;
int X=0;
int L=0;
int C=0;
int D=0;
int M=0;
int check(int i,int *X,int *Y,int *Z);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("preface.in");
    outFile.open("preface.out");
    int N;
    int i;
    inFile>>N;
    inFile.close();
    for(i=1;i<=N;i++)
    {
                     check(i/1000,&M,&M,&M);
                     check((i/100-(i/1000)*10),&M,&D,&C);
                     check((i/10-(i/100)*10),&C,&L,&X);
                     check(i-(i/10)*10,&X,&V,&I);                   
    }
    if(I!=0)
    outFile<<"I "<<I<<endl;
    if(V!=0)
    outFile<<"V "<<V<<endl;
    if(X!=0)
    outFile<<"X "<<X<<endl;
    if(L!=0)
    outFile<<"L "<<L<<endl;
    if(C!=0)
    outFile<<"C "<<C<<endl;
    if(D!=0)
    outFile<<"D "<<D<<endl;
    if(M!=0)
    outFile<<"M "<<M<<endl;
    return 0;
} 
int check(int i,int *O,int *P,int *Q)
{
    
              if(i==9)
              {
                      *O=*O+1;
                      *Q=*Q+1;
              }
              if(i>=5&&i<=8)
              {
                            *P=*P+1;
                            *Q=*Q+i-5;
              }
              if(i==4)
              {
                      *P=*P+1;
                      *Q=*Q+1;
              }
              if(i<=3)
              *Q=*Q+i;
              return 0;
}
