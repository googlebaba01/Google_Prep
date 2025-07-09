#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        vector<vector<string>> ans;  // Final answer: list of all shortest transformation sequences
        unordered_map<string, vector<string>> parents;  // Stores parents of each word (used to backtrack later)
        unordered_map<string, int> level;  // Stores the level (distance from start) of each word
        queue<string> q;

        dict.insert(end); // Ensure 'end' is in the dictionary

        level[start] = 0;  // Level of start word is 0
        q.push(start);     // Begin BFS from the start word

        // BFS to build level and parent map
        while (!q.empty()) {
            string word = q.front(); q.pop();
            int curLevel = level[word];  // Current word's level

            // Try changing every character in the word
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    newWord[i] = c;

                    // If transformed word is not in dictionary, skip
                    if (dict.find(newWord) == dict.end()) continue;

                    // First time visiting newWord
                    if (!level.count(newWord)) {
                        level[newWord] = curLevel + 1;     // Set level
                        q.push(newWord);                   // Add to queue
                        parents[newWord].push_back(word);  // Set parent
                    }
                    // Already visited at same level (another shortest path)
                    else if (level[newWord] == curLevel + 1) {
                        parents[newWord].push_back(word);  // Add another parent
                    }
                }
            }
        }

        // If we never reached 'end', return empty answer
        if (!parents.count(end)) return {};

        // DFS to build paths from end to start using parent links
        vector<string> path = {end};  // Start backtracking from the end word
        dfs(end, start, parents, path, ans);
        return ans;
    }

    // Recursive function to build paths using parents map
    void dfs(string word, string &start,
             unordered_map<string, vector<string>> &parents,
             vector<string> &path,
             vector<vector<string>> &ans) {

        if (word == start) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());  // Reverse because we built path from end to start
            ans.push_back(temp);
            return;
        }

        // Recurse on each parent
        for (const string &p : parents[word]) {
            path.push_back(p);
            dfs(p, start, parents, path, ans);
            path.pop_back();  // Backtrack
        }
    }
};
