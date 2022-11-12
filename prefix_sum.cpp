#include <bits/stdc++.h>
using namespace std;

void prefix_sum(int arr[],int n){
    int pfsum[n];
    int prevsum = 0;

    for(int i = 0; i< n; i++){
        pfsum[i] = prevsum + arr[i];
        prevsum = pfsum[i];
    }

}

void solve()
{
    // Problem Statement: Given an array of n integers, find if any index exists such that the sum of elements to its right is equal to the sum of elements to its left. If yes print the index, otherwise print “No Equilibrium”.
    int n = 5;
    int arr[n] = {7,2,1,5,4};
    int leftsum = 0, rightsum=0;

    for(int i = 0; i< n; i++){
        rightsum += arr[i];
    }

    for(int i = 0; i< n; i++){
        if(leftsum == (rightsum - arr[i])) cout << i << endl;
        leftsum += arr[i];
        rightsum -= arr[i];
    }
    
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
    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
  
    return 0;
}
