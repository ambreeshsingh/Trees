#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data =val;
        left=right=NULL;

    }

};
static int idx=-1;
Node* buildTree(vector<int>preorder){
    idx++;
    //base case
    if(preorder[idx]==-1)return NULL;
    //ekkaam mai kar dunga
    Node*root=new Node(preorder[idx]);

    //baaki recursion sambhal lega
    root->left=buildTree(preorder);//left
    root->right=buildTree(preorder);//right
    return root;

}
//preorder
void preOrder(Node*root){//0(n)
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);



}

//inorder
void inorder(Node*root){//0(n)
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(Node*root){//0(n)
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
//LEVEL ORDER TRAVERSAL
void levelordertraversal(Node*root){
    queue<Node*>q;
    q.push(root);

    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);

        }
        if(curr->right!=NULL){

            q.push(curr->right);

        }
    }

cout<<endl;

}






int main(){
     vector<int> preorder={1,2,-1,-1,3,-1,-1};
     Node *root=buildTree(preorder);
     preOrder(root);
     cout<<endl;
     
     inorder(root);
     cout<<endl;

     postorder(root);
     cout<<endl;

     levelordertraversal(root);
     cout<<endl;
    return 0;

}