
/*
ID: yang.su1
PROG:numtri
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("numtri.in");
    outFile.open("numtri.out");
    int R;
    inFile>>R;
    int *input=new int[600000];
    int i,j,sum;
    for(i=1;i<=(R*(R+1))/2;i++)
    inFile>>input[i];
    input[0]=input[1];
    if(R==1)
    outFile<<input[1]<<endl;
    else
    {
        for(i=2;i<=R;i++)
    {
                     for(j=(i*(i-1))/2+1;j<=(i*(i+1))/2;j++)
                     {
                                                         if(j==(((i-1)*i)/2+1))
                                                         input[j]=input[j]+input[j+1-i];
                                                         if(j==((i+1)*i)/2)
                                                         input[j]=input[j]+input[j-i];
                                                         if(j>(((i-1)*i)/2+1)&&j<((i+1)*i)/2)                                                                                                                  
                                                         input[j]=input[j]+((input[j+1-i]>=input[j-i])?input[j+1-i]:input[j-i]);
                     }          
    }
    sum=input[((R-1)*R)/2+1];
    for(i=((R-1)*R)/2+1;i<=((R+1)*R)/2;i++)
    sum=(sum>=input[i])?sum:input[i];
    outFile<<sum<<endl;
}
    return 0;
} 
