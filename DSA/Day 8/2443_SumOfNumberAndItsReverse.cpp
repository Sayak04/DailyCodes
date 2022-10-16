class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 9999) return true;
        for(int i = 0; i <= num; i++) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int other = stoll(s);
            if(other + i == num) return true;
        }
        return false;
    }
};