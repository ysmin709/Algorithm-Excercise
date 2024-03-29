# 트리의 기둥과 가지
| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| :-----: | :-----: | :-----: | :-----: | :----: | :-------: |
| 2.5 초 | 1024 MB | 772 | 262 | 209 | 34.950% |

## 문제
그림 확인 : https://www.acmicpc.net/problem/20924

시청 공무원 마이크로는 과장으로부터 시에 있는 나무의 기둥의 길이와 가장 긴 가지의 길이를 파악하라는 업무 지시를 받았다.

마이크로는 ICPC Sinchon Winter Algorithm Camp에서 배운 트리 자료 구조를 이용하면 이 작업을 좀 더 수월하게 할 수 있으리라 판단했다. 

마이크로는 트리의 기둥과 가지를 분류하기 위해 기가 노드를 추가로 정의하였다.

기가 노드는 루트 노드에서 순회를 시작했을 때, 처음으로 자식 노드가 $2개 이상인 노드다. 기둥-가지를 줄여 기가 노드라 이름 붙였다. 위 그림에서 기가 노드는 4번 노드다.

단, 위 그림과 같이 리프 노드가 단 1개인 경우 리프 노드가 동시에 기가 노드가 된다.

또한, 위 그림과 같이 루트 노드가 동시에 기가 노드인 경우도 가능하다.

트리의 기둥은 루트 노드에서부터 기가 노드까지다. 위 그림에서 기둥은 1-2-3-4 이다.
기둥의 길이는 기둥의 간선 길이의 합인 1 + 2 + 3 = 6이 된다.
트리의 가지는 기가 노드에서부터 임의의 리프 노드까지다. 위 그림에서 가지는 4-5-6-7, 4-5-8, 4-9, 4-10-11, 4-10-12 총 $5$개가 있다.
가지의 길이는 가지의 간선 길이의 합이다. 다행히도 가장 긴 가지의 길이 하나만 기재하면 된다. 4-10-12 가지가 간선 길이의 합 3 + 3 = 6 으로 가장 긴 가지이다.
마이크로는 시의 나무를 트리 자료 구조로 옮겼다. 그런데 과장이 마이크로에게 또 다른 업무를 지시했다! 너무 바쁜 마이크로를 대신해 트리의 기둥과 가장 긴 가지의 길이를 측정하자.

## 입력
입력 확인 : https://www.acmicpc.net/problem/20924

트리가 아닌 그래프는 입력으로 주어지지 않는다.

## 출력
나무의 기둥의 길이와 가장 긴 가지의 길이를 출력한다.

## 예제
| 입력 | 출력 |
| -------- | ----- |
| 12 1<br/>1 2 1<br/>2 3 2<br/>3 4 3<br/>4 5 1<br/>5 6 2<br/>6 7 1<br/>5 8 1<br/>4 9 2<br/>4 10 3<br/>10 11 1<br/>10 12 3 | 6 6 |
| 9 1<br/>1 2 5<br/>2 3 4<br/>3 4 2<br/>2 5 5<br/>1 6 8<br/>1 7 6<br/>7 8 7<br/>7 9 1 | 0 13 |
| 4 1<br/>1 2 100<br/>2 3 10<br/>3 4 1 | 111 0 |
| 1 1 | 0 0 |