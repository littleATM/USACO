/*
ID: yang.su1
PROG:butter
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("butter.in");
    outFile.open("butter.out");
    short a[801][801]={0};
    int N,P,C;
    int i,j,k,w,sum,min;
    inFile>>N>>P>>C;
    for(i=1;i<=N;i++){
        inFile>>j;
        a[0][j]++;
        }
    for(i=1;i<=C;i++){
        inFile>>j>>k>>w;
        a[j][k]=w;
        a[k][j]=w;
        a[j][0]++;
        a[k][0]++;
        }
    for(w=1;w<=P;w++)
        if(a[w][0]!=1)
        for(i=1;i<=P;i++)
            if(a[i][w]!=0)
            for(j=i;j<=P;j++)
                if(a[j][w]!=0&&i!=j){
                    if(a[i][j]==0||a[i][j]>a[i][w]+a[j][w]){
                        a[i][j]=a[i][w]+a[j][w];
                        a[j][i]=a[i][j];
                        }
                    }
    for(i=1;i<=P;i++){
        sum=0;
        for(j=1;j<=P;j++)
            sum+=a[i][j]*a[0][j];
        if(i==1)
            min=sum;
        else
            min=(min<sum?min:sum);
        }
    outFile<<min<<endl;
    return 0;
    }
