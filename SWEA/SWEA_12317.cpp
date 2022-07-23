int tree[101][6];
int childNum[101];
int king, root;

void dfs_init(int N, int path[100][2])
{   
    for(int i = 1; i < 101; i++){
        childNum[i] = 0;
        for(int j = 0; j < 6; j++){
            tree[i][j] = 0;
        }
    }
    for(int i = 0; i < N - 1; i++){
        int parent = path[i][0];
        int child = path[i][1];
        tree[parent][childNum[parent]++] = child;
    }
    
}
  
int findKing(int n)
{   
    if(n > king){
        king = n;
        return king;
    }
    int i = 0;
    int ans = -1;
    while(tree[n][i]){
        if(king > root) return king;
        int next = findKing(tree[n][i]);
        if(next > ans) ans = next;
        i++;
    }
	return ans;
}

int dfs(int n){
    king = n;
    root = n;
    return findKing(n);
}


