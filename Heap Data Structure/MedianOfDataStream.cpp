#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int val)
{

    //If size of both the heaps is same then we always push the element into the maxHeap.
    if (maxHeap.size() == minHeap.size())
    {

        /**
         * Case 1. If both heaps are empty.
         *       --> Insert the element into the maxHeap.
         */

        if (maxHeap.size() == 0)
        {
            maxHeap.push(val);
        }

        /**
         * Case 2. If val is greater than top of minHeap.
         *       -->Then push the top of minHeap into the maxHeap and pop it
         *          and push the val into the minHeap.
         */

        else if (val > minHeap.top())
        {
            int temp = minHeap.top();
            minHeap.pop();
            minHeap.push(val);
            maxHeap.push(temp);
        }

        /**
         * Case 3. If val is less than the top of minHeap.
         *      --> Then simply push it into the maxHeap.
         */
        else
        {
            maxHeap.push(val);
        }
    }

    //If the size of both the heaps is not same, then we know that the size of
    //maxHeap is 1 more than the minHeap, so we will always push element into the
    //minHeap.

    else
    {

        /**
             * Case 1 If val is less than the top of maxHeap.
             *      -->Then pop the top element of the maxHeap and push that into minHeap.
             *      -->and push the val into the maxHeap.
             */

        if (val < maxHeap.top())
        {
            int temp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(val);
            minHeap.push(temp);
        }

        /**
             * Case 2. If val is greater than the top of maxHeap.
             *      --> Then simply push the val into minHeap.
             */

        else
        {
            minHeap.push(val);
        }
    }
}

double findMedian()
{
    int lSize = maxHeap.size();
    int rSize = minHeap.size();

    if(lSize > rSize){
        return maxHeap.top();
    }

    else{
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
}

int main()
{
    insert(5);
    cout<<findMedian()<<" ";
    insert(3);
    cout<<findMedian()<<" ";
    insert(4);
    cout<<findMedian()<<" ";
    insert(2);
    cout<<findMedian()<<" ";
    insert(6);
    cout<<findMedian()<<" ";
}