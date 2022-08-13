#include<iostream>
#include<math.h>
using namespace std;

long reverse(int n, int R=0)
    {
        if (n==0) return R;
       
       return reverse(n/10, 10*R+(n%10));
    }
long int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
}
int main()
{
    int x = 12;
    cout << power(2,5) << endl;
    cout << reverse(x) << endl;
    cout << (long long) power(x, reverse(x)) % 1000000007 << endl;
    //cout << 9223372036854775807 % 1000000007;
}