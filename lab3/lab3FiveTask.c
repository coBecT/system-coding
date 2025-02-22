#include <stdio.h>
#include <windows.h>

void modify_values(int* int_ptr, float* float_ptr) {
    *int_ptr += 10;
    *float_ptr *= 2.0f;
}

int main() {
    SetConsoleCP(CP_UTF8);       // Установка кодировки ввода UTF-8
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода UTF-8
    int my_int = 5;
    float my_float = 2.5f;

    printf("До вызова функции:\n");
    printf("my_int = %d, my_float = %.1f\n", my_int, my_float);

    modify_values(&my_int, &my_float);

    printf("\nПосле вызова функции:\n");
    printf("my_int = %d, my_float = %.1f\n", my_int, my_float);
    while (getchar() != '\b');
    getchar();
    return 0;
}