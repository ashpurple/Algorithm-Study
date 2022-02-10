# 조합(DFS), 완전 탐색

1. 부분 집합(조합) 구현
```C++
if(idx == half){
		mp[sum]++;
		return;
	}
	left(idx + 1, sum);
	left(idx + 1, sum + num[idx]);
``` 
    `O(2^N)`으로 N이 작을 때만 사용가능

2. 배열 반으로 나누기
N = 40 일때는 조합 알고리즘 사용불가<br>
배열을 반으로 쪼개어 N=20에서 구현
- map[sum]으로 부분합의 개수를 카운트
- cnt += map[S - sum]으로 최종 부분수열의 개수 카운트