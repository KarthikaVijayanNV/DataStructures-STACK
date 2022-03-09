#include<iostream>  // Nearest greater to left /// 
#include<vector>
#include<algorithm> 
#include<stack>
using namespace std;

void NearestGreaterToRight(int arr[] , int n)
{
    vector<int> V;
    stack<int> st;

    for(int i = 0; i<n; i++)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty()  && st.top()> arr[i])
        {
            V.push_back(st.top());
        }
        else if(!st.empty() && st.top() <= arr[i])
        {
            while(!st.empty() && st.top() <= arr[i])
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

    // you don't need to reverse the vector here    

     //o/p
    for(auto i : V)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}



int main()
{
   int arr[] = {10,5,11,6,20,12};
   NearestGreaterToRight(arr,6);  //o/p = 


    return 0;
}