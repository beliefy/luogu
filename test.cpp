#include<bits/stdc++.h>
#include<cmath>

#define mem(a,b) memset(a,b,sizeof a)
#define ssclr(ss) ss.clear(),ss.str("")
#define INF 0x3f3f3f
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct node{
    int data;
    node *left,*right;
};

unordered_map<int,int> lvl;
unordered_map<int,node*> fu;

node *insert_bst(node* root,int d,int l,node *par)
{
    if(root == NULL)
    {
        root = new node;
        root->left=root->right=NULL;
        root->data=d;
        lvl[d] = l;
        if(par == NULL)
        {
            par = root;
        }
        fu[d]=par;
        return root;
    }
    if(root->data>d)
        root->left=insert_bst(root->left,d,l+1,root);
    if(root->data<d)
        root->right=insert_bst(root->right,d,l+1,root);
}

int main()
{
    return 0;
}
