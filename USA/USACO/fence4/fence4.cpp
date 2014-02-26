/*
ID: yang.su1
PROG:fence4
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct point{
    int x;
    int y;
    };
struct line{
       point a;
       point b;
       int c;
       };
int cross(line q,line p);
int kill_intersection(line p,line q);
point point_temp;
int judge(line l,point p);
double a[9];
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("fence4.in");
    outFile.open("fence4.out");
    int N,i,j,k,w;
    k=0;
    line line_temp1,line_temp2;
    line line_temp;
    line line_temp_first1,line_temp_first2;
    point origin;
    inFile>>N;
    inFile>>origin.x>>origin.y;
    line_temp.a=origin;
    point pointIn[201];
    for(i=1;i<=N;i++)
        inFile>>pointIn[i].x>>pointIn[i].y;
    line lineIn[201];
    for(i=1;i<=N-1;i++){
        lineIn[i].a.x=pointIn[i].x;
        lineIn[i].a.y=pointIn[i].y;
        lineIn[i].b.x=pointIn[i+1].x;
        lineIn[i].b.y=pointIn[i+1].y;
        lineIn[i].c=0;
        lineIn[i+1].c=0;
        }
    lineIn[N].a.x=pointIn[N].x;
    lineIn[N].a.y=pointIn[N].y;
    lineIn[N].b.x=pointIn[1].x;
    lineIn[N].b.y=pointIn[1].y;
    for(i=2;i<=N;i++)
        for(j=1;j<=i-1;j++)
            if(i!=j&&!(i==N&&j==1)&&cross(lineIn[j],lineIn[i])){
                outFile<<"NOFENCE"<<endl;
                outFile<<i<<" "<<j;
                return 0;
                }
    if(cross(lineIn[N],lineIn[1])){
        outFile<<"NOFENCE"<<endl;
        return 0;
        }
    /*lineIn[1].a=origin;
    lineIn[1].b.x=2.3;
    lineIn[1].b.y=3;
    outFile<<judge(lineIn[1],lineIn[3])<<endl<<lineIn[3].a.x<<" "<<lineIn[3].a.y<<" "<<lineIn[3].b.x<<" "<<lineIn[3].b.y<<endl;
    for(i=0;i<=8;i++)
    outFile<<a[i]<<endl;*/
    for(i=1;i<=N;i++){
        line_temp1.a=origin;
        line_temp1.b=lineIn[i].a;
        line_temp2.a=origin;
        line_temp2.b=lineIn[i].b;
        line_temp_first1.a=origin;
        line_temp_first2.a=origin;
        line_temp_first1.b=lineIn[i].a;
        line_temp_first2.b=lineIn[i].b;
        for(j=i+1;j<=N+i-1;j++){
            w=j%N;
            if(w==0)
            w=N;
            if(judge(line_temp1,lineIn[w].a)*judge(line_temp1,lineIn[i].b)>0&&judge(line_temp2,lineIn[w].a)*judge(line_temp2,lineIn[i].a)>0&&judge(lineIn[i],lineIn[w].a)*judge(lineIn[i],origin)>0){
   
                line_temp.b=lineIn[w].a;
                if(judge(line_temp,lineIn[w].b)*judge(line_temp,line_temp1.b)>0)
                    line_temp1.b=lineIn[w].a;
                else
                    line_temp2.b=lineIn[w].a;
                continue;
                }
            if(judge(line_temp1,lineIn[w].b)*judge(line_temp1,lineIn[i].b)>0&&judge(line_temp2,lineIn[w].b)*judge(line_temp2,lineIn[i].a)>0&&judge(lineIn[i],lineIn[w].b)*judge(lineIn[i],origin)>0){
                line_temp.b=lineIn[w].b;
                if(judge(line_temp,lineIn[w].a)*judge(line_temp,line_temp1.b)>0)
                    line_temp1.b=lineIn[w].b;
                else
                    line_temp2.b=lineIn[w].b;
                continue;
                }
            /*if(judge(line_temp1,lineIn[w].a)*judge(line_temp1,lineIn[w].b)<=0&&judge(line_temp2,lineIn[w].a)*judge(line_temp2,lineIn[w].b)<=0)
                if(!((judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].a)<=0&&judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].b)<=0))&&(judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].a)<=0||judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].b)<=0)){
                if(judge(line_temp_first1,lineIn[w].a)*judge(line_temp_first1,lineIn[i].b)>=0&&judge(line_temp_first2,lineIn[w].a)*judge(line_temp_first2,lineIn[i].a)>=0&&judge(lineIn[i],lineIn[w].a)*judge(lineIn[i],origin)>=0)
                    if(judge(line_temp_first1,lineIn[w].b)*judge(line_temp_first1,lineIn[i].b)>=0&&judge(line_temp_first2,lineIn[w].b)*judge(line_temp_first2,lineIn[i].a)>=0&&judge(lineIn[i],lineIn[w].b)*judge(lineIn[i],origin)>=0){
                        lineIn[i].c=1;
                        j=1000;
                        k++;
                        continue;
                        }
                if(judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].a)<=0&&judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].b)<=0){

                    lineIn[i].c=1;
                    k++;
                    j=10000;
                    continue;
                    }
                if(judge(lineIn[w],origin)*judge(lineIn[w],line_temp1.b)<=0||judge(lineIn[w],origin)*judge(lineIn[w],origin)>judge(lineIn[w],line_temp1.b)*judge(lineIn[w],line_temp1.b)){
                    lineIn[i].c=1;
                    k++;
                    j=10000;
                    continue;
                    }
                }*/
            if(!(judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].a)>=0&&judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].b)>=0))
            if(judge(line_temp2,lineIn[i].a)*judge(line_temp2,lineIn[w].a)>=0)
                if(judge(line_temp1,lineIn[i].b)*judge(line_temp1,lineIn[w].a)<=0)
                    if(judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].a)>=0||judge(line_temp_first1,lineIn[i].b)*judge(line_temp_first1,lineIn[w].a)<=0)
                        if(judge(line_temp1,lineIn[i].b)*judge(line_temp1,lineIn[w].b)>=0)
                            if(judge(line_temp2,lineIn[i].a)*judge(line_temp2,lineIn[w].b)<=0)
                                if(judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].b)>=0||judge(line_temp_first2,lineIn[i].a)*judge(line_temp_first2,lineIn[w].b)<=0)
                                    if(judge(lineIn[w],origin)*judge(lineIn[w],line_temp1.b)<=0||judge(lineIn[w],origin)*judge(lineIn[w],origin)>judge(lineIn[w],line_temp1.b)*judge(lineIn[w],line_temp1.b)){
                                        lineIn[i].c=1;
                                        k++;
                                        j=10000;
                                        continue;
                                        }
            if(!(judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].a)>=0&&judge(lineIn[w],origin)*judge(lineIn[w],lineIn[i].b)>=0))
            if(judge(line_temp2,lineIn[i].a)*judge(line_temp2,lineIn[w].b)>=0)
                if(judge(line_temp1,lineIn[i].b)*judge(line_temp1,lineIn[w].b)<=0)
                    if(judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].b)>=0||judge(line_temp_first1,lineIn[i].b)*judge(line_temp_first1,lineIn[w].b)<=0)
                        if(judge(line_temp1,lineIn[i].b)*judge(line_temp1,lineIn[w].a)>=0)
                            if(judge(line_temp2,lineIn[i].a)*judge(line_temp2,lineIn[w].a)<=0)
                                if(judge(lineIn[i],origin)*judge(lineIn[i],lineIn[w].a)>=0||judge(line_temp_first2,lineIn[i].a)*judge(line_temp_first2,lineIn[w].a)<=0)
                                    if(judge(lineIn[w],origin)*judge(lineIn[w],line_temp1.b)<=0||judge(lineIn[w],origin)*judge(lineIn[w],origin)>judge(lineIn[w],line_temp1.b)*judge(lineIn[w],line_temp1.b)){
                                        lineIn[i].c=1;
                                        k++;
                                        j=10000;
                                        continue;
                                        }
            }
        }
    outFile<<N-k<<endl;
    for(i=1;i<=N-2;i++)
        if(lineIn[i].c==0)
        outFile<<lineIn[i].a.x<<" "<<lineIn[i].a.y<<" "<<lineIn[i].b.x<<" "<<lineIn[i].b.y<<endl;
    if(lineIn[N].c==0)
        outFile<<lineIn[N].b.x<<" "<<lineIn[N].b.y<<" "<<lineIn[N].a.x<<" "<<lineIn[N].a.y<<endl;
    if(lineIn[N-1].c==0)
        outFile<<lineIn[N-1].a.x<<" "<<lineIn[N-1].a.y<<" "<<lineIn[N-1].b.x<<" "<<lineIn[N-1].b.y<<endl;
    return 0;


    } 
