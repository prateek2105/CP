struct SegTree {
    int n;
    vector<long long> tree;
    // to use, update the operation function(line 10) and default value(line 31)
    SegTree(const vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    long long opn(long long a, long long b){
      return a+b; // type of operation
    }
    long long merge(long long a, long long b) {
        return opn(a, b);
    }

    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // query gcd on range [ql, qr]
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;  // returns default value
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return merge(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
void solve(int tc){
  vector<int> vec = {1,2,3,4,5};
  SegTree st(vec);
  cout<<st.query(0,1)<<endl; // prints (vec[0] + vec[1])
}
