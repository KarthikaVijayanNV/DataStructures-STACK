#include<iostream>  //Nearest smaller to right // or next smaller element
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

void NearestSmallerToRight(int arr[], int n)
{
    vector<int> V;
    stack<int> st;

    for(int i=n-1; i>=0; i--)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty() && st.top() < arr[i])
        {
            V.push_back(st.top());
        }
        else if(!st.empty() && st.top() >= arr[i])
        {
            while (!st.empty() && st.top() >= arr[i])
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

        st.push(arr[i]);
    }

    reverse(V.begin() ,V.end());   // u should reverse it..

    for(auto i: V)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}



int main()
{

  int arr[] = {1,3,2,4};
  NearestSmallerToRight(arr, 4);


    return 0;
}
