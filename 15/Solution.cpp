vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3){
        return result;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]){  //Remove duplicate
            continue;
        }
        int left = i + 1;                      // + 1
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                result.push_back(temp);
            }
            if(sum <= 0){
                while(left < right && nums[left + 1] == nums[left]) left++; //remove duplicate
                left++;
            }
            if(sum >= 0){
                while(left < right && nums[right - 1] == nums[right]) right--;
                right--;
            }
        }            
    }
    return result;  
}
//Practice using one Hash. Mind ordering for duplciate!
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3){
        return result;
    }
    map<int, int> H;
    for(int i = 0; i < nums.size(); i++){
        if(H.find(nums[i]) == H.end()){
            H[nums[i]] = 1;
        }
        else{
            H[nums[i]] += 1;
        }
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]){  //Remove duplicate is needed even for Hash method
            continue;
        }
        for(int j = i + 1; j < nums.size(); j++){
            if(j != i + 1 && nums[j] == nums[j - 1]){
                continue;
            }
            if(H.find(0 - nums[i] - nums[j]) == H.end()){
                continue;
            }
            if(nums[i] == nums[j]){
                if(nums[j] == 0 - nums[i] - nums[j] && H[0 - nums[i] - nums[j]] >= 3){
                        vector<int> temp(3, nums[i]);
                        result.push_back(temp);
                }
                else if(nums[j] < 0 - nums[i] - nums[j]){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(0 - nums[i] - nums[j]);
                    result.push_back(temp);
                }
            }
            else{
                if(nums[j] ==0 - nums[i] - nums[j] && H[0 - nums[i] - nums[j]] >= 2){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(0 - nums[i] - nums[j]);
                    result.push_back(temp);
                }
                else if(nums[j] < 0 - nums[i] - nums[j]){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(0 - nums[i] - nums[j]);
                    result.push_back(temp);
                }
            }
        }        
    }
    return result;  
}
