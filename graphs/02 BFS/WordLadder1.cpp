#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
         if (start == end) return 1;

        queue<pair<string, int>>q;
        q.push({start,1});
        dict.erase(start);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == end) return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];

                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(word == end) return steps+1; // if the word is not in dict 

                    if(dict.find(word) != dict.end()){
                        dict.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};