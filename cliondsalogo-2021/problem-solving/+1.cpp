#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> increment(vector<int> arr ,int N) {
        vector<int> result;
        int i = N-1;
        int carry = 1;

        while(carry && i>=0){
            int sum = arr[i] + carry;
            int num = sum == 10 ? 0:sum;
            int carry = sum == 10 ? 1:0;
            result.push_back(num);
            i--;
        }

        if(carry) result.push_back(1);

        if(i>=0){
            for(int j = i;j>=0;j--){
                result.push_back(arr[j]);
            }
        }

        reverse(result.begin(),result.end());

        return result;
    }
};

int main(){

    vector<int> arr{1,2,4};
    Solution s;
    vector<int> result = s.increment(arr,arr.size());

    for(int r:result){
        cout<<r<<" ";
    }



}
