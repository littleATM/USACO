
/*
ID: yang.su1
PROG:range
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("range.in");
    outFile.open("range.out");
    int N;
    inFile>>N;
    int a[251][251]={0};
    int i,j,k,w;
    char x;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++){
            inFile>>x;
            a[i][j]=x-48;
            }
    for(k=2;k<=N;k++){
        w=0;
        for(i=1;i<=N-k+1;i++)
            for(j=1;j<=N-k+1;j++){
                if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1){
                    a[i][j]=1;
                    w++;
                    }
                else
                    a[i][j]=0;
                }
        if(w==0)
            break;
        else{
            outFile<<k<<" "<<w<<endl;
            }
        }
    return 0;
    } 
