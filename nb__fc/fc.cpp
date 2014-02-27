
/*
ID: yang.su1
PROG:fc
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
	double x,y;
};
point p[10003],s[10003];
bool mult(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator < (const point &l,const point &r)
{
	return l.y<r.y||(l.y==r.y&&l.x<r.x);
}
int graham(point pnt[],int n,point res[])
{
	int i,len,k=0,top=1;
	sort(pnt,pnt+n);
	if(n==0)
		return 0;
	res[0]=pnt[0];
	if(n==1)
		return 1;
	res[1]=pnt[1];
	if(n==2)
		return 2;
	res[2]=pnt[2];
	for(i=2;i<n;i++)
	{
		while(top&&mult(pnt[i],res[top],res[top-1]))
			top--;
		res[++top]=pnt[i];
	}
	len=top;
	res[++top]=pnt[n-2];
	for(i=n-3;i>=0;i--)
	{
		while(top!=len&&mult(pnt[i],res[top],res[top-1]))
			top--;
		res[++top]=pnt[i];
	}
	return top;
}
double dis(point pn,point re)
{
	return sqrt((pn.x-re.x)*(pn.x-re.x)+(pn.y-re.y)*(pn.y-re.y));
}
int main()
{
	ofstream fout("fc.out");
	ifstream fin("fc.in");
	int n,i;
	double ans=0;
	fin>>n;
	for(i=0;i<n;i++)
		fin>>p[i].x>>p[i].y;
	n=graham(p,n,s);
	for(i=1;i<n;i++)
		ans+=dis(s[i-1],s[i]);
	ans+=dis(s[n-1],s[0]);
	fout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
	return 0;
}
