#include <stdio.h>
#include <windows.h>
#include <corecrt.h>
// Реализация функции для подсчета длины строки

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') { // Идем по строке до нуль-терминатора
        len++;
    }
    return len;
}

int main() {
    SetConsoleCP(CP_UTF8);       // Установка кодировки ввода UTF-8
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода UTF-8
    // Проверка для строки, объявленной через char*
    char *message_ptr = "Hello, World!";
    printf("Длина строки (char*): %zu\n", my_strlen(message_ptr));

    // Проверка для строки, объявленной через char[]
    char message_arr[] = "Hello, World!";
    printf("Длина строки (char[]): %zu\n", my_strlen(message_arr));
    while(getchar() != '\n');
    getchar();
    return 0;
}