#include<iostream>
using namespace std;

bool isPalindrome(char str[],int n){
    int p1 = 0;
    int p2 = n-1;
    while(str[p1] <= str[p2]){

        if(str[p1] != str[p2]){
            return false;
        }

    }

    return true;

}

bool isPalindrome(string str){
    int p1 = 0;
    int p2 = str.size();
    while(str[p1] <= str[p2]){

        if(str[p1] != str[p2]){
            return false;
        }
        p1++;
        p2--;
    }

    return true;

}

int main(int argc,char **argv){

    char str1[100] = "GeeksForGeeks";
    string str2 = "ABCDCBA";

    isPalindrome(str1,13) ? cout<<"Yes str1 is palindrome\n" : cout<<"Not str1 is not\n";
    isPalindrome(str2) ? cout<<"Yes str2 is palindrome\n" : cout<<"Not str2 is not\n";


}
