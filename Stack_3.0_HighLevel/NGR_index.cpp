#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


void NGRIndex(int arr[] , int n)
{
    stack<int> st;
    vector<int> V;

    for(int i=n-1; i>=0; i--)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }

        else if(!st.empty() && arr[st.top()] > arr[i]) // arr only difference
        {
            V.push_back(st.top());
        }
        
        else if(!st.empty() && arr[st.top()] <= arr[i]) // arr the difference
        {
            while(!st.empty() && arr[st.top()] <= arr[i]) // arr  .....
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

        st.push(i); // instead of arr[i] ..pushing the index i
    }

    reverse(V.begin() ,V.end());

    for(auto &i : V)
    {
        cout<<i<<" ";
    }
}




int main()
{
    int arr[] = {1,3,0,0,1,2,4}; // 1 6 4 4 5 6 -1

    NGRIndex(arr,7);

    return 0;
}