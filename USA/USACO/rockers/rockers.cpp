/*
ID: yang.su1
PROG:rockers
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile("rockers.in");
    ofstream outFile("rockers.out");
    int N,T,M;
    int i,j,k,w,max;
    int input[22];
    int song[22][22][2];
    for(i=0;i<=21;i++)
        for(j=0;j<=21;j++){
            song[i][j][0]=0;
            song[i][j][1]=0;
            }
    song[1][0][0]=1;
    song[1][0][1]=0;
    inFile>>N>>T>>M;
    j=1;
    for(i=1;i<=N;i++){
        inFile>>input[j];
        if(input[j]<=T)
            j++;
        }
    N=j-1;
    if(j=1&&input[1]>T){
        outFile<<0<<endl;
        return 0;
        }
    for(k=1;k<=N;k++){
        for(i=M;i>=0;i--)
            for(j=T;j>=0;j--){
                if(song[i][j][0]==1){
                    if(j+input[k]<=T){
                        song[i][j+input[k]][0]=1;
                        song[i][j+input[k]][1]=(song[i][j+input[k]][1]>(song[i][j][1]+1)?song[i][j+input[k]][1]:(song[i][j][1]+1));
                        }
                    else{
                         song[i+1][input[k]][0]=1;
                         song[i+1][input[k]][1]=(song[i+1][input[k]][1]>(song[i][j][1]+1)?song[i+1][input[k]][1]:(song[i][j][1]+1));
                         }
                    }
                }
        }
    max=0;
    for(i=1;i<=M;i++)
        for(j=1;j<=T;j++)
            if(song[i][j][0]==1)
                max=(max>song[i][j][1]?max:song[i][j][1]);
    outFile<<max<<endl;
    return 0;
    }
