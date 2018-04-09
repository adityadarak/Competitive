/* Given a binary tree, return the inorder traversal of its nodes' values. */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> fin;
        stack <TreeNode*> st;
        if(root==NULL){
            return fin;
        }
        int done=0;
        st.push(root);
        while(!st.empty()){
            TreeNode* n=st.top();
            if(n->left && !done){
                st.push(n->left);
                done=0;
            }
            else{
                fin.push_back(n->val);
                st.pop();
                done=1;
                if(n->right){
                    st.push(n->right);
                    done=0;
                }
            }
        }
        return fin;
    }
};

/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
  3
   / \
  9  20
    /  \
   15   7
   return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
class Solution {
public:
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    
    void zigzag(TreeNode* root, vector<vector<int>>& ans, int level){
        if(!root){
            return;
        }
        
        ans[level].push_back(root->val);
        //if(level%2==0){
        zigzag(root->right,ans,level+1);
        zigzag(root->left,ans,level+1);
        //}
        //else{
        //zigzag(root->left,ans,level+1);
        //zigzag(root->right,ans,level+1);
        //}
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h=height(root);
        vector<vector<int>> ans;
        ans.resize(h);
        zigzag(root,ans,0);
        for(int i=0;i<h;i=i+2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};

/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
class Solution {
public:
    bool hasSum(TreeNode* root, int sum, int curr){
        if(!root){
            return false;
        }
        curr+=root->val;
        //cout<<curr<<endl;
        if(sum==curr && !root->left && !root->right){
            return true;
        }
        bool ans=hasSum(root->left,sum,curr)|| hasSum(root->right,sum,curr);
        return ans;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        int curr=0;
        return hasSum(root,sum,curr);
    }
};

/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
class Solution {
public:
    void hasSum(TreeNode* root, int sum, int curr, vector<vector<int>>& ans, vector<int> temp){
        if(!root){
            return;
        }
        curr+=root->val;
        temp.push_back(root->val);
        if(curr==sum && !root->left && !root->right){
            ans.push_back(temp);
        }
        hasSum(root->left,sum,curr,ans,temp);
        hasSum(root->right,sum,curr,ans,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        hasSum(root,sum,0,ans,temp);
        return ans;
    }
};

/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> fin;
        if(root==NULL){
            return fin;
        }
        stack <TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* n=st.top();
            fin.push_back(n->val);
            st.pop();    
            if(n->right){
                st.push(n->right);
            }
            if(n->left){
                st.push(n->left);
            }
        }
        return fin;
    }
};

/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3
 

return [3,2,1].
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> fin;
        stack <TreeNode*> st;
        if(!root){
            return fin;
        }
        st.push(root);
        TreeNode* prev=NULL;
        while(!st.empty()){
            TreeNode* curr=st.top();
            if(!prev || prev->left==curr || prev->right==curr){
                if(curr->left){
                    st.push(curr->left);
                }
                else if(curr->right){
                    st.push(curr->right);
                }
                else{
                    fin.push_back(curr->val);
                    st.pop();
                }
                prev=curr;
            }
            else if(curr->left==prev){
                if(curr->right){
                    st.push(curr->right);
                }
                else{
                    fin.push_back(curr->val);
                    st.pop();
                }
            }
            else if(curr->right==prev){
                fin.push_back(curr->val);
                st.pop();
            }
            prev=curr;
        }
        return fin;
    }
};

/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        TreeNode* l=invertTree(root->left);
        TreeNode* r=invertTree(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
};

/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
class Solution {
public:
    
    int findrob(TreeNode* root, int& l, int& r){
        if(!root){
            return 0;
        }
        int ll=0,lr=0,rl=0,rr=0;
        l=findrob(root->left,ll,lr);
        r=findrob(root->right,rl,rr);
        //cout<<max(root->val+ll+lr+rl+rr,l+r)<<endl;
        return max(root->val+ll+lr+rl+rr,l+r);
    }
    
    int rob(TreeNode* root) {
        int l,r;
        return findrob(root,l,r);
    }
};

/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& s){
        if(!root){
            return;
        }
        inorder(root->left,s);
        s.push_back(root->val);
        inorder(root->right,s);
    }
    
    bool isValidBST(TreeNode* root){
        if(!root){
            return true;
        }
        vector<int> s;
        inorder(root,s);
        for(int i=1;i<s.size();i++){
            if(s[i]<=s[i-1]){
                return false;
            }
        }
        return true;
    }
};

/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
   */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        } 
        return hep(root->left, root->right);
    }
    
    bool hep(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        if(left->val!=right->val){
            return false;
        }
        
        return hep(left->left,right->right) && hep(left->right,right->left);
    }
};

/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fin;
        queue<TreeNode*> st;
        if(!root){
            return fin;
        }
        st.push(root);
        while(!st.empty()){
            vector<int> f;
            int q=st.size();
            for(int i=0;i<q;i++){
                TreeNode* curr=st.front();
                if(curr->left){
                    st.push(curr->left);
                }
                if(curr->right)
                    st.push(curr->right);
                f.push_back(curr->val);
                st.pop();
            }
            fin.push_back(f);
        }
        return fin;
    }
};

