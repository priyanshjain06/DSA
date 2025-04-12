// EXample : priya jain => priya@40jain
// NOTE replace with @40

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
      string modify(string& s) {
          string result = "";
          for (char ch : s) {
              if (ch != ' ') {
                  result.push_back(ch);
              }
          }
          return result;
      }
  };