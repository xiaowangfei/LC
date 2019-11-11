class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> two_sum_map;
	vector<int> result;
	for(int i=0; i < nums.size(); i++){
	        if(two_sum_map.find(target - nums[i]) != two_sum_map.end()){
			result.push_back(i);
			result.push_back(two_sum_map[target - nums[i]]);
			return result;
		}
	        two_sum_map[target - nums[i]] = i;
	}
        return result;
    }
};
