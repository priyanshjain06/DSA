

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