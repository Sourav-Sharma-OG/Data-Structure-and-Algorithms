#include<bits/stdc++.h>
using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc){
    if(sr == dr && sc == dc){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    vector<string>hPaths;
    vector<string>vPaths;

    if(sr < dr){
        hPaths = getMazePaths(sr + 1, sc, dr, dc);
    }

    if(sc < dc){
        vPaths = getMazePaths(sr, sc + 1, dr, dc);
    }

    vector<string>result;

    for(auto s : hPaths){
        string temp = "h" + s;
        result.push_back(temp);
    }

    for(auto s : vPaths){
        string temp = "v" + s;
        result.push_back(temp);
    }

    return result;
}

vector<string> getMazePathsWithJumps(int sr, int sc, int dr, int dc){
    if(sr == dr && sc == dc){
        vector<string> result;
        result.push_back("");
        return result;
    }

    vector<string>result;

    //Vertical moves
    for(int jump = 1; jump <= dr - sr; jump++){
        vector<string> vPaths = getMazePathsWithJumps(sr + jump, sc, dr, dc);
        for(auto i : vPaths){
            string temp = "v" + to_string(jump) + i;
            result.push_back(temp);
        }
    }

    //Horizontal moves
    for(int jump = 1; jump <= dc - sc; jump++){
        vector<string> hPaths = getMazePathsWithJumps(sr, sc + jump, dr, dc);
        for(auto i: hPaths){
            string temp = "h" + to_string(jump) + i;
            result.push_back(temp);
        }
    }

    //Diagonal Moves

    for(int jump = 1; jump <= dc - sc && jump <= dr - sr; jump ++){
        vector<string> dPaths = getMazePathsWithJumps(sr + jump, sc + jump, dr, dc);
        for(auto i: dPaths){
            string temp = "d" + to_string(jump) + i;
            result.push_back(temp);
        }
    }

    return result;
}

int main(){
    int sr = 0, sc = 0, dr = 3, dc = 3;
    vector<string>ans = getMazePaths(sr, sc, dr, dc);

    for(auto i : ans){
        cout<<i<<" ";
    }


    cout<<endl<<endl;
    vector<string>ans1 = getMazePathsWithJumps(sr, sc, dr, dc);

    for(auto i : ans1){
        cout<<i<<" ";
    }
    return 0;
}