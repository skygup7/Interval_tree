#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LLMAX 1000000000000000010
#define MAX 100005
#define gcd __gcd
#define mod 1000000007
#define pb(n) push_back(n)
#define fr front()
#define vint vector<int>
#define vstring vector<string>
#define vll vector<long long int>
#define forp(i,a,n) for(int i=(a);i<(n);i++)
#define forn(i,a,n) for(int i=(a);i>=(n);i--)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

struct node
{
    node* left;
    node* right;
    node* p;
    int key;
};
node* root;

void rotate_left(node T,node* x)
{
    node* y=(x->right);
    x->right=y->left;
    y->left->p=x;
    y->p=x->p;
    if(x->p==NULL)
        root=y;
    else if(x==(x->p)->left)
        (x->p)->left=y;
    else
        (x->p)->right=y;
    y->left=x;
    x->p=y;
}
void rotate_right(node T,node* x)
{
    node* y=(x->left);
    x->left=y->right;
    y->right->p=x;
    y->p=x->p;
    if(x->p==NULL)
        root=y;
    else if(x==(x->p)->left)
        (x->p)->left=y;
    else
        (x->p)->right=y;
    y->right=x;
    x->p=y;
}
void insrt(node T,node x)
{

}
void delet(node T, node x)
{

}
node serch(node T,int i)
{
    node x;
    return x;
}

int main()
{
    csl;
    int n,x,y;
    cin>>n;
    int interval[2][n];
    forp(i,0,n)
    {
        cin>>x>>y;
        interval[0][i]=x;
        interval[1][i]=y;
    }
    node T;
    T.left=NULL;
    T.right=NULL;
    T.p=NULL;
    T.key=interval[0][0];
    root = &T;
    forp(i,1,n)
    {
        node x;
        x.left=NULL;
        x.right=NULL;
        x.p=NULL;
        x.key=interval[0][i];
        insrt(T,x);
    }
    node z;
    forp(i,0,10)
    {
        z=serch(T,i);
        if(z.key>=0)
            cout<<z.key<<endl;
        else
            cout<<"key not found"<<endl;
    }
    forp(i,0,10)
    {
        delet(T,serch(T,i));
    }
}


