#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// @brief 高精度除法s
/// @param A of high precision int
/// @param B of int
/// @param r 回传余数
/// @return C = A / B
vector<int> div(vector<int> A, int B , int &r )
{
    vector<int> C;
    // int t = 0;
    for (int i = A.size() - 1; i >= 0; --i)
    {
        r = 10 * r + A[i];
        C.push_back(r / B);
        r %= B ;
    }
    reverse(C.begin(),C.end());
    while(C.back()==0) C.pop_back();
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
    int r = 0;
    auto C = div(A, B, r);

    for (int i = C.size() - 1; i >= 0; --i)
    {
        printf("%d", C[i]);
    }
    cout<<endl<<r;
    return 0;
}