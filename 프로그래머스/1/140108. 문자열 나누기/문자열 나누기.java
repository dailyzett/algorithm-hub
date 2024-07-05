import java.util.*;

class Solution {
    public int solution(String s) {
        int ret = 0;
        char first = s.charAt(0);
        int firstCount = 0;
        int otherCount = 0;
        for(int i=0; i<s.length(); i++) {
            if(first == s.charAt(i)) {
                firstCount++;
            } else {
                otherCount++;
            }
            
            if(firstCount == otherCount) {
                ret++;
                firstCount = 0;
                otherCount = 0;
                if(i+1 < s.length()) {
                    first = s.charAt(i+1);
                }
            } else if(i == s.length() - 1) {
                ret++;
            }
        }
        return ret++;
    }
}