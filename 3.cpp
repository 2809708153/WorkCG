#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
struct state {
    int A, B;
    string seq;
    state(int m, int n, string s) : A(m), B(n), seq(s) {}
};

void bfs(int Ca, int Cb, int N) {
    vector<string> actions = { "Fill A", "Fill B", "Empty A", "Empty B", "Pour A B", "Pour B A" };
    queue<state> q;
    q.push(state(0, 0, ""));
    unordered_set<string> visited;
    visited.insert("0 0");
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (cur.B == N) {
            cout << cur.seq << "Success" << endl;
            return;
        }
        for (int i = 0; i < 6; i++) {
            int next_A = cur.A, next_B = cur.B;
            string next_seq = cur.seq + actions[i] + "\n";
            switch (i) {
            case 0: next_A = Ca; break; // Fill A
            case 1: next_B = Cb; break; // Fill B
            case 2: next_A = 0; break;  // Empty A
            case 3: next_B = 0; break;  // Empty B
            case 4: {                   // Pour A B
                int amount = min(cur.A, Cb - cur.B);
                next_A = cur.A - amount;
                next_B = cur.B + amount;
                break;
            }
            case 5: {                   // Pour B A
                int amount = min(cur.B, Ca - cur.A);
                next_A = cur.A + amount;
                next_B = cur.B - amount;
                break;
            }
            }
            if (visited.count(to_string(next_A) + " " + to_string(next_B)) == 0) {
                visited.insert(to_string(next_A) + " " + to_string(next_B));
                q.push(state(next_A, next_B, next_seq));
            }
        }
    }
}
int main() {
    int Ca, Cb, N;
    cin >> Ca >> Cb >> N;
    bfs(Ca, Cb, N);
    return 0;
}