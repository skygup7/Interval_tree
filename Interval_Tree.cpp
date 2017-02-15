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
    int color;
};
node* root;
node* nill;

void rotate_left(node T,node* x)
{
    node* y=(x->right);
    x->right=y->left;
    y->left->p=x;
    y->p=x->p;
    if(x->p==nill)
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
    if(x->p==nill)
        root=y;
    else if(x==(x->p)->left)
        (x->p)->left=y;
    else
        (x->p)->right=y;
    y->right=x;
    x->p=y;
}
void fix_insert(node T,node* z)
{
    node* y;
    while(z->color==0)
    {
        if(z->p==z->p->p->left)
        {
            y=z->p->p->right;
            if(y->color==0)
            {
                z->p->color=1;
                y->color=1;
                z->p->p->color=0;
                z=z->p->p;
            }
            else
            {
                if(z==z->p->right)
                {
                    z=z->p;
                    rotate_left(T,z);
                }
                z->p->color=1;
                z->p->p->color=0;
                rotate_right(T,z->p->p);
            }
        }
        else
        {
            y=z->p->p->left;
            if(y->color==0)
            {
                z->p->color=1;
                y->color=1;
                z->p->p->color=0;
                z=z->p->p;
            }
            else
            {
                if(z==z->p->left)
                {
                    z=z->p;
                    rotate_right(T,z);
                }
                z->p->color=1;
                z->p->p->color=0;
                rotate_left(T,z->p->p);
            }
        }
    }
    root->color=1;
}
void fix_delete(node T,node* z)
{

}
void insrt(node T,node* z)
{
    node* y=nill;
    node* x=root;
    while(x)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==nill)
        root=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->color=0;
    fix_insert(T,z);
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
    T.left=nill;
    T.right=nill;
    T.p=nill;
    T.color=1;
    T.key=interval[0][0];
    nill->left=NULL;
    nill->right=NULL;
    nill->p=NULL;
    nill->color=1;
    nill->key=-1;
    root = &T;
    forp(i,1,n)
    {
        node x;
        x.left=nill;
        x.right=nill;
        x.p=nill;
        x.color=0;
        x.key=interval[0][i];
        insrt(T,&x);
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


