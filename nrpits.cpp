#include <fstream>
#include <stack>

using namespace std;

ifstream fin("nrpits.in");
ofstream fout("nrpits.out");

int main() {
    int n, x, nrPits = 0;
    stack<int>st;

    fin >> n;
    for(int i = 0; i < n; ++i) {
        fin >> x;
        while(!st.empty() && st.top() <= x) {
            if(st.size() > 1)
                ++nrPits;
            st.pop();
        }
        st.push(x);
    }
    fout << nrPits << '\n';
    return 0;
}