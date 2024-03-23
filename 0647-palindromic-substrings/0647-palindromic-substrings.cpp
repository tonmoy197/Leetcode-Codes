class Solution {
public:
    vector<string> ans;

    void expand(string &s, int left, int right){
        while(left >= 0 && right < s.size()){
            if(s[left] != s[right]) break;
            string ss = s.substr(left, right - left + 1);
            ans.push_back(ss);
            left --;
            right ++;
        }
    }
    int countSubstrings(string s) {
        for(int i = 0 ; i < s.size(); i ++){
            expand(s, i, i );
            expand(s, i , i + 1);
        }
        return ans.size();
        
    }
};