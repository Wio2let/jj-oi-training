# 26级研究生-程序设计训练题集 · 编程题（18 题）

- 题目集: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7>
- 抓取时间: 2026-10-11 07:56 UTC
- 题型: `CODE_COMPLETION`（分值合计 315 分）

| # | 题目 | 分值 | 时间 | 内存 | 链接 |
|---:|---|---:|---:|---:|---|
| 1 | 使用函数求e的近似值 | 15 | None ms | None KB | [7-1](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505346>) |
| 2 | 使用函数统计指定数字的个数 | 15 | None ms | None KB | [7-2](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505347>) |
| 3 | 使用函数求1到10的阶乘和 | 10 | None ms | None KB | [7-3](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505348>) |
| 4 | 使用函数判断完全平方数 | 10 | None ms | None KB | [7-4](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505349>) |
| 5 | 使用函数输出一个整数的逆序数 | 20 | None ms | None KB | [7-5](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505350>) |
| 6 | 使用函数输出水仙花数 | 20 | None ms | None KB | [7-6](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505351>) |
| 7 | 使用函数输出指定范围内的完数 | 20 | None ms | None KB | [7-7](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505352>) |
| 8 | 函数实现字符串逆序 | 15 | None ms | None KB | [7-8](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505353>) |
| 9 | 拆分实数的整数与小数部分 | 15 | None ms | None KB | [7-9](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505354>) |
| 10 | 计算最长的字符串长度 | 15 | None ms | None KB | [7-10](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505355>) |
| 11 | 字符定位（最后一次找到的字符） | 15 | None ms | None KB | [7-11](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505356>) |
| 12 | 指定位置输出字符串 | 20 | None ms | None KB | [7-12](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505357>) |
| 13 | 使用函数实现字符串部分复制 | 20 | None ms | None KB | [7-13](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505358>) |
| 14 | 判断回文字符串 | 20 | None ms | None KB | [7-14](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505359>) |
| 15 | 求自定类型元素序列的中位数 | 25 | None ms | None KB | [7-15](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505360>) |
| 16 | 单链表结点删除 | 20 | None ms | None KB | [7-16](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505361>) |
| 17 | 学生成绩链表处理 | 20 | None ms | None KB | [7-17](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505362>) |
| 18 | 有序表的增删改查操作 | 20 | None ms | None KB | [7-18](<https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505363>) |

---

## 1. 使用函数求e的近似值

- 题号: `7-1` 　分值: **15** 　作者: 颜晖
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505346>

自然常数$$e$$可以用级数$$1+1/1!+1/2!+\cdots +1/n! $$来近似计算。本题要求实现一个计算阶乘的简单函数，使得可以利用该函数，对给定的非负整数$$n$$，求该级数的前$$n$$+1项和。

### 函数接口定义：
```c++
double fact( int n );
```

其中$$n$$是用户传入的参数，函数返回$$n$$的阶乘。

### 裁判测试程序样例：
```c++
#include <stdio.h>

double fact( int n );

int main(void)
{    
    int i, n;
    double sum; 

    scanf("%d", &n);
    sum = 1;
    for(i = 1; i <= n; i++){
        sum = sum + 1.0/fact(i); 
     }
     printf("%f\n", sum);

    return 0;
}

/* 请在这里填写答案 */
```

### 输入样例：

```in
10
```

### 输出样例：

```out
2.718282
```

---

## 2. 使用函数统计指定数字的个数

- 题号: `7-2` 　分值: **15** 　作者: 张高燕
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505347>

本题要求实现一个统计整数中指定数字的个数的简单函数。

### 函数接口定义：
```c++
int CountDigit( int number, int digit );
```
其中`number`是不超过长整型的整数，`digit`为[0, 9]区间内的整数。函数`CountDigit`应返回`number`中`digit`出现的次数。

### 裁判测试程序样例：
```c++
#include <stdio.h>

int CountDigit( int number, int digit );
    
int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));
    
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
-21252 2
```

### 输出样例：
```out
Number of digit 2 in -21252: 3
```

---

## 3. 使用函数求1到10的阶乘和

- 题号: `7-3` 　分值: **10** 　作者: 张高燕
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505348>

本题要求实现一个计算非负整数阶乘的简单函数，使得可以利用该函数，计算$$1! + 2! + \cdots + 10!$$的值。

### 函数接口定义：
```c++
double fact( int n );
```
其中`n`是用户传入的参数，其值不超过10。如果`n`是非负整数，则该函数必须返回`n`的阶乘。

