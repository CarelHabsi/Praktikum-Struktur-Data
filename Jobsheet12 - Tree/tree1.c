#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct tree_node {
    struct tree_node* left;
    struct tree_node* right;
    struct tree_node* temp;
    struct tree_node* help;
    struct tree_node* height;
    char nomor[50];
    char nama[50];
    char nim[50];
    char email[50];
};

struct tree_node* root = NULL;

int isEmpty() {
    return root == NULL;
}

void insert(char* no, char* nm, char* n, char* ml) {
    struct tree_node* t = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node* parent = NULL;
    
    strcpy(t->nomor, no);
    strcpy(t->nama, nm);
    strcpy(t->nim, n);
    strcpy(t->email, ml);
    
    t->left = NULL;
    t->right = NULL;
    
    if (isEmpty()) {
        root = t;
    } else {
        struct tree_node* curr = root;
        while (curr != NULL) {
            parent = curr;
            if (strcmp(t->nomor, curr->nomor) > 0) {
                curr = curr->right;
            } else if (strcmp(t->nama, curr->nama) > 0) {
                curr = curr->right;
            } else if (strcmp(t->nim, curr->nim) > 0) {
                curr = curr->right;
            } else if (strcmp(t->email, curr->email) > 0) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        if (strcmp(t->nomor, parent->nomor) < 0) {
            parent->left = t;
        } else if (strcmp(t->nama, parent->nama) < 0) {
            parent->left = t;
        } else if (strcmp(t->nim, parent->nim) < 0) {
            parent->left = t;
        } else if (strcmp(t->email, parent->email) < 0) {
            parent->left = t;
        } else {
            parent->right = t;
        }
    }
}

void inorder(struct tree_node* p) {
    if (p != NULL) {
        if (p->left) inorder(p->left);
        printf(" | %s | %s | %s | %s |\n", p->nomor, p->nama, p->nim, p->email);
        if (p->right) inorder(p->right);
    }
}

void postorder(struct tree_node* p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf(" | %s | %s | %s | %s |\n", p->nomor, p->nama, p->nim, p->email);
    }
}

void preorder(struct tree_node* p) {
    if (p != NULL) {
        printf(" | %s | %s | %s | %s |\n", p->nomor, p->nama, p->nim, p->email);
        if (p->left) preorder(p->left);
        if (p->right) preorder(p->right);
    }
}

void print_preorder() {
    preorder(root);
}

void print_postorder() {
    postorder(root);
}

void print_inorder() {
    inorder(root);
}

int height(struct tree_node* root) {
    if (root == NULL) return -1;
    int u = height(root->left);
    int v = height(root->right);
    return (u > v) ? u + 1 : v + 1;
}

int main() {
    system("cls");
    int ch;
    char x[50], tmp[50], t[50], o[50];
    
    while (1) {
        system("cls");
        printf("\nMenu Utama Operasi Pohon Biner\n");
        printf("--------------------\n");
        printf("1. Insert/Tambah Data\n");
        printf("2. Kunjungan In-Order\n");
        printf("3. Kunjungan Pre-Order\n");
        printf("4. Kunjungan Post-Order\n");
        printf("5. Exit\n");
        printf("Pilihan Anda : ");
        scanf("%d", &ch);
        printf("\n");
        
        switch (ch) {
            case 1:
                printf("- NOMOR : ");
                scanf("%s", x);
                printf("- Nama : ");
                scanf("%s", tmp);
                printf("- NIM : ");
                scanf("%s", t);
                printf("- Email : ");
                scanf("%s", o);
                insert(x, tmp, t, o);
                break;
            case 2:
                printf("\nKunjungan In-Order\n");
                printf("---------------\n");
                printf(" --------------------------------------------------------------------------\n");
                printf(" |No|     NAMA          |    NIM     |    e-MAIL    |\n");
                printf(" --------------------------------------------------------------------------\n");
                print_inorder();
                getch();
                break;
            case 3:
                printf(" --------------------------------------------------------------------------\n");
                printf(" |No|     NAMA          |    NIM     |    e-MAIL    |\n");
                printf(" --------------------------------------------------------------------------\n");
                print_preorder();
                getch();
                break;
            case 4:
                printf("\nKunjungan In-Order\n");
                printf("---------------\n");
                printf(" --------------------------------------------------------------------------\n");
                printf(" |No|     NAMA          |    NIM     |    e-MAIL    |\n");
                printf(" --------------------------------------------------------------------------\n");
                print_postorder();
                getch();
                break;
            case 5:
                return 0;
            default:
                printf("Pilihan yang Anda Masukkan salah!\n");
                getch();
                break;
        }
    }
}