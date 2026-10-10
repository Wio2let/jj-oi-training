/*
7-2 输出闰年
分数 15
作者 陈建海
单位 浙江大学
输出21世纪中截止某个年份以来的所有闰年年份。注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。

输入格式:
输入在一行中给出21世纪的某个截止年份。

输出格式:
逐行输出满足条件的所有闰年年份，即每个年份占一行。输入若非21世纪的年份则输出"Invalid year!"。若不存在任何闰年，则输出“None”。
*/
#include <iostream>
using namespace std;

int main(){
	int a, cnt = 0;
	cin >> a;
	if (a >= 2001 && a <= 2100)
	{
		for (int i = 2001; i <= a; i++)
		{
			if (i % 4 == 0 && (i % 100 != 0 && i % 400 != 0))
			{
				cout << i << endl;
				cnt++;
			}
		}
		if (!cnt) cout << "None" << endl;
	return 0;
	}

	cout << "Invalid year!" << endl;

}




