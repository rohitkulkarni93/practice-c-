//	Leetcode median of 2 sorted arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> vals;
        AddToVals(nums1, vals);
        AddToVals(nums2, vals);
        std::sort(vals.begin(), vals.end());
        return getMedian(vals);
    }
    
    private:
    
        double getMedian(vector<double> & vals)
        {
            if(vals.size() > 3)
                return (vals[1] + vals[2]) / 2;
            else if(vals.size() == 3)
                return vals[1];
            else if(vals.size() == 2)
                return (vals[0] + vals[1]) / 2;
            else return vals[0];
        }
    
        void AddToVals(vector<int> & nums1, vector<double> & vals)
        {
            if(nums1.size() > 0)
            {
                int middleIndex = (nums1.size() - 1) / 2;
                vals.push_back(nums1[middleIndex]);
                if(nums1.size() % 2 == 0 && middleIndex + 1 < nums1.size())
                    vals.push_back(nums1[middleIndex + 1]);
            }
        }
};
