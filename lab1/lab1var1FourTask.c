#include <stdio.h>
#include <windows.h>

//4. **Переменные:** 
// Демонстрация локальных и глобальных переменных с использованием _разных_ имен переменных
// (`localValue`, `globalValue`).

int globalValue = 100;

void demonstriryya() {
    int localValue = 50;

    printf("[Функция demonstriryya]\n");
    printf("Глобальная переменная: %d\n", globalValue);
    printf("Локальная переменная: %d\n", localValue);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int localValue = 20;

    printf("[Функция main]\n");
    printf("Глобальная переменная: %d\n", globalValue);
    printf("Локальная переменная: %d\n", localValue);

    demonstriryya();

    return 0;
}