### 裁判测试程序样例：
```c++
#include <stdio.h>

double fact( int n );

int main(void)
{    
    int i;
    double sum; 

    sum = 0; 
    for(i = 1; i <= 10; i++) 
        sum = sum + fact(i); 
        
    printf("1!+2!+...+10! = %f\n", sum); 
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：

本题没有输入。

### 输出样例：
```out
1!+2!+...+10! = 4037913.000000
```

---

## 4. 使用函数判断完全平方数

- 题号: `7-4` 　分值: **10** 　作者: 张高燕
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505349>

本题要求实现一个判断整数是否为完全平方数的简单函数。

### 函数接口定义：
```c++
int IsSquare( int n );
```

其中`n`是用户传入的参数，在长整型范围内。如果`n`是完全平方数，则函数`IsSquare`必须返回1，否则返回0。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#include <math.h>

int IsSquare( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    if ( IsSquare(n) ) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例1：
```in
90

```

### 输出样例1：
```out
NO

```

### 输入样例2：
```
100
```

### 输出样例2：
```
YES
```

**鸣谢安阳师范学院段晓云老师、用户黄凯涵修正数据~**

---

## 5. 使用函数输出一个整数的逆序数

- 题号: `7-5` 　分值: **20** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505350>

本题要求实现一个求整数的逆序数的简单函数。

### 函数接口定义：
```c++
int reverse( int number );
```
其中函数`reverse`须返回用户传入的整型`number`的逆序数。

### 裁判测试程序样例：
```c++
#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
-12340
```

### 输出样例：
```out
-4321
```

---

## 6. 使用函数输出水仙花数

- 题号: `7-6` 　分值: **20** 　作者: 张高燕
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505351>

水仙花数是指一个$$N$$位正整数（$$N\ge 3$$），它的每个位上的数字的$$N$$次幂之和等于它本身。例如：$$153 = 1^3 + 5^3+ 3^3$$。 本题要求编写两个函数，一个判断给定整数是否水仙花数，另一个按从小到大的顺序打印出给定区间$$(m,n)$$内所有的水仙花数。

### 函数接口定义：
```c++
int narcissistic( int number );
void PrintN( int m, int n );
```
函数`narcissistic`判断`number`是否为水仙花数，是则返回1，否则返回0。

函数`PrintN`则打印开区间(`m`, `n`)内所有的水仙花数，每个数字占一行。题目保证100$$\le$$`m`$$\le$$`n`$$\le$$10000。

### 裁判测试程序样例：
```c++
#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
153 400

```

### 输出样例：
```out
153 is a narcissistic number
370
371

```

---

## 7. 使用函数输出指定范围内的完数

- 题号: `7-7` 　分值: **20** 　作者: 陈建海
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505352>

本题要求实现一个计算整数因子和的简单函数，并利用其实现另一个函数，输出两正整数$$m$$和$$n$$（$$0<m\le n\le 10000$$）之间的所有完数。所谓完数就是该数恰好等于除自身外的因子之和。例如：6=1+2+3，其中1、2、3为6的因子。

### 函数接口定义：
```c++
int factorsum( int number );
void PrintPN( int m, int n );
```
其中函数`factorsum`须返回`int number`的因子和；函数`PrintPN`要逐行输出给定范围[`m`, `n`]内每个完数的因子累加形式的分解式，每个完数占一行，格式为“完数 = 因子1 + 因子2 + ... + 因子k”，其中完数和因子均按递增顺序给出。如果给定区间内没有完数，则输出一行“No perfect number”。

### 裁判测试程序样例：
```c++
#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
	
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例1：
```in
6 30
```

### 输出样例1：
```out
6 is a perfect number
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
```

### 输入样例2：
```in
7 25
```

### 输出样例2：
```out
No perfect number
```

**鸣谢杭州电子科技大学网络空间安全学院李丰同学修正数据！**

---

## 8. 函数实现字符串逆序

- 题号: `7-8` 　分值: **15** 　作者: 张泳
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505353>

本题要求实现一个字符串逆序的简单函数。

### 函数接口定义：
```c++
void f( char *p );
```
函数`f`对`p`指向的字符串进行逆序操作。要求函数`f`中不能定义任何数组，不能调用任何字符串处理函数。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#define MAXS 20

void f( char *p );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];
    
    ReadString(s);
    f(s);
    printf("%s\n", s);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
