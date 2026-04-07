#include <bits/stdc++.h>
using namespace std;

// Fast input using fread buffer
struct FastInput {
    static const size_t BUFSIZE = 1 << 20; // 1 MiB
    int idx, size;
    char buf[BUFSIZE];
    FastInput(): idx(0), size(0) {}
    inline char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    template<typename T>
    bool nextInt(T &out) {
        char c; T sign = 1; T x = 0;
        c = read();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = read();
            if (!c) return false;
        }
        if (c == '-') { sign = -1; c = read(); }
        for (; c >= '0' && c <= '9'; c = read()) x = x * 10 + (c - '0');
        out = x * sign;
        return true;
    }
} In;

struct SegTree {
    int n;
    vector<int> mx;      // maximum on interval
    vector<int> lazy;    // lazy addition
    SegTree(int n_=0): n(n_) {
        if (n > 0) {
            mx.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }
    }
    inline void apply(int p, int val) {
        mx[p] += val;
        lazy[p] += val;
    }
    inline void push(int p) {
        if (lazy[p] != 0) {
            int v = lazy[p];
            apply(p<<1, v);
            apply(p<<1|1, v);
            lazy[p] = 0;
        }
    }
    inline void pull(int p) {
        mx[p] = max(mx[p<<1], mx[p<<1|1]);
    }
    void range_add(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(p, val);
            return;
        }
        push(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) range_add(p<<1, l, mid, ql, qr, val);
        if (qr > mid)  range_add(p<<1|1, mid+1, r, ql, qr, val);
        pull(p);
    }
    int range_max(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return mx[p];
        push(p);
        int mid = (l + r) >> 1;
        int ans = INT_MIN;
        if (ql <= mid) ans = max(ans, range_max(p<<1, l, mid, ql, qr));
        if (qr > mid)  ans = max(ans, range_max(p<<1|1, mid+1, r, ql, qr));
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, k, p;
    if (!In.nextInt(x)) return 0;
    In.nextInt(k);
    In.nextInt(p);

    // Number of segments between stations is x-1
    int segN = max(0, x - 1);
    SegTree st(segN > 0 ? segN : 1);

    // Buffered output
    static const int OUT_BUFSZ = 1 << 20;
    static char outbuf[OUT_BUFSZ];
    int out_idx = 0;
    auto out_ch = [&](char c){ if (out_idx < OUT_BUFSZ) outbuf[out_idx++] = c; else { fwrite(outbuf,1,out_idx,stdout); out_idx=0; outbuf[out_idx++] = c; } };

    for (int i = 0; i < p; ++i) {
        int u, v, n;
        In.nextInt(u); In.nextInt(v); In.nextInt(n);
        if (u >= v || segN == 0) {
            // Zero-length trip uses no seat segments; always satisfied
            out_ch('T'); out_ch('\n');
            continue;
        }
        int L = u;         // segment indices are [1, x-1], mapping [u, v-1]
        int R = v - 1;
        if (L < 1) L = 1;
        if (R > segN) R = segN;
        int current_max = st.range_max(1, 1, segN, L, R);
        if (current_max <= k - n) {
            st.range_add(1, 1, segN, L, R, n);
            out_ch('T');
        } else {
            out_ch('N');
        }
        out_ch('\n');
    }

    if (out_idx) fwrite(outbuf, 1, out_idx, stdout);
    return 0;
}

