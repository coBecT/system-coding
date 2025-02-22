#include <stdio.h>

// 1. Обмен значениями
void swap_ints(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 5. Функция modify_values
void modify_values(int* int_ptr, float* float_ptr) {
    *int_ptr += 10;
    *float_ptr *= 2.0f;
}

// 6. Реализация my_strlen
size_t my_strlen(const char* str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

int main() {
    // 1. Проверка swap_ints
    int x = 5, y = 10;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap_ints(&x, &y);
    printf("After swap: x=%d, y=%d\n\n", x, y);

    // 2. Вывод массива в обратном порядке
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers + 4; // Указатель на последний элемент
    printf("Reverse array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr--);
    }
    printf("\n\n");

    // 3. Работа со строками
    char* message = "Hello, world!";
    printf("Message 1: %s\n", message);
    message = "New string!";
    printf("Message 2: %s\n", message);

    char fixed_message[] = "Original";
    // fixed_message = "Another"; // Ошибка: массив нельзя переназначить
    fixed_message[0] = 'A'; // Можно изменить посимвольно
    printf("Fixed message: %s\n\n", fixed_message);

    // 4. Константные указатели
    int val = 100;
    const int* ptr1 = &val;  // Указатель на константу
    // *ptr1 = 200; // Ошибка: значение нельзя изменить
    ptr1 = &x;      // Можно изменить указатель

    int* const ptr2 = &val; // Константный указатель
    *ptr2 = 200;    // Можно изменить значение
    // ptr2 = &x;   // Ошибка: указатель нельзя изменить

    const int* const ptr3 = &val; // Константный указатель на константу
    // *ptr3 = 300; // Ошибка
    // ptr3 = &x;   // Ошибка

    // 5. Проверка modify_values
    int my_int = 5;
    float my_float = 2.5f;
    printf("Before modify: my_int=%d, my_float=%.1f\n", my_int, my_float);
    modify_values(&my_int, &my_float);
    printf("After modify: my_int=%d, my_float=%.1f\n\n", my_int, my_float);

    // 6. Проверка my_strlen
    char* str1 = "Test String";
    char str2[] = "Another Test";
    printf("Length of '%s': %zu\n", str1, my_strlen(str1));
    printf("Length of '%s': %zu\n", str2, my_strlen(str2));

    return 0;
}