#include <cstdio>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <queue>
#include <vector>
#include <stack>
#include <thread>
using namespace std;
#define Maxn 1510214
//#define Maxn 101
#define Maxm 7942819
#define LL long long

int head[Maxn+5],nex[(Maxm+5)<<1],to[(Maxm+5)<<1],cnt=1;

void addedge(int x,int y)
{
        to[++cnt]=y; nex[cnt]=head[x]; head[x]=cnt;
        to[++cnt]=x; nex[cnt]=head[y]; head[y]=cnt;
}

int real_n;
int real_a[Maxn+5],qwq;

long double B_C[Maxn+5],B_C2[Maxn+5],B_C3[Maxn+5],B_C4[Maxn+5];
queue<int>Q,Q2,Q3,Q4;
long double theta[Maxn+5],theta2[Maxn+5],theta3[Maxn+5],theta4[Maxn+5];
long double sigm[Maxn+5],sigm2[Maxn+5],sigm3[Maxn+5],sigm4[Maxn+5];
int d[Maxn+5],d2[Maxn+5],d3[Maxn+5],d4[Maxn+5];
int S[Maxn+5],S2[Maxn+5],S3[Maxn+5],S4[Maxn+5];
int top,top2,top3,top4;
int HEAD[Maxn+5],CUR=0,NEX[Maxm+5],TO[Maxm+5];
int HEAD2[Maxn+5],CUR2=0,NEX2[Maxm+5],TO2[Maxm+5];
int HEAD3[Maxn+5],CUR3=0,NEX3[Maxm+5],TO3[Maxm+5];
int HEAD4[Maxn+5],CUR4=0,NEX4[Maxm+5],TO4[Maxm+5];

long double B_C5[Maxn+5],B_C6[Maxn+5],B_C7[Maxn+5],B_C8[Maxn+5];
queue<int>Q5,Q6,Q7,Q8;
long double theta5[Maxn+5],theta6[Maxn+5],theta7[Maxn+5],theta8[Maxn+5];
long double sigm5[Maxn+5],sigm6[Maxn+5],sigm7[Maxn+5],sigm8[Maxn+5];
int d5[Maxn+5],d6[Maxn+5],d7[Maxn+5],d8[Maxn+5];
int S5[Maxn+5],S6[Maxn+5],S7[Maxn+5],S8[Maxn+5];
int top5,top6,top7,top8;
int HEAD5[Maxn+5],CUR5=0,NEX5[Maxm+5],TO5[Maxm+5];
int HEAD6[Maxn+5],CUR6=0,NEX6[Maxm+5],TO6[Maxm+5];
int HEAD7[Maxn+5],CUR7=0,NEX7[Maxm+5],TO7[Maxm+5];
int HEAD8[Maxn+5],CUR8=0,NEX8[Maxm+5],TO8[Maxm+5];

