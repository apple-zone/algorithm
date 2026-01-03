#include <iostream>
#include <vector>
using namespace std;

/// @brief 高精度整数乘整数
/// @param A of High precision
/// @param B of Int
/// @return C = A * B
vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size()||t; ++i)//结合两个循环（乘和处理高进位
    {
        if(i<A.size())t += A[i]*B;
        C.push_back(t%10);
        t /= 10;
    }
    return C;
}

int main()
{
    vector<int> A;
    string a;
    int B;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');
    auto C = mul(A, B);

    for (int i = C.size() - 1; i >= 0; --i)
    {
        printf("%d", C[i]);
    }
    return 0;
}
