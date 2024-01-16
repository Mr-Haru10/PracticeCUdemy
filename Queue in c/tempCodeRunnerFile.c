#include <stdio.h>

int main() {
  int num = 19; // Change this to your desired integer
  int bit_size = sizeof(num) * 8; // Assuming 8 bits per byte

  for (int i = bit_size - 1; i >= 0; i--) {
    if ((num & (1 << i)) != 0) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");

  return 0;
}