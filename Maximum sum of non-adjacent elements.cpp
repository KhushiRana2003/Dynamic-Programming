#include <bits/stdc++.h> 
// Recursion

int solve(vector<int> &nums, int n){
    if( n < 0 )
        return 0;
    if(n == 0){
        return nums[0];
    }
    
    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;
    
    return max(include, exclude);
}

// Memoization
int solveMemo(vector<int> &nums, int n, vector<int> &dp){
    
    if( n < 0 )
        return 0;
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    
    int include = solveMemo(nums, n-2, dp) + nums[n];
    int exclude = solveMemo(nums, n-1, dp) + 0;
    dp[n] = max(include, exclude);
    return dp[n];
}

// tabulation
int solveTab(vector<int> &nums){
    
    int n = nums.size();
    
    vector<int> dp(n,0);
    
    dp[0]=nums[0];
    
    for(int i = 1; i < n; i++){
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1] + 0;
        
        dp[i] = max(inc,exc);
    }
    return dp[n-1];
}

// Space Optimisation
int solveSpace(vector<int> &nums){
    
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];
    int ans;
    for(int i = 1; i < n; i++){
        int inc = prev2 + nums[i];
        int exc = prev1 + 0;
        
        ans = max(inc,exc);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    
//     int ans = solve(nums, n-1);
//     return ans;
//     vector<int> dp(n, -1);
//     return solveMemo(nums, n-1, dp);
    
//     return solveTab(nums);
    return solveSpace(nums);
}
