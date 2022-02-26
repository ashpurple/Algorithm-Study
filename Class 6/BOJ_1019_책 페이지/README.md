# 수학

수학적 풀이를 참고하여 구현하였다

[알고리즘]
- start = 1, end = N 으로 초기화한 뒤 start와 end 값을 늘이고 줄여가며 카운트한다
- start는 끝자리가 0, end는 끝자리가 9가 될때까지 값을 변화시키며 `count(num)`해준다
- 조건을 만족하면 start와 end를 10으로 나눈 뒤 다음 식을 적용한다
```C++
        int diff = end - start + 1;
        for(int i = 0; i < 10; i++) cnt[i] += diff * digit;
```
=> 한번에 count 해줌으로써 불필요한 연산을 줄일 수 있다

[count 함수]
```C++
void count(int n){
    while(n > 0){
        cnt[n % 10] += digit;
        n /= 10;
    }
}
```
