#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
        // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q; // REVIEW string types

        // BFS traversal with pushing values in queue
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1}); // REVIEW -

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end()); // FIXME
        st.erase(startWord);                                        // REVIEW -
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.

                char original = word[i]; // REVIEW word[i]
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word); // REVIEW
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // REVIEW
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};
