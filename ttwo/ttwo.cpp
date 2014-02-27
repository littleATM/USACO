/*
ID: yang.su1
PROG:ttwo
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
      ifstream inFile;
      ofstream outFile;
      inFile.open("ttwo.in");
      outFile.open("ttwo.out");
      int i,j,k,iC,jC,iF,jF,dC,dF,Ci,Cj,Fi,Fj;
      char forest[12][12];
      for(i=0;i<=11;i++)
      for(j=0;j<=11;j++)
      {
                        if(i==0||j==0||i==11||j==11)
                        forest[i][j]='*';
                        else
                        {
                        inFile>>forest[i][j];
                        if(forest[i][j]=='C')
                        {
                                           forest[i][j]='.';
                                           iC=i;
                                           jC=j;
                        }
                        if(forest[i][j]=='F')
                        {
                                          forest[i][j]='.';
                                          iF=i;
                                          jF=j;
                        }
                        }
      }
      dC=0;
      dF=0;
      for(k=0;k<=11000;k++)
      {
                                           if(iC==iF&&jC==jF)
                                           {
                                                             outFile<<k<<endl;
                                                             return 0;
                                           }
                                           Ci=iC;
                                           Cj=jC;
                                           Fi=iF;
                                           Fj=jF;
                                           if(dC==0&&forest[iC-1][jC]=='.')                                           
                                           iC--;
                                           if(dC==1&&forest[iC][jC+1]=='.')
                                           jC++;
                                           if(dC==2&&forest[iC+1][jC]=='.')
                                           iC++;
                                           if(dC==3&&forest[iC][jC-1]=='.')
                                           jC--;
                                           if(Ci==iC&&Cj==jC)
                                           dC=(dC+1)%4;
                                           if(dF==0&&forest[iF-1][jF]=='.')                                           
                                           iF--;
                                           if(dF==1&&forest[iF][jF+1]=='.')
                                           jF++;
                                           if(dF==2&&forest[iF+1][jF]=='.')
                                           iF++;
                                           if(dF==3&&forest[iF][jF-1]=='.')
                                           jF--;
                                           if(Fi==iF&&Fj==jF)
                                           dF=(dF+1)%4;
      }
      outFile<<0<<endl;
      return 0;
}
