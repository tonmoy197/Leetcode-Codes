class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        // checking is the end word actully exited
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        int ladder = 1;
        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i ++){
                string word = q.front();
                q.pop();

                // checking if it reached the endWord
                if(word == endWord){
                    return ladder;
                }

                // checking every combination by changing one character 
                for(int j = 0; j < word.size(); j ++){
                    char c = word[j];
                    for(int k = 0; k < 26; k ++){
                        word[j] = 'a' + k;
                        if(dict.find(word) != dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }

            ladder++;
        }
        return 0;
    }
};