Hello World!
```

### 输出样例：
```out
!dlroW olleH
```

---

## 9. 拆分实数的整数与小数部分

- 题号: `7-9` 　分值: **15** 　作者: 张泳
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505354>

本题要求实现一个拆分实数的整数与小数部分的简单函数。

### 函数接口定义：
```c++
void splitfloat( float x, int *intpart, float *fracpart );
```
其中`x`是被拆分的实数（0$$\le$$`x`$$<$$10000），`*intpart`和`*fracpart`分别是将实数x拆分出来的整数部分与小数部分。

### 裁判测试程序样例：
```c++
#include <stdio.h>

void splitfloat( float x, int *intpart, float *fracpart );

int main()
{
    float x, fracpart;
    int intpart;
    
    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
2.718
```

### 输出样例：
```out
The integer part is 2
The fractional part is 0.718
```

---

## 10. 计算最长的字符串长度

- 题号: `7-10` 　分值: **15** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505355>

本题要求实现一个函数，用于计算有n个元素的指针数组s中最长的字符串的长度。

### 函数接口定义：
```c++
int max_len( char *s[], int n );
```
其中`n`个字符串存储在`s[]`中，函数`max_len`应返回其中最长字符串的长度。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
4
blue
yellow
red
green
```

### 输出样例：
```out
6

```

---

## 11. 字符定位（最后一次找到的字符）

- 题号: `7-11` 　分值: **15** 　作者: 张泳
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505356>

本题要求定义一个函数，在字符串中查找字符，并定位在最后一次找到的位置。

### 函数接口定义：
```c++
char * match(char *s, char ch);
```

其中s是字符串首地址，ch是要查找的字符。要求函数在字符串s中查找字符ch，如果找到，返回最后一次找到的该字符在字符串中的位置（地址）；否则，返回空指针NULL。

### 裁判测试程序样例：
```c++
#include <stdio.h> 
char *match(char *s, char ch); 

int main(void )
{
    char ch, str[80], *p = NULL;

    scanf("%s", str);
    getchar();         		/* 跳过输入字符串和输入字符之间的分隔符 */
    ch = getchar();  		/* 输入一个字符 */
    p = match(str, ch); 	/* 调用函数match() */
    if( p != NULL ){    	/* 找到字符ch */
        printf("%s\n", p);
    }else{ 
        printf("Not Found.\n");
    }

    return 0;
}

/* 请在这里填写答案 */
```

### 输入样例1：
```in
program
r
```

### 输出样例1：
```out
ram
```

### 输入样例2：
```in
program
x
```

### 输出样例2：
```out
Not Found.
```

---

## 12. 指定位置输出字符串

- 题号: `7-12` 　分值: **20** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505357>

本题要求实现一个函数，对给定的一个字符串和两个字符，打印出给定字符串中从与第一个字符匹配的位置开始到与第二个字符匹配的位置之间的所有字符。

### 函数接口定义：
```c++
char *match( char *s, char ch1, char ch2 );
```
函数`match`应打印`s`中从`ch1`到`ch2`之间的所有字符，并且返回`ch1`的地址。

### 裁判测试程序样例：
```c++
#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例1：
```in
program
r g
```

### 输出样例1：
```out
rog
rogram
```

### 输入样例2：
```
program
z o
```

### 输出样例2：
```
(空行)
(空行)
```

### 输入样例3：
```
program
g z
```

### 输出样例3：
```
gram
gram
```

---

## 13. 使用函数实现字符串部分复制

- 题号: `7-13` 　分值: **20** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505358>

本题要求编写函数，将输入字符串$$t$$中从第$$m$$个字符开始的全部字符复制到字符串$$s$$中。

### 函数接口定义：
```c++
void strmcpy( char *t, int m, char *s );
```
函数`strmcpy`将输入字符串`char *t`中从第`m`个字符开始的全部字符复制到字符串`char *s`中。若`m`超过输入字符串的长度，则结果字符串应为空串。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;
    
    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
7
happy new year

```

### 输出样例：
```out
new year

```

---

## 14. 判断回文字符串

- 题号: `7-14` 　分值: **20** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505359>

本题要求编写函数，判断给定的一串字符是否为“回文”。所谓“回文”是指顺读和倒读都一样的字符串。如“XYZYX”和“xyzzyx”都是回文。

### 函数接口定义：
```c++
bool palindrome( char *s );
```
函数`palindrome`判断输入字符串`char *s`是否为回文。若是则返回`true`，否则返回`false`。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
    char s[MAXN];
    
    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例1：
```in
thisistrueurtsisiht
```

### 输出样例1：
```out
Yes
thisistrueurtsisiht

```

### 输入样例2：
```
thisisnottrue
```

### 输出样例2：
```
No
thisisnottrue
```

---

## 15. 求自定类型元素序列的中位数

- 题号: `7-15` 　分值: **25** 　作者: 陈越
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505360>

本题要求实现一个函数，求`N`个集合元素`A[]`的中位数，即序列中第$$\lfloor (N+1)/2\rfloor$$大的元素。其中集合元素的类型为自定义的`ElementType`。

### 函数接口定义：
```c++
ElementType Median( ElementType A[], int N );
```

其中给定集合元素存放在数组`A[]`中，正整数`N`是数组元素个数。该函数须返回`N`个`A[]`元素的中位数，其值也必须是`ElementType`类型。

### 裁判测试程序样例：
```c++
#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
3
12.3 34 -5
```

### 输出样例：
```out
12.30
```

---

## 16. 单链表结点删除

- 题号: `7-16` 　分值: **20** 　作者: 张泳
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505361>

本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中所有存储了某给定值的结点删除。链表结点定义如下：

```
struct ListNode {
    int data;
    ListNode *next;
};
```

### 函数接口定义：
```c++
struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
```
函数`readlist`从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到$$-1$$时表示输入结束，函数应返回指向单链表头结点的指针。

函数`deletem`将单链表`L`中所有存储了`m`的结点删除。返回指向结果链表头结点的指针。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
10 11 10 12 10 -1
10
```

### 输出样例：
```out
11 12 
```

---

## 17. 学生成绩链表处理

- 题号: `7-17` 　分值: **20** 　作者: C课程组
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505362>

本题要求实现两个函数，一个将输入的学生成绩组织成单向链表；另一个将成绩低于某分数线的学生结点从链表中删除。

### 函数接口定义：
```c++
struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );
```
函数`createlist`利用`scanf`从输入中获取学生的信息，将其组织成单向链表，并返回链表头指针。链表节点结构定义如下：
```c++
struct stud_node {
    int              num;      /*学号*/
    char             name[20]; /*姓名*/
    int              score;    /*成绩*/
    struct stud_node *next;    /*指向下个结点的指针*/
};
```
输入为若干个学生的信息（学号、姓名、成绩），当输入学号为0时结束。

函数`deletelist`从以`head`为头指针的链表中删除成绩低于`min_score`的学生，并返回结果链表的头指针。

### 裁判测试程序样例：
```c++
#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：
```in
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0
80
```

