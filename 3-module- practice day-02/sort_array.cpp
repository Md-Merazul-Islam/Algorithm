
class Solution {
private:
    void merge(vector<int>& nums, int l, int r, int mid) {
        int left_size = mid - l + 1;
        int L[left_size];

        int right_size = r - mid;
        int R[right_size];

        for (int i = 0; i < left_size; i++) {
            L[i] = nums[l + i];
        }

        for (int i = 0; i < right_size; i++) {
            R[i] = nums[mid + 1 + i];
        }

        int lp = 0, rp = 0;
        for (int i = l; i <= r; i++) {
            if (lp < left_size && (rp >= right_size || L[lp] <= R[rp])) {
                nums[i] = L[lp];
                lp++;
            } else {
                nums[i] = R[rp];
                rp++;
            }
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        merge(nums, l, r, mid);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};