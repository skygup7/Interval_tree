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
    int low;
    int high;
    int color;
    int max_high;
};
node* root;
node* nill;

node* successor(node* z)
{
    node* y;
    if(z->right!=nill)
    {
        while(z->left)
            z=z->left;
        return z;
    }
    y=z->p;
    while(y!=nill && z==y->right)
    {
        z=y;
        y=y->p;
    }
    return y;
}
void rotate_left(node T,node* x)
{
    //cout<<x->p->low<<endl;
    node* y=(x->right);
    x->right=y->left;
    y->left->p=x;
    y->p=x->p;
    if(x->p==nill)
        {root=y;}
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
    //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
    node* y;
    //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
    while(z->p->color==0)
    {
        //cout<<"check insert fix"<<endl;
        //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
        if(z->p==z->p->p->left)
        {
            y=z->p->p->right;
            //cout<<"check insert fix 1 "<<endl;
            if(y->color==0)
            {
                z->p->color=1;
                y->color=1;
                z->p->p->color=0;
                z=z->p->p;
                //cout<<"check insert fix 1 2"<<endl;
            }
            else
            {
                if(z==z->p->right)
                {
                    z=z->p;
                    rotate_left(T,z);
                }
                z->p->p->color=0;
                z->p->color=1;
                rotate_right(T,z->p->p);
                //cout<<"check insert fix 1 2"<<endl;
            }
            //cout<<"check insert fix 1"<<endl;
        }
        else
        {
            //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
            y=z->p->p->left;
            //cout<<"check insert fix 2"<<endl;
            if(y->color==0)
            {
                //cout<<"check insert fix 2 1"<<endl;
                z->p->color=1;
                y->color=1;
                z->p->p->color=0;
                z=z->p->p;
            }
            else
            {
                //cout<<"check insert fix 2 2"<<endl;
                if(z==z->p->left)
                {
                    z=z->p;
                    rotate_right(T,z);
                }
                (z->p)->p->color=0;
                z->p->color=1;
                rotate_left(T,z->p->p);
                //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
                //cout<<" special "<<z->p->p->low<<endl;
            }
            //cout<<"check insert fix 2"<<endl;
        }
    }
    root->color=1;
    //cout<<z->p->low<<" "<<z->low<<endl;
    //cout<<root->low<<" "<<endl;
}
void fix_delete(node T,node* x)
{
    node* y;
    node* w;
    while(x!=root && x->color==1)
    {
        if(x==x->p->left)
        {
            w=x->p->right;
            if(w->color==0)
            {
                w->color=1;
                x->p->color=0;
                rotate_left(T,x->p);
                w=x->p->right;
            }
            if(w->left->color==1 && w->right->color==1)
            {
                w->color=0;
                x=x->p;
            }
            else
            {
                if(w->right->color==1)
                {
                    w->left->color=1;
                    w->color=0;
                    rotate_right(T,w);
                    w=x->p->right;
                }
                w->color=x->p->color;
                x->p->color=1;
                w->right->color=1;
                rotate_left(T,x->p);
                x=root;
            }
        }
        else
        {
            w=x->p->left;
            if(w->color==0)
            {
                w->color=1;
                x->p->color=0;
                rotate_right(T,x->p);
                w=x->p->left;
            }
            if(w->right->color==1 && w->left->color==1)
            {
                w->color=0;
                x=x->p;
            }
            else
            {
                if(w->left->color==1)
                {
                    w->right->color=1;
                    w->color=0;
                    rotate_left(T,w);
                    w=x->p->left;
                }
                w->color=x->p->color;
                x->p->color=1;
                w->left->color=1;
                rotate_right(T,x->p);
                x=root;
            }
        }
    }
    x->color=1;
}
void insrt(node T,node* z)
{
    node* y=nill;
    node* x=root;
    while(x!=nill)
    {
        y=x;
        if(z->low<x->low)
            x=x->left;
        else
            x=x->right;
    }
    //cout<<z<<" "<<y<<" "<<y->p<<endl;
    z->p=y;
    //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
    if(y==nill)
        root=z;
    else if(z->low<y->low)
        y->left=z;
    else
        y->right=z;
    z->color=0;
    //cout<<z<<" "<<z->p<<" "<<z->p->p<<endl;
    //cout<<"check insert"<<endl;
    fix_insert(T,z);
}
void delet(node T, node* z)
{
    node* y;
    node* x;
    if(z->left==nill || z->right==nill)
        {y=z;}
    else
        y=successor(z);
    cout<<z->low<<endl;
    cout<<z->p->low<<endl;
    cout<<y->p->low<<endl;
    cout<<"check successor"<<endl;
    if(y->left!=nill)
        x=y->left;
    else
        x=y->right;
    cout<<"before parent assigned"<<endl;
    cout<<y->p->low<<endl;
    x->p=y->p;
    if(y->p==nill)
        root=x;
    else if(y==y->p->left)
        y->p->left=x;
    else
        y->p->right=x;
    if(y!=z)
    {
        z->low=y->low;
    }
    cout<<"delete complete almost"<<endl;
    if(y->color==1)
        fix_delete(T,x);
}
node* serch(node T,int i,int j)
{
    node* x=root;
    while(x!=nill && (j<x->low || i>x->high))
    {
        if(x->left!=nill && x->left->max_high>=i)
            x=x->left;
        else
            x=x->right;
    }
    //cout<<x->low<<" "<<x->high<<endl;
    return x;
}
int maintenance(node* x)
{
    if(x==nill)
        return 0;
    x->max_high=max(max(maintenance(x->left),maintenance(x->right)),x->high);
    return x->max_high;
}
void traverse(node* x)
{
    if(x==nill)
        return;
    traverse(x->left);
    cout<<"low of node is "<<x->low<<" & low of parent is "<<x->p->low<<endl;
    traverse(x->right);
}

