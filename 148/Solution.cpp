void sortColors(vector<int>& nums) {
    int p0 = 0;
    int p1 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            nums[i] = 2;
            nums[p1] = 1;
            p1++;
        }
        else if(nums[i] == 0){
            nums[i] = 2;
            nums[p1] = 1;
            nums[p0] = 0;
            p0++;
            p1++;
        }
    }      
}