int cross(line q,line p){
    if(q.b.x==p.a.x&&q.b.y==p.a.y){
        if((q.a.y-q.b.y)*(p.a.x-p.b.x)==(p.a.y-p.b.y)*(q.a.x-q.b.x)&&(p.b.x-p.a.x)*(q.a.x-q.b.x)>0)
            return 1;
        else
            return 0;
        }
    if((q.a.y-q.b.y)*(p.a.x-p.b.x)==(p.a.y-p.b.y)*(q.a.x-q.b.x)){
        if(((q.a.y-q.b.y)*(q.a.x-p.b.x)!=(q.a.y-p.b.y)*(q.a.x-q.b.x))||(q.a.x>p.a.x&&q.a.x>p.b.x&&q.b.x>p.a.x&&q.b.x>p.b.x)||(q.a.x<p.a.x&&q.a.x<p.b.x&&q.b.x<p.a.x&&q.b.x<p.b.x)||(q.a.y>p.a.y&&q.a.y>p.b.y&&q.b.y>p.a.y&&q.b.y>p.b.y)||(q.a.y<p.a.y&&q.a.y<p.b.y&&q.b.y<p.a.y&&q.b.y<p.b.y))
            return 0;
        else
            return 1;
        }
    if(((q.b.y-q.a.y)*(p.a.x-q.b.x)-(q.b.x-q.a.x)*(p.a.y-q.b.y))*((q.b.y-q.a.y)*(p.b.x-q.b.x)-(q.b.x-q.a.x)*(p.b.y-q.b.y))>0||((p.b.y-p.a.y)*(q.a.x-p.b.x)-(p.b.x-p.a.x)*(q.a.y-p.b.y))*((p.b.y-p.a.y)*(q.b.x-p.b.x)-(p.b.x-p.a.x)*(q.b.y-p.b.y))>0)
        return 0;
    else
        return 1;
    }
int judge(line l,point p){
    return (p.y-l.a.y)*(l.a.x-l.b.x)-(l.a.y-l.b.y)*(p.x-l.a.x);
    }
