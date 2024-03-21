#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Langkah yang mungkin dilakukan oleh bidak kuda
    int moves[8][2] = { //merepresentasikan langkah-langkah yang mungkin dilakukan oleh bidak kuda
        {-2, -1}, {-2, 1}, 
        //Dua langkah ke atas dan satu langkah ke kiri, Dua langkah ke atas dan satu langkah ke kanan
        {-1, -2}, {-1, 2},
        //Satu langkah ke atas dan dua langkah ke kiri, Satu langkah ke atas dan dua langkah ke kanan
        {1, -2}, {1, 2},
        //Satu langkah ke bawah dan dua langkah ke kiri, Satu langkah ke bawah dan dua langkah ke kanan
        {2, -1}, {2, 1}
        //Dua langkah ke bawah dan satu langkah ke kiri, Dua langkah ke bawah dan satu langkah ke kanan
    };

    // Melakukan simulasi untuk setiap kemungkinan langkah
    for (int k = 0; k < 8; k++) {
        //loop yang akan berjalan sebanyak 8 kali
        int new_i = i + moves[k][0];
        //menghitung posisi baris baru 
        int new_j = j + moves[k][1];
        //menghitung posisi kolom baru

        
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            // Memastikan posisi baru berada dalam batas papan catur
            chessBoard[new_i * size + new_j] = 1;
             // Menandai posisi yang dapat dicapai oleh bidak kuda
        }
    }
}

int main() {
    // Membuat array 2D berukuran 8x8 untuk papan catur
    int size = 8;
    //ukuran papan catu
    int *chessBoard = (int *)malloc(size * size * sizeof(int));
    //mengalokasikan memori dinamis untuk array 2D merepresentasikan papan catur

    // Inisialisasi papan catur dengan nilai 0
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            chessBoard[i * size + j] = 0;
            //mengatur nilai dari elemen papan catur
        }
    }

    // Input posisi bidak kuda
    int i, j;
    scanf("%d %d", &i, &j);

    koboImaginaryChess(i, j, size, chessBoard);
    // Memanggil fungsi untuk mensimulasikan langkah bidak kuda

    // Menampilkan hasil papan catur setelah simulasi
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", chessBoard[i * size + j]);
            // mencetak nilai dari setiap elemen di papan catur.
        }
        printf("\n");
    }

    free(chessBoard);
    // Menghapus array dinamis

    return 0;
}
