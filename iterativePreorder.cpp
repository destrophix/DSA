#include<bits/stdc++.h>
using namespace std;

vector<int> iterativePreorderTraversal(Node* root){
   vector<int> preorder;
   if(root==NULL) return preorder;
   stack<Node*> st;
   st.push(root);

   while(!st.empty()){
        Node* root = st.top();
        st.pop();
        preorder.push_back(root->val);

        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);

   }
   return preorder;
}

int main(){
    return 0;
}
