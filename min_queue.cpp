#include <bits/stdc++.h>

using namespace std;

stack <pair<int, int>> s1, s2; // s1 for adding new ele, s2 for removing eles
int getMin(){
    /*
    Assumes that at least 1 element exists in the 'queue'.
    The min must be either of the newest or oldest .second
    */
    if(s1.empty()){
        cout << s2.top().second << '\n';
        return s2.top().second;
    }else if(s2.empty()){
        cout << s1.top().second << '\n';
        return s1.top().second;
    }
    cout << min(s1.top().second, s2.top().second) << '\n';
    return min(s1.top().second, s2.top().second);
}

void addEle(int x){
    /*
    If s1 is empty, then assume the item is min, unless the current top has a smaller min
    This is fine, because we will check against the previous items in s2 in getMin
    */
    int minimum;
    if(s1.empty()){
        minimum = x;
    }else{
        minimum = min(x, s1.top().second);
    }
    s1.push(make_pair(x, minimum));
    cout << "Added: " << x << '\n';
}

int removeEle(){
    /*
    If s2, the remove stack, is empty, all items are moved from s1 to s2
    In doing so, the order is inverted, similar to an actual queue
    c       a
    b   ->  b
    a       c
    a was last in, and will still be the first one out
    The minimum is computed, between item to be added to s2 and the top of s2
    */
    if(s2.empty()){
        while(!s1.empty()){
            int element = s1.top().first;
            s1.pop();
            int minimum;
            if(s2.empty()){
                minimum = element;
            }else{
                minimum = min(element, s2.top().second);
            }
            s2.push(make_pair(element, minimum));
        }
    }
    int res = s2.top().first;
    s2.pop();
    cout << "Removed: " << res << '\n';
    return res;
}

int main()
{
    addEle(3);
    addEle(4);
    addEle(5);
    getMin();
    addEle(1);
    getMin();

    return 0;
}
