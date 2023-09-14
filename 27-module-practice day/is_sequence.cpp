class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = s.size();
        int i=0;
        bool ans = false;
        if(n==0 && m==0)
        {
        ans=true;
        }
        for( char c: t)
        {
            
            if(c== s[i])
            {
                i++;
            }
            if(i == s.size())
            {
                ans= true;
                break;
            }
        }
        return ans;

    }
};