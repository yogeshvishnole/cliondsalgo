#include<iostream>
#include<cstring>
using namespace std;

// function for length of string

int strLength(char str[]){

    int count = 0;

    for(int i = 0;str[i] !='\0';i++){
        count++;
    }

     return count;
}

int strCmp(char str1[],char str2[]){
    if(strlen(str1) != strlen(str2)) return 0;
    for(int i = 0;str1[i] != '\0' || str2[i] != '\0';i++){
        if((str1[i] - str2[i]) != 0) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

int strCpy(char str1[],char str2[]){

    for(int i = 0;i<=strlen(str2);i++){
        str1[i] = str2[i];
    }


}


// function for reversing a string

void strReverse(char str[]){

    int pointer1 = 0;
    int pointer2 = strLength(str)-1;

    while(pointer1<=pointer2){
        swap(str[pointer1],str[pointer2]);
        pointer1++;
        pointer2--;
    }


}

void printAllPrefixes(char str[]){
    for(int i = 0;i<=strlen(str);i++){
        for(int j=0;j<i;j++){
            cout<<str[j];
        }
        cout<<"\n";
    }

}

int main(){

    // c like strings
    // in c strings are array of characters terminated with a null symbol
    // characters are in single quote
    // strings are in double quotes

  /*  char name[10] = "yogesh";

    for(int i = 0;name[i]!='\0';i++){
        cout<<name[i];
    }

    cout<<endl;

    cout<<strLength(name)<<endl;*/

    // use of cin.getline

//     * Disadvantages of cout
//     *
//     * 1. cout not take input after spaces tabs and endline
//     * 2. cout will take any number of input
//     *
//     *

    // cin.geline(char_array,number_of_char_we_want,delimeter_for_ending)

  /* char address[100];
   cin.getline(address,20,'o');
   cout<<address;*/

    // check reversal of string

 /*   cout<<"Name before reverse : "<<name<<endl;
    strReverse(name);
    cout<<"Name after reverse : "<<name<<endl;*/

 // Now string inbuilt functions

 // we are going to learn 5
 // 1. strlen --> give length of string
 // 2. strcmp --> compare two strings
 // 3. strcpy --> copy 1 string to other
 // 4. strncpy --> copy n elements of one string to other
 // 5. strcat --> concatenate one string into another

  // Above all functions are in cstring header  file

//  char str[] = "yogesh";
//  cout<<strlen(str)<<endl;

// My implementation of strcmp see above
/*  char str1[100];
  char str2[100];

  cin>>str1>>str2;

  if(strCmp(str1,str2) == 0){
      cout<<"Equal\n";
  }else{
      cout<<"Not equal\n";
  }*/

// strcpy(dest_str,src_str)
// ex if a= "abc" b = "def" then after strcpy(a,b) a = "def" and b = "def"
// strcpy copy also the null character

/*char a[100]  = "abcd";
char b[100] = "def";

cout<<"Before Copying\n";
cout<<a<<"\n"<<b<<"\n";
strCpy(a,b);
cout<<"After Copying\n";
cout<<a<<"\n"<<b<<"\n";*/

// strncpy(dest_str,src_str,n_of_char_to_cpy)
// it will not copy null character

/*    char a[100]  = "abcd";
    char b[100] = "def";

    cout<<"Before Copying\n";
    cout<<a<<"\n"<<b<<"\n";
    strncpy(a,b,2);
    cout<<"After Copying\n";
    cout<<a<<"\n"<<b<<"\n";*/

// strcat(str1,str2) str1 = "abc" str2 = "def" strcat(str1,str2) str1 = "abcdef"

/*    char a[100]  = "abcd";
    char b[100] = "def";

    cout<<"Before Copying\n";
    cout<<a<<"\n"<<b<<"\n";
    strcat(a,b);
    cout<<"After Copying\n";
    cout<<a<<"\n"<<b<<"\n";*/


// Print all prefixes

// str1 = "abcd"
//then print "a" "ab" "abc" "abcd"

char str1[] = "abcd";
printAllPrefixes(str1);

}


