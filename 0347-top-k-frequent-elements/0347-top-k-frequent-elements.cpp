class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store in a map
        map<int, int > mp;
        for(auto u : nums){
           mp[u] ++;
        }

        // store in set to sort 
        set<pair<int, int>> st;
        for(auto u : nums){
            st.insert({mp[u], u});
        }

        // find answer 
        vector<int> ans;
        set<pair<int, int >>::reverse_iterator rit; 
        int i = 0;
         for (auto rit = st.rbegin(); rit != st.rend(); rit++){
            if(i == k) break;
            pair<int, int> u = *rit;
            ans.push_back(u.second);
            i ++;
        }

        return ans;
    }
};