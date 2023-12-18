#include <fstream>
#include <queue>

using namespace std;

ifstream fin("cifre4.in");
ofstream fout("cifre4.out");

bool solve(int n, int p) {
    queue<long long>q;
    vector<bool>vis(p, false);
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    while(!q.empty()) {
        long long x = q.front();
        q.pop();
        
        if(!vis[x % p]) {
            vis[x % p] = true;
            if (x % p == n) {
                fout << x << '\n';
                return 1;
            }

            q.push(x * 10 + 2);
            q.push(x * 10 + 3);
            q.push(x * 10 + 5);
            q.push(x * 10 + 7);
        }
    }
    return 0;
}

int main() {
    int n, p, k;

    fin >> k;
    for(int i = 0; i < k; ++i) {
        fin >> n >> p;
        if(!solve(n, p))
            fout << "-1\n";
    }
    return 0;
}