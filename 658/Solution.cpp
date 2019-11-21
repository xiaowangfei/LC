vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int start = 0;
    int end = arr.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] > x){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    int left;
    int right;
    left = start - 1;
    right = start ;
    for(int i = 0; i < k; i++){
        if(left >= 0 && right < arr.size()){
            if(x - arr[left] <= arr[right] - x){
                left--;
            }
            else{
                right++;
            }
        }
        else if(left >= 0){
            left--;
        }
        else{
            right++;
        }
    }
    //left is 1 element beyond starting point
    return vector<int>(arr.begin() + left + 1, arr.begin() +right);        
}
