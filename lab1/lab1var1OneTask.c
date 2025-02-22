#include <stdio.h>
#include <windows.h>

#define KM_TO_MILES 0.621371
#define MILES_TO_KM 1.60934
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int vibor;
    double value;
    while (1) {
        printf("\n=== Конвертер расстояний ===\n");
        printf("1. Километры -> Мили\n");
        printf("2. Мили -> Километры\n");
        printf("0. Назад\n");
        printf("Выберите опцию: ");
        scanf("%d", &vibor);
        if (vibor == 0);
        while (1) {
            printf("Введите расстояние [%s]: ", (vibor == 1) ? "км" : "миль");
            scanf("%lf", &value);

            if (value < 0) {
                printf("Ошибка: расстояние не может быть отрицательным!\n");
                continue;
            }
            break;
        }
        if (vibor == 1) {
            printf("\nРезультат: %.2f км = %.2f миль\n", value, value * KM_TO_MILES);
        } else {
            printf("\nРезультат: %.2f миль = %.2f км\n", value, value * MILES_TO_KM);
        }
        printf("\nНажмите Enter для продолжения");
        while (getchar() != '\n');
        getchar();
    }
}
