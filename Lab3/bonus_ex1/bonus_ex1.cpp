#include <iostream>
#include <cstring>
using namespace std;

#include "MyStack.h"

// Given an expression check if it's a palindrome or not using Stack.
// Ex: “a santa at nasa” and  “a nut  for a jar of tuna” are palindromes.
string prepareString(string str)
{
    string strAux = "";
    for(int i = 0; i < str.length(); i++){
        if (isalpha(str[i]))
            strAux += tolower(str[i]);
    }
    return strAux;
}

bool isPalindrome(string text) {
    Stack<char> palindrome;
    text = prepareString(text);
    for(int i=0; i<text.length(); i++){
        palindrome.push(text[i]);
    }
    for(int i=0; i<text.length(); i++){
        if(text[i] != palindrome.pop()) {
            return false;
        }
    }
    return true;
}

int main(){
	string s ="Taco Cat";
	if(isPalindrome(s)) {
        cout << "\"" << s << "\"" << " is a palindrome";
	} else {
        cout << "\"" << s << "\"" << " is not a palindrome";
	}
}
