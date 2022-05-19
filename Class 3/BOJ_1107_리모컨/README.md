# Bruteforce

완전 탐색으로 해결하였다<br>
먼저 초기 채널번호가 100이므로 100에서 +-로 이동가능한 경우를 abs(N-100)로 초기화 하였고<br>
이를 1부터 10만번 채널 중 유효한 채널에서 +-로 이동가능한 경우와 비교해주었다<br>
굳이 복잡한 최적화 없이도 해결할 수 있는 문제이다

```C++
if (isPossible(str, size)) {
		int temp = abs(N - i) + size;
		ans = min(ans, temp);
	}
```
