#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);       // Установка кодировки ввода UTF-8
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода UTF-8

    int numbers[] = {10, 20, 30, 40, 50};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    int* ptr = numbers + arraySize - 1;

    printf("Вывод в обратном порядке: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", *ptr--);
    }
    printf("\n");
    while(getchar() != '\n');
    getchar();
    return 0;
}