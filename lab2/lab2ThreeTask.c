#include <stdio.h>
#include <locale.h>
#include <windows.h>
//Запросить у пользователя имя, фамилию, возраст и хобби (строка).
// Вывести в одну строку через табуляции, а имя и фамилию в кавычках.
// Использовать `printf`, `\n`, `\t`, `\"`.
//дима
//домокуров
//18
//спорт
int main() {
    SetConsoleCP(CP_UTF8);     // Устанавливаем кодировку ввода
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку вывода
    char name[100], surname[100], hobby[100];
    int age;

    printf("Введите имя: ");
    scanf(" %s", name);

    printf("Введите фамилию: ");
    scanf(" %s", surname);

    printf("Введите возраст: ");
    scanf("%d", &age);
    while (age != 1 && age < 0) {
        while (getchar() != '\n');
        printf("Ошибка! Введите число: ");
    }

    printf("Введите хобби: ");
    scanf("%s", hobby);

    printf("\"%s\"\t\"%s\"\t%s\t%d", name, surname, hobby, age);
    while (getchar() != '\n');
    getchar();
    return 0;
}