#include <iostream>
using namespace std;

int valueGiver(char romanLetter){

    switch(romanLetter){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }

}

int romanToDecimal(string &str) {

    int num = 0;

    num += valueGiver(str[str.size() - 1]);

    if(str.size() == 1){
        return num;
    }

    for(int i = str.size()-2;i>=0;i++){

        if(valueGiver(str[i]) < valueGiver(str[i+1])){
            num -= valueGiver(str[i]);
        }else{
            num +=  valueGiver(str[i]);
        }

    }

    return num;


}

int main()
{

    string str = "2345";
    swap(str[0],str[3]);
    cout<<str;

    return 0;
}