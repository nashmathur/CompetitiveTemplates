ll parent[MAXN];
ll sizeRank[MAXN];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

//run this for the entire array
void make_set(ll v) {
    parent[v] = v;
    sizeRank[v] = 0;
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizeRank[a] < sizeRank[b])
            swap(a, b);
        parent[b] = a;
        if (sizeRank[a] == sizeRank[b])
            sizeRank[a]++;
    }
}