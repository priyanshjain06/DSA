// REVIEW question summary :

// You are given a list of words and a maxWidth. You must format the text so that:

// Each line has exactly maxWidth characters.

// Words are fully justified (evenly spaced).

// The last line should be left-justified.

// If spaces can’t be evenly divided, put extra spaces on the left.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n)
        {
            int j = i + 1;
            int lineLength = words[i].size();

            // Group as many words as possible into the current line
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth)
            {
                lineLength += words[j].size();
                j++;
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;
            string line;

            // Case 1: Last line OR only one word
            if (j == n || numWords == 1)
            {
                for (int k = i; k < j; ++k)
                {
                    line += words[k];
                    if (k < j - 1)
                        line += " ";
                }
                // Fill the remaining space with trailing spaces
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                // Case 2: Fully justified line //REVIEW
                int spaceBetween = numSpaces / (numWords - 1);
                int extra = numSpaces % (numWords - 1);

                for (int k = i; k < j; ++k)
                {
                    line += words[k];
                    if (k < j - 1)
                    {
                        int spaces = spaceBetween + (extra-- > 0 ? 1 : 0);
                        // REVIEW -
                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // REVIEW
        }

        return result;
    }
};
