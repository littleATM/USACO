
/*
ID: yang.su1
PROG:crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int judge(int a[],int m);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("crypt1.in");
    outFile.open("crypt1.out");
    int N,i,j,sum=0;
    inFile>>N;
    int *figure=new int[N+1];
    figure[N]=0;
    for(i=0;i!=N;i++)
    {
                     inFile>>figure[i];
    }
    for(i=111;i!=1000;i++)
    {
                          if(judge(figure,i))
                          {
                                             for(j=11;j!=100;j++)
                                             {
                                                                 if(judge(figure,j)&&judge(figure,(j%10)*i)&&(((j%10)*i)/1000==0)&&judge(figure,(j/10)*i)&&((j/10)*i)/1000==0&&judge(figure,i*j)&&(i*j)/10000==0)
                                                                 {
                                                                                                                                                              sum++; 
                                                                 }
                                             }
                          }
    }
    outFile<<sum<<endl;
    return 0;
}
int judge(int a[],int m)
{
    int i,j,n;
    for(j=1;m/j!=0;j=j*10)
    {
                           n=0;
                           for(i=0;a[i]!=0;i++)
                           {
                                               if(a[i]==(m/j-10*(m/(j*10))))
                                               {
                                                                            n=1;
                                                                            break;
                                               }
                           }
                           if(n==0)
                           break;
    }
    return n;
} 