void bfs(int St)
{
    top=0;
    for(int i=1;i<=real_n;i++) sigm[real_a[i]]=0,d[real_a[i]]=-1;
    sigm[St]=1; d[St]=0;
    Q.push(St);
    int x,y,i;
    while(!Q.empty())
    {
        x=Q.front(); Q.pop();
        S[++top]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d[y]<0)
            {
                Q.push(y);
                d[y]=d[x]+1;
            }
            if(d[y]==d[x]+1)
            {
                sigm[y]+=sigm[x];
                
            //    P[y].push_back(x);
                TO[++CUR]=x;
                NEX[CUR]=HEAD[y];
                HEAD[y]=CUR;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta[real_a[i]]=0;
    while(top)
    {
        x=S[top--];
        for(i=HEAD[x];i;i=NEX[i])
        {
            y=TO[i];
            theta[y]+=1.0*sigm[y]/sigm[x]*(1+theta[x]);
        }
        HEAD[x]=0;
        if(x!=St) 
        {
            B_C[x]+=theta[x]; 
        }
    }
    CUR=0;
}
void bfs2(int St)
{
    top2=0;
    for(int i=1;i<=real_n;i++) sigm2[real_a[i]]=0,d2[real_a[i]]=-1;
    sigm2[St]=1; d2[St]=0;
    Q2.push(St);
    int x,y,i;
    while(!Q2.empty())
    {
        x=Q2.front(); Q2.pop();
        S2[++top2]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d2[y]<0)
            {
                Q2.push(y);
                d2[y]=d2[x]+1;
            }
            if(d2[y]==d2[x]+1)
            {
                sigm2[y]+=sigm2[x];
                
            //    P[y].push_back(x);
                TO2[++CUR2]=x;
                NEX2[CUR2]=HEAD2[y];
                HEAD2[y]=CUR2;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta2[real_a[i]]=0;
    while(top2)
    {
        x=S2[top2--];
        for(i=HEAD2[x];i;i=NEX2[i])
        {
            y=TO2[i];
            theta2[y]+=1.0*sigm2[y]/sigm2[x]*(1+theta2[x]);
        }
        HEAD2[x]=0;
        if(x!=St) 
        {
            B_C2[x]+=theta2[x]; 
        }
    }
    CUR2=0;
}
void bfs3(int St)
{
    top3=0;
    for(int i=1;i<=real_n;i++) sigm3[real_a[i]]=0,d3[real_a[i]]=-1;
    sigm3[St]=1; d3[St]=0;
    Q3.push(St);
    int x,y,i;
    while(!Q3.empty())
    {
        x=Q3.front(); Q3.pop();
        S3[++top3]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d3[y]<0)
            {
                Q3.push(y);
                d3[y]=d3[x]+1;
            }
            if(d3[y]==d3[x]+1)
            {
                sigm3[y]+=sigm3[x];
                
            //    P[y].push_back(x);
                TO3[++CUR3]=x;
                NEX3[CUR3]=HEAD3[y];
                HEAD3[y]=CUR3;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta3[real_a[i]]=0;
    while(top3)
    {
        x=S3[top3--];
        for(i=HEAD3[x];i;i=NEX3[i])
        {
            y=TO3[i];
            theta3[y]+=1.0*sigm3[y]/sigm3[x]*(1+theta3[x]);
        }
        HEAD3[x]=0;
        if(x!=St) 
        {
            B_C3[x]+=theta3[x]; 
        }
    }
    CUR3=0;
}
void bfs4(int St)
{
    top4=0;
    for(int i=1;i<=real_n;i++) sigm4[real_a[i]]=0,d4[real_a[i]]=-1;
    sigm4[St]=1; d4[St]=0;
    Q4.push(St);
    int x,y,i;
    while(!Q4.empty())
    {
        x=Q4.front(); Q4.pop();
        S4[++top4]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d4[y]<0)
            {
                Q4.push(y);
                d4[y]=d4[x]+1;
            }
            if(d4[y]==d4[x]+1)
            {
                sigm4[y]+=sigm4[x];
                
            //    P[y].push_back(x);
                TO4[++CUR4]=x;
                NEX4[CUR4]=HEAD4[y];
                HEAD4[y]=CUR4;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta4[real_a[i]]=0;
    while(top4)
    {
        x=S4[top4--];
        for(i=HEAD4[x];i;i=NEX4[i])
        {
            y=TO4[i];
            theta4[y]+=1.0*sigm4[y]/sigm4[x]*(1+theta4[x]);
        }
        HEAD4[x]=0;
        if(x!=St) 
        {
            B_C4[x]+=theta4[x]; 
        }
    }
    CUR4=0;
}

void bfs5(int St)
{
    top5=0;
    for(int i=1;i<=real_n;i++) sigm5[real_a[i]]=0,d5[real_a[i]]=-1;
    sigm5[St]=1; d5[St]=0;
    Q5.push(St);
    int x,y,i;
    while(!Q5.empty())
    {
        x=Q5.front(); Q5.pop();
        S5[++top5]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d5[y]<0)
            {
                Q5.push(y);
                d5[y]=d5[x]+1;
            }
            if(d5[y]==d5[x]+1)
            {
                sigm5[y]+=sigm5[x];
                
            //    P[y].push_back(x);
                TO5[++CUR5]=x;
                NEX5[CUR5]=HEAD5[y];
                HEAD5[y]=CUR5;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta5[real_a[i]]=0;
    while(top5)
    {
        x=S5[top5--];
        for(i=HEAD5[x];i;i=NEX5[i])
        {
            y=TO5[i];
            theta5[y]+=1.0*sigm5[y]/sigm5[x]*(1+theta5[x]);
        }
        HEAD5[x]=0;
        if(x!=St) 
        {
            B_C5[x]+=theta5[x]; 
        }
    }
    CUR5=0;
}

void bfs6(int St)
{
    top6=0;
    for(int i=1;i<=real_n;i++) sigm6[real_a[i]]=0,d6[real_a[i]]=-1;
    sigm6[St]=1; d6[St]=0;
    Q6.push(St);
    int x,y,i;
    while(!Q6.empty())
    {
        x=Q6.front(); Q6.pop();
        S6[++top6]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d6[y]<0)
            {
                Q6.push(y);
                d6[y]=d6[x]+1;
            }
            if(d6[y]==d6[x]+1)
            {
                sigm6[y]+=sigm6[x];
                
            //    P[y].push_back(x);
                TO6[++CUR6]=x;
                NEX6[CUR6]=HEAD6[y];
                HEAD6[y]=CUR6;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta6[real_a[i]]=0;
    while(top6)
    {
        x=S6[top6--];
        for(i=HEAD6[x];i;i=NEX6[i])
        {
            y=TO6[i];
            theta6[y]+=1.0*sigm6[y]/sigm6[x]*(1+theta6[x]);
        }
        HEAD6[x]=0;
        if(x!=St) 
        {
            B_C6[x]+=theta6[x]; 
        }
    }
    CUR6=0;
}

void bfs7(int St)
{
    top7=0;
    for(int i=1;i<=real_n;i++) sigm7[real_a[i]]=0,d7[real_a[i]]=-1;
    sigm7[St]=1; d7[St]=0;
    Q7.push(St);
    int x,y,i;
    while(!Q7.empty())
    {
        x=Q7.front(); Q7.pop();
        S7[++top7]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d7[y]<0)
            {
                Q7.push(y);
                d7[y]=d7[x]+1;
            }
            if(d7[y]==d7[x]+1)
            {
                sigm7[y]+=sigm7[x];
                
            //    P[y].push_back(x);
                TO7[++CUR7]=x;
                NEX7[CUR7]=HEAD7[y];
                HEAD7[y]=CUR7;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta7[real_a[i]]=0;
    while(top7)
    {
        x=S7[top7--];
        for(i=HEAD7[x];i;i=NEX7[i])
        {
            y=TO7[i];
            theta7[y]+=1.0*sigm7[y]/sigm7[x]*(1+theta7[x]);
        }
        HEAD7[x]=0;
        if(x!=St) 
        {
            B_C7[x]+=theta7[x]; 
        }
    }
    CUR7=0;
}

void bfs8(int St)
{
    top8=0;
    for(int i=1;i<=real_n;i++) sigm8[real_a[i]]=0,d8[real_a[i]]=-1;
    sigm8[St]=1; d8[St]=0;
    Q8.push(St);
    int x,y,i;
    while(!Q8.empty())
    {
        x=Q8.front(); Q8.pop();
        S8[++top8]=x;
        for(i=head[x];i;i=nex[i])
        {
            y=to[i];
            if(d8[y]<0)
            {
                Q8.push(y);
                d8[y]=d8[x]+1;
            }
            if(d8[y]==d8[x]+1)
            {
                sigm8[y]+=sigm8[x];
                
            //    P[y].push_back(x);
                TO8[++CUR8]=x;
                NEX8[CUR8]=HEAD8[y];
                HEAD8[y]=CUR8;
            }
        }
    }
    for(int i=1;i<=real_n;i++) theta8[real_a[i]]=0;
    while(top8)
    {
        x=S8[top8--];
        for(i=HEAD8[x];i;i=NEX8[i])
        {
            y=TO8[i];
            theta8[y]+=1.0*sigm8[y]/sigm8[x]*(1+theta8[x]);
        }
        HEAD8[x]=0;
        if(x!=St) 
        {
            B_C8[x]+=theta8[x]; 
        }
    }
    CUR8=0;
}

bool cc_vis[Maxn+5];
int Block,Block2,Block3,Block4;
int Block5,Block6,Block7,Block8;
int N1,N2,N3,N4;
int N5,N6,N7,N8;
void work1()
{
    for(int i=N1+1;i<=N1+Block;i++) bfs(real_a[i]);
}
void work2()
{
    for(int i=N2+Block2+1;i<=N2+2*Block2;i++) bfs2(real_a[i]);
}
void work3()
{
    for(int i=N3+2*Block3+1;i<=N3+3*Block3;i++) bfs3(real_a[i]);
}
void work4()
{
    for(int i=N4+3*Block4+1;i<=N4+4*Block4;i++) bfs4(real_a[i]);
}
void work5()
{
    for(int i=N5+4*Block5+1;i<=N5+5*Block5;i++) bfs5(real_a[i]);
}
void work6()
{
    for(int i=N6+5*Block6+1;i<=N6+6*Block6;i++) bfs6(real_a[i]);
}
void work7()
{
    for(int i=N7+6*Block7+1;i<=N7+7*Block7;i++) bfs7(real_a[i]);
}
void work8()
{
//    for(int i=N8+7*Block8+1;i<=N8+8*Block8;i++) bfs8(real_a[i]);
    for(int i=N8+7*Block8+1;i<=real_n;i++) bfs8(real_a[i]);
}
int main()
{
    //freopen("/Users/apple/Desktop/graph_analysis/max_cc_edges.txt","r",stdin);
    freopen("edges.txt","r",stdin);
    
    //freopen("/root/edges_test.txt","r",stdin);
    //freopen("/Users/apple/Desktop/edges_test.txt","r",stdin);

    freopen("output1.txt","w",stdout);
    //freopen("/Users/apple/Desktop/output1.txt","w",stdout);

    int x,y,n=0;
    while(scanf("%d,%d",&x,&y)!=EOF)
    {
        x+=1; y+=1;
        addedge(x,y);
        n=max(n,max(x,y));
        if(!cc_vis[x]) cc_vis[x]=1,real_n++;
        if(!cc_vis[y]) cc_vis[y]=1,real_n++;
        // printf("%d %d\n",x,y);
    }
    for(int i=1;i<=n;i++) if(cc_vis[i])
    {
        real_a[++qwq]=i;
    }

    N1=N2=N3=N4=N5=N6=N7=N8=0;//bias
    Block=real_n/8;//block_size
//  Above two sentences are required to tune the number.

    Block2=Block3=Block4=Block;
    Block5=Block6=Block7=Block8=Block;
    thread t1(work1);
    thread t2(work2);
    thread t3(work3);
    thread t4(work4);
    thread t5(work5);
    thread t6(work6);
    thread t7(work7);
    thread t8(work8);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    for(int i=1;i<=real_n;i++)
    {
        B_C[real_a[i]]+=B_C2[real_a[i]]+B_C3[real_a[i]]+B_C4[real_a[i]]+B_C5[real_a[i]]+B_C6[real_a[i]]+B_C7[real_a[i]]+B_C8[real_a[i]];
    }
    for(int i=1;i<=real_n;i++)
        printf("%d %.9Lf\n",real_a[i],B_C[real_a[i]]/n/(n-1));
    //    printf("%d %.9Lf\n",real_a[i],B_C[real_a[i]]);
    return 0;
}