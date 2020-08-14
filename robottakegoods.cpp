#include<cstdio>
void read(int &y)
{
    y=0;char x=getchar();int f=1;
    while(x<'0'||x>'9')
    {
        if(x=='-') f=-1;
        x=getchar();
    }
    while(x>='0'&&x<='9')
    {
        y=y*10+x-'0';
        x=getchar();
    }
    y*=f;
}
int b[55][55],v[55][55][5];
int qd[20005],qx[20005],qy[20005],qs[20005];
int rx,ry,l,r;
int nx[6]={0,0,1,0,-1,0};
int ny[6]={0,1,0,-1,0,0};
char de[5];
void add(int x,int y,int d,int s)
{
    v[x][y][d]=1;
    qx[++r]=x;
    qy[r]=y;
    qd[r]=d;
    qs[r]=s+1;
}
int main()
{
    int n,m,x;
    read(n);read(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            read(x);
            if(x==1)
            {
                b[i][j]=1;
                b[i+1][j]=1;
                b[i][j+1]=1;
                b[i+1][j+1]=1;
            }
        }
    }
    int sx,sy;
    read(sx);read(sy);read(rx);read(ry);
    if(sx==rx&&sy==ry)
    {
        printf("0");
        return 0;
    }
    scanf("%s",de);
    if(de[0]=='E') qd[l]=1;
    if(de[0]=='S') qd[l]=2;
    if(de[0]=='W') qd[l]=3;
    if(de[0]=='N') qd[l]=4;
    qx[l]=sx;qy[l]=sy;
    while(l<=r)
    {
        for(int j=1;j<=3;j++)
        {
            int tx=qx[l]+nx[qd[l]]*j;
            int ty=qy[l]+ny[qd[l]]*j;
            if((tx<=0||tx>=n)||(ty<=0||ty>=m)) break;
            if(b[tx][ty]==1) break;
        
            if(tx==rx&&ty==ry)
            {
                printf("%d",qs[l]+1);
                return 0;
            }
            if(v[tx][ty][qd[l]]==0) add(tx,ty,qd[l],qs[l]);
        }
        int tl=qd[l]-1,tr=qd[l]+1;
        if(tl==0) tl=4;
        if(tr==5) tr=1;
        if(v[qx[l]][qy[l]][tl]==0) add(qx[l],qy[l],tl,qs[l]);
        if(v[qx[l]][qy[l]][tr]==0) add(qx[l],qy[l],tr,qs[l]);
        l++;
    }
    printf("-1");
    return 0;
}