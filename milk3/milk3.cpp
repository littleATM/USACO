
/*
ID: yang.su1
PROG:milk3
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct milk
{
       int a;
       int b;
       int c;
};
int pureYtoX(int a,int b,int c,int d);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("milk3.in");
    outFile.open("milk3.out");
    int A,B,C;
    inFile>>A>>B>>C;
    inFile.close();
    milk *input=new milk[10000];
    input[0].a=0;
    input[0].b=0;
    input[0].c=C;
    int i,j,k,n,m;
    i=0;
    for(k=0;k<=i;k++)
    {
          for(j=0;j<=i;j++)
                           if(input[j].a==pureYtoX(input[k].a,input[k].b,A,B)&&input[j].c==input[k].c)
                           break;
          if(j>i)
          {
                 input[i+1].a=pureYtoX(input[k].a,input[k].b,A,B);
                 input[i+1].b=input[k].a+input[k].b-pureYtoX(input[k].a,input[k].b,A,B);
                 input[i+1].c=input[k].c;
                 i++;
          }
          for(j=0;j<=i;j++)
                           if(input[j].b==pureYtoX(input[k].b,input[k].a,B,A)&&input[j].c==input[k].c)
                           break;
          if(j>i)
          {
                 input[i+1].b=pureYtoX(input[k].b,input[k].a,B,A);
                 input[i+1].a=input[k].b+input[k].a-pureYtoX(input[k].b,input[k].a,B,A);
                 input[i+1].c=input[k].c;
                 i++;
          }   
          for(j=0;j<=i;j++)
                           if(input[j].b==pureYtoX(input[k].b,input[k].c,B,C)&&input[j].a==input[k].a)
                           break;
          if(j>i)
          {
                 input[i+1].b=pureYtoX(input[k].b,input[k].c,B,C);
                 input[i+1].c=input[k].b+input[k].c-pureYtoX(input[k].b,input[k].c,B,C);
                 input[i+1].a=input[k].a;
                 i++;
          }   
          for(j=0;j<=i;j++)
                           if(input[j].c==pureYtoX(input[k].c,input[k].b,C,B)&&input[j].a==input[k].a)
                           break;
          if(j>i)
          {
                 input[i+1].c=pureYtoX(input[k].c,input[k].b,C,B);
                 input[i+1].b=input[k].c+input[k].b-pureYtoX(input[k].c,input[k].b,C,B);
                 input[i+1].a=input[k].a;
                 i++;
          }   
          for(j=0;j<=i;j++)
                           if(input[j].a==pureYtoX(input[k].a,input[k].c,A,C)&&input[j].b==input[k].b)
                           break;
          if(j>i)
          {
                 input[i+1].a=pureYtoX(input[k].a,input[k].c,A,C);
                 input[i+1].c=input[k].a+input[k].c-pureYtoX(input[k].a,input[k].c,A,C);
                 input[i+1].b=input[k].b;
                 i++;
          }   
          for(j=0;j<=i;j++)
                           if(input[j].c==pureYtoX(input[k].c,input[k].a,C,A)&&input[j].b==input[k].b)
                           break;
          if(j>i)
          {
                 input[i+1].c=pureYtoX(input[k].c,input[k].a,C,A);
                 input[i+1].a=input[k].a+input[k].c-pureYtoX(input[k].c,input[k].a,C,A);
                 input[i+1].b=input[k].b;
                 i++;
          }       
    }
    k=0;
    n=0;
    int *output=new int[10001];
    output[0]=C;
    for(j=0;j<=i;j++)
    {
                     if(input[j].a==0&&input[j].c!=C)
                     {
                                      for(k=0;input[j].c>output[k]&&k<=n;k++);
                                                                           for(m=n;m>=k;m--)
                                                                           output[m+1]=output[m];
                                                                           output[k]=input[j].c;
                                                                           n++;
                     }
    }
    for(i=0;i!=n;i++)
    {
                     outFile<<output[i]<<" ";
    }
    outFile<<output[n]<<endl;
    return 0;
}
int pureYtoX(int x,int y,int X,int Y)
{
    if(y>=X-x)
    return X;
    else
    return (x+y);
} 
