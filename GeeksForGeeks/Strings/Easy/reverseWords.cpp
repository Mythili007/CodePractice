#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        string st;
        cin>>st;
        // cout<<st<<endl;
        istringstream iss(st);
        std::vector<std::string> tokens;
        std::string token;
        
        while(std::getline(iss, token, '.')){
            if(!token.empty()){
                tokens.push_back(token);
            }
        }

        for(int i=tokens.size()-1;i>=0;i--){
            cout<<tokens[i]<<".";
        }
    }
    return 0;
}