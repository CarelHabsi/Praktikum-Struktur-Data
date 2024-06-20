#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan node dalam queue
struct Node {
    int data;
    struct Node* next;
};

// Struktur untuk queue
struct Queue {
    struct Node *front, *rear;
};

// Fungsi untuk membuat node baru dalam queue
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Fungsi untuk membuat queue kosong
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Fungsi untuk menambah elemen ke queue
void enQueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Fungsi untuk menghapus elemen dari queue
int deQueue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

// Fungsi untuk melakukan Breadth-First Search
void BFS(int graph[][4], int start, int n) {
    int visited[4] = {0}; // Array untuk melacak node yang sudah dikunjungi
    struct Queue* q = createQueue(); // Membuat queue
    
    visited[start] = 1; // Menandai node awal sebagai dikunjungi
    enQueue(q, start); // Menambah node awal ke queue
    
    printf("Breadth-First Search dimulai dari node %d:\n", start);
    
    while (q->front != NULL) {
        int current = deQueue(q); // Mengambil elemen pertama dari queue
        printf("%d ", current);
        
        // Mengecek semua node yang terhubung dengan node saat ini
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Menandai node sebagai dikunjungi
                enQueue(q, i); // Menambah node ke queue
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    BFS(graph, 0, 4); // Memulai BFS dari node 0
    
    return 0;
}