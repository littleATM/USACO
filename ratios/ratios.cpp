
/*
ID: yang.su1
PROG:ratios
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int divisor(int m,int n);
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("ratios.in");
    outFile.open("ratios.out");
    int a[4][4]={0};
    int i,j,k,w;
    for(i=0;i!=4;i++)
        for(j=1;j!=4;j++)
            inFile>>a[i][j];
    if(a[1][2]!=0){
    a[2][2]=a[2][2]*a[1][1]-a[2][1]*a[1][2];
    a[3][2]=a[3][2]*a[1][1]-a[3][1]*a[1][2];
    a[0][2]=a[0][2]*a[1][1]-a[0][1]*a[1][2];
    }
    if(a[1][3]!=0){
    a[2][3]=a[2][3]*a[1][1]-a[2][1]*a[1][3];
    a[3][3]=a[3][3]*a[1][1]-a[3][1]*a[1][3];
    a[0][3]=a[0][3]*a[1][1]-a[0][1]*a[1][3];
        }
    if(a[2][3]!=0){
    a[3][3]=a[3][3]*a[2][2]-a[3][2]*a[2][3];
    a[0][3]=a[0][3]*a[2][2]-a[0][2]*a[2][3];
        } 
    
    a[3][0]=a[0][3];
    a[0][0]=a[3][3];
    /*if((a[0][0]*a[0][2]-a[3][2]*a[3][0])%a[2][2]!=0||(a[0][0]*a[0][1]-a[3][0]*a[3][1]-a[2][0]*a[2][1])%a[1][1]!=0){
        outFile<<"none"<<endl;
        return 0;
        }*/
    a[2][0]=(a[0][0]*a[0][2]-a[3][2]*a[3][0])/a[2][2];

    a[1][0]=(a[0][0]*a[0][1]-a[3][0]*a[3][1]-a[2][0]*a[2][1])/a[1][1];

    if(a[0][0]<0||a[1][0]<0||a[2][0]<0||a[3][0]<0)
        for(i=0;i!=4;i++)
            a[i][0]*=-1;
    if(a[0][0]<0||a[1][0]<0||a[2][0]<0||a[3][0]<0){
        outFile<<"NONE"<<endl;   
        return 0;
        } 

    
    w=divisor(a[0][0],divisor(a[1][0],divisor(a[2][0],a[3][0])));
    outFile<<a[1][0]/w<<" "<<a[2][0]/w<<" "<<a[3][0]/w<<" "<<a[0][0]/w<<endl;
    return 0;
    } 
int divisor(int m,int n){
    int max,min;
    if(m==0)
    return n;
    if(n==0)
    return m;
    for(;m!=n;){
        min=(m<n?m:n);
        max=(m>n?m:n);
        n=min;
        m=max-min;
        }
    return m;
    }
