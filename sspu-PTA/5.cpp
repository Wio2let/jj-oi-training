/*
7-5 输出大写英文字母
分数 15
作者 颜晖
单位 浙大城市学院
本题要求编写程序，顺序输出给定字符串中所出现过的大写英文字母，每个字母只输出一遍；若无大写英文字母则输出“Not Found”。

输入格式：
输入为一个以回车结束的字符串（少于80个字符）。

输出格式：
按照输入的顺序在一行中输出所出现过的大写英文字母，每个字母只输出一遍。若无大写英文字母则输出“Not Found”。

遗忘：
set的使用方法
cin一行的使用方法
unordered_set的顺序与哈希表有关
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;
using ll = long long;
using ull = unsigned long long;
bool flag = 0;
int main() {
    string s;
    getline(cin, s);
    bool vis[26] = {0};
    for (char c: s){
    	if (c >= 'A' && c <= 'Z' && !vis[c - 'A']) 
    	{
    		cout << c;
    		vis[c - 'A'] = 1;
    		flag = 1;
    	}
    	
    }
    if (!flag) cout << "Not Found"; 
    return 0;
}
