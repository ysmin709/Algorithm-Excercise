# 단어 뒤집기 2
| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| :---: | :-----: | :-----: | :-----: | :----: | :-------: |
| 1 초 | 512 MB | 13420 | 7581 | 5836 | 56.809% |

## 문제
문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.

먼저, 문자열 S는 아래와과 같은 규칙을 지킨다.

- 알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
- 문자열의 시작과 끝은 공백이 아니다.
- '<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.

태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다. 단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다. 태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.

## 입력
첫째 줄에 문자열 S가 주어진다. S의 길이는 100,000 이하이다.

## 출력
첫째 줄에 문자열 S의 단어를 뒤집어서 출력한다.

## 예제
| 입력 | 출력 |
| -------------------------- | ------------------------- |
| baekjoon online judge | noojkeab enilno egduj |
| < open>tag< close> | < open>gat< close> |
| < ab cd>ef gh< ij kl> | < ab cd>fe hg< ij kl> |
| one1 two2 three3 4fourr 5five 6six | 1eno 2owt 3eerht rruof4 evif5 xis6 |
| < int>< max>2147483647< long long>< max>9223372036854775807 | < int>< max>7463847412< long long>< max>7085774586302733229 |
| < problem>17413< is hardest>problem ever< end> | < problem>31471< is hardest>melborp reve< end> |
| <   space   >space space space<    spa   c e> | <   space   >ecaps ecaps ecaps<    spa   c e> |