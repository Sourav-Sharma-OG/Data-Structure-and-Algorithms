/*
A newly designed keypad was tested, where a tester pressed a sequence of n keys, one at a time.
You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence, and a sorted list releaseTimes, where releaseTimes[i] was the time the ith key was released. Both arrays are 0-indexed. The 0th key was pressed at the time 0, and every subsequent key was pressed at the exact time the previous key was released.
The tester wants to know the key of the keypress that had the longest duration. The ith keypress had a duration of releaseTimes[i] - releaseTimes[i - 1], and the 0th keypress had a duration of releaseTimes[0].
Note that the same key could have been pressed multiple times during the test, and these multiple presses of the same key may not have had the same duration.
Return the key of the keypress that had the longest duration. If there are multiple such keypresses, return the lexicographically largest key of the keypresses. 
Example 1:

Input: releaseTimes = [9,29,49,50], keysPressed = "cbcd"
Output: "c"
Explanation: The keypresses were as follows:
Keypress for 'c' had a duration of 9 (pressed at time 0 and released at time 9).
Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 right after the release of the previous character and released at time 29).
Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 right after the release of the previous character and released at time 49).
Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 right after the release of the previous character and released at time 50).
The longest of these was the keypress for 'b' and the second keypress for 'c', both with duration 20.
'c' is lexicographically larger than 'b', so the answer is 'c'.
*/

#include <bits/stdc++.h>
using namespace std;

char slowestKeyBruteForce(string keysPressed, vector<int> releaseTime)
{
    int maxTime = releaseTime[0];
    for (int i = 1; i < releaseTime.size(); i++)
    {
        maxTime = max(maxTime, releaseTime[i] - releaseTime[i - 1]);
    }

    vector<char> ch;
    for (int i = 0; i < releaseTime.size(); i++)
    {
        if (i == 0) 
        {
            if (releaseTime[i] == maxTime)
            {
                ch.push_back(keysPressed[i]);
            }
        }
        else
        {
            if (releaseTime[i] - releaseTime[i - 1] == maxTime)
            {
                ch.push_back(keysPressed[i]);
            }
        }
    }

    sort(ch.begin(), ch.end(), greater<char>());
    return ch[0];
}

char slowestKeyOptimised(string keysPressed, vector<int>& releaseTime) {
    int maxTime = releaseTime[0];
    char maxChar = keysPressed[0];
    
    for(int i = 1; i<releaseTime.size(); i++){
        int duration = releaseTime[i] - releaseTime[i-1];
        if(duration > maxTime){
            maxTime = duration;
            maxChar = keysPressed[i];
        }
        else if(duration == maxTime){
            maxChar = max(maxChar, keysPressed[i]);
        }
    }
    
    return maxChar;
}

int main()
{
    string keysPressed = "cbcd";
    vector<int> releaseTime = {9, 29, 49, 50};

    cout << slowestKeyBruteForce(keysPressed, releaseTime);
    cout<<endl;
    cout<<slowestKeyOptimised(keysPressed, releaseTime);
    return 0;
}