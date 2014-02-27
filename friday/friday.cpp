/*
ID: yang.su1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int week[7];
    int i;
    for(i=0;i!=7;i++)
    {
            week[i]=0;
            }
    int lastMonth=13%7;
    week[13%7]++;
    for(i=2;i!=13;i++)
    {
            if(i-1==9||i-1==11||i-1==4||i-1==6)
            {
                                               lastMonth=(lastMonth+30)%7;
            }
            else
            {
                if(i-1==2)
                {
                          lastMonth=(lastMonth+28)%7;
                }
                else
                {
                    lastMonth=(lastMonth+31)%7;
                }
            }
            week[lastMonth]++;
    }
    int leapweek[7];
    for(i=0;i!=7;i++)
    {
            leapweek[i]=0;
            }
    lastMonth=13%7;
    leapweek[13%7]++;
    for(i=2;i!=13;i++)
    {
            if(i-1==9||i-1==11||i-1==4||i-1==6)
            {
                                               lastMonth=(lastMonth+30)%7;
            }
            else
            {
                if(i-1==2)
                {
                          lastMonth=(lastMonth+29)%7;
                }
                else
                {
                    lastMonth=(lastMonth+31)%7;
                }
            }
            leapweek[lastMonth]++;
    }
    int N;
    ifstream inFile;
    inFile.open("friday.in");
    inFile>>N;
    int WEEK[7];
    for(i=0;i!=7;i++)
    {
            WEEK[i]=0;
    }
    int lastYear=0;
    int j;
    for(i=1900;i!=1900+N;i++)
    {
                     if(i%4==0)
                     {
                               if(i%100==0)
                               {
                                           if(i%400==0)
                                           {
                                                      for(j=0;j!=7;j++)
                                                      { 
                                                                 WEEK[(j+lastYear)%7]=WEEK[(j+lastYear)%7]+leapweek[j];
                                                       }
                                                       lastYear=(lastYear+366)%7;
                                                       
                                           }
                                           else
                                           {
                                               for(j=0;j!=7;j++)
                                               {
                                                               WEEK[(j+lastYear)%7]=WEEK[(j+lastYear)%7]+week[j];
                                                }
                                                lastYear=(lastYear+365)%7;
                                           }
                               }
                               else
                               {
                                   for(j=0;j!=7;j++)
                                   { 
                                             WEEK[(j+lastYear)%7]=WEEK[(j+lastYear)%7]+leapweek[j];        
                                   }
                                   lastYear=(lastYear+366)%7;
                               }
                     }
                     else
                     {
                         for(j=0;j!=7;j++)
                         {
                                          WEEK[(j+lastYear)%7]=WEEK[(j+lastYear)%7]+week[j];
                         }
                         lastYear=(lastYear+365)%7;
                     }
    }
    ofstream outFile;
    outFile.open("friday.out");
    for(i=0;i!=6;i++)
    {
                     outFile<<WEEK[(i+6)%7]<<" ";
    }
    outFile<<WEEK[5]<<endl;
    return 0;
    
} 
