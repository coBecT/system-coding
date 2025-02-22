#include <stdio.h>
#include <windows.h>
#include <math.h>

//3. **Калькулятор:** Калькулятор, выполняющий операции возведения в степень и извлечения квадратного корня.
//    - Ввод двух чисел: число, которое возводится в степень, и сама степень (только целая), а также число,
//    из которого извлекают квадратный корень (только положительные).

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double base, number_for_root;
    int exponent;

    printf("Введите число и степень (через пробел): ");
    scanf("%lf %d", &base, &exponent);

    double power_result = pow(base, exponent);
    printf("Результат: %.2f^%d = %.2f\n", base, exponent, power_result);

    printf("Введите число для квадратного корня: ");
    scanf("%lf", &number_for_root);

    if (number_for_root >= 0) {
        double root_result = sqrt(number_for_root);
        printf("Квадратный корень из %.2f = %.2f\n", number_for_root, root_result);
    } else {
        printf("Ошибка: число должно быть неотрицательным!\n");
    }

    return 0;
}