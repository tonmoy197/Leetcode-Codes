class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int ss = s.size(), ts = t.size();

        if(ts < ss) return false;
        if(t == s) return true;
        return false;
    }
};