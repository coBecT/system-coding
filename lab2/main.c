#include <stdio.h>
#include <ctype.h>
#include <windows.h>


// 1. Таблица умножения
void tablYmnozh() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }
}

// 2. Калькулятор
// - Проверка ввода на корректность ввода (только числа).
// - Проверка деления на ноль.
void calculator() {
    double nums[3];
    char ops[2];
    printf("Введите три числа и две операции (например: 1 + 2 * 3): ");
    if (scanf("%lf %c %lf %c %lf", &nums[0], &ops[0], &nums[1], &ops[1], &nums[2]) != 5) {
        printf("Ошибка ввода!\n");
        // Очистка буфера
        while (getchar() != '\n');
        return;
    }

    // Проверка деления на ноль
    for (int i = 0; i < 2; i++) {
        if (ops[i] == '/' && nums[i+1] == 0) {
            printf("Ошибка: деление на ноль!\n");
            return;
        }
    }

    // Вычисление с учётом приоритета операций
    double result;
    if ((ops[0] == '+' || ops[0] == '-') && (ops[1] == '*' || ops[1] == '/')) {
        // Выполняем вторую операцию сначала
        switch (ops[1]) {
            case '*': result = nums[1] * nums[2]; break;
            case '/': result = nums[1] / nums[2]; break;
        }
        switch (ops[0]) {
            case '+': result = nums[0] + result; break;
            case '-': result = nums[0] - result; break;
        }
    } else {
        // Последовательное выполнение
        switch (ops[0]) {
            case '+': result = nums[0] + nums[1]; break;
            case '-': result = nums[0] - nums[1]; break;
            case '*': result = nums[0] * nums[1]; break;
            case '/': result = nums[0] / nums[1]; break;
        }
        switch (ops[1]) {
            case '+': result += nums[2]; break;
            case '-': result -= nums[2]; break;
            case '*': result *= nums[2]; break;
            case '/': result /= nums[2]; break;
        }
    }

    printf("Результат: %.2lf\n", result);
}

// 3. Форматированный вывод
void formattedOutput() {
    char name[50], surname[50], hobby[100];
    int age;

    printf("Введите имя: ");
    scanf("%49s", name);
    printf("Введите фамилию: ");
    scanf("%49s", surname);
    printf("Введите возраст: ");
    scanf("%d", &age);
    printf("Введите хобби: ");
    scanf(" %99[^\n]", hobby);

    printf("\"%s\"\t\"%s\"\t%d\t%s\n", name, surname, age, hobby);
}

// 4. Символьный ввод/вывод
void characterInputOutput() {
    int ch;
    printf("Вводите символы (для выхода - 'x'):\n");
    // Очистка буфера перед началом
    while ((ch = getchar()) != '\n' && ch != EOF);

    while (1) {
        ch = getchar();
        if (ch == 'x') break;
        if (ch == EOF) continue;
        putchar(toupper(ch));
    }
    printf("\nЗавершено.\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    tablYmnozh();
 //   printMultiplicationTable();
    calculator();
    formattedOutput();
    characterInputOutput();
    return 0;
}