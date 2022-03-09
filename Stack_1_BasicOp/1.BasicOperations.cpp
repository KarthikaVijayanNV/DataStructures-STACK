#include<iostream>  // push(), pop()  ,Top()  ,empty()
using namespace std;

#define n 100

class stack
{
    int* arr;  // these members are private
    int top;

   public:
    stack ()
    {
        arr = new int[n];
        top =-1;
    }


    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"stack is full- Overflow"<<endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"No element to pop- underflow"<<endl;
            return ;
        }
        
        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"No element in the stack"<<endl;
            return -1;
        }

        return arr[top];      
    }


    bool empty()
    {
        return top == -1;
    }
};






int main()
{
   stack st;
   st.push(1);
   st.push(2);
   st.push(3);  // 1,2,3,  pushed
   cout<<st.Top()<<endl;  // 3

   st.pop();  // now 3 is poped
   cout<<st.Top()<<endl;  // 2

   st.pop();  // 2 is poped
   st.pop();  // 1 is poped
   st.pop();  // get the msg

   cout<<st.empty()<<endl;  // true it is empty



    return 0;
}