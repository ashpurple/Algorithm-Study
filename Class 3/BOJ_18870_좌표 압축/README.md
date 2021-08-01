# map을 활용한 중복 제거

중복을 피해 value를 기준으로 정렬하고 그에 맞는 index를 출력하는 문제이다. <br>
먼저 입력을 받아 key 값을 기준으로 정렬을 해준 뒤 중복을 제거해주었다.<br>
중복 제거는 `vector.erase(unique(vector.begin(), vector.end()), vector.end())` 구문을 이용하였다.<br>
그 다음 map의 key값을 정렬된 vector 값으로 하고 value 값을 index를 주었다. <br>
마지막 출력 부분은 반대로 `map[vector[i]]` 와 같이 key값으로 index 값을 찾아 주었다.