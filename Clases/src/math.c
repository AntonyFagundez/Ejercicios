int sum(int x, int y){
    return x + y;
}

int rest(int x, int y){
    return x - y;
}

int mult(int x, int y){
    return x * y;
}

float div(int x, int y){
    return (float)x / y;
}

long long fact(int n){
    long long fact = 1;
    for (int i = 1; i <= n; ++i) 
    {
        fact *= i;
    }

    return fact;
}