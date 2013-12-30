/*
 * Copyright 2013 Chen Ruichao <linuxer0x@163.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h> // memory.h is not available in some implementations

#if defined(_WIN32) || defined(WIN32)
#   define readInt(v) scanf("%I64d",&v);
#   define println(v) printf("%I64d\n",v)
#else
#   define readInt(v) scanf("%lld",&v);
#   define println(v) printf("%lld\n",v)
#endif

#define maxH 10
#define MOD 100000007

typedef long long Matrix[maxH][maxH];

long long cnt[maxH+1]={};
Matrix M, T, tmp;

void mul(Matrix A, Matrix B)
{
    int i, j, k;

    for(i=0; i<maxH; i++)
        for(j=0; j<maxH; j++) {
            tmp[i][j] = 0;
            for(k=0; k<maxH; k++)
                tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    for(i=0; i<maxH; i++)
        memcpy(A[i], tmp[i], sizeof(A[0][0])*maxH);
}

void work(void)
{
    int N, h, i;
    long long H;

    scanf("%d",&N);
    while(N--) {
        scanf("%d",&h);
        cnt[h]++;
    }

    for(i=0; i<maxH; i++) {
        memset(M[i], 0, sizeof(M[i][0])*maxH);
        memset(T[i], 0, sizeof(T[i][0])*maxH);
        M[i][i] = 1;
        if(i>0) T[i][i-1] = 1;
        T[i][maxH-1] = cnt[maxH-i];
    }

    readInt(H);
    for(; H; H>>=1) {
        if(H&1) mul(M,T);
        mul(T,T);
    }

    println( M[maxH-1][maxH-1] );
}

int main(void)
{
    freopen("alignment.in", "r",stdin );
    freopen("alignment.out","w",stdout);
    work();
    return 0;
}
