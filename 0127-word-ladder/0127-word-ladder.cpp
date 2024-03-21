class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        queue<string> q;
        q.push(beginWord);

        // checking is the end word actully exited
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        // storing beginning and ending
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;

        // running bfs
        while(!head.empty() && !tail.empty()){

            if(head.size() < tail.size()){
                phead = &head; // set 1 is the forward set 
                ptail = &tail; // set 2 is the target node for set1 to search
            }

            else{
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> temp;
            for(auto it = phead -> begin() ; it != phead -> end(); it ++){
                string word = *it;

                // trying different combination 
                for(int i = 0; i < word.size(); i ++){
                    char c = word[i];

                    for(int j = 0 ; j < 26; j ++){
                        word[i] = 'a' + j;

                        if(ptail -> find(word) != ptail -> end()){
                            return ladder;
                        }

                        if(dict.find(word) != dict.end()){
                            temp.insert(word);
                            dict.erase(word);
                        }    
                        
                    }
                    word[i] = c;
                }
            }

            ladder++;
            phead -> swap(temp);
        }
        return 0;
    }
};