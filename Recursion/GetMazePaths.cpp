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
    for(int vJump = 1;vJump <= dr - sr; vJump++){
        vector<string> vPaths = getMazePathsWithJumps(sr + vJump, sc, dr, dc);
        for(auto i : vPaths){
            string temp = "v" + to_string(vJump) + i;
            result.push_back(temp);
        }
    }

    //Horizontal moves
    for(int hJump = 1; hJump <= dc - sc; hJump++){
        vector<string> hPaths = getMazePathsWithJumps(sr, sc + hJump, dr, dc);
        for(auto i: hPaths){
            string temp = "h" + to_string(hJump) + i;
            result.push_back(temp);
        }
    }

    //Diagonal Moves

    for(int dJump = 1; dJump <= dc - sc && dJump <= dr - sr; dJump ++){
        vector<string> dPaths = getMazePathsWithJumps(sr + dJump, sc + dJump, dr, dc);
        for(auto i: dPaths){
            string temp = "d" + to_string(dJump) + i;
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