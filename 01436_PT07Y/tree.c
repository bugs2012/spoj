#include<stdio.h>
#include<stdint.h>

#define MAX_VERTICES 10100
struct node {
    int v;
    int parent;
    int rank;
};

int find(struct node *A, int v)
{
    if (A[v].parent == v)
        return v;
    A[v].parent = find(A, A[v].parent);
    return (A[v].parent);
}

int union1(struct node *A, int v1, int v2)
{
    int v1_root, v2_root;

    v1_root = find(A, v1);
    v2_root = find(A, v2);

    if (v1_root == v2_root) {
        return -1;
    } else {
        if (A[v1_root].rank > A[v2_root].rank) {
            A[v2_root].parent = v1_root;
            A[v1_root].rank += A[v2_root].rank;
        } else {
            A[v1_root].parent = v2_root;
            A[v2_root].rank += A[v1_root].rank;
        }
    }
    return 0;

}

int main()
{
    int num_ver, num_edges;
    int v1, v2;
    int cur_root, iroot, i;

    struct node A[MAX_VERTICES];

    for (i = 0; i < MAX_VERTICES; i++) {
        A[i].v      = i;
        A[i].parent = i;
        A[i].rank   = 0;
    }

    scanf("%d %d", &num_ver, &num_edges);
    while (num_edges--) {
        scanf("%d %d", &v1, &v2);
        if (union1(A, v1, v2) == -1) {
            printf("NO\n");
            return 0;
        }
    }
    cur_root = find(A, 1);
    for (i = 1; i <= num_ver; i++) {
        iroot = find(A, i);
        if (iroot != cur_root) {
            printf("NO\n");
            return 0;
        } 
    }
    printf("YES\n");

    return 0;
}
