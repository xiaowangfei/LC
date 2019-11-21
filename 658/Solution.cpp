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

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //binary search for result's starting index
    int start = 0;
    int end = arr.size() - k;  //Right most possible start index
    while(start < end){
        int mid = start + (end - start)/2;
        if(x - arr[mid] > arr[mid + k] - x){//Check which side of result range has closer difference with target
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return vector<int>(arr.begin() + start , arr.begin() + start + k);        
}