### 输出样例：
```out
2 wang 80
4 zhao 85
```

---

## 18. 有序表的增删改查操作

- 题号: `7-18` 　分值: **20** 　作者: 张高燕
- 时间限制: None ms 　内存限制: None KB 　代码长度限制: None KB
- 链接: <https://pintia.cn/problem-sets/2101904400470790144/exam/problems/type/7?problemSetProblemId=2101904400680505363>

首先输入一个正整数$$N$$（$$1\le N\le 1000$$）和一个无重复元素的、从小到大排列的、$$N$$个元素的有序表，然后在屏幕上显示以下菜单（编号和选项）。
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
```
用户可以反复对该有序表进行插入、删除、修改和查找操作，也可以选择结束。当用户输入编号`1`～`4`和相关参数时，将分别对该有序表进行插入、删除、修改和查找操作，输入其他编号，则结束操作。

本题要求实现4个函数，分别在有序表（数组）中插入、删除、修改、查找一个值。

### 函数接口定义：
```c++
int insert(int a[ ], int value);	
int del(int a[ ], int value);
int modify(int a[ ], int value1, int value2); 
int query(int a[ ], int value);
```
函数`insert`在有序数组`a`中插入一个值为`value`的元素，如果在数组`a`中已有值为`value`的元素，则返回`-1`。

函数`del`删除有序数组`a`中等于`value`的元素，如果在数组`a`中没有找到值为`value`的元素，则返回`-1`。

函数`modify`将有序数组`a`中等于`value1`的元素，替换为`value2` ，如果在数组`a`中没有找到值为`value1`的元素或者`value2`已在数组`a`中存在，则返回`-1`。

函数`query`用二分法在有序数组`a`中查找元素`value`，如果找到，则返回相应的下标；如果没有找到，则返回`-1`。

### 裁判测试程序样例：
```c++
/* 有序表的增删改查操作 */
#include<stdio.h>
#define MAXN 10000	/* 定义符号常量表示数组a的长度 */

int Count = 0;		/* 用全局变量Count表示数组a中待处理的元素个数 */
void select(int a[], int option, int value); /* 决定对有序数组a进行何种操作的控制函数 */
int input_array(int a[ ]);	/* 输入有序数组a的函数 */
void print_array(int a[ ]);	/* 输出有序数组a的函数 */
int insert(int a[ ], int value);	/* 在有序数组a中插入一个值为value的元素的函数 */
int del(int a[ ], int value);	/* 删除有序数组a中等于value的元素的函数 */
int modify(int a[ ], int value1, int value2); /* 将有序数组a中等于value1的元素，替换为value2 */ 
int query(int a[ ], int value);	 /* 用二分法在有序数组a中查找元素value的函数 */

