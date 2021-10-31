/*Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> path;
        dfs(s, dict, path, res);
        return res;
    }
    
    void dfs(string s, unordered_set<string>& dict, vector<string>& path, vector<string>& res) {
        if (s.empty()) {
            string tmp;
            for (auto& w : path) {
                tmp += w + " ";
            }
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                path.push_back(word);
                dfs(s.substr(i), dict, path, res);
                path.pop_back();
            }
        }
    }
};