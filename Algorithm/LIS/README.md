# LIS (최장 증가 부분수열)

최장 증가 부분 수열이란 인덱스 순으로 부분 수열을 구성해 나갈 때 가장 긴 길이를 가진 증가하는 수열을 뜻한다. <br>
LIS의 길이를 완전 탐색으로 찾는다면 `O(2^N)`의 시간이 걸리므로 완전 탐색은 불가능하다.

## 1. DP를 이용한 방법
lis는 길이가 더 작은 증가 부분 수열의 집합으로 이루어져있다.<br>
따라서 dp[i] 를 i번쨰 수를 마지막 원소로 가지는 lis의 길이로 정의하면 완전 탐색에서 중복 연산을 피할 수 있다.<br>

![longest_increasing_subsequence_tabulation](https://user-images.githubusercontent.com/75887645/127164655-eed5ac52-34b8-451c-8711-ece1603f0ed8.gif)


### 알고리즘
arr[i] 는 끝값 arr[j]는 비교 값이다
- dp[i] = 1 로 초기화 한다.
- arr[j] < arr[i] 일 경우 증가 수열이다.
- 동시에 dp[i] < dp[j] + 1 를 만족하면 dp[i] 를 dp[j] + 1로 업데이트 한다 (이전 연산 + 1)

위 알고리즘의 시간복잡도는 `O(N^2)`으로 크기가 적당한 input이 주어질 땐 위와 같은 dp로 해결이 가능하다.

## 2.이분탐색을 이용한 방법
LIS를 저장하는 벡터를 생성해 이분탐색으로 벡터를 갱신시키는 방법이다<br>
벡터의 크기가 LIS의 길이이며 벡터의 요소는 LIS 중 하나이다<br>
* 단 해당 코드에서는 `vector.size() - 1`이 LIS 이다 (초기값 0을 삽입하기 때문)

![image](https://user-images.githubusercontent.com/75887645/152678576-e6c02a86-72d6-4eea-89e9-df5f5a1b4e3c.png)

### 알고리즘
- vector[0]을 가장 작은 수로 초기화한다
- 탐색을 진행하며 벡터의 끝값과 비교한다
  - 배열값이 벡터의 끝값보다 클 떄: 벡터 맨 뒤에 삽입
  - 배열값이 벡터의 끝값보다 작을 때: lowerbound로 벡터값을 배열값으로 교체

장점
- N번의 이분탐색을 사용하기 때문에 `O(NlgN)`의 시간복잡도를 가진다
- 이는 인덱스트리와 시간복잡도가 같지만 코드가 간결한 것이 장점이다

주의점
- lis 수열을 찾는것은 보장하지 않는다
- vector의 item은 lis가 아니므로 lis를 구하고 싶을 때는 dp와 stack을 추가로 사용해야한다
-> 해당 문제 참고 [가장 긴 증가하는 부분수열 5](https://github.com/ashpurple/Algorithm-Study/tree/main/Class%205/BOJ_14003_%EA%B0%80%EC%9E%A5%20%EA%B8%B4%20%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%20%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B45)
  
