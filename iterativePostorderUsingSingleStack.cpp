#include<bits/stdc++.h>
using namespace std;

vector<int> iterativePostorderTraversalUsingSingleStack(Node* root){
    vector<int> postorder;

    if(root == NULL) return postorder;
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr)
            curr = curr->left;
        }else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }
            }else{
                curr = temp;
            }
        }
    }

    return postorder;
}

int main(){
    return 0;
}
