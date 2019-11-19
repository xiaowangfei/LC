 bool isPalindrome(string s) {
     int start = 0;
     int end = s.size() - 1;
     while(start < end){
         while(start < s.size() && !isalnum(s[start])){
             start++;
         }
         while(end >= 0 && !isalnum(s[end])){
             end--;
         }
         if(start < end && tolower(s[start]) != tolower(s[end])){
             return false;
         }
         start++;
         end--;
     }
     return true;
 }

 bool isPalindrome(string s) {
     int start = 0;
     int end = s.size() - 1;
     while(start < end){
         while(start < end && !isalnum(s[start])){
             start++;
         }
         while(start < end && !isalnum(s[end])){
             end--;
         }
         if(tolower(s[start]) != tolower(s[end])){
             return false;
         }
         start++;
         end--;
     }
     return true;
 }
 
