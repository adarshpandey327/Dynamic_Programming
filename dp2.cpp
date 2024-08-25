/*

1239.
Maximum Length of a Concatenated String with Unique Characters
Solved
Medium

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

*/

// solution :

class Solution {
    private:
    
    bool hasduplicate(string s1, string s2){
        vector<int>map(26,0);
        for(auto ch:s1){
            if(map[ch-'a']>0) return true;

            map[ch-'a']++;
        }
        for(auto ch:s2){
            if(map[ch-'a'] > 0) return true;
        }
        return false;
    }

    int solve(int i, string temp, vector<string>& arr, unordered_map<string,int>dp ,int n){
        if(i>=n){
            return temp.length();
        }
        if(dp.find(temp)!=dp.end()) return dp[temp];
        int include =0;
        int  exclude = solve(i+1, temp ,arr,dp , n);
        if(!hasduplicate(arr[i],temp)){
            include = solve(i+1, temp+arr[i] , arr,dp , n);
        }
        return dp[temp]=max(include,exclude);
    }
public:
    int maxLength(vector<string>& arr) {
        int n= arr.size();
        string temp= "";
        unordered_map<string,int>dp;
        return solve(0, temp ,arr, dp ,n);
    }
};
