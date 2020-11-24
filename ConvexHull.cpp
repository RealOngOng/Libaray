#include <bits/stdc++.h>

using namespace std;

struct CHT {
	int n;
	vector<int> la, lb;

	void Init(int _n) {
		n = _n;
		la.resize(n + 1), lb.resize(n+1);
	}

	double cross(int x, int y) { return (double)(lb[y] - lb[x]) / (la[x] - la[y]); }

	int now, sz;
	void add(int a, int b) {
		la[sz] = a, lb[sz] = b;

		while (sz > 1 && cross(sz - 2, sz - 1) > cross(sz - 1, sz)) {
			la[sz - 1] = la[sz];
			lb[sz - 1] = lb[sz];
			sz--;
		}
		sz++;
	}

	int query(int x) {
		int lo = 0, hi = sz - 1;
		while (lo != hi) {
			int mid = (lo + hi) / 2;
			if (cross(mid, mid + 1) <= x) lo = mid + 1;
			else hi = mid;
		}

		return la[lo] * x + lb[lo];
	}
};