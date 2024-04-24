#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int>::iterator itnum1;
        itnum1 = nums1.begin();
        std::vector<int>::iterator itnum2;
        std::vector<int> num3;

        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m-n; j++)
            {
                cout << endl << "nums1[i]" << nums1[j];
                cout << "\tnums2[i]" << nums2[i];

                if (nums1[j] > nums2[i])
                {   cout << "\tInsert nums2[i]" << nums2[i];
                   // nums1.insert(itnum1 + i, nums2[i]);
                   num3.push_back(nums2[i]);
                }
                else
                {
                    num3.push_back(nums1[j]);
                }
            }
        }
        cout << endl;
        cout << endl;
        for (int x : num3)
            cout << x << " ";
        cout << endl;
    }
    
};

int main()
{
    vector<int> nums1{1,2,3,0,0,0};
    for (int x : nums1)
        cout << x << " ";

    cout << endl;

    vector<int>nums2{2,5,6};
    for (int x : nums2)
        cout << x << " ";
    cout << endl;
    int m = nums1.capacity() + nums2.capacity();
    int n = nums2.capacity();

    cout << "m = " << m;
    cout << "\tn = " << n;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";

    return 0;
}