int main(void) 
{
   int option, value, a[MAXN];
	
    if(input_array(a) == -1){ 	/* 调用函数输入有序数组 a */
         printf("Error");		/* a不是有序数组，则输出相应的信息 */
         return 0;
    }
    
    printf("[1] Insert\n");	/* 以下4行显示菜单*/
    printf("[2] Delete\n");
    printf("[3] Update\n");
    printf("[4] Query\n");
    printf("[Other option] End\n");
    while (1) {			/* 循环 */
        scanf("%d", &option); 		/* 接受用户输入的编号 */
        if (option < 1 || option > 4) {	/* 如果输入1、2、3、4以外的编号，结束循环 */
            break;
        }
        scanf("%d", &value); 		/* 接受用户输入的参数value */
        select(a, option, value); 		/* 调用控制函数 */
        printf("\n");
    }
    printf("Thanks.");			/* 结束操作 */
    
    return 0;
}

/* 控制函数 */
void select(int a[ ], int option, int value) 
{
    int index, value2;
	
    switch (option) {
        case 1:
            index = insert(a, value);  	/* 调用插入函数在有序数组 a 中插入元素value */
            if(index == -1){		/* 插入数据已存在，则输出相应的信息 */
            	printf("Error");
            }else{						
            	print_array(a);		/* 调用输出函数，输出插入后的有序数组a */
            }
            break;
        case 2:
            index = del(a, value);  	/* 调用删除函数在有序数组 a 中删除元素value */
            if(index == -1){		/* 没找到value，则输出相应的信息 */
                printf("Deletion failed.");
	    }else{
	        print_array(a); 		/* 调用输出函数，输出删除后的有序数组a */
	    }
            break;
        case 3:
            scanf("%d", &value2); 		/* 接受用户输入的参数value2 */
            index = modify(a, value, value2);  	/* 调用修改函数在有序数组 a 中修改元素value的值为value2 */
            if(index == -1){			/* 没找到value或者vaule2已存在，则输出相应的信息 */
            	printf("Update failed.");
            }else{
	        print_array(a); 		/* 调用输出函数，输出修改后的有序数组a */
            }
            break;
        case 4:
            index = query(a, value); 	/* 调用查询函数在有序数组 a 中查找元素value */
            if(index == -1){		/* 没找到value，则输出相应的信息 */
            	printf( "Not found.");
            }else{			/* 找到，则输出对应的下标 */
	        printf("%d", index);
            }
            break;
    }
}

/* 有序表输入函数 */
int input_array(int a[ ]) 
{
    scanf("%d", &Count);
    for (int i = 0; i < Count; i ++) {
        scanf("%d", &a[i]);
        if(i > 0 && a[i] <= a[i-1]){	/* a不是有序数组 */
        	return -1;
        }
    }
    
    return 0;
}

/* 有序表输出函数 */
void print_array(int a[ ]) 
{
    for (int i = 0; i < Count; i ++) { /* 输出时相邻数字间用一个空格分开，行末无空格 */
        if(i == 0){ 	
           printf("%d", a[i]);
        }else{
           printf(" %d", a[i]);
        }
    }
}
 
/* 请在这里填写答案 */
```

### 输入样例1
插入一个值：
```
6 -2 3 7 9 101 400
1
96
0
```
### 输出样例1：
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
-2 3 7 9 96 101 400
Thanks.
```
### 输入样例2
删除一个值：
```
6 -2 3 7 9 101 400
2
400
0
```
### 输出样例2：
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
-2 3 7 9 101
Thanks.
```
### 输入样例3
修改一次：
```
6 -2 3 7 9 101 400
3
7
10
0
```
### 输出样例3：
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
-2 3 9 10 101 400
Thanks.
```
### 输入样例4
查询一次：
```
6 -2 3 7 9 101 400
4
-2
0
```
### 输出样例4：
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
0
Thanks.
```
### 输入样例5
连续增删改查：
```
6 -2 3 7 9 101 400
2
101
1
-10
4
101
3
400
444
0
```
### 输出样例5：
```
[1] Insert
[2] Delete
[3] Update
[4] Query
[Other option] End
-2 3 7 9 400
-10 -2 3 7 9 400
Not found.
-10 -2 3 7 9 444
Thanks.
```

---
