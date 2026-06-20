class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n3 = n1 + n2;
        int leftParitionSize = (n3+1)/2;

        int low = 0;
        int high = n1;

        while(low <= high) {
            int mid1 = (low+high)/2;

            int mid2 = leftParitionSize - mid1;

            int l1 = (mid1 == 0)? INT_MIN : nums1[mid1-1];
            int r1 = (mid1 == n1)? INT_MAX: nums1[mid1];

            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n2)? INT_MAX: nums2[mid2];

            // valid condition
            if(l1 <= r2 && l2 <= r1) {
                if(n3%2 != 0) {
                    return max(l1,l2);
                } else {
                    return ((max(l1,l2)+min(r1,r2))/2.0);
                }
            } else {
                if((l1 > r2)) {
                    high = mid1-1;
                } else {
                    low = mid1+1;
                }
            }
        }
        return 0.0;
    }
};

/*
return max(l1, l2); why this
Gemini said
Bhai, ye max(l1, l2) wala part sirf Odd (visham) total elements ke case mein chalta hai. Iska logic samajhne ke liye ek simple example dekhte hain.

Maan lo hamare paas total 7 elements hain: [1, 3, 5, 7, 8, 9, 10].
Iska median kya hona chahiye? Chautha (4th) element, yaani 7.

💡 Left Partition Size ka Khel

Humnne formula use kiya tha: leftPartitionSize = (n1 + n2 + 1) / 2.

Agar total 7 elements hain: (7 + 1) / 2 = 4.

Iska matlab hamara Left Half bada hai (4 elements) aur Right Half chota hai (3 elements).


*/
