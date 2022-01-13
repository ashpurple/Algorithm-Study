# LCS (Longest Common Substring)

Substring vs Subsequence

![image](https://user-images.githubusercontent.com/75887645/149322885-07903847-1659-4a52-9d27-cf7852c93b0c.png)

## DP를 이용한 구현
1. margin이 있는 2차원 dp를 생성한다 (0으로 초기화)
2. 2중 for문을 이용해 한글자씩 비교 후 두 글자가 다르다면 0을 표시
3. 두문자가 같다면 `dp[i][j] = dp[i-1][j-1] + 1` (왼쪽 대각선위)
4. 2,3 번 반복 후 dp 배열 중 최대값이 lcs 값이다 

시간복잡도: `O(MN)`

![image](https://user-images.githubusercontent.com/75887645/149323688-e1c3bec7-8516-4bc1-bf5f-ba5a1145284b.png)

# LCS (Longest Common Subsequence)

## DP를 이용한 구현
1. margin이 있는 2차원 dp를 생성한다 (0으로 초기화)
2. 2중 for문을 이용해 한글자씩 비교 후 두 글자가 다르면 `dp[i][j] = max(dp[i-1][j], dp[i][j-1]` (왼쪽 위쪽 중의 큰값)
3. 두문자가 같다면 `dp[i][j] = dp[i-1][j-1] + 1` (왼쪽 대각선위 + 1)
4. 2,3 번 반복 후 dp 배열 중 마지막 값이 lcs 값이다
시간복잡도: `O(MN)`

## LCS Substring 값 찾기
- 같은 길이를 가진 부분문자열이 여러개 나올 수 있다
- 행렬 끝의 lcs 값부터 탐색을 시작한다
- 위, 왼쪽 값이 자신과 같으면 위 또는 왼쪽으로 이동한다
- 위, 왼쪽 값이 자신과 다르면 왼쪽 대각선 위로 이동히며 스택에 문자를 넣는다
- 0이 나오면 탐색을 멈추고 스택을 반환한다
- 삽입 역순으로 스택값을 출력한다

![image](https://user-images.githubusercontent.com/75887645/149324469-f93f9194-7b66-4158-b308-3bf7daebc923.png)