int main()
{
    csl;
    int n,x,y;
    int loop=1;
    node T;
    nill=new struct node;
    nill->left=NULL;
    nill->right=NULL;
    nill->p=NULL;
    nill->color=1;
    nill->low=-1;
    nill->high=-1;
    nill->max_high=0;
    T.left=nill;
    T.right=nill;
    T.p=nill;
    T.color=1;
    T.low=-1;
    T.high=-1;
    T.max_high=0;
    root = &T;
    node* ptr;
    while(loop)
    {
        cout<<"Enter respective integer for following and -1 for exit\n 1   Insert\n 2   Delete\n 3   Search\n 4    In-order Traversal giving node and its parent value\n\n For default test case, refer Readme.md\n"<<endl;
        cin>>loop;
        if(loop<=-1)
            break;
        if(loop==1)
        {
            cout<<"Enter number of elements"<<endl;
            cin>>n;
            cout<<"Enter "<<n<<" intervals, one in each line"<<endl;
            forp(i,0,n)
            {
                cin>>x>>y;
                if(T.low==-1)
                {
                    T.low=x;
                    T.high=y;
                    T.max_high=0;
                }
                else
                {
                    node* a=new struct node;
                    a->left=nill;
                    a->right=nill;
                    a->p=nill;
                    a->color=0;
                    a->low=x;
                    a->high=y;
                    a->max_high=0;
                    insrt(T,a);
                }
            }
        }
        else if(loop==2)
        {
            maintenance(root);
            cout<<"Enter number of elements to be deleted"<<endl;
            cin>>n;
            cout<<"Enter "<<n<<" intervals to be deleted(one in a line)"<<endl;
            forp(i,0,n)
            {
                cin>>x>>y;
                ptr=serch(T,x,y);
                cout<<"check"<<endl;
                if(ptr->low>=0)
                    {delet(T,serch(T,x,y));}
                else
                    cout<<"Interval not found"<<endl;
            }
        }
        else if(loop==3)
        {
            maintenance(root);
            cout<<"Enter number of elements to be searched"<<endl;
            cin>>n;
            cout<<"Enter "<<n<<" intervals to be searched(one in a line)"<<endl;
            forp(i,0,n)
            {
                cin>>x>>y;
                ptr=serch(T,x,y);
                if(ptr->low>=0)
                    cout<<"Overlapping Interval found:   "<<ptr->low<<" "<<ptr->high<<endl;
                else
                    cout<<"Interval not found"<<endl;
            }
        }
        else if(loop==4)
        {
            traverse(root);
        }
        else
            cout<<"Kindly limit your expectations ....XD.... :P"<<endl;
////        cout<<"construction done"<<endl;
////        maintenance(root);
////        cout<<"Maintenance done"<<endl;
////        node* z;
////        forp(i,0,10)
////        {
////            z=serch(T,i,i);
////            if(z->low>=0)
////                cout<<z->low<<" "<<z->high<<endl;
////            else
////                cout<<"Interval not found"<<endl;
////        }
////        cout<<"search done"<<endl;
////        forp(i,1,4)
////        {
////            delet(T,serch(T,i,i));
////        }
////        cout<<"deletion done"<<endl;
////        maintenance(root);
////        cout<<"Maintenance done"<<endl;
////        forp(i,3,5)
////        {
////            z=serch(T,i,i);
////            if(z->low>=0)
////                cout<<z->low<<" "<<z->high<<endl;
////            else
////                cout<<"Interval not found"<<endl;
////        }

    }
}

/*
11
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
11 11
*/
