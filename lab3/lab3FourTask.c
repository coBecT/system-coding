#include <stdio.h>
#include <windows.h>


int main() {
    SetConsoleCP(CP_UTF8);       // Установка кодировки ввода UTF-8
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода UTF-8
    int x = 100;
    int y = 200; // Дополнительная переменная для демонстрации

    // 1. Указатель на константу
    const int *ptr1 = &x;
    // *ptr1 = 200; // Ошибка: нельзя изменить значение через ptr1
    ptr1 = &y;      // OK: можно изменить сам указатель
    printf("ptr1: %d\n", *ptr1); // Выведет 200

    // 2. Константный указатель
    int *const ptr2 = &x;
    *ptr2 = 300;    // OK: можно изменить значение
    // ptr2 = &y;   // Ошибка: нельзя изменить адрес указателя
    printf("x: %d\n", x); // Выведет 300

    // 3. Константный указатель на константу
    const int *const ptr3 = &x;
    // *ptr3 = 400; // Ошибка: нельзя изменить значение
    // ptr3 = &y;   // Ошибка: нельзя изменить адрес
    printf("ptr3: %d\n", *ptr3); // Выведет 300

    return 0;
}

