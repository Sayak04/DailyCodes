class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> arr;
        string temp = "";
        // we split the string and put all into one array
        for(int i = 0; i < sentence.length(); i++) {
            if(sentence[i] == ' ') {
                arr.push_back(temp);
                temp = "";
            } else
                temp += sentence[i];
        }
        if(temp.size() > 0) arr.push_back(temp);
        
        // we loop over the array and check for $(num) and then apply discount to it
        for(int i = 0; i < arr.size(); i++) {
            string help = arr[i];
            bool found = false;
            string num = "";
            for(int j = 0; j < help.size(); j++) {
                if(j == 0 && help[j] == '$') found = true;
                else if(found == true) {
                    if(help[j] >= '0' && help[j] <= '9') num += help[j];
                    else {
                        found = false;
                        break;
                    }
                }
            } 
            if(found && num.size() > 0) {
                long long number = stoll(num);
                long double discountPrice = (number * discount) / 100.0;
                long double finalNum = number - discountPrice;
                arr[i] = "$";
                arr[i] += to_string(finalNum);
                int pres = 4;
                while(pres--)
                    arr[i].pop_back();
            }
        }
        
        // at last we put the sliced array back into the string
        string ans = "";
        for(auto it: arr) {
            ans += it + " ";
        }
        
        // remove the last trailing space.
        ans.pop_back();
        return ans;
    }
};