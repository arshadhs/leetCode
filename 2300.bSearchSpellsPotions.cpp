// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());

        vector<int> result;
        for (int spell : spells) {
            int found = FindASpell(spell, potions, success);
 //           cout << "\nSpell = " << spell << "\t" << found;
            int temp = (found == -1) ? 0 : potions.size() - found;
            result.push_back(temp);
        }
        return result;
    }
        
    int FindASpell(int spell, vector<int>& potions, int success) {
        int l = 0, h = potions.size();

        while ( l <= h) {
            int mid = l + ((h - l)/2);
            if ((spell * potions.at(mid))  == success) {
                return mid;
            }

            if ((mid-1 >= 0) && ((spell * potions.at(mid-1))  < success) && ((spell * potions.at(mid))  >= success)) {
                return mid;
            }

            if ((mid+1 < potions.size()) && ((spell * potions.at(mid))  < success) && ((spell * potions.at(mid+1))  >= success)) {
                return mid+1;
            }

            if ((spell * potions.at(mid))  < success) {
                l = mid+1;
            }

            if ((spell * potions.at(mid))  > success) {
                h = mid-1;
            }
        }

        return -1;
    }   
};

int main()
{
    vector<int> spells{15,8,19};
    vector<int> potions{38,36,23};
    /// 24, 15, 24
    /// 8. 5. 8
    /// 16, 10, 16
    // 345 540 570

    Solution obj;
    vector<int> result = obj.successfulPairs(spells, potions, 328);

    for (auto v : result)
        cout << "\t" << v;
    return 0;
}