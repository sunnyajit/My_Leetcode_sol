 class Solution {
public: // code written by sunny
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0; 
        int n= nums1.size(), m=nums2.size();
        while(i<n&&j<m){
            if(nums1[i]==nums2[j]){
                if(ans.size()>=1&&ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }else if(ans.size()==0){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;

            }else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return ans;
    }
};