/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Examples :

Input: 25525511135
Output: [“255.255.11.135”, “255.255.111.35”]
Explanation:
These are the only valid possible
IP addresses.

Input: "25505011535"
Output: []
Explanation: 
We cannot generate a valid IP
address with this string.
First, we will place 3 dots in the given string and then try out all the possible combinations for the 3 dots. 
Corner case for validity:

For string "25011255255"
25.011.255.255 is not valid as 011 is not valid.
25.11.255.255 is not valid either as you are not
allowed to change the string.
250.11.255.255 is valid.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string ip)
{
    vector<string> ips;
    string ex = "";

    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex += ip[i];
        }
    }
    ips.push_back(ex);

    for (int i = 0; i < ips.size(); i++)
    {
        int curr = stoi(ips[i]);
        if (ips[i].length() > 3 || curr < 0 || curr > 255)
            return 0;

        if (ips[i].length() > 1 && curr == 0)
            return 0;

        if (ips[i].length() > 1 && curr != 0 && ips[i][0] == '0')
            return 0;
    }
    return true;
}

void convert(string ip)
{
    int l = ip.length();

    if (l > 12 || l < 4)
    {
        cout << "Not valid IP Address.";
        return;
    }

    string check = ip;
    vector<string> ans;

    //Generating different Combinations
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);

                if (isValid(check))
                {
                    ans.push_back(check);
                    cout << check <<endl;
                }
                check = ip;
            }
        }
    }
}

int main()
{
    string ip = "25525511135";
    convert(ip);
    return 0;
}