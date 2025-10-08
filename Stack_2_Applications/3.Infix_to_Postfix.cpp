#include<iostream>
#include<stack>
using namespace std;

int Precd(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*'  || c == '/')
    {
        return 2;
    }
    else if(c == '+'  || c == '-')
    {
        return 1;
    }
    else    // when it encouters  "("
    {
        return -1;
    }
}

string InfixtoPostfix(string s)
{
    stack<char> st;
    string result;  

    for(int i=0; i<s.length(); i++)
    {
        if(( s[i] >= 'a' && s[i] <= 'z' )  || ( s[i]>= 'A' && s[i] <= 'Z'))   // for operand
        {
            result+=s[i];
        }  
 
        else if(s[i] == '(')        // for "("
        {
            st.push(s[i]);
        }

        else if(s[i] == ')')       // for ")"
        {
            while(!st.empty() && st.top() != '(')
            {
                result+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop(); //poping the "("
            }
        }

        else // for operators
        {
            while(!st.empty() &&  Precd(st.top()) >  Precd(s[i]))
            {
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }

    return result;
}





int main()
{
  cout<<InfixtoPostfix("(a-b/c)*(a/k-l)"); // abc/-ak/l-*
  
  //(a*b)+c check out this one also
    return 0;
}