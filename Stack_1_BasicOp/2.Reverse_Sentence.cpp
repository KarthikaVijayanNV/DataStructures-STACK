#include<iostream>
#include<stack>     //using STL
using namespace std;

void ReverseSentence(string s)
{
    stack <string> st;

    for(int i=0; i<s.length(); i++)
    {
        string word ="";

        while(s[i] != ' '  &&  i<s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }
  

    while( !st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl; 
}

// Reversing a word   
/*
void Reverse(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
       st.push(s[i]);
    }

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
*/

int main()
{
    string s ="Hey, how are you doing?";
    
    ReverseSentence(s);


    /*   if u want to read an entire sentense from user without any miss
    string s;
    getline(cin, s);
    Reverse(s);

   */

    return 0;
}