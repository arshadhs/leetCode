#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int largest = 0;
        for (int i = 0; i < candies.size(); i++)
            if (largest < candies[i]) largest = candies[i];

        vector <bool> extra;

        for (int i = 0; i < candies.size(); i++)
            if (candies[i] + extraCandies >= largest)
                extra.push_back(true);
            else
                extra.push_back(false);
        
        return extra;
    }
};

int main() {
    Solution s;
    vector <int> v1{2,3,5,1,3};

    vector <bool> vRslt1 = s.kidsWithCandies(v1, 3);
    for (int i = 0; i < vRslt1.size(); i++)
        cout << "\t" << vRslt1[i];
    return 0;
}