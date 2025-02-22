#include <stdio.h>
#include <windows.h>

//5. **`static`:** В одном файле объявляется `static` переменная, которая увеличивается при каждом вызове
// функции `incrementCounter()`, во втором файле выполняется несколько вызовов этой функции и выводится значение переменной-счетчика.

void incrementCounter();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    incrementCounter(); // Счетчик: 1
    incrementCounter(); // Счетчик: 2
    incrementCounter(); // Счетчик: 3
    return 0;
}