#include <iostream>
#include <vector>

using namespace std;

vector<bool> used{};
vector<int> now{};

void solve(int N, int M) {
    if (0 == M) {
        for (const auto& v : now)
        {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (used[i])
            continue;

        now.push_back(i);
        used[i] = true;

        solve(N, M - 1);

        now.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    used = vector<bool>(N+1, false);

    solve(N, M);

    return 0;
}