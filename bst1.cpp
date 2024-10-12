#include<iostream>
#include<queue>
using namespace std;

class node1{
    public:
        int data;
        node1* left;
        node1* right;

    node1(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node1* insertintoBST(node1* &root,int val){
    if(root==NULL){
        root= new node1(val);
        return root;
    } 
    if(val>root->data){
        root->right=insertintoBST(root->right,val);
    }
    else{
        root->left=insertintoBST(root->left,val);
    }
    return root;
    
}

void createBST(node1* &root){
    cout<<"enthe the data : ";
    int val;
    cin>>val;

    while(val!=-1){
        root=insertintoBST(root,val);
        cout<<"enter the data : ";
        cin>>val;
    }
}
void levelordertrav(node1* root ) {
	queue<node1*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node1* temp = q.front();
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
void preord(node1* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preord(root->left);
    preord(root->right );

}

// INORDER OF A BST IS ALWAYS SORTED 
void inord(node1* root){
    if(root==NULL){
        return ;
    }
    inord(root->left);
    cout<<root->data<<" ";
    inord(root->right );

}

node1* maxele(node1* root){
    if(root==NULL)
        return NULL;
    node1* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;  
}

int minele(node1* root){
    if(root==NULL)
        return -1;
    node1* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;  
}

// searching in the bst 
void searchtar(node1* root, int tar){
    if(root==NULL ){
        cout<<"empty tree"<<endl;
        return; 
    }
    node1* temp=root;
    if(tar==temp->data){
        cout<<"found"<<endl;
        return ;
    }
    if(tar>temp->data)
        searchtar(temp->right,tar);
    else{
        searchtar(temp->left,tar);
    }
}
// deleting a node from BST

node1* deletenode(node1* root,int tar){
    if(root==NULL)
        return NULL;
    
    if(root->data==tar){
        // case 1 leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // case2 node with left child
        else if(root->right==NULL){
            node1* childsubtree=root->left;
            delete root;
            // we are returning the new subtree so that it can connect to the original sub tree 
            return childsubtree;
        }
        // case 3 node with only right child 
        else if(root->left==NULL){
            node1* childsubtree=root->right;
            delete root;

            return childsubtree;
        }
        // case4 node with both child 
        else{
            // finding max in left sub tree
            node1* maxi=maxele(root->left);
            // replace maxi with root node 
            root->data=maxi->data;
            delete maxi;
            root->left=deletenode(root->left,maxi->data);
            return root;
        }
    }

    else if(tar<root->data){
        // 'root->left=' is important so that we can coonect the new updated sub tree to the original subtree

        root->left= deletenode(root->left,tar);
    }
    else{
        root->right= deletenode(root->right,tar);
    }
    return root;

}

int main(){
    node1* root=NULL;
    createBST(root);
    levelordertrav(root);
    cout<<endl;

//     cout<<"preorder traversal :";
//     preord(root); 


// // INORDER OF A BST IS ALWAYS SORTED 
//     cout<<endl<<"inorder traversal :";
//     inord(root);


// // finding the max value 
//     int maxval=maxele(root);
//     cout<<"the max value is : "<<maxval<<endl;

// // finding min value 
//     int minval=minele(root);
//     cout<<"the min value is : "<<minval<<endl;

// searching the tree 
    // searchtar(root,6);

// // deleting a node from BST
//     deletenode(root,5);
//     levelordertrav(root);
    
}