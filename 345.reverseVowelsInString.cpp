#include<iostream>
using namespace std;

    
class Solution {
public:
    string reverseVowels(string s) {
        int j = s.length() - 1;
        for (int i = 0; i < j; i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            {
 //               cout << endl << i << "\t" << s[i];
                for (; j >= s.length()/2 - 1; j--) {
 //                   cout << endl << j << "\t" << s[j];
                    if (s[j] == 'a' || s[j] == 'A' || s[j] == 'e' || s[j] == 'E' || s[j] == 'i' || s[j] == 'I' || s[j] == 'o' || s[j] == 'O' || s[j] == 'u' || s[j] == 'U')
                    {
                        cout << endl << "swap\t" <<  s[i] << "\t" << s[j];
                        swap(s[i], s[j]);
                        j--;
                        break;
                    }
                }
            }
        }
        cout << endl;
        return s;
    }
};

int main ()
{
    Solution s;
    cout << endl << endl <<s.reverseVowels("Marge, let's \"went.\" I await news telegram.");
    return 0;
}