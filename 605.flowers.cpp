#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool found = false;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            found = false;
            if (flowerbed[i] == 0)
            {
                bool left = (i == 0 || flowerbed[i-1] == 0) ? 0 : 1;
                bool right = ((flowerbed.size() - 1 == i) || flowerbed[i+1] == 0) ? 0 : 1;

                if (!left && ! right)
                {
                    found = true;
                    n--;
                }
            }

            if (found)
                i = i+1;
        }
        return  (n == 0) ? true : false;
    }
};

int main() {
    Solution s;
    // vector <int> v1{1,0,0,0,1};

    // std::cout << endl << s.canPlaceFlowers(v1, 1);

    // std::cout << endl << s.canPlaceFlowers(v1, 2);

    // vector <int> v2{1,0,0,0,0,1};
    // std::cout << endl << s.canPlaceFlowers(v2, 2);

    // vector <int> v3{1,0,0,0,0,0,1};
    // std::cout << endl << s.canPlaceFlowers(v3, 2);
    vector <int> v4{1,0,0,0,1,0,0};
    std::cout << endl << s.canPlaceFlowers(v4, 2);
    
    return 0;
}