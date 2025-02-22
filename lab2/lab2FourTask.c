#include <stdio.h>
#include <ctype.h>
#include <windows.h>
int main() {
    SetConsoleCP(CP_UTF8);     // Устанавливаем кодировку ввода
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку вывода
    int a;
    printf("Вводите символы (x для выхода):\n");

    while ((a = getchar()) != 'x') {
        if (a == EOF) break; // Завершение при ошибке ввода или Ctrl+D/Z
        putchar(toupper(a));
    }
    return 0;
}