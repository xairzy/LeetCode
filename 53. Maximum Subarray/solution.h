class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for(int num : nums)
        {
            sum = max(num, num + sum);
            res = max(res, sum);
        }
        return res;
    }
};