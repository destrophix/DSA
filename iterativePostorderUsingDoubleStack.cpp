#include<bits/stdc++.h>
using namespace std;

vector<int> iterativePostorderUsingDoubleStack(Node* root){
    vector<int> postorder;
    if(root == NULL) return postorder;

    stack<Node*> st1,st2;

    st1.push(root);
    while(!st1.empty()){
        Node* root = st1.top();
        st1.pop();

        st2.push(root);
        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st2.push(root->right);
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
    }

    return postorder;
}

int main(){
    return 0;
}
