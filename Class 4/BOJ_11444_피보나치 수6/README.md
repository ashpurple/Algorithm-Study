# 수학, 분할정복

<피보나치 점화식의 행렬 표현>

![image](https://user-images.githubusercontent.com/75887645/150720915-0cc370f1-3e27-4087-aa79-81b784a2f583.png)
![image](https://user-images.githubusercontent.com/75887645/150720923-e01b4857-eb26-490f-b4e9-87f297ef2128.png)

즉 위의 행렬식을 이용해 최종 값을 찾으면 `O(lgN)`번의 행렬곱을 통해 답을 구할 수 있다

단 계산을 빠르게 하기 위해 N이 짝수 일때는 n/2 로 분할하여 계산한다

ex) mat^8 = mat^4 * mat^2 * mat * mat

