#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node* newnode(int k){
    node* temp = new node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}

int height(node* root){
	if(!root){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}

void inorder(node* root){
	if(!root){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void inorderset(node* root, set<int> &s){
	if(!root){
		return;
	}
	inorderset(root->left,s);
	s.insert(root->data);
	inorderset(root->right,s);
}

void bstfromset(node* root, set<int> &s){
	if(!root){
		return;
	}
	bstfromset(root->left,s);
	set<int>::iterator it=s.begin();
	root->data=*it;
	s.erase(it);
	bstfromset(root->right,s);
}

void postorder(node* root){
	if(!root){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void preorder(node* root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void genbst(node *root){
	set<int> s;
	inorderset(root,s);
	bstfromset(root,s);
	inorder(root);
}

node* lca(node* root, int a, int b){
	if(!root){
		return NULL;
	}

	if(root->data==a || root->data==b){
		return root;
	}

	node* left=lca(root->left,a,b);
	node* right=lca(root->right,a,b);

	if(left && right)
		return root;
	else if(left){
		return left;
	}
	else{
		return right;
	}
}

int finddistancegivenlca(node* root,int a, int b){
	if(!root){
		return -1;
	}
	if(root->data==a){
		return b;
	}
	int left=finddistancegivenlca(root->left,a,b+1);
	if(left==-1){
		return finddistancegivenlca(root->right,a,b+1);
	}
	return left;
}

int finddistance(node* root, int a, int b){
	node* lc=lca(root,a,b);
	return finddistancegivenlca(lc,a,0)+finddistancegivenlca(lc,b,0);
}

int main(){
	struct node* root = newnode(5);
    root->left = newnode(7);
    root->right = newnode(9);
    root->right->left = newnode(10);
    root->left->left = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(11);
    cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"preorder traversal of the tree is: ";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal of the tree is: ";
    postorder(root);
    cout<<endl;
    cout<<"inorder traversal of the tree is: ";
    inorder(root);
    cout<<endl;

    cout<<"Lowest Common Ancestor of 10 and 11 is: "<<lca(root,10,11)->data<<endl;

    cout<<"Distance between 10 and 11 is: "<<finddistance(root,10,11)<<endl;

    cout<<"Inorder traversal of bst tree generated from given tree is: ";
    genbst(root);
    cout<<endl;
	return 0;
}