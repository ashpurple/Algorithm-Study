# 자료구조 set

교집합을 구현하는 문제이다.

set은 원소를 넣을 때맏 자동으로 정렬되어 들어가므로 따로 정렬이 불필요했다.

교집합은 STL의 set_intersection 으로 구현하였다.
```
for(set<string>::iterator it = s3.begin(); it != s3.end(); it++){
        cout << *it << '\n';
    }
```
출력은 위와 같이 iterator을 활용하였다.