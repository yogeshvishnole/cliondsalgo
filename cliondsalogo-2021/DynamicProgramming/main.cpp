#include <iostream>
#include<cstring>
#include "minSteps.h"

int main() {
    int arr[500+1];
    memset(arr,-1,sizeof arr);
    cout<<minStepsEfficient(11,arr)<<endl;
    cout<<minStepsExpensive(11)<<endl;
    cout<<minStepsBottomUp(11)<<endl;
    return 0;
}
