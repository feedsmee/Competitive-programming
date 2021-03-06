struct DSU {
  vector<int> par, size;
  int CC;
  DSU(int n) {
    CC = n;
    par.resize(n + 1);
    size.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);
  }
  int root(int a) { return par[a] == a ? a : par[a] = root(par[a]); }
  void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);

    par[b] = a;
    size[a] += size[b];
    --CC;
  }
  bool same(int a, int b) { return root(a) == root(b); }
};
