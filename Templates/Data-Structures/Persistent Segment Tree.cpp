struct node{
    int val;
    node* left;
    node* right;
    node():val(0),left(NULL),right(NULL){};
    node(int _v):val(_v),left(NULL),right(NULL){};
};

int l,r,v;
node* pers[N];

node* build(int i,int j,node* pre){
    if(i>r || j<l) return pre;
    if(i>=l && j<=r) return new node{v};
    int mid=(i+j)>>1;
    node* cur=new node();
    cur->left=build(i,mid,pre->left);
    cur->right=build(mid+1,j,pre->right);
    cur->val=f(cur->left->val,cur->right->val);
    return cur;
}

node* init(int i=0,int j=n-1){
    if(i==j) return new node();
    int mid=(i+j)>>1;
    node* cur=new node();
    cur->left=init(i,mid);
    cur->right=init(mid+1,j);
    return cur;
}

int query(int i,int j,node* pre, node* nex){
    if(i>r || j<l) return 0;
    if(i>=l && j<=r) return f(nex->val,pre->val);
    int mid=(i+j)>>1;
    int L=query(i,mid,pre->left,nex->left);
    int R=query(mid+1,j,pre->right,nex->right);
    return f(L,R);
}

