
// 7-1 符号配对
// 分数 15
// 作者 DS课程组
// 单位 浙江大学
// 请编写程序检查C语言源程序中下列符号是否配对：/*与*/、(与)、[与]、{与}。
// 
// 输入格式:
// 输入为一个C语言源程序。当读到某一行中只有一个句点.和一个回车的时候，标志着输入结束。
// 程序中需要检查配对的符号不超过100个。
// 
// 输出格式:
// 首先，如果所有符号配对正确，则在第一行中输出YES，否则输出NO。
// 然后在第二行中指出第一个不配对的符号：如果缺少左符号，则输出?-右符号；如果缺少右符号，则输出左符号-?。
// 

/*
遇到左符号压栈，遇到右符号弹栈
情形                  	 │ 现场                         │ 报告         │ 
 ├───────────────────────┼──────────────────────────────┼───────────  │  
 │ 缺左符号               │ 遇到右符号，但栈空               │ ?-右符号    │
 │                       │                              │             │ 
 │                       │                              │             │ 
 ├───────────────────────┼──────────────────────────────┼─────────────┼
 │ 缺右符号（类型不匹配     │ 遇到右符号，栈非空但栈顶是别      │ 栈顶左符号    │ 
 │ ）                    │ 的左符号                       │ -?          │
 │                       │                              │             │ 
 ├───────────────────────┼──────────────────────────────┼─────────────┼
 │ 缺右符号（扫描结束）  │ 扫完，栈非空                      │ 栈顶左符号    │ 
 │                       │                              │ -?          │ 
 │                       │                              │             │ 
 └───────────────────────┴──────────────────────────────┴─────────────┴
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string name(int t){
	if (t == 1) return "/*";
	if (t == 2) return "(";
	if (t == 3) return "[";
	return "{";
} 

int main() {
	vector<int> stk;
	char last = 0;
 	string s;
	while(getline(cin, s)) {
		//测试数据的行尾大概带有 \r,去掉防止有影响
		while (!s.empty() && (s.back() == '\r' || s.back() == ' ')) s.pop_back();
		if (s ==  ".") break;
		for (char c: s) {
			//压栈
			if (c == '*' && last == '/') {
				stk.push_back(1);
				//防止出现/*/的情况
				last = 0;
				continue;
			}
			//弹栈
			else if (c == '/' && last == '*'){
				if (stk.empty()) {
					cout << "NO\n?-*/" << endl;
					return 0;
				}
				//缺右符号
				if (stk.back() != 1) {
					cout << "NO\n" <<  name(stk.back()) << "-?" << endl;
					return 0;
				}
				//啥都不缺
				stk.pop_back();
				last = 0;
				continue;
			}
			//压栈
			else if (c == '(') stk.push_back(2);
			else if (c == ')') {
				//缺左
				if (stk.empty()) {
					cout << "NO\n?-)" << endl;
					return 0;
				}
				//缺右
				if (stk.back() != 2) {
					cout << "NO\n" << name(stk.back()) << "-?" << endl;
					return 0;
				}
				//不缺
				stk.pop_back();
			}
			else if (c == '[') stk.push_back(3);
			else if (c == ']') {
				if (stk.empty()) {
					cout << "NO\n?-]" << endl;
					return 0;
				}
				if (stk.back() != 3) {
					cout << "NO\n" << name(stk.back()) << "-?" << endl;
					return 0; 
				}
				stk.pop_back();
			}
			else if (c == '{') stk.push_back(4);
			else if (c == '}') {
				if (stk.empty()) {
					cout << "NO\n?-}" << endl;
					return 0;
				}
				if (stk.back() != 4) {
					cout << "NO\n" << name(stk.back()) << "-?" << endl;
					return 0;
				}
				stk.pop_back();
			}
			last = c;
	
	
		}
		last = 0;
		
	}
	//检查左符号有没有剩下
	if (!stk.empty()) {
		cout << "NO\n" << name(stk.back()) << "-?" << endl;
	}
	else {
		cout << "YES" << endl;
	}
    return 0;
}
