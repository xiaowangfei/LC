    int firstBadVersion(int n) {
        if(n <= 1) return n;
        int start = 1;
        int end = n;
        while(start < end){
            int mid = start + (end - start)/2;
            if(isBadVersion(mid)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        if(isBadVersion(start)) return start;
        return -1;
    }
