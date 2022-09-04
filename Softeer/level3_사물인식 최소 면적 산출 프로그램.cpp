#include<iostream>
#include<vector>
using namespace std;
struct Point{
	int x; int y;
};
int N, K;
vector<Point> points[1000];
int ans = 1987654321;

void dfs(int minX, int minY, int maxX, int maxY, int cnt){
    if(cnt == K){
		int area = (maxX - minX) * (maxY - minY);
        ans = min(ans, area);
        return;
	}

    for (Point point : points[cnt]){
		int x1 = min(point.x, minX);
		int x2 = max(point.x, maxX);
		int y1 = min(point.y, minY);
		int y2 = max(point.y, maxY);

        int area = (x2 - x1) * (y2 - y1);
        if(area < ans){ // pruning
			dfs(x1, y1, x2, y2, cnt + 1);
		}
	}
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for(int i = 0; i < N; i++){
		int x, y, c;
		cin >> x >> y >> c;
		points[c - 1].push_back({x, y});
	}

	for(Point point: points[0]) dfs(point.x, point.y, point.x, point.y, 1);

	cout << ans;
	return 0;
}