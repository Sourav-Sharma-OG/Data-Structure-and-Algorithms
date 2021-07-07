/*
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc. 
Example: 
 

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.
*/

/*
Algorithm:
We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that previous minimum element can be retrieved using current minEle and its value stored in stack. Below are detailed steps and explanation of working.

Push(x) : Inserts x at the top of stack. 
 
--> If stack is empty, insert x into the stack and make minEle equal to x.
--> If stack is not empty, compare x with minEle. Two cases arise:
    --> If x is greater than or equal to minEle, simply insert x.
    --> If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous  minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.

Pop() : Removes an element from top of stack. 
 

==> Remove element from top. Let the removed element be y. Two cases arise:
    --> If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
    --> If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.

*/

#include <bits/stdc++.h>
using namespace std;

class Special_stack
{
public:
    stack<int> st;
    int minEle;

    void specialPush(int x)
    {
        if (st.empty())
        {   
            minEle = x;
            st.push(x);
            cout<<"Top element is: "<<st.top()<<endl;
            return;
        }

        if (x >= minEle)
        {
            st.push(x);
            cout<<"Top element is: "<<st.top()<<endl;
        }
        else
        {
            minEle = x;
            st.push((x * 2 )- minEle);
            cout<<"Top element is: "<<st.top()<<endl;
            
        }
    }

    void specialPop()
    {
        if (st.empty())
        {
            cout << "Stack is empty.";
            return;
        }

        if (st.top() >= minEle)
        {
            st.pop();
            cout<<"Top element is: "<<st.top()<<endl;
        }
        else
        {
            minEle = (minEle * 2) - st.top();
            st.pop();
            cout<<"Top element is: "<<st.top()<<endl;
        }
    }

    int getMin()
    {
        return minEle;
    }
};

int main()
{
    Special_stack st;
    cout<<"Minimum while pushing : "<<endl;
    st.specialPush(18);
    cout<<st.getMin()<<endl;
    st.specialPush(19);
    cout<<st.getMin()<<endl;
    st.specialPush(29);
    cout<<st.getMin()<<endl;
    st.specialPush(15);
    cout<<st.getMin()<<endl;
    st.specialPush(16);
    cout<<st.getMin()<<endl;

    cout<<"\nMinimum while popping: "<<endl;
    st.specialPop();
    cout<<st.getMin()<<endl;
    st.specialPop();
    cout<<st.getMin()<<endl;
    st.specialPop();
    cout<<st.getMin()<<endl;
    st.specialPop();
    cout<<st.getMin()<<endl;
    st.specialPop();
    cout<<st.getMin()<<endl;
}