# Oj week8

## 大约MT2121

![image-20230420220534487](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230420220534487.png)



![image-20230420220559565](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230420220559565.png)

~~~c++
#include<iostream>
#include<queue>
#include<algorithm>
int n, ans = 0, a[100005] = {0};
using namespace std;
priority_queue<int, vector<int>, less<int>>max2,maxDel;//less表示按照递减(从大到小)的顺序插入元素
priority_queue<int, vector<int>, greater<int>>min2,minDel;//greater表示按照递增（从小到大）的顺序插入元素

int main()
{
	cin >> n;
	for (int i = 1, j = 1; i <= n; i++)
	{
		cin >> a[i];
		max2.push(a[i]);
		min2.push(a[i]);
		while (max2.top() - min2.top()>1)//max-min>1
		{
			maxDel.push(a[j]);
			minDel.push(a[j]);
			j++;//j前移
			while (maxDel.size() && maxDel.top() == max2.top())
			{
				max2.pop();
				maxDel.pop();
			}
			while (minDel.size() && min2.top() == minDel.top())
			{
				min2.pop();
				minDel.pop();
			}
		}
		//i-j+1标识个数
		ans = max(ans, i - j + 1);
	}
	cout << ans;
}
~~~

## 五彩斑斓的世界MT2115

![image-20230420221020488](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230420221020488.png)

![image-20230420221039584](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230420221039584.png)

![image-20230420221053682](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230420221053682.png)

~~~c++
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
stack<char> stk;
char str[100005];
int index1, index2;
int main()
{
	cin >> str;
	//处理（）
    int len=strlen(str);
	for (int i = 0; i<len; i++)
	{
		index1 = 0;
		index2 = 0;
		if (str[i] != ')')
		{
			stk.push(str[i]);
		}
		else
		{
			while (stk.top() != '(')
			{
				if (stk.top() == 'a')
				{
					index1++;//记录几个a
				}
				else
				{
					//stk.top()=='|'
					//index2记录 '|'两边最多a的个数
					index2 = max(index1, index2);
					index1 = 0;
				}
				stk.pop();
			}
			if (stk.top() == '(')
			{
				stk.pop();
				index2 = max(index1, index2);
			}
			while (index2--)
			{
				stk.push('a');
			}
		}
	}


	//处理 |
	index1 = index2 = 0;
	while (!stk.empty())
	{
		if (stk.top() == 'a')
		{
			index1++;
			stk.pop();
		}
		else if (stk.top()=='|')
		{
			index2 = max(index1, index2);
			index1 = 0;
			stk.pop();
		}
	}
	cout << max(index1, index2);
}
~~~

## 栈间

![image-20230422134742747](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422134742747.png)

~~~c++
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int stk[5000005] = { 0 };
int num = 0;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int opcode;
		//cin >> opcode;
		scanf("%d", &opcode);
		switch (opcode)
		{
		case 1:
		{
			int x;
			scanf("%d", &x);
			stk[num++] = x;
			break;
		}
		case 2:
		{
			//cout << stk[num - 1] << endl;
			printf("%d\n", stk[num - 1]);
			break;
		}
		case 3:
		{
			int x;
			//cin >> x;
			scanf("%d", &x);
			//cout << stk[x] << endl;
			printf("%d\n", stk[x]);
			break;
		}
		case 4:
		{
			num--;
			break;
		}
		default:
			break;
		}
	}
}
~~~

**用scanf、printf代替cin、cout，（卡长）**

## 第k小函数值

![image-20230422143209798](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422143209798.png)

![image-20230422143239538](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422143239538.png)

~~~c++
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int f(int a, int b, int c, int x)
{
	return a * x * x + b * x + c;
}
class node
{
public:
	int a, b, c, x;
	int ans;
	node(int a, int b, int c, int x)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->x = x;
		this->ans = f(a, b, c, x);
	}
};
bool operator > (const node& a,const node& b)
{
	return a.ans > b.ans;
}
priority_queue<node, vector<node>, greater<node>> min2;
int f_args[25][3] = { 0 };
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> f_args[i][0] >> f_args[i][1] >> f_args[i][2];
	}
	for (int i = 0; i < n; i++)
	{
		min2.push(node(f_args[i][0], f_args[i][1], f_args[i][2], 1));
	}
	while (k > 0)
	{
		k--;
		node temp = min2.top();
		min2.pop();
		min2.push(node(temp.a, temp.b, temp.c, temp.x + 1));
		if (k == 0)
		{
			cout << temp.ans;
		}
		//cout << temp.ans << endl;
	}
}
~~~

## 事务处理

![image-20230422143558626](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422143558626.png)

![image-20230422143625508](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422143625508.png)

![image-20230422143644176](C:\Users\LHA\AppData\Roaming\Typora\typora-user-images\image-20230422143644176.png)

~~~c++
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
class node
{
public:
	int a;
	int t;
	int f;
	int v;
	int origin;
	node(int a, int t, int f, int v)
	{
		this->a = a;
		this->t = t;
		this->f = f;
		this->v = v;
		origin = t;
	}
};
bool operator < (const node& a,const node& b)
{
	//return a.v < b.v;
	if (a.v < b.v)
	{
		return 1;
	}
	else if (a.v == b.v)
	{
		if (a.origin < b.origin)
			return 0;
		else
			return 1;
	}
	return 0;
}
priority_queue<node, vector<node>, less<node>>min2;//大根堆
int main()
{
	int a, t, f, v;
	while (cin >> a >> t >> f >> v)
	{
		if (min2.empty())
		{
			min2.push(node(a, t, f, v));
		}
		else
		{
			node temp = min2.top();
			int time = t-temp.t;
			while (true)
			{
				temp = min2.top();
				if (time >= temp.f)
				{
					min2.pop();
					cout << temp.a <<" "<<temp.t+temp.f <<endl;
					if (min2.empty())
						break;
					time -= temp.f;
				}
				else
				{
					//f改变，重新加入堆
					node top_c = min2.top();
					top_c.t = t;
					top_c.f -= time;
					min2.pop();
					min2.push(top_c);
					break;
				}
			}
			min2.push(node(a, t, f, v));
		}
	}
	int index = min2.top().t;
	while (!min2.empty())
	{
		index += min2.top().f;
		cout << min2.top().a<<" "<< index<< endl;
		min2.pop();
	}
}
~~~



