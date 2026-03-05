#include <iostream>

using namespace std;

const int N = 10010;
int h[N],e[N],ne[N]; //头节点,模拟链表
int idx = 0;//数组存储头指针

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;//头插法
}

int main()
{

}