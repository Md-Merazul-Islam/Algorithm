class Solution {
public:
    int search(vector<int>& v, int x) {
        int ans ;
        int l=0;
        int r= v.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(v[mid]==x)
            {
                return mid;
            }
            else if(v[mid]<x)
            {
                l = mid+1;
            }
            
            else{
                r = mid -1; 
            }
        }
        
         return -1;
    }
};