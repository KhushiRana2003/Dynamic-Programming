class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        int p = 1;
        for(char i = 'a'; i <= 'z'; i++){
            mp[i] = p++;
        }

        for(int i = 0; i < chars.length(); i++){
            mp[chars[i]] = vals[i]; 
        }

        vector<int> res;
        for(auto i:s){
            res.push_back(mp[i]);
        }

        int ans = 0;
        int count = 0;
        for(auto i : res){
            count += i;
            ans = max(ans,count);
            if(count < 0) count = 0;
        }
        return ans;
    }
};
