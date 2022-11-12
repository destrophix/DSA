#include<bits/stdc++.h>
using namespace std;

vector<int> InorderTraversal(Node* root) {
    vector<int> inorder;

    if(root==NULL) return inorder;
    stack<Node*> st;
    Node* node = root;
    while(true) {
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()==true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;

}


int main(){
    return 0;
}
