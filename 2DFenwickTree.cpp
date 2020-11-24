#include <bits/stdc++.h>

using namespace std;

struct Fenwick2D {
	int n, m;
	vector<vector<int>> tree;
	void Init(vector<vector<int>>& vec) {
		n = vec.size() + 1;
		m = vec[0].size() + 1;
		tree.resize(n, vector<int>(m));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				update(i, j, vec[i-1][j-1]);
	}

	void update(int x, int y, int diff) {
		while (x < n) {
			int ty = y;
			while (ty < m) {
				tree[x][ty] += diff;
				ty += (ty & -ty);
			}
			x += (x & -x);
		}
	}

	int query(int x, int y) {
		int ans = 0;
		while (x > 0) {
			int ty = y;
			while (ty > 0) {
				ans += tree[x][ty];
				ty -= (ty & -ty);
			}
			x -= (x & -x);
		}
		return ans;
	}
	int query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1-1, y1-1);
	}
};