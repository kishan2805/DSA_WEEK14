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
                // this if is usded to prevent this while loop from converting it to a infinite loop 
                // as if removed null will be pushed and poped infinitely 
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
void inord(node * root ){
    if(root==NULL){
        return ;
    }
    inord(root->left);
    cout<<root->data;
    inord(root->right );
}



int main(){
    node* root=NULL;
    createnode(root);
    levelordtra(root);
}