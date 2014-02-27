
/*
ID: yang.su1
PROG:cowtour
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int N;
int w;
int x[151];
int y[151];
double pas[151][151];
char pass[151][151];
int move(int i,int j,double dis);
int move2(int i);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("cowtour.in");
    outFile.open("cowtour.out");
    inFile>>N;
    int i,j;
    for(i=1;i<=N;i++)
      inFile>>x[i]>>y[i];
    for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
        inFile>>pass[i][j];
    for(i=1;i<=N;i++){
      pas[i][0]=0;
      for(j=1;j<=N;j++)
        pas[i][j]=(i==j?0:-1);
      }
    w=1;
    for(i=1;i<=N;i++)
      move(i,i,0);
    for(i=1;i<=N;i++){
        if(pas[i][0]==0){
          move2(i);
          w++;
          }
       }  
    for(i=1;i<=N;i++){
      pas[0][i]=0;
      for(j=1;j<=N;j++)
        pas[0][i]=(pas[0][i]>pas[i][j]?pas[0][i]:pas[i][j]);
      }
    pas[0][0]=0;
    for(i=1;i<=N;i++)
      pas[0][0]=(pas[0][0]>pas[0][i]?pas[0][0]:pas[0][i]);
    w-=1;
    double min;
    min=0;
    for(;w>0;--w)
      for(i=1;i<=N;i++)
        if(pas[i][0]==w)
          for(j=1;j<=N;j++)
            if(pas[j][0]<w){
              min=((min>(pas[0][i]+pas[0][j]+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)))||min==0)?(pas[0][i]+pas[0][j]+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))):min);
    }
    outFile.precision(6);
    outFile<<fixed<<(min<pas[0][0]?pas[0][0]:min)<<endl;
    return 0;  
}
int move(int i,int j,double dis){
    int k;
    for(k=1;k<=N;k++)
      if(pass[j][k]=='1'&&j!=k){
        if(pas[i][k]==-1){
          pas[i][k]=dis+sqrt(pow(x[k]-x[j],2)+pow(y[k]-y[j],2));
          move(i,k,pas[i][k]);
          }
        if(pas[i][k]>dis+sqrt(pow(x[k]-x[j],2)+pow(y[k]-y[j],2))){
          pas[i][k]=dis+sqrt(pow(x[k]-x[j],2)+pow(y[k]-y[j],2));
          move(i,k,pas[i][k]);
          }
        }
      return 0;      
}
int move2(int i)
{
    if(pas[i][0]==0){
      pas[i][0]=w;
      for(int j=1;j<=N;j++)
        if(pass[i][j]=='1')
          move2(j);
      }
}
