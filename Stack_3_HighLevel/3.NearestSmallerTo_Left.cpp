#include<iostream> //Nearest smaller to left....OR   Nearest greater element
#include<stack>
#include<vector>
using namespace std;

void NearestSmallerToLeft(int arr[], int n)
{
    vector<int> V;
    stack<int> st;

    for(int i=0; i<n; i++)  // left to right traversal
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty()  && st.top() < arr[i])
        {
            V.push_back(st.top());
        }
        else if(!st.empty() && st.top() >= arr[i])
        {
           while(!st.empty()  && st.top() >= arr[i])
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

  // No need to reverse it..
    for(auto i : V)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}


int main()
{

  int arr[]= {3,2,10,11,5,10,6,3};
  NearestSmallerToLeft(arr,8);


    return 0;
}
