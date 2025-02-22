#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleCP(CP_UTF8);       // Установка кодировки ввода UTF-8
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода UTF-8
    char* message = "Hello, world!";
    printf(" %s\n", message);
    message = "New string!";
    printf(" %s\n", message);

    char fixed_message[] = "Original";
    // fixed_message = "Another"; // Ошибка: массив нельзя переназначить
    printf("Fixed message: %s\n\n", fixed_message);
    fixed_message[0] = 'A'; // Можно изменить посимвольно
    fixed_message[1] = 'n';
    fixed_message[2] = 'o';
    fixed_message[3] = 't';
    fixed_message[4] = 'h';
    fixed_message[5] = 'e';
    fixed_message[6] = 'r';
    fixed_message[7] = '!';
    printf("Fixed message: %s\n\n", fixed_message);
    while(getchar() != '\n');
    getchar();
}