#include <stdio.h>

int maxGirlsImpressed(int N, int K, int girls[]) {
    int maxGirls = 0;
    int currGirls = 0;
    
    for (int i = 0; i < K; i++) {
        currGirls += girls[i];
    }
    maxGirls = currGirls;
    
    for (int i = K; i < N; i++) {
        currGirls = currGirls + girls[i] - girls[i - K];
        if (currGirls > maxGirls) {
            maxGirls = currGirls;
        }
    }
    
    return maxGirls;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        
        int girls[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &girls[i]);
        }
        
        int maxImpressed = maxGirlsImpressed(N, K, girls);
        printf("%d\n", maxImpressed);
    }
    
    return 0;
}
