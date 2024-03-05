#include <bits/stdc++.h>
using namespace std;


bool Recur(vector <int> postorder, int i, int j) {
    if (i >= j) 
        return true;
    int p = i;
    while (postorder[p] < postorder[j]) 
        p++;
    int m = p;
    while (postorder[p] > postorder[j]) 
        p++;
    return p == j && Recur(postorder, i, m - 1) && Recur(postorder, m, j - 1);
}
int main() {
    vector <int> arr;
    int x;
    char ch;
    while (1) {
        cin >> x;
        arr.push_back(x);
        ch = getchar();
        if (ch == '\n')
            break;
    }
    if (Recur(arr, 0, (int)arr.size() - 1))
        cout << "true";
    else
        cout << "false";
    return 0;
}


