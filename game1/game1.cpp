/*
ID: yang.su1
PROG:game1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("game1.in");
    outFile.open("game1.out");
    int N;
    inFile>>N;
    int a[101][101][2]={0};
    int i,j,k,w;
    for(i=1;i<=N;i++)
        inFile>>a[i][i][0];
    for(w=1;w<=N-1;w++)
        for(i=1;i+w<=N;i++){
            a[i][i+w][0]=((a[i][i+w-1][1]+a[i+w][i+w][0])>(a[i+1][i+w][1]+a[i][i][0])?(a[i][i+w-1][1]+a[i+w][i+w][0]):(a[i+1][i+w][1]+a[i][i][0]));
            a[i][i+w][1]=a[i][i][0]+a[i+1][i+w][0]+a[i+1][i+w][1]-a[i][i+w][0];
            }
    outFile<<a[1][N][0]<<" "<<a[1][N][1]<<endl;
    return 0;
    }
