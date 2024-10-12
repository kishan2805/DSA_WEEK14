#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data ;
        node* left;
        node* right;
    
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
}; 
// inserting a node 
node* insertnode(node* &root,int val){
    if(root==NULL){
        root= new node(val);
        return root;
    } 
    if(val>root->data){
        root->right=insertnode(root->right,val);
    }
    else{
        root->left=insertnode(root->left,val);
    }
    return root;
}

// create node 
void createnode(node* &root){
    cout<<"enter the data :";
    int val;
    cin>>val;

    while(val!=-1){
        root=insertnode(root,val);
        cout<<"enter the data : ";
        cin>>val;
    }

}
// level order traversal 
void levelordtra(node* root ){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
    }
}

// inorder trav
void inord(node * root ){
    if(root==NULL){
        return ;
    }
    inord(root->left);
    cout<<root->data;
    inord(root->right );
}

// making a bst from inorder 
node* intobst(int inorder[],int s, int e){
    if(s>e)
        return NULL;
    int mid=(s+e)/2;
    int ele=inorder[mid];
    node* root =new node(ele);

    // recursive call for left subtree
    root->left=intobst(inorder,s,mid-1);
    // recursive call for right subtree
    root->right=intobst(inorder,mid+1,e);

    return root ;

}

// LEETCODE 98 valid BST
// bool solve(node* root, long long int low, long long int upp){
//     if(root==NULL)
//         return true;
//     bool c1=(root->data>low);
//     bool c2=(root->data<upp);
//     bool c3=solve(root->left,low,root->data);
//     bool c4=solve(root->right,root->data,upp);

//     return (c1 && c2 && c3 && c4);
// }

// bool isValidBST(node* root) {
//         long long int low=INT_MIN+10;
//         long long int upp=INT_MAX+10;

//     // we added 10 beacause when int_min/max is used few testcases
//     // have the equal values of them so we increased the range of the 
//     // max and min 

//     return solve(root,low,upp);
// }

// ye gfg ka kth ancestor wala code hai BT week ka 

// Node* solve(Node* root, int &k , int tar, int& ans){
//     if(!root)   return 0;  // return 0 give null as return when accepter is a pointer 
    
//     if(root->data==tar) return root;
//     // lca ka code hai yahan se 
//     auto l=solve(root->left,k,tar,ans);
//     auto r=solve(root->right,k,tar,ans);
    
//     if(ans!=-1)
//         return root;
    
//     if(!l && !r)    return 0;  //if(l==NULL && r==NULL) leaf node wala case 
//     k--;
//     if(k==0)
//         ans=root->data;
//     if(!l && r) return r;
//     if(l&& !r)  return l;
//     if(l && r)  return root;
// }
// int kthAncestor(Node *root, int k, int node)
// {
//     // Code here
//     int ans=-1;
//     auto temp=solve(root,k,node,ans);
//     return ans;
// }

// GENERIC TREE 
class gentree{
    public :
        int data;
        int child_count;
        gentree** child;
    
    gentree(int val){
        this->data=val;
        this->child_count=0;
        this->child=0;
    }
};

gentree* takeinput(){
    int data,count;
    cout<<"enter val: ";
    cin>>data;
    cout<<endl<<"enter children count :";
    cin>>count;

    gentree* root=new gentree(data);
    root->child_count=count;
    root->child=new gentree* [count];
    for(int i=0;i<count;i++){
        root->child[i]=takeinput();
    }
    return root;
}

void levelorder2(gentree* root){
    queue<gentree*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        gentree* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty())  q.push(0);
        }
        else{
            cout<<front->data<<" ";
            for(int i=0;i<front->child_count;i++){
                if(front->child[i])  //if child is not null then push in queue
                    q.push(front->child[i]);
            }
        }
    }
}
// converting bst to a doublly ll 
void convertbsttoll(node* root, node* &head){
    if(!root)   return ;

    // rnl

    // r
    convertbsttoll(root->right,head);
    // n
    root->right=head;
    if(head!=NULL)
        head->left=root;
    head=root;

    // l
    convertbsttoll(root->left,head);
}

void printingll(node* head){
    if(!head)   return;
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->right;
    }
}

node* convertDLLtoBST(node* &head,int n){
    if(!head || n<=0)   return NULL;
    // LNR

    // L
    node* leftsubtree=convertDLLtoBST(head,n/2);
    // N
    node* root=head;
    root->left=leftsubtree;
    head=head->right;

    // R
    node* rightsubtree=convertDLLtoBST(head,n-n/2-1);
    root->right=rightsubtree;

    return root;
}

// ASSIGNMENT PROBLEMS 
// INORDER SUCCESSOR

void inordersuccesor(node* root, int tar){
    if(!root)   return;
    int val=root->data;
    
    if(val==tar && root->right!=NULL){
        node* ans=root->right ;
        cout<<ans->data;
    }
    else if (tar>val){
        inordersuccesor(root->right,tar);
    }
    else {
        inordersuccesor(root->left,tar);
    }
// if not found 
    return;
}

// inorder predecessor 
void inorderpresor(node* root, int tar,node* &ans){
    if(!root)   return;
    int val=root->data;
    
    if(val==tar){
        cout<<ans->data;
        return ;
    }
    else if (tar>val){
        ans=root;
        inorderpresor(root->right,tar,ans);
    }
    else {
        ans=root;
        inorderpresor(root->left,tar,ans);
    }
// if not found 
    return;
}

// problem 3 bst from pre 
// TreeNode* sol(int &i, int min , int max , vector<int>& preorder){
//         // base case 
//         if(i>=preorder.size())
//             return NULL;
//         TreeNode* root=NULL;
//         if(preorder[i]>min && preorder[i]<max){
//             // i++;
//             root=new TreeNode(preorder[i++]);
//             root->left=sol(i,min,root->val,preorder);
//             root->right=sol(i,root->val,max,preorder);
//         }
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int i=0;
//         int min=INT_MIN;
//         int max=INT_MAX;
//         return sol(i,min,max,preorder);
//     }

// problem 4 : brothers from diff root 


int main(){
    // node* root=NULL;
    // createnode(root);
    // levelordtra(root);

    // inorder to bst 
    int inorder[]={2,3,4,5,6,7,8};
    node* root=intobst(inorder,0,6);
    levelordtra(root);
    cout<<endl;

    // gentree* root=takeinput();
    // levelorder2(root);

    // converting bst to a doubly ll
    // node* head=NULL;
    // convertbsttoll(root,head);
    // printingll(head);

    // node* root2=convertDLLtoBST(head,7);
    // cout<<endl; 
    // levelordtra(root2);

    // ASSIGNMENT PROBLEM

    // problem 1 : INORDER SUCCESSOR
    // int target=7;
    // inordersuccesor(root,target);

    // problem 2 : INORDER PREDECESSOR
    // int tar=7;
    // node* ans=NULL;
    // inorderpresor(root,tar,ans);

    // problem 3 : BUILD BST USING PREORDER TRAVERSAL 





    

}