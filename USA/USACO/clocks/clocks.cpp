
/*
ID: yang.su1
PROG:clocks
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct clocks
{
       int point[9];
};
int r=0;
int check(clocks a);
clocks move1(clocks a);
clocks move2(clocks a);
clocks move3(clocks a);
clocks move4(clocks a);
clocks move5(clocks a);
clocks move6(clocks a);
clocks move7(clocks a);
clocks move8(clocks a);
clocks move9(clocks a);
int main()
{
    ofstream outFile;
    ifstream inFile;
    inFile.open("clocks.in");
    outFile.open("clocks.out");
    int i,j,n,m=0;
    clocks input,mid;
    for(i=0;i!=9;i++)
                      inFile>>input.point[i];
    mid=input;
    int output[20];
    int i1,i2,i3,i4,i5,i6,i7,i8,i9;
    for(i1=1;i1!=5&&r!=1;i1++)
    {   
                        mid=move1(mid);
                        check(mid);
                        for(i2=1;i2!=5&&r!=1;i2++)
                        {   
                            mid=move2(mid);
                            check(mid);
                            for(i3=1;i3!=5&&r!=1;i3++)
                            {   
                                mid=move3(mid);
                                check(mid);
                                for(i4=1;i4!=5&&r!=1;i4++)
                                {   
                                    mid=move4(mid);
                                    check(mid);
                                    for(i5=1;i5!=5&&r!=1;i5++)
                                    {   
                                        mid=move5(mid);
                                        check(mid);
                                        for(i6=1;i6!=5&&r!=1;i6++)
                                        {   
                                            mid=move6(mid);
                                            check(mid);
                                            for(i7=1;i7!=5&&r!=1;i7++)
                                            {   
                                                mid=move7(mid);
                                                check(mid);
                                                for(i8=1;i8!=5&&r!=1;i8++)
                                                {   
                                                    mid=move8(mid);
                                                    check(mid);
                                                    for(i9=1;i9!=5&&r!=1;i9++)
                                                    {   
                                                        mid=move9(mid);
                                                        check(mid);                                                          
                                                    }         
                                                }         
                                            }         
                                        }         
                                    }         
                                }         
                            }         
                        }         
    }
    for(i=1;i<=9;i++)
    {
                      if(i==1)
                      j=i1-1;
                      if(i==2)
                      j=i2-1;
                      if(i==3)
                      j=i3-1;
                      if(i==4)
                      j=i4-1;
                      if(i==5)
                      j=i5-1;
                      if(i==6)
                      j=i6-1;
                      if(i==7)
                      j=i7-1;
                      if(i==8)
                      j=i8-1;
                      if(i==9)
                      j=i9-1;
                      for(n=1;n<=(j%4);n++)
                      {
                                       output[m]=i;
                                       m++;
                      }
                      
    }
    for(i=0;i!=m-1;i++)
    {
                       outFile<<output[i]<<" ";
    }
    outFile<<output[m-1]<<endl;
    
    
    return 0;
    
    
    
}

clocks move1(clocks a)
{
    a.point[0]+=3;
    a.point[1]+=3;
    a.point[3]+=3;
    a.point[4]+=3;
    return a;
}
clocks move2(clocks a)
{
    a.point[0]+=3;
    a.point[1]+=3;
    a.point[2]+=3;
    return a;
}
clocks move3(clocks a)
{
    a.point[1]+=3;
    a.point[2]+=3;
    a.point[4]+=3;
    a.point[5]+=3;
    return a;
}
clocks move4(clocks a)
{
    a.point[0]+=3;
    a.point[3]+=3;
    a.point[6]+=3;
    return a;
}
clocks move5(clocks a)
{
    a.point[1]+=3;
    a.point[3]+=3;
    a.point[4]+=3;
    a.point[5]+=3;
    a.point[7]+=3;
    return a;
}
clocks move6(clocks a)
{
    a.point[2]+=3;
    a.point[5]+=3;
    a.point[8]+=3;
    return a;
}
clocks move7(clocks a)
{
    a.point[3]+=3;
    a.point[4]+=3;
    a.point[6]+=3;
    a.point[7]+=3;
    return a;
}
clocks move8(clocks a)
{
    a.point[6]+=3;
    a.point[7]+=3;
    a.point[8]+=3;
    return a;
}
clocks move9(clocks a)
{
    a.point[4]+=3;
    a.point[5]+=3;
    a.point[7]+=3;
    a.point[8]+=3;
    return a;
}
int check(clocks a)
{
    int i,m=0;
    for(i=0;i!=9;i++)
    {
                      m=m+a.point[i]%12;
    }
    if(m==0)
    r=1;
    return 0;
}
 
