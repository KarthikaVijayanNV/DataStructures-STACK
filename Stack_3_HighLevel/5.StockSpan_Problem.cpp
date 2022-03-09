#include<iostream>    // stock span problem - It's a variation of NGL
#include<stack>
#include<vector>
using namespace std;

void StockSpan(int arr[], int n)
{
  vector<int> V;
  stack <pair<int,int>> st;

   for(int i=0; i<n; i++)
   {
       if(st.empty())
       {
           V.push_back(-1);
       }
       else if(!st.empty()  && st.top().first > arr[i])
       {
           V.push_back(st.top().second);
       }
       else if(!st.empty() && st.top().first <= arr[i])
       {
           while(!st.empty() && st.top().first <= arr[i])
           {
               st.pop();
           }
           if(st.empty())
           {
               V.push_back(-1);
           }
           else
           {
               V.push_back(st.top().second);
           }
       }

       st.push({arr[i], i});  // in stack pushing both element and it's index
   }

   // alter the vector for giving the output
    for(int i=0; i<n; i++)
    {
        V[i]= i-V[i];
    }

    //output
    for(auto i : V)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}



int main()
{

    int arr[] ={100,80,60,70,60,75,85};
    StockSpan(arr,7);  //soooooper u are getting the correct answere


    return 0;
}