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

#define maxN    2000
#define maxlogN 12

int N, d[maxN+1];                           /* depth          */
int anc[maxlogN+1][maxN+1];                 /* ancestor       */
int hdr[maxN+1], nxt[maxN-1], dst[maxN-1];  /* adjacency list */

int jumpToDepth(int v, int dep)
{
    int i, j;

    for(i=maxlogN, j=1<<maxlogN; j>d[v]-dep; i--, j>>=1);
    for(; d[v]!=dep; i--, j>>=1) {
        if(j <= d[v]-dep)
            v = anc[i][v];
    }
    return v;
}

void updateTree(int v)
{
    int i, j, e;

    d[v] = d[anc[0][v]] + 1;
    for(i=1, j=2; j<=d[v]; i++, j<<=1)
        anc[i][v] = anc[i-1][anc[i-1][v]];
    for(e=hdr[v]; e!=-1; e=nxt[e])
        updateTree(dst[e]);
}

void work(void)
{
    char c;
    int u, v, e, t, i, j, x, y;

    scanf("%d",&N);
    memset(d+1, 0, sizeof(d[0])*N);
    memset(hdr+1, -1, sizeof(hdr[0])*N);

    e=0;
    while(1) {
        scanf(" %c%d%d", &c, &u, &v);
        if(c == 'M') {
            v = jumpToDepth(v, 0);
            if(v == jumpToDepth(u, 0))
                continue;
            nxt[e] = hdr[u];
            dst[e] = v;
            hdr[u] = e++;
            anc[0][v] = u;
            if(e == N-1) break;
            updateTree(v);
        } else {
            t = d[u] < d[v] ? d[u] : d[v];
            u = jumpToDepth(u, t);
            v = jumpToDepth(v, t);
            if(u == v) {
                printf("%d\n", u);
                continue;
            }
            for(i=0, j=1; (j<<1)<=d[u]; i++, j<<=1);
            for(; j>0; i--, j>>=1) {
                x = anc[i][u];
                y = anc[i][v];
                if(j<=t && x!=y) {
                    u=x;
                    v=y;
                    t-=j;
                }
            }
            /* not necessary, just for clarity */
            printf("%d\n", t==0 ? -1 : anc[0][u]);
        }
    }
}

int main(void)
{
    freopen("toy.in" ,"r",stdin );
    freopen("toy.out","w",stdout);
    work();
    return 0;
}
