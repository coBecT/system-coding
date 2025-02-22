#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
//2. **Калькулятор:** Калькулятор, выполняющий сложение, вычитание, умножение и деление _трех_ чисел.
//    - Проверка ввода на корректность ввода (только числа).
//    - Проверка деления на ноль.

int main() {
    SetConsoleOutputCP(CP_UTF8);
    float a, b, c;
    char operations;

    printf("Введите 3 числа: ");
    if (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("Незнакомая операция.\n");
        while (getchar() != '\n');
        return 0;
    }

    printf("Выбери операцию из предложенных +, -, *, /: ");
    //%c сканирует 1 символ (char) похожая %s сканирует строку
    scanf(" %c", &operations);

    float res;
    bool valid =  true;

    switch (operations) {
        case '+': res = a + b + c; break;
        case '-': res = a - b - c; break;
        case '*': res = a * b * c; break;
        case '/':
            if (b == 0 || c == 0) {
                printf("Деление на 0!\n");
                valid = false;
            } else res = a / b / c;
            break;
        default:
            printf("Незнакомая операция.\n");
            valid = false;
    }

    if (valid){
        printf("Результат: %.2f\n", res);
    }

    printf("Введите enter для выхода из программы");

    while (getchar() != '\n');
    getchar();

    return 0;
}