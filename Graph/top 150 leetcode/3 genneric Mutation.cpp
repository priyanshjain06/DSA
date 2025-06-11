#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {

        // REVIEW similar to word ladder !

        unordered_set<string> valid(bank.begin(),
                                    bank.end()); // REVIEW declare a set
        if (!valid.count(endGene))
            return -1;

        queue<pair<string, int>> q; // pair: gene string, number of mutations
        unordered_set<string> visited;


        q.push({startGene, 0});
        visited.insert(startGene);

        string genes = "ACGT";

        while (!q.empty())
        {
            auto [current, steps] = q.front();
            q.pop();

            if (current == endGene)
                return steps;

            for (int i = 0; i < current.size(); ++i)
            {
                char original = current[i];
                for (char ch : genes)
                {
                    if (ch == original)
                        continue; // REVIEW

                    current[i] = ch;
                    if (valid.count(current) && !visited.count(current))
                    {
                        visited.insert(current);
                        q.push({current, steps + 1});
                    }
                }
                current[i] = original; // restore original gene
            }
        }

        return -1; // if endGene is not reachable
    }
};
