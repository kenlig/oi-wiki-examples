#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define int long long
#define maxn 500001
struct Tree
{
	int l, r, w, f;
} tree[maxn << 2];
int n, m, ans, a[maxn];
inline void down(int k)
{
	tree[k << 1].f += tree[k].f;
	tree[k << 1 | 1].f += tree[k].f;
	tree[k << 1].w += tree[k].f * (tree[k << 1].r - tree[k << 1].l + 1);
	tree[k << 1 | 1].w += tree[k].f * (tree[k << 1 | 1].r - tree[k << 1 | 1].l + 1);
	tree[k].f = 0;
}
inline void build(int k, int ll, int rr)
{
	tree[k].l = ll;
	tree[k].r = rr;
	if (ll == rr)
	{
		tree[k].w = a[ll];
		return;
	}
	int mid = (ll + rr) / 2;
	build(k << 1, ll, mid);
	build(k << 1 | 1, mid + 1, rr);
	tree[k].w = tree[k << 1].w + tree[k << 1 | 1].w;
}
void add(int k, int ll, int rr, int v)
{
	if (tree[k].l >= ll && tree[k].r <= rr)
	{
		tree[k].w += (tree[k].r - tree[k].l + 1) * v;
		tree[k].f += v;
		return;
	}
	if (tree[k].f)
		down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if (ll <= mid)
		add(k << 1, ll, rr, v);
	if (mid < rr)
		add(k << 1 | 1, ll, rr, v);
	tree[k].w = tree[k << 1].w + tree[k << 1 | 1].w;
}
void query(int k, int ll, int rr)
{
	if (tree[k].l >= ll && tree[k].r <= rr)
	{
		ans += tree[k].w;
		return;
	}
	if (tree[k].f)
		down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if (ll <= mid)
		query(k << 1, ll, rr);
	if (rr > mid)
		query(k << 1 | 1, ll, rr);
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int opt, x, y, k;
		scanf("%lld", &opt);
		if (opt == 1)
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			add(1, x, y, k);
		}
		if (opt == 2)
		{
			scanf("%lld%lld", &x, &y);
			query(1, x, y);
			printf("%lld\n", ans);
			ans = 0;
		}
	}
	return 0;
}