/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
class Solution {
public:
    void has(TreeNode* root, vector<string>& ans, string temp){
        temp+="->";
        cout<<root->val<<endl;
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        else{
            if(root->right){
                has(root->right,ans,temp);
            }
            if(root->left){
                has(root->left,ans,temp);
            }
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)
            return ans;
        string temp;
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        if(root->left)
            has(root->left,ans,temp);
        if(root->right)
            has(root->right,ans,temp);
        return ans;
    }
};

/*Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        if(root->left && root->right){
            root->left->next=root->right;
            if(root->next){
                if(root->next->left){
                    root->right->next=root->next->left;
                }
                else if(root->next->right){
                    root->right->next=root->next->right;
                }
            }
            else{
                root->right->next=NULL;
            }
        }
        else if(root->left){
            if(root->next){
                if(root->next->left){
                    root->left->next=root->next->left;
                }
                else if(root->next->right){
                    root->left->next=root->next->right;
                }
            }
            else{
                root->left->next=NULL;
            }
        }
        else if(root->right){
            if(root->next){
                if(root->next->left){
                    root->right->next=root->next->left;
                }
                else if(root->next->right){
                    root->right->next=root->next->right;
                }
            }
            else{
                root->right->next=NULL;
            }
        }
        connect(root->left);
        connect(root->right);
    }
};

/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#";
        }
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        return mdeserialize(data);
    }
    TreeNode* mdeserialize(string& data) {
        if(data[0]=='#'){
            if(data.size()!=1)
                data=data.substr(2);
            return NULL;
        }
        TreeNode* root=new TreeNode(helper(data));
        root->left=mdeserialize(data);
        root->right=mdeserialize(data);
        return root;
    }
    
    int helper(string& data){
        int index=data.find(",");
        int ans=stoi(data.substr(0,index));
        data=data.substr(index+1);
        return ans;
    }
};

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/
queue<int> inorder(TreeNode* root, queue<int> p){
    if(!root){
        return p;
    }
    p=inorder(root->left,p);
    p.push(root->val);
    p=inorder(root->right,p);
    return p;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<int> p;
        int c=0;
        p=inorder(root,p);
        for(int i=0;i<k-1;i++){
            p.pop();
        }
        return p.front();
    }
}; 

/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1)
            return new TreeNode(nums[0]);
        int mid=nums.size()/2;
        TreeNode* root=new TreeNode(nums[mid]);
        vector<int> l(nums.begin(),nums.begin()+mid);
        vector<int> r(nums.begin()+mid+1,nums.end());
        root->left=sortedArrayToBST(l);
        root->right=sortedArrayToBST(r);
        return root;
    }
};

/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;;
        }
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return max(l,r)+1;
    }
};

/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/
class Solution {
public:
    void c(TreeNode* root, int* count, bool flag){
        if(!root){
            return;
        }
        if(!root->left && !root->right && flag){
            (*count)+=root->val;
        }
        c(root->left,count,true);
        c(root->right,count,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 0;
        }
        int count=0;
        if(root->left){
            c(root->left,&count,true);
        }
        if(root->right)
            c(root->right,&count,false);
        return count;
    }
};

/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
    */
class Solution {
public:
    TreeNode* findleft(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val==key){
            if(!root->right){
                TreeNode* temp=root->left;
                delete(root);
                return root->left;
            }
            else{
                TreeNode* temp=findleft(root->right);
                swap(root->val,temp->val);
                //delete(temp);
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};

/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/
class Solution {
public:
    void findleft(TreeNode* root, int* a,int* depth, int l){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(l>(*depth)){
                (*depth)=l;
                *a=root->val;
            }
        }
        if(root->left){
            findleft(root->left,a,depth,l+1);
        }
        if(root->right){
            findleft(root->right,a,depth,l+1);
        }
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int a=root->val;
        int maxdepth=0;
        findleft(root,&a,&maxdepth, 0);
        return a;
    }
};

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/
class Solution {
public:
    //int maxdepth=0;
    
    int diameterOfBinaryTree(TreeNode* root){
        int maxdepth=0;
        diameter(root,&maxdepth);
        return maxdepth;
    }
    
    int diameter(TreeNode* root, int* maxdepth) {
        if(!root){
            return 0;
        }
        int left=diameter(root->left,maxdepth);
        int right=diameter(root->right,maxdepth);
        //cout<<root->val<<" "<<left<<" "<<right<<" "<<*maxdepth<<endl;
        if(*maxdepth<left+right)
            *maxdepth=left+right;
        return max(left,right)+1;
    }
};

/*Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/
int findnext(TreeNode* root, int k){
    if(!root){
        return -1;
    }
    if(root->val>k){
        return root->val;
    }
    int c=findnext(root->left,k);
    int d=findnext(root->right,k);
    if(c==d==-1){
        return -1;
    }
    else{
        if(c!=-1 && d!=-1){
            return min(c,d);
        }
        if(d!=-1){
            return d;
        } 
        else if(c!=-1){
            return c;
        }
    }
    return min(c,d);
}
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        int k=root->val;
        int c=findnext(root->left,k);
        int d=findnext(root->right,k);
        cout<<c<<endl;
        cout<<d<<endl;
        if(c==-1 && d==-1){
            return -1;
        }
        else{
            if(c!=-1 && d!=-1){
                return min(c,d);
            }
            if(d!=-1){
                return d;
            }
            else if(c!=-1){
                return c;
            }
        }
        return min(c,d);
    }
};
