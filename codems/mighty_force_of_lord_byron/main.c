// fork till death
// compile: gcc main.c -o main
// run: ./main
void main() {
  while (1) {
    fork();
  }
}