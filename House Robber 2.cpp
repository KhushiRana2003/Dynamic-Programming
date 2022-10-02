#include <bits/stdc++.h> 
long long int solveSpace(vector<long long int> &nums){
    
    long long int n = nums.size();
    
    long long int prev2 = 0;
    long long int prev1 = nums[0];
    long long int ans;
    for(int i = 1; i < n; i++){
        long long int inc = prev2 + nums[i];
        long long int exc = prev1 + 0;
        
        ans = max(inc,exc);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    long long int n = valueInHouse.size();
    vector<long long int> temp1, temp2;
    if(n == 1)
        return valueInHouse[0];
    for(int i = 0; i < n; i++){
        if(i != 0)
            temp1.push_back(valueInHouse[i]);
        if(i != n-1)
            temp2.push_back(valueInHouse[i]);
    }
    long long int ans1 = solveSpace(temp1);
    long long int ans2 = solveSpace(temp2);
    
    return max(ans1, ans2);
}
