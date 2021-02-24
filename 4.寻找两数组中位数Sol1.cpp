class Solution {
public:
    double findKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int offset1 = 0, offset2 = 0;

        while(k > 0){
            if(offset1 == nums1.size()) return nums2[offset2+k-1];
            if(offset2 == nums2.size()) return nums1[offset1+k-1];

            if(k == 1) return min(nums1[offset1], nums2[offset2]);
            
            int p = k/2 - 1;
            int cut = 0;
            if(offset1 + p >= m){
                if(nums1[m-1] > nums2[offset2+p]) {
                    cut = p+1;
                    offset2 += p+1;
                }
                else{
                    cut = m - offset1;
                    offset1 = m;
                }
            }
            else if(offset2 + p >= n) {
                if(nums2[n-1] > nums1[offset1+p]) {
                    cut = p+1;
                    offset1 += p+1;
                }
                else{
                    cut = n - offset2;
                    offset2 = n;
                }
            }
            else {
                if(nums1[offset1+p] > nums2[offset2+p]) {
                    cut = p+1;
                    offset2 += p+1;
                }
                else  {
                    cut = p+1;
                    offset1 += p+1;
                }
            }

            k -= cut;
        }

        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double a = findKthElement(nums1, nums2, (m+n+1)/2), b = findKthElement(nums1, nums2, (m+n+2)/2);
        return (a+b)/2;
    }
};
