#include <bits/stdc++.h>
using namespace std;
#define SIZE 1001

int heapsize;
int heap[SIZE];

void heap_push(int val)
{
    if (heapsize >= SIZE)
    {
        cout << "Heap overflow...";
        return;
    }

    heap[heapsize] = val;
    int idx = heapsize;
    heapsize++; //Incrementing the heap size after push.

    //Perlocate up..
    while (idx > 0 and heap[idx] > heap[(idx - 1) / 2])
    {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2; //Current idx pointer moves to the parent..
    }
}

int heap_pop()
{
    if (heapsize <= 0)
    {
        cout << "Heap underflow...";
        return -1;
    }

    int idx = 0;
    int popped = heap[0];         //Saving the element to be popped.
    heap[0] = heap[heapsize - 1]; //Copy last element to  the root.
    heapsize--;                   //Reducing the heap size.

    //Max-Heapify using while loop
    while (idx * 2 + 1 < heapsize)
    { //left child exists..
        int child;

        //If we only have left child.
        if (idx * 2 + 2 == heapsize)
        {
            child = idx * 2 + 1; //Make the left child as child.
        }
        else
        {
            if (heap[idx * 2 + 1] > heap[idx * 2 + 2])
            {
                child = idx * 2 + 1;
            }
            else
            {
                child = idx * 2 + 2;
            }
        }

        //If current idx is lower than max(leftChild, rightChild)
        //then swap and do max_heapify again for that child..
        if (heap[idx] < heap[child])
        {
            swap(heap[idx], heap[child]);
            idx = child;
        }
        else
        {
            break; //Max heapify is done.
        }
    }
    return popped;
}

void show_heap(){
    for(int i = 0; i<heapsize; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void init(){
    heapsize = 0;
}

int main()
{
    init();

    while(true){
        int option, element;
        cout<<"Enter you choice: "<<endl;
        cout<<".*. Press 1 for push into heap."<<endl;
        cout<<".*. Press 2 for pop from heap."<<endl;
        cout<<".*. Press 3 for show heap."<<endl;
        cout<<".*. Press 4 to exit..."<<endl;

        cin>>option;
        switch(option){
            case 1: cout<<"Enter element: ";
                    cin>>element;
                    heap_push(element);
                    break;

            case 2: cout<<"Popped element is: "<<heap_pop()<<endl;
                    break;
            
            case 3: show_heap();
                    break;

            default:
                    return 0;
        }
    }

}