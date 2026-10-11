/*
7-9 换硬币
分数 20
作者 C课程组
单位 浙江大学
将一笔零钱换成5分、2分和1分的硬币，要求每种硬币至少有一枚，有几种不同的换法？

输入格式:
输入在一行中给出待换的零钱数额x∈(8,100)。

输出格式:
要求按5分、2分和1分硬币的数量依次从大到小的顺序，输出各种换法。
每行输出一种换法，格式为：“fen5:5分硬币数量, fen2:2分硬币数量, fen1:1分硬币数量, total:硬币总数量”。最后一行输出“count = 换法个数”。


*/

#include <iostream>
using namespace std;

int x;
int cnt = 0;

void money(int type, int remain, int five, int two, int one)
{
    if (type == 3)
    {
        if (remain == 0 && five >= 1 && two >= 1 && one >= 1)
        {
            cout << "fen5:" << five
                 << ", fen2:" << two
                 << ", fen1:" << one
                 << ", total:" << five + two + one << '\n';
            cnt++;
        }
        return;
    }

    int value;
    if (type == 0) value = 5;
    else if (type == 1) value = 2;
    else value = 1;

    for (int i = remain / value; i >= 0; i--)
    {
        if (type == 0)
            money(type + 1, remain - i * value, i, two, one);
        else if (type == 1)
            money(type + 1, remain - i * value, five, i, one);
        else
            money(type + 1, remain - i * value, five, two, i);
    }
}

int main()
{
    cin >> x;
    money(0, x, 0, 0, 0);
    cout << "count = " << cnt << '\n';
    return 0;
}

