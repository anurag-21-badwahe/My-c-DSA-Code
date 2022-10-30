#include<iostream>
using namespace std;
int  fibo(int n)
{
  if(n <= 1)
  {
    return n;
  }

  int ans = fibo(n-1) + fibo(n-2);
  return ans;
}


int main()
{
    int n;
    cout << "ENTER THE TERM YOU WANT IN FIBO SERIES:-";
    cin >> n;
    cout << fibo(n) << " ";
}