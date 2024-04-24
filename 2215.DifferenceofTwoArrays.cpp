#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v;
        vector<int> v1;
        vector<int> v2;

        for(int i : nums1)
        {    bool found = false;
            for (int j : nums2)
            {   
                if (i == j)
                {
                    found = true;
                    break;
                }
            }
            if (!found && std::find(v1.begin(), v1.end(), i) == v1.end()) v1.push_back(i);
        }

        for(int i : nums2)
        {    bool found = false;
            for (int j : nums1)
             {
                   if (i == j)
                {
                        found = true;
                        break;
                }
             }
            if (!found&& std::find(v2.begin(), v2.end(), i) == v2.end()) v2.push_back(i);
        }
        v.push_back(v1);
        v.push_back(v2);
        return v;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1,2,3,3};
    vector<int> v2 = {1,1,2,2};
    vector<vector<int>> v = s.findDifference(v1, v2);

    for(int i : v[0])
        cout << "\t" << i;
    
    cout << endl;

    for(int i : v[1])
        cout << "\t" << i;
    return 0;
}