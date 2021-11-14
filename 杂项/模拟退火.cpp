#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
#define eps 1e-8
#define ll long long
int n;
double X,Y,Z;
struct node
{
    double x,y,z,val;
}p[35],peop;
double dist(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int main()
{
    srand((unsigned(time(NULL))));
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        X=Y=Z=100;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        peop.x=(rand()%1000+1)*1.0/1000.0*X;
        peop.y=(rand()%1000+1)*1.0/1000.0*Y;
        peop.z=(rand()%1000+1)*1.0/1000.0*Z;
        peop.val=get(peop);
        double T=X;
        node ne;
        double ans=1e9;
        while(T>eps)
        {
            double now=0;
            int who;
            for(int j=1;j<=n;j++)
            {
                if(now<dist(p[j],peop))
                {
                    now=dist(p[j],peop);
                    who=j;
                }
            }
            peop.x=peop.x+(p[who].x-peop.x)/now*T;//不断向更优处移动
            peop.y=peop.y+(p[who].y-peop.y)/now*T;
            peop.z=peop.z+(p[who].z-peop.z)/now*T;
            peop.val=get(ne);
            if(now<ans)
                ans=now;
            T*=0.99;
        }
        printf("%.7f\n",ans);
    }

    return 0;
}

