// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> count;
        for (int i : arr) {
            std::map<int, int>::iterator it = count.find(i);
            if (it == count.end())
            {   // not found
                count[i] = 1;
            }
            else
            {   // found
                it->second++;
            }
        }

        bool ret = true;
        for (auto it = count.begin(); it != count.end(); it++ )
        {
            for (auto it2 = next(it); it2 != count.end(); it2++ )
            {
                if (it->second == it2->second)
                {
                    ret = false;
                    break;
                }
            }
        }

        // std::map<int, int>::iterator it;
        // for (it = count.begin(); it != count.end(); it++ )
        // {
        //     cout << endl << it->first << "\t" << (*it).second;
        // }
        return ret;
    }
};

int main() {
    Solution obj;

    vector <int> arr = {1,2,2,1,3};

    bool found = obj.uniqueOccurrences(arr);
    cout << "\n Found = " << found;

    return 0;
}