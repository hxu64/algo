// partial sum test

#include <bits/stdc++.h>
using namespace std;

int N, M, L, R, delta, k;
char c;
vector<int> v, change;

// N: size of array
// N integers
// M: number of queries
// I a b c: increase elements from index a to b by c
// P: print the modified array

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    v.resize(N + 1, 0);
    cout << "original array\n";
    for(int i=0;i<N;i++){
        cin >> v[i];
        cout << v[i] << ' ';
    }
    cout << '\n';
    change.resize(N + 1, 0);
    
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> c;
        if(c == 'I'){
            cin >> L >> R >> delta;
            cout << "increased " << L << " to " << R << " by " << delta << '\n';
            change[L] += delta;
            change[R + 1] -= delta;
        }else{
            cout << "print query\n";
            k = 0;
            for(int j=0;j<N;j++){
                k += change[j];
                cout << v[j] + k << ' ';
            }
            cout << '\n';
        }
    }
}