// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> i;

        while (n != 0)
        {
            n = n%10;
        }
    }
};

int main ()
{
    Solution obj;
    obj.countBits(55);

    return 0;
}