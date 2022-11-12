#include <bits/stdc++.h>
using namespace std;
int dist[1000000];
int bfs(int init, vector<int> arr[], int n){
    queue<int> q;
    q.push(init);

    int visited[n+1];
    for(int i = 0; i<= n; i++){
        visited[i] = 0;
        dist[i] = 0;
    }

    visited[init] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i< arr[u].size(); i++){
            if(visited[arr[u][i]] == 0) {
                visited[arr[u][i]] = 1;
                dist[arr[u][i]] += dist[u]+1;
                 q.push(arr[u][i]);
            }
        }
    }

    return int(max_element(dist+1,dist+n+1)-dist);
}
int findDiameter(vector<int> arr[],int n){
    int init = bfs(1,arr,n);
    int val = bfs(init,arr,n);
    int diameter = dist[val];
    bool endpoint[n+1] = {false};
    for(int i = 1; i<= n; i++){
        if(dist[i] == diameter) endpoint[i] = true;
    }
    bfs(val,arr,n);
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(endpoint[i]==true || dist[i] == diameter){
            cout << diameter+1 << endl;
        }else{
            cout << diameter << endl;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr[n+1];
    for(int i = 0; i< n-1; i++){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

   findDiameter(arr,n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
#ifndef ONLINE_JUDGE
    (void)!freopen("input.txt", "r", stdin);
//    (void)!freopen("output.txt", "w", stdout);
#endif
  
    int t = 1;
    while (t--) {
        solve();
        cout << "\n";
    }
  
    return 0;
}
