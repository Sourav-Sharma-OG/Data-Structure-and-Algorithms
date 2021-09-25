/*
Write a function “runCustomerSimulation” that takes following two inputs 
a) An integer ‘n’: total number of computers in a cafe and a string: 
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer. 
A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times. 
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.
For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.
runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0
runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.
runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.
*/

#include<bits/stdc++.h>
using namespace std;

int NoOfCustomersDidntGetComputer(int n, string seq){
    unordered_map<char, int>mp;
    int occupied = 0;
    int didntGetComputer = 0;

    for(int i = 0; i < seq.length(); i++){
        if(mp[seq[i]] == 0 and occupied < n){
            occupied++;
            mp[seq[i]] = 1;
        }
        else if(mp[seq[i]] == 1 and occupied <= n){
            occupied--;
            mp[seq[i]] = 0;
        }
        else{
            didntGetComputer++;
        }
    }

    return didntGetComputer / 2;
}

int main(){
    int n;
    cin>>n;
    string seq;
    cin>>seq;

    cout<<NoOfCustomersDidntGetComputer(n, seq);
    return 0;
}

/*
(.) -> given  (|) -> left  (*) -> didnt get

 n = 3 ||  occ = 0 1 2 3 2 3 - - 2 1 0 1 0

 . . . | . * * | | | . |
 G A C C B D D B A G E E
 */