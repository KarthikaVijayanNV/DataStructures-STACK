#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void NSRindex(int arr[] , int n)
{
    stack<int> st;
    vector<int> V;

    for(int i=n-1; i>=0; i--)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty() && arr[st.top()] < arr[i]) // arr 
        {
            V.push_back(st.top());
        }
        else if(!st.empty() && arr[st.top()] >= arr[i]) // arr
        {
            while(!st.empty() && arr[st.top()] >= arr[i])// arr
            {
                st.pop();
            }
            if(st.empty())
            {
                V.push_back(-1);
            }
            else
            {
                V.push_back(st.top());
            }
        }

        st.push(i); // index i ...into stack
    }

    reverse(V.begin() , V.end());
    
    for(auto &i : V)
    {
        cout<<i<<" ";
    }
}



int main()
{
    int arr[] = {4,5,2,10,8};
    NSRindex(arr,5); // 2 2 -1 4 -1

    return 0;
}