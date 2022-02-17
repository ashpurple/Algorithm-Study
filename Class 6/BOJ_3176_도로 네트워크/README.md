# LCA

LCA의 기본 구조에 최대거리와 최대거리를 저장하는 dp배열 두개를 만듬으로써 구현할 수 있습니다

점화식
```C++
minimum = min(minimum, min(shortest[i][y], shortest[i][x]));
maximum = max(maximum, max(longest[i][y], longest[i][x]));
```
기존 dp와 같은 인덱스에 접근해 점화식을 활용했습니다
