# 침투
| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :---: | :-----: | :-----: | :-----: | :-----: | :-------: |
| 1 초 | 512 MB | 3987 | 1729 | 1288 | 44.552% |

## 문제
인제대학교 생화학연구실에 재직중인 석교수는 전류가 침투(percolate) 할 수 있는 섬유 물질을 개발하고 있다. 이 섬유 물질은 2차원 M × N 격자로 표현될 수 있다. 편의상 2차원 격자의 위쪽을 바깥쪽(outer side), 아래쪽을 안쪽(inner side)라고 생각하기로 한다. 또한 각 격자는 검은색 아니면 흰색인데, 검은색은 전류를 차단하는 물질임을 뜻하고 흰색은 전류가 통할 수 있는 물질임을 뜻한다. 전류는 섬유 물질의 가장 바깥쪽 흰색 격자들에 공급되고, 이후에는 상하좌우로 인접한 흰색 격자들로 전달될 수 있다.

김 교수가 개발한 섬유 물질을 나타내는 정보가 2차원 격자 형태로 주어질 때, 바깥쪽에서 흘려 준 전류가 안쪽까지 침투될 수 있는지 아닌지를 판단하는 프로그램을 작성하시오.

그림 확인 : https://www.acmicpc.net/problem/13565

예를 들어, Figure 1(a) 에서는 바깥쪽에서 공급된 전류가 안쪽까지 침투하지만, Figure 1(b)에서는 그렇지 못한다.

## 입력
첫째 줄에는 격자의 크기를 나타내는  M (2 ≤ M ≤ 1,000) 과 N (2 ≤ N ≤ 1,000) 이 주어진다. M줄에 걸쳐서, N개의 0 또는 1 이 공백 없이 주어진다. 0은 전류가 잘 통하는 흰색, 1은 전류가 통하지 않는 검은색 격자임을 뜻한다.

## 출력
바깥에서 흘려준 전류가 안쪽까지 잘 전달되면 YES를 출력한다.

그렇지 않으면 NO를 출력한다.

## 예제
| 입력 | 출력 |
| -------- | --- |
| 5 6<br/>010101<br/>010000<br/>011101<br/>100011<br/>001011 | NO |
| 8 8<br/>11000111<br/>01100000<br/>00011001<br/>11001000<br/>10001001<br/>10111100<br/>01010000<br/>00001011 | YES |