#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string reverseWords(string str) {
       int start = 0;
      int end = 0;
      vector <string> v;

      for (int i = 0; i <= str.length(); i++) {
         if (str[i] == ' ' || str[i] == '\0')
         {
            while (str[i] == ' ') { i++; }
            end = i - start;
            v.push_back(str.substr(start, end));
            start = i; 
         }
      }

      string newStr;
      for (auto it = v.rbegin(); it != v.rend(); ++it)
      {
         newStr += *it;
         if (it != v.rend() - 1)
         {
            newStr += ' ';
         }
      }
//      newStr += '\0';
      return newStr;
    }
};

int main ()
{
    Solution s;
    cout << endl << endl <<s.reverseWords("  hello world  ");
    return 0;
}