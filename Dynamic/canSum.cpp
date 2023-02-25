#include<bits/stdc++.h>
using namespace std;

bool canSum(int target, vector<int> arr) {
    if (target == 0) return true;
    if (target < 0) return false; 
    for (auto ele: arr) {
        if (canSum(target - ele, arr)) {
            return true;
        }
    }

    return false;
}


int main() {
    cout << (canSum(7, {2,3,4,7}) ? "True": "False") << endl;
    cout << (canSum(100, {1,2,3}) ? "True": "False") << endl;
    cout << (canSum(10000, {1, 2}) ? "True": "False") << endl;
}