#include <stdio.h>
#include <windows.h>
void swap_ints(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    SetConsoleCP(CP_UTF8);     // Устанавливаем кодировку ввода
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку вывода
    int a = 5, b = 10;
    printf("До: x=%d, y=%d\n", a, b);
    swap_ints(&a, &b);
    printf("После: x=%d, y=%d\n\n", a, b);
    while(getchar() != '\n');
    getchar();
}