#include <stdio.h>

int main() {
  // Menentukan jumlah kartu.
  int N;
  scanf("%d", &N);

  // Membaca nilai kartu.
  int cards[N];
  for (int i = 0; i < N; i++) {
    char card;
    scanf(" %c", &card);
    if (card >= '1' && card <= '9') {
      cards[i] = card - '0';
    } else if (card == 'J') {
      cards[i] = 11;
    } else if (card == 'Q') {
      cards[i] = 12;
    } else if (card == 'K') {
      cards[i] = 13;
    }
  }

  // Menghitung jumlah minimal langkah pertukaran.
  int swaps = 0;
  for (int i = 0; i < N; i++) {
    // Menemukan kartu minimum di sisa kartu.
    int min_idx = i;
    for (int j = i + 1; j < N; j++) {
      if (cards[j] < cards[min_idx]) {
        min_idx = j;
      }
    }

    // Tukar kartu minimum dengan kartu di posisi saat ini.
    if (min_idx != i) {
      int temp = cards[i];
      cards[i] = cards[min_idx];
      cards[min_idx] = temp;
      swaps++;
    }
  }

  // Mencetak output.
  printf("%d\n", swaps);

  return 0;
}
