#include <bits/stdc++.h>
using namespace std;

#define LEFT 5
#define RIGHT 8
#define MAXN 10
#define K 25

int st[K + 1][MAXN];
vector<int> arr = {1, 2, 3, 4, 4, 16, 4, 32, 64, 16};

int log2_floor(unsigned long i) {
    return std::bit_width(i) - 1;
}

int f(int x, int y) {
    /*
    Some generic idempotent function
    */
    return (x < y) ? x : y;
}

int gcd(int x, int y) {
    /*
    Gets gcd using the euclidean algorithm
    */
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    return x;
}

int main() {
    #ifdef NOT_DMOJ
    freopen("data.txt", "r", stdin);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);

    // Initialize st[0] with arr
    for (int j = 0; j < arr.size(); j++) {
        st[0][j] = arr[j];
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= arr.size(); j++) {
            st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    int L = LEFT, R = RIGHT;
    int i = log2_floor(R - L + 1);
    int minimum = gcd(st[i][L], st[i][R - (1 << i) + 1]);
    cout << "GCD from " << LEFT << " to " <<  RIGHT << ": " << minimum << '\n';
}