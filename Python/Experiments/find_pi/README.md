# 파이값 구하기

여러 방법을 사용하여 파이값을 직접 계산해봄

## 정확도 (테스트케이스 10⁸개 기준)

| 이름                | 방법                            | 값               | 오차       | 걸린 시간 |
| ------------------- | ------------------------------- | ---------------- | ---------- | --------- |
| [basel](./basel.py) | 바젤 문제를 이용해 파이값 계산  | 3.14159264498239 | 0.0000001% | 16초      |
| [rand](./rand.py)   | 몬테카를로 방법으로 파이값 계산 | 3.1412904        | 0.0096210% | 60초      |
| [coord](./coord.py) | 좌표평면위의 원 넓이 구하기     | 3.14199048       | 0.0126632% | 67초      |