// https://leetcode.com/problems/reverse-words-in-a-string/
//
// Input : "the sky is blue"
// Output : "blue is sky the"
//
//

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string str) { 
    if (str.length() == 0)
        return "";
    string word = ""; 
    stack<string> mystack;

    for (auto x : str) 
    { 
        if (x == ' ') 
        { 
            //cout << word;
            if (word != "")
                mystack.push(word);
            word = ""; 
        } 
        else
        { 
            word = word + x; 
        } 
    } 
    //cout << word; 
    if (word != "")
        mystack.push(word);

    if (mystack.empty())
        return "";
    string temp = mystack.top();
    mystack.pop();
    string result = temp;
    while(!mystack.empty())
    {
        //cout << mystack.top() << endl;
        temp = mystack.top();
        result = result + " " + temp;
        mystack.pop();
    }
    return result;
} 

int main() 
{
    string input = "  the sky is blue";
    cout << "Input is : " << input << endl;
    cout << "Output is : " << reverseWords(input) << endl;

    return 0;
}

