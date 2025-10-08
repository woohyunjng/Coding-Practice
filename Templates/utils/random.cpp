random_device rd;
mt19937_64 mt(rd());

mt(); // Generates a random number
shuffle(arr.begin(), arr.end(), mt);