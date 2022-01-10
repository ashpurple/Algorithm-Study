int root[1000001];

int find(int x) {
    if (root[x] == x) {
        return x;
    } 
    else {
        // "경로 압축(Path Compression)"
        return root[x] = find(root[x]); 
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    root[y] = x;
}