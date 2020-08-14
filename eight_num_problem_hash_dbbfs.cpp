#include<iostream>
#include<queue>
#define For(i,j) for(register int (i)=0;(i)<(j);++(i))

using std::cin;
using std::cout;
using std::queue;
using std::swap;
using std::endl;

const int mod1=1e5+7,mod2=1e6+9,dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool flag;
int ans;
struct Node
{
    int key,step;
    bool head;
    Node *next;
    Node(){key=step=head=0;next=NULL;}
}hash[mod1+2];
struct CB
{
    int value[3][3],spx,spy,step;
    void init()
    {
        value[0][0]=1;
        value[0][1]=2;
        value[0][2]=3;
        value[1][0]=8;
        value[1][1]=0;
        value[1][2]=4;
        value[2][0]=7;
        value[2][1]=6;
        value[2][2]=5;
        spx=1,spy=1;
    }
    bool operator== (const CB &x) const
    {
        For(i,3)
            For(j,3)
                if(value[i][j]!=x.value[i][j])
                    return false;
        return true;
    }
}start,goal;
bool Query(const CB &x,bool head)
{
    int num=0,sum1,sum2;
    For(i,3)
        For(j,3)
            num=num*10+x.value[i][j];
    sum1=num%mod1,sum2=num%mod2;
    if(!hash[sum1].key)
    {
        hash[sum1].key=sum2;
        hash[sum1].head=head;
        hash[sum1].step=x.step;
        return true;
    }
    if(hash[sum1].key==sum2)
    {
        if(head!=hash[sum1].head)
        {
            flag=true;
            ans=x.step+hash[sum1].step;
        }
        return false;
    }
    else
    {
        Node *now=&hash[sum1];
        while(now->next)
        {
            now=now->next;
            if(now->key==sum2)
            {
                if(head!=now->head)
                {
                    flag=true;
                    ans=now->step+x.step;
                }
                return false;
            }
        }
        Node *newnode=new Node;
        newnode->key=sum2;
        newnode->head=head;
        now->next=newnode;
        return true;
    }
}
void BFS()
{
    queue <CB> q1;
    queue <CB> q2;
    start.step=goal.step=0;
    q1.push(start);
    q2.push(goal);
    while(true)
    {
        if(q1.size()>q2.size())
        {
            CB now=q2.front();
            q2.pop();
            For(i,4)
            {
                int xx=now.spx+dx[i],yy=now.spy+dy[i];
                if(xx<0||xx>2||yy<0||yy>2)
                    continue;
                CB wib=now;
                wib.step=now.step+1;
                wib.spx=xx,wib.spy=yy;
                swap(wib.value[xx][yy],wib.value[now.spx][now.spy]);
                if(Query(wib,0))
                    q2.push(wib);
                if(flag)
                    return;
            }
        }
        else
        {
            CB now=q1.front();
            q1.pop();
            For(i,4)
            {
                int xx=now.spx+dx[i],yy=now.spy+dy[i];
                if(xx<0||xx>2||yy<0||yy>2)
                    continue;
                CB wib=now;
                swap(wib.value[xx][yy],wib.value[now.spx][now.spy]);
                wib.spx=xx,wib.spy=yy;
                wib.step=now.step+1;
                if(Query(wib,1))
                    q1.push(wib);
                if(flag)
                    return;
            }
        }
        if(flag)
            return;
    }
}
int main(int argc,char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    char ch;
    For(i,3)
        For(j,3)
        {
            cin>>ch;
            if(ch=='0')
                start.spx=i,start.spy=j;
            start.value[i][j]=ch-'0';
        }
    goal.init();
    if(goal==start)
    {
        cout<<0;
        return 0;
    }
    BFS();
    cout<<ans;
    return 0;
}