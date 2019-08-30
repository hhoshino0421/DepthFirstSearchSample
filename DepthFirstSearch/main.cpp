#include <iostream>
#include <stack>

int *visited;
int **adj;
int V;
std::stack<int> S;

void init();

void DFSearch();

void output();

void terminal();


int main() {

    init();

    DFSearch();

    output();

    terminal();


    return 0;
}

void DFSearch() {

    int i, k;

    for (k = 0; k < V; k++) {
        visited[k] = 0;
    }

    for (k = V - 1; k >= 0; k--) {
        S.push(k);
    }

    while(S.size() > 0) {
        k = S.top();
        S.pop();

        if (!visited[k]) {
            visited[k] = 1;
        }

        for (i = V - 1; i >= 0; i--) {
            if (adj[k][i]) {
                S.push(i);
            }
        }

    }

}


void init() {

    visited = (int *)malloc(sizeof(int) * 5);

    adj = (int **)malloc(sizeof(int *) * 5);

    for(int i = 0; i < 5; i++) {
        adj[i] = (int *)malloc(sizeof(int) * 5); // 1行分のデータを保持する領域を確保
    }

    //initial data
    adj[0][0] = 0;
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[0][3] = 1;
    adj[0][4] = 0;

    adj[1][0] = 1;
    adj[1][1] = 0;
    adj[1][2] = 0;
    adj[1][3] = 1;
    adj[1][4] = 1;

    adj[2][0] = 1;
    adj[2][1] = 0;
    adj[2][2] = 0;
    adj[2][3] = 1;
    adj[2][4] = 1;

    adj[3][0] = 1;
    adj[3][1] = 1;
    adj[3][2] = 1;
    adj[3][3] = 0;
    adj[3][4] = 1;

    adj[4][0] = 0;
    adj[4][1] = 1;
    adj[4][2] = 1;
    adj[4][3] = 1;
    adj[4][4] = 0;

}

void output() {

    int k;

    for (k = 0; k < 5; k++) {
        std::cout << k << ":" << visited[k] << std::endl;
    }

}

void terminal() {

    for(int i = 0; i < 5; i++) {
        free(adj[i]);
    }

    free(adj);

    free(visited);

}

