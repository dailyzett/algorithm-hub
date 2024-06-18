class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        vector<int> ret;
        for(int i=0; i<nums.size(); i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());
        int start_index = 0;
        int end_index = temp.size() - 1;

        while(start_index < end_index) {
            int sum = temp[start_index].first + temp[end_index].first;
            if(sum == target) {
                ret.push_back(temp[start_index].second);
                ret.push_back(temp[end_index].second);
                break;
            } else if(sum > target) {
                end_index--;
            } else {
                start_index++;
            }
        }
        return ret;
    }
};