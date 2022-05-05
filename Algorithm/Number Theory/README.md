# Number Theory (정수론)

## GCD (최대 공약수)
[유클리드 호제법]
1. 큰수를 작은 수로 MOD 연산을 반복힌다
2. 나머지가 0이 됐을 때 큰 수가 GCD가 된다
=> `O(lgN)`

## LCM (최소 공배수)
GCD를 이용해 구할 수 있다<br>`a * b / gcd(a, b)`
