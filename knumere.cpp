#include <fstream>
#include <queue>
#include <climits>

using namespace std;

ifstream fin("knumere.in");
ofstream fout("knumere.out");

vector<int> v, dif;
deque<int> dq;

int main() {
    int n, k, res;

    fin >> n >> k;

    v.resize(n + 1);
    dif.resize(n + 1);
    res = 2e9;

    for(int i = 1; i <= n; ++i) {
        fin >> v[i];
        if(i > 1) {
            dif[i - 1] = v[i] - v[i - 1];
        }
    }

    for(int i = 1; i < n; i++) {
        while(!dq.empty() && dif[i] >= dif[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if(dq.front() <= i - (n - k - 1))
            dq.pop_front();

        if(i >= n - k - 1 && dif[dq.front()] < res)
            res = dif[dq.front()];
    }
    fout << res << endl;
    return 0;
}