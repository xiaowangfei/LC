//More comments on 704
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    if(nums.empty()){
        return result;
    }

    int start = 0;
    int end = nums.size() - 1;
    //Check First
    //For start < end, end can just equal mid without dead loop, but not start. (When start = end, mid points to start)
    while(start < end){
        int mid = start + (end - start)/2;
        if(nums[mid] >= target){
            end = mid;             
        }
        else{
            start = mid + 1;
        }
    }
    if(nums[start] == target) result[0] = start;

    start = 0;
    end = nums.size() - 1;
    //Check Last
    //But start has to be mid + 1, so need to check next item when nums[mid] = target
    while(start <= end){ 
        int mid = start + (end - start)/2;
        if(nums[mid] > target){
            end = mid - 1;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else if(mid < nums.size() -1 && nums[mid + 1] == target){
            start = mid + 1;
        }
        else{
            result[1] = mid;
            return result;
        }
    }
    return result;

}
//start + 1 < end, so start and end can just = mid when nums[mid] = target
vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result(2, -1);
    if(nums.empty()){
        return result;
    }
    
    int start = 0;
    int end = nums.size() - 1;
    while(start < end - 1){
        int mid = start + (end - start)/2;
        if(nums[mid] >= target){
            end = mid;
        }
        else{
            start = mid;
        }
    }   
    if(nums[start] == target)            result[0] = start;
    else if(nums[end] == target)         result[0] = end;

    start = 0;
    end = nums.size() - 1;
    while(start + 1 < end){ 
        int mid = start + (end - start)/2;
        if(nums[mid] > target){
            end = mid;
        }
        else if(nums[mid] <= target){
            start = mid ;
        }
    }
    if(nums[end] == target) result[1] = end;
    else if(nums[start] == target) result[1] = start;  
    
    return result;
}

