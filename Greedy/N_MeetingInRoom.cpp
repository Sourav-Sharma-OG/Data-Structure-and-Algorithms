/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

#include<bits/stdc++.h>
using namespace std;

struct Meetings{
    int start;
    int end;
    int pos;
};

bool comparator(struct Meetings m1, Meetings m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    else return true;
}

int maxMeetings(int start[], int end[], int n){
    Meetings meet[n];
    for(int i = 0; i < n; i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i;
    }

    sort(meet, meet + n, comparator);

    int count = 1;
    int limit = meet[0].end;

    for(int i = 1; i < n; i++){
        if(meet[i].start > limit){
            count++;
            limit = meet[i].end;
        }
    }

    return count;
}

int main(){
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    cout<<maxMeetings(start, end, n);
    return 0;
}