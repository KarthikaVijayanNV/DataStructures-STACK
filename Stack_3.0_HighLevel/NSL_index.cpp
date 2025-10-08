#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void NSLindex(int arr[] , int n)
{
    vector<int> V;
    stack<int> st;

    for(int i=0; i<n ;i++)
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
            while(!st.empty() && arr[st.top()] >= arr[i]) //arr
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
        st.push(i); // i is the index
    }

    for(auto &i : V)
    {
        cout<<i<<" ";
    }
}




int main()
{
    int arr[] = {4,5,2,10,8};
    NSLindex(arr,5); // -1 0 -1 2 2
}