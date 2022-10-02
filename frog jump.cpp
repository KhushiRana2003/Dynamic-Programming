#include <bits/stdc++.h>
// Memoization
// int helper(int idx, vector<int> &height, vector<int> &dp){
//     if(idx == 0){
//         return 0;
//     }
//     if(dp[idx] != -1){
//         return dp[idx];
//     }
    
//     int left = helper(idx-1, height, dp) + abs(height[idx]-height[idx-1]);
//     int right = INT_MAX;
//     if(idx > 1){
//         right = helper(idx-2, height, dp) + abs(height[idx]-height[idx-2]);
//     }
//     return dp[idx] = min(left,right);
// }



int frogJump(int n, vector<int> &heights)
{

//     vector<int> dp(n+1, -1);
//     return helper(n-1, heights, dp);

//     Tabulation
//     vector<int> dp(n,0);
//     dp[0] = 0;
//     for(int i = 1; i < n; i++){
//         int fn = dp[i-1] + abs(heights[i] - heights[i-1]);
//         int ss = INT_MAX;
//         if(i > 1)
//             ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        
//         dp[i] = min(fn,ss);
//     }
//     return dp[n-1];
    
//     Space Optimization
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = prev2 + abs(heights[i] - heights[i-2]);
        
        int curr = min(fs,ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
