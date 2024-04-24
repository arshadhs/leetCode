#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    void moveZeroes(vector<int>& nums) 
    {
        int index = 0;
        int index_2 = 0;
        int end = nums.size();

        while(index < end && index_2 < end) {
            if (nums[index] != 0) index++;
            if (nums[index_2] == 0) index_2++;

            cout << endl << "num[" << index << "]=" << nums[index];
            cout << "\t" << "num[" << index_2 << "]=" << nums[index_2];

            if (index < end && index_2 < end && index < index_2) myswap(nums[index], nums [index_2]);
            index_2++;
        }

        cout << endl;
        for(int i : nums) {
           cout << "\t" << i;
        }
    }

    void moveZeroesFast(vector<int>& nums) 
    {
        vector<int> temp;
        for(int i : nums)
           if(i != 0) temp.push_back(i);
        
        for(int i = 0; i <= temp.size()-1; i++)
           nums[i]=temp[i];
        
        for(int i = nums.size() - temp.size()+1; i < nums.size(); i++)
           nums[i]=0;
    }

    void moveZeroesSwap(vector<int>& nums) {
        int index = 0;
        int end = nums.size() - 1;

        while(index < end) {
            if (nums[index] == 0) {
                  while(index < end) {
                        if (nums[end] != 0) {
                            myswap(nums[index], nums [end]);
                            break;
                        }
                        else {
                            end--;
                        }
                    }
            }
            index++;
        }

        for(int i : nums) {
           cout << "\t" << i;
        }
    }

    void myswap(int &i , int &j) {
        int temp = i;
        i = j;
        j = temp;
    }
};

int main()
{
    vector<int> v{0,1,0,3,12};
    Solution s;
    s.moveZeroesFast(v);
    cout << endl;
    for(int i : v) {
        cout << "\t" << i;
    }
    return 0;
}