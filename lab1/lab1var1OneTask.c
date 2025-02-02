#include <stdio.h>
#include <windows.h>


#define KM_TO_MILES 0.621371
#define MILES_TO_KM 1.60934

void convertDistance() {
    int choice;
    double value;
    char input[100]; // Буфер для ввода

    while(1) {
        printf("\n=== Конвертер расстояний ===\n");
        printf("1. Километры -> Мили\n");
        printf("2. Мили -> Километры\n");
        printf("0. Назад\n");
        printf("Выберите опцию: ");


        if(fgets(input, sizeof(input), stdin) == NULL) {
            printf("Ошибка чтения ввода!\n");
            continue;
        }

        // Проверка корректности выбора
        if(sscanf(input, "%d", &choice) != 1 || choice < 0 || choice > 2) {
            printf("Неверный выбор! Допустимые значения: 0-2\n");
            continue;
        }

        if(choice == 0) return;

        // Ввод значения
        while(1) {
            printf("Введите расстояние [%s]: ",
                   (choice == 1) ? "км" : "миль");

            if(fgets(input, sizeof(input), stdin) == NULL) {
                printf("Ошибка чтения ввода!\n");
                continue;
            }

            // Проверка числового ввода
            if(sscanf(input, "%lf", &value) != 1) {
                printf("Ошибка: введите числовое значение!\n");
                continue;
            }

            // Проверка отрицательных значений
            if(value < 0) {
                printf("Ошибка: расстояние не может быть отрицательным!\n");
                continue;
            }

            break;
        }

        // Выполнение конвертации
        if(choice == 1) {
            printf("\nРезультат: %.2f км = %.2f миль\n",
                   value, value * KM_TO_MILES);
        } else {
            printf("\nРезультат: %.2f миль = %.2f км\n",
                   value, value * MILES_TO_KM);
        }

        // Пауза для просмотра результата
        printf("\nНажмите Enter для продолжения...");
        while(getchar() != '\n');
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    convertDistance();
    return 0;
}