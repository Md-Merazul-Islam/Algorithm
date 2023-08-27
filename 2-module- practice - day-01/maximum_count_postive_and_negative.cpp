class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int possitive_count = 0;
        int negative_count = 0;
        for (auto it =nums.begin(); it<nums.end();it++)
        {
        if(*it > 0)
        {
            possitive_count++;
        }
        if(*it<0)
        {
            negative_count++;
        }
        }

        if(negative_count < possitive_count)
        {
            return possitive_count;
        }
        else return negative_count;
    }
};