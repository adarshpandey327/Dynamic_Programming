/*

1335.
Minimum Difficulty of a Job Schedule
Hard

You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.

*/

// Solution :-

int dp[301][11];
class Solution {
    private:
    int solve(int index, vector<int>&nums , int d,int n){
        if(d==1){
            int maxi = INT_MIN;
            for(int i=index ;i<n ;i++){
                maxi = max(nums[i],maxi);
            }
            return maxi;
        }

        if(dp[index][d]!=-1) return dp[index][d];

        int maxi_element = nums[index];
        int ans = INT_MAX;
        for(int i=index; i <= n-d ; i++ ){
            maxi_element = max(maxi_element, nums[i]);
            int result = maxi_element + solve(i+1, nums ,d-1 ,n);
            ans = min(result,ans);
        }
        return dp[index][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int n= jd.size();
        if(d > n) 
            return -1;
        return solve(0, jd, d, n);
    }
};
