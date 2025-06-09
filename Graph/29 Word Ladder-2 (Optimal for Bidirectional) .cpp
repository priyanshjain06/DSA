#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(targetWord) == dict.end())
            return {}; // No transformation possible

        queue<vector<string>> q;
        q.push({startWord});
        dict.erase(startWord);

        bool found = false;
        unordered_set<string> wordsUsedInLevel;

        while (!q.empty())
        {
            int qSize = q.size();
            wordsUsedInLevel.clear();

            for (int i = 0; i < qSize; i++)
            {
                vector<string> path = q.front();
                string word = path.back(); //REVIEW - 
                q.pop();

                if (word == targetWord)
                {
                    ans.push_back(path);
                    found = true;
                }

                for (int j = 0; j < word.size(); j++)
                {
                    char original = word[j];

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;

                        if (dict.find(word) != dict.end())
                        {
                            path.push_back(word);
                            q.push(path);
                            wordsUsedInLevel.insert(word);
                            path.pop_back();
                        }
                    }

                    word[j] = original;
                }
            }

            if (found)
                break; // Stop BFS once we find the shortest transformation sequences

            for (auto &word : wordsUsedInLevel)
                dict.erase(word);
        }
        return ans;
    }
};
