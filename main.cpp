#include <iostream>
#include <vector>
#include <map>

using namespace std;

int x, y, cx, cy, dx, dy, n;

map<pair<int, int>, vector<pair<int, int>>> G;
map<pair<int, int>, int> Paths;

pair<int, int> current, dest, final, source;

void visit(pair<int, int> arg) {
    if(G[arg].empty()) {
        if (arg == final)
            Paths[arg] = 1;
        else
            Paths[arg] = 0;
    }
    for (auto k: G[arg]) {
        auto status = Paths.find(k);
        if (status != Paths.end()) {
            Paths[arg] = (Paths[arg] + Paths[k]) % 999979;
        } else {
            visit(k);
            Paths[arg] = (Paths[arg] + Paths[k]) % 999979;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);

    cin >> x;
    cin >> y;
    cin >> n;

    final = pair(x, y);
    source = pair(0, 0);

    for(int i = 0; i < n; i++) {
        cin >> cx;
        cin >> cy;
        cin >> dx;
        cin >> dy;

        current = pair(cx, cy);
        dest = pair(dx, dy);

        G[current].push_back(dest);
    }

    visit(source);

    cout << Paths[source];
    return 0;
}