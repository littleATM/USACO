
/*
ID: yang.su1
PROG:packrec
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct rectangles
{
       int l;
       int w;
};
int largest=10000;
int k=0;
int model12(rectangles a,rectangles b,rectangles c,rectangles d);
int model13(rectangles a,rectangles b,rectangles c,rectangles d);
int model14(rectangles a,rectangles b,rectangles c,rectangles d);
int model22(rectangles a,rectangles b,rectangles c,rectangles d);
int model23(rectangles a,rectangles b,rectangles c,rectangles d);
rectangles *largestarea=new rectangles[10000];
int MAX(int a,int b);
int MIN(int a,int b);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("packrec.in");
    outFile.open("packrec.out");
    int i,j,p,q;
    rectangles A,B,C,D;
    rectangles rectangle[8];
    for(i=0;i!=4;i++)
    {
                     inFile>>rectangle[i].w;
                     inFile>>rectangle[i].l;
                     rectangle[i+4].w=rectangle[i].l;
                     rectangle[i+4].l=rectangle[i].w;
    }
    for(i=0;i!=8;i++)
    {
                     A=rectangle[i];
                     for(j=0;j!=8;j++)
                     {
                                      if((8+j-i)%4!=0)
                                      {
                                                      B=rectangle[j];
                                                      for(p=0;p!=8;p++)
                                                      {
                                                                       if((8+p-j)%4!=0&&(8+p-i)%4!=0)
                                                                       {
                                                                                                     C=rectangle[p];
                                                                                                     for(q=0;q!=8;q++)
                                                                                                     {
                                                                                                                      if((8+q-p)%4!=0&&(8+q-j)%4!=0&&(8+q-i)%4!=0)
                                                                                                                      {
                                                                                                                                                                  D=rectangle[q];
                                                                                                                                                                  model12(A,B,C,D);
                                                                                                                                                                  model13(A,B,C,D);
                                                                                                                                                                  model14(A,B,C,D);
                                                                                                                                                                  model22(A,B,C,D);
                                                                                                                                                                  model23(A,B,C,D);
                                                                                                                                                                  
                                                                                                                      }
                                                                                                     }
                                                                       }
                                                      }
                                      }
                     }
    }
    rectangles mid;
    for(j=0;j!=k;j++)
    {
    for(i=1;i!=k;i++)
    {
                     if(largestarea[i-1].w>largestarea[i].w)
                     {
                                                mid=largestarea[i-1];
                                                largestarea[i-1]=largestarea[i];
                                                largestarea[i]=mid;
                     }                 
    }
    }
    outFile<<largest<<endl;
    for(i=0;i!=k;i++)
    {
    outFile<<largestarea[i].w<<" "<<largestarea[i].l<<endl;
    }
    return 0;
    
    
    
} 
int model12(rectangles a,rectangles b,rectangles c,rectangles d)
{
    int i,j=1;
           if(a.l>b.l&&a.l*(a.w+b.w)==largest&&MAX((a.l-b.l),b.w)>=MAX(MAX(c.l,d.l),(c.w+d.w))&&MIN((a.l-b.l),b.w)>=MIN(MAX(c.l,d.l),(c.w+d.w)))
           {
                       for(i=0;i!=k;i++)
                       {                                             
                                                                    if(largestarea[i].l==MAX(a.l,(a.w+b.w)));
                                                                    j=0;
                       }
                                                                    if(j==1)
                                                                    {
                                                                    largestarea[k].l=MAX(a.l,(a.w+b.w));
                                                                    largestarea[k].w=MIN(a.l,(a.w+b.w));
                                                                    k++;
                                                                    }
                       
           }
           
           if(a.l>b.l&&a.l*(a.w+b.w)<largest&&MAX((a.l-b.l),b.w)>=MAX(MAX(c.l,d.l),(c.w+d.w))&&MIN((a.l-b.l),b.w)>=MIN(MAX(c.l,d.l),(c.w+d.w)))
           {
                                                                    largest=a.l*(a.w+b.w);
                                                                    k=0;
                                                                    largestarea[k].l=MAX(a.l,(a.w+b.w));
                                                                    largestarea[k].w=MIN(a.l,(a.w+b.w));
                                                                    k++;
           }
           return 0;
}
int model13(rectangles a,rectangles b,rectangles c,rectangles d)
{
    int i,j=1;
    if(a.l>=b.l&&b.l>=c.l&&a.l*(a.w+b.w+c.w)==largest&&(((a.l-b.l)>=d.l&&(b.w+c.w)>=d.w)||((a.l-c.l)>=d.l&&c.w>=d.w)))
    {
                    for(i=0;i!=k;i++)
                    {
                                                                     if(largestarea[i].l==MAX(a.l,(a.w+b.w+c.w)))
                                                                     j=0;
                    }
                                                                     if(j==1)
                                                                     {
                                                                     largestarea[k].l=MAX(a.l,(a.w+b.w+c.w));
                                                                     largestarea[k].w=MIN(a.l,(a.w+b.w+c.w));
                                                                     k++;
                                                                     }
    }
    if(a.l>=b.l&&b.l>=c.l&&a.l*(a.w+b.w+c.w)<largest&&(((a.l-b.l)>=d.l&&(b.w+c.w)>=d.w)||((a.l-c.l)>=d.l&&c.w>=d.w)))
    {
                                                                     largest=a.l*(a.w+b.w+c.w);
                                                                     k=0;
                                                                     largestarea[k].l=MAX(a.l,(a.w+b.w+c.w));
                                                                     largestarea[k].w=MIN(a.l,(a.w+b.w+c.w));
                                                                     k++;
    }
    return 0;
}
int model14(rectangles a,rectangles b,rectangles c,rectangles d)
{
    int i,j=1;
    if((a.w+b.w+c.w+d.w)*MAX(MAX(MAX(a.l,b.l),c.l),d.l)==largest)
    {
                       for(i=0;i!=k;i++)
                       {
                                                                 if(largestarea[i].l==MAX((a.w+b.w+c.w+d.w),MAX(MAX(MAX(a.l,b.l),c.l),d.l)))
                                                                 j=0;
                       }
                                                                 if(j==1)
                                                                 {
                                                                 largestarea[k].l=MAX((a.w+b.w+c.w+d.w),MAX(MAX(MAX(a.l,b.l),c.l),d.l));
                                                                 largestarea[k].w=MIN((a.w+b.w+c.w+d.w),MAX(MAX(MAX(a.l,b.l),c.l),d.l));
                                                                 k++;
                                                                 }
    }
    if((a.w+b.w+c.w+d.w)*MAX(MAX(MAX(a.l,b.l),c.l),d.l)<largest)
    {
                                                                 largest=(a.w+b.w+c.w+d.w)*MAX(MAX(MAX(a.l,b.l),c.l),d.l);
                                                                 k=0;
                                                                 largestarea[k].l=MAX((a.w+b.w+c.w+d.w),MAX(MAX(MAX(a.l,b.l),c.l),d.l));
                                                                 largestarea[k].w=MIN((a.w+b.w+c.w+d.w),MAX(MAX(MAX(a.l,b.l),c.l),d.l));
                                                                 k++;
    }
    return 0;
}
int model22(rectangles a,rectangles b,rectangles c,rectangles d)
{
    int i,j=1;
    if((!(b.l>a.l&&c.w>a.w))&&c.w<(a.w+b.w)&&b.l<(a.l+c.l)&&(a.w+b.w)*(a.l+c.l)==largest&&(((a.l+c.l-b.l)>=d.l&&((a.w+b.w)-MAX(c.w,a.w))>=d.w)||((a.l-b.l)>=d.l&&b.w>=d.w)||((a.l+c.l)-MAX(a.l,b.l)>=d.l&&(a.w+b.w-c.w)>=d.w)||((a.w-c.w)>=d.w&&c.l>=d.l)))
    {
                              for(i=0;i!=k;i++)
                              {
                                                                if(largestarea[i].l==MAX((a.w+b.w),(a.l+c.l)))
                                                                 j=0;
                              }
                                                                 if(j==1)
                                                                 {
                                                                 largestarea[k].l=MAX((a.w+b.w),(a.l+c.l));
                                                                 largestarea[k].w=MIN((a.w+b.w),(a.l+c.l));
                                                                 k++;
                                                                 }
    }
    if((!(b.l>a.l&&c.w>a.w))&&c.w<(a.w+b.w)&&b.l<(a.l+c.l)&&(a.w+b.w)*(a.l+c.l)<largest&&(((a.l+c.l-b.l)>=d.l&&((a.w+b.w)-MAX(c.w,a.w))>=d.w)||((a.l-b.l)>=d.l&&b.w>=d.w)||((a.l+c.l)-MAX(a.l,b.l)>=d.l&&(a.w+b.w-c.w)>=d.w)||((a.w-c.w)>=d.w&&c.l>=d.l)))
    {
                                                                 largest=(a.w+b.w)*(a.l+c.l);
                                                                 k=0;
                                                                 largestarea[k].l=MAX((a.w+b.w),(a.l+c.l));
                                                                 largestarea[k].w=MIN((a.w+b.w),(a.l+c.l));
                                                                 k++;
    }
    return 0;
}
int model23(rectangles a,rectangles b,rectangles c,rectangles d)
{
    int i,j=1;
    if((!(d.l>a.l&&b.w>a.w))&&!(d.l>(a.l+b.l)&&c.w>a.w)&&d.l<(a.l+b.l+c.l)&&c.w<(a.w+d.w)&&b.w<(a.w+d.w)&&(d.w+a.w)*(a.l+b.l+c.l)==largest)
    {
                                for(i=0;i!=k;i++)
                                {
                                                                if(largestarea[i].l==MAX((a.w+d.w),(a.l+b.l+c.l)))
                                                                j=0;
                                }
                                                                 if(j==1)
                                                                 {
                                                                 largestarea[k].l=MAX((a.w+d.w),(a.l+b.l+c.l));
                                                                 largestarea[k].w=MIN((a.w+d.w),(a.l+b.l+c.l));
                                                                 k++;
                                                                 }
    }
    if((!(d.l>a.l&&b.w>a.w))&&!(d.l>(a.l+b.l)&&c.w>a.w)&&d.l<(a.l+b.l+c.l)&&c.w<(a.w+d.w)&&b.w<(a.w+d.w)&&(d.w+a.w)*(a.l+b.l+c.l)<largest)
    {
                                                                largest=(a.w+d.w)*(a.l+b.l+c.l);
                                                                k=0;
                                                                largestarea[k].l=MAX((a.w+d.w),(a.l+b.l+c.l));
                                                                largestarea[k].w=MIN((a.w+d.w),(a.l+b.l+c.l));
                                                                k++;
    }
    return 0;
}
int MAX(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int MIN(int a,int b)
{
    if(a<=b)
    return a;
    else
    return b;
}
