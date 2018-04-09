#include<bits/stdc++.h>
using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};

tree* newnode(int k){
	tree* temp = (tree*)malloc(sizeof(tree));
	temp->data=k;
	temp->left=temp->right=NULL;
	return temp;
}

void diagonaltrav(tree* t){
	//Prints Diagonal traversal of a tree
	if(!t){
		return;	
	}
	queue<tree*> q;
	q.push(t);
	q.push(NULL);
	while(!q.empty()){
		tree* node=q.front();
		while(!node){
			q.pop();
			if(q.empty()){
				cout<<endl;
				return;
			}
			node=q.front();
		}
		q.pop();
		if(node->left)
			q.push(node->left);
		cout<<node->data<<" ";
		node=node->right;
		
		while(node){
			cout<<node->data<<" ";
			if(node->left){
				q.push(node->left);
			}
			node=node->right;
				
		}
		while(q.front()){
			node=q.front();
			q.pop();
			cout<<node->data<<" ";
			q.push(node->left);
			node=node->right;
			while(node){
				cout<<node->data<<" ";
				q.push(node->left);
			}
		}
		q.pop();
		q.push(NULL);
	}	
}

void inorder(tree* node){
	if(!node)
		return;
	stack<tree*> q;
	q.push(node);
	while(!q.empty()){
		node=q.top();	
		while(node->left){
			q.push(node->left);
			node=node->left;
		}
		while(!q.empty()){
			tree* n=q.top();
			q.pop();
			cout<<n->data<<" ";
			if(n->right){
				q.push(n->right);
				break;
			}
		}
	}
	cout<<endl;
}

tree* lca(tree* root, int a, int b){
	//find the lowest common ancestor of two nodes containing a and b resp.
	if(!root)
		return NULL;
	if(root->data==a || root->data==b)
		return root;
	tree* left=lca(root->left,a,b);
	tree* right=lca(root->right,a,b);
	if(left && right){
		return root;
	}
	else if(left)
		return left;
	return right;
}

int finddistance(tree* root, int a, int b){
	if(!root){
		return -1;
	}
	
	if(root->data==a){
		return b;
	}
	int x=finddistance(root->left, a, b+1);
	if(x!=-1)
		return x;
	return finddistance(root->right,a,b+1);
}

int distance(tree* node, int a ,int b){
	//Finds distance between nodes containing a and b
	tree* l=lca(node,a,b);
	return finddistance(l,a,0)+finddistance(l,b,0);
}

void printsingles(tree* root){
	//prints all elements of the tree which have no siblings
	if(!root)
		return;
	if(root->left && root->right){
		printsingles(root->left);
		printsingles(root->right);
	}
	else if(root->left){
		cout<<root->left->data<<" ";
		printsingles(root->left);
	}
	else if(root->right){
		cout<<root->right->data<<" ";
		printsingles(root->right);
	}
}


int main(){
	tree* t=newnode(1);
	t->left=newnode(2);
	t->right=newnode(4);
	t->left->left=newnode(3);
	t->left->right=newnode(5);
	t->right->left=newnode(6);
	t->right->right=newnode(7);
	diagonaltrav(t);
	inorder(t);
	cout<<lca(t,3,5)->data<<endl;
	cout<<distance(t,3,2)<<endl;
	printsingles(t);
	cout<<endl;
	return 0;

/*
		1
	2		4
   3	    5       6	    7
*/
}
