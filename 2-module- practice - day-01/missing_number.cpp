class Solution {
public:
    int missingNumber(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int result ;
        for (int i=0; i<n;i++)
        {
            if(i != v[i])
            {
                result = i;
                break;
            }
        }
        return result ;
    }
};