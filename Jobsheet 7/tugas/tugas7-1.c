#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_SIZE 100

// Struktur data untuk representasi graf
struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

// Fungsi untuk membuat graf baru
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Membuat matriks adjacency dengan ukuran sesuai jumlah vertices
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Fungsi untuk menambahkan edge antara dua vertices
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Fungsi untuk melakukan Breadth First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    // Array untuk melacak status kunjungan vertices
    int visited[MAX_SIZE] = {0};

    // Membuat queue untuk BFS
    int queue[MAX_SIZE];
    int front = 0, rear = 0;

    // Menandai startVertex sebagai sudah dikunjungi dan memasukkannya ke dalam queue
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Hasil BFS traversal: ");

    while (front < rear) {
        // Mengambil vertex dari queue dan mencetaknya
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Menambahkan semua tetangga yang belum dikunjungi ke dalam queue
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    system("cls");
    int vertices, edges;
    printf("Masukkan jumlah vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Masukkan jumlah edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Masukkan source dan destination untuk edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Masukkan start vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}