#include <stdio.h>
#include <windows.h>
//2. **Площадь/Периметр:** Вычисление площади и периметра треугольника (по стороне и высоте).
//    - Константа: `AREA_TRIANGLE_FACTOR` (0.5).

#define AREA_TRIANGLE_FACTOR 0.5

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double side, height;

    printf("Введите длину стороны треугольника: ");
    scanf("%lf", &side);
    printf("Введите высоту треугольника: ");
    scanf("%lf", &height);

    double area = AREA_TRIANGLE_FACTOR * side * height;
    double perimeter = 3 * side;

    printf("\nПлощадь: %.2f\n", area);
    printf("Периметр (для равностороннего треугольника): %.2f\n", perimeter);

    return 0;
}