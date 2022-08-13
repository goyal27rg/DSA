#include <iostream>
using namespace std;
long long toh(int N, int from, int to, int aux) {
    //Your code here
    if (N==1)
        {
            printf("move disk %d from rod %d to rod %d\n", N, from, to);
            return 1;
        }
    
    long long moves = toh(N-1, from, aux, to);
    printf("move disk %d from rod %d to rod %d\n", N, from, to);
    moves += 1 + toh(N-1, aux, to, from);
    return moves;
}

int main() {
    cout << endl << toh(3, 1, 2, 3);
}