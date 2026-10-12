#include <iostream>
#include <vector>
using namespace std;

string name(int t){ if(t==1)return "/*"; if(t==2)return "("; if(t==3)return "["; return "{"; }

int main(){
    vector<int> stk;
    char last=0;
    string s;
    int ln=0;
    while(getline(cin,s)){
        if(s==".") break;
        ln++;
        for(char c: s){
            if(c=='*'&&last=='/'){ stk.push_back(1); cerr<<"L"<<ln<<" push /*\n"; }
            else if(c=='/'&&last=='*'){
                cerr<<"L"<<ln<<" got */ stk.size="<<stk.size();
                if(!stk.empty()) cerr<<" top="<<name(stk.back());
                cerr<<"\n";
                if(stk.empty()){ cerr<<"  -> NO ?-*/\n"; return 0; }
                if(stk.back()!=1){ cerr<<"  -> NO "<<name(stk.back())<<"-?\n"; return 0; }
                stk.pop_back();
            }
            else if(c=='('){ stk.push_back(2); cerr<<"L"<<ln<<" push (\n"; }
            else if(c==')'){ if(stk.empty()){cerr<<"NO ?-)\n";return 0;} if(stk.back()!=2){cerr<<"NO "<<name(stk.back())<<"-?\n";return 0;} stk.pop_back(); cerr<<"L"<<ln<<" pop )\n"; }
            else if(c=='['){ stk.push_back(3); cerr<<"L"<<ln<<" push [\n"; }
            else if(c==']'){ if(stk.empty()){cerr<<"NO ?-]\n";return 0;} if(stk.back()!=3){cerr<<"NO "<<name(stk.back())<<"-?\n";return 0;} stk.pop_back(); cerr<<"L"<<ln<<" pop ]\n"; }
            else if(c=='{'){ stk.push_back(4); cerr<<"L"<<ln<<" push {\n"; }
            else if(c=='}'){ if(stk.empty()){cerr<<"NO ?-}\n";return 0;} if(stk.back()!=4){cerr<<"NO "<<name(stk.back())<<"-?\n";return 0;} stk.pop_back(); cerr<<"L"<<ln<<" pop }\n"; }
            last=c;
        }
        last='\n';
    }
    if(!stk.empty()) cerr<<"END NO "<<name(stk.back())<<"-?\n";
    else cerr<<"END YES\n";
}
