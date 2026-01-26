random_device rd;
mt19937_64 mt(rd());
uniform_int_distribution<int> dis(0, 99);
normal_distribution<double> dist(/* 평균 = */ 0, /* 표준 편차 = */ 1);

mt(); // Generates a random number
shuffle(arr.begin(), arr.end(), mt);