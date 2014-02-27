/*
ID: yang.su1
PROG:calfflac
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("calfflac.in");
    outFile.open("calfflac.out");
    string str1,str2,str3;
    int i,j,k,n,length,longest=0,m,min,max;
    char qqq='\n';
    str3=qqq;

    for(;getline(inFile,str2);)
    {
    str2=str2+str3;
    str1=str1+str2;
    str2.clear();

    }
    n=str1.size();
    char *array=new char[n+1];
    for(i=0,j=-1;i!=n;i++)
    {
                     if(str1[i]>=65&&str1[i]<=90)
                     {
                                                 j++;
                                                 array[j]=str1[i];
                     }
                     if(str1[i]>=97&&str1[i]<=122)
                     {
                                                  j++;
                                                  array[j]=str1[i]-32;
                     }
    }
    array[j+1]='\0';
    for(i=0;i!=j+1;i++)
    {
                      for(k=i,length=1;(2*i-k-1)>=0&&k<=j;k++)
                      {
                                             if(array[2*i-k-1]==array[k+1])
                                             {
                                                                       length=length+2;
                                             }
                                             else
                                             break;
                      } 
                      if(length>longest)
                      {
                                        longest=length;
                                        m=i;
                                        n=1;
                      }
                      for(k=i,length=0;(2*i-k)>=0&&(k+1)<=j;k++)
                      {
                                            if(array[2*i-k]==array[k+1])
                                            {
                                                                length=length+2;
                                            }
                                            else
                                            break;
                      }
                      if(length>longest)
                      {
                                        longest=length;
                                        m=i;
                                        n=0;
                      }
    }

    if(n==1)
    {
            for(i=0,j=0;j!=m+1+(longest-1)/2;i++)
            {
                         if((str1[i]<=90&&str1[i]>=65)||(str1[i]>=97&&str1[i]<=122))
                         j++;
            }
            max=i-1;
                        for(i=0,j=0;j!=m+1-(longest-1)/2;i++)
            {
                         if((str1[i]<=90&&str1[i]>=65)||(str1[i]>=97&&str1[i]<=122))
                         j++;
            }
            min=i-1;
    }
    else
    {
                    for(i=0,j=0;j!=m+1+(longest)/2;i++)
            {
                         if((str1[i]<=90&&str1[i]>=65)||(str1[i]>=97&&str1[i]<=122))
                         j++;
            }
            max=i-1;
                        for(i=0,j=0;j!=m+2-(longest)/2;i++)
            {
                         if((str1[i]<=90&&str1[i]>=65)||(str1[i]>=97&&str1[i]<=122))
                         j++;
            }
            min=i-1;
        
    }
    outFile<<longest<<endl;
    for(i=min;i<=max;i++)
    {
                         outFile<<str1[i];
    }
    outFile<<endl;
    return 0;
    
    
}

