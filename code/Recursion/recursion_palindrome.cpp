#include<iostream>

using namespace std;

bool palindrome(string str, int n){
    if (n==0 || n==1)
        return true;
    if (str[0] == str[n-1])
        return palindrome(&str[1], n-2);
    else
        return false;
}

int main(){
    cout << palindrome("abcba", 5) << endl;
}