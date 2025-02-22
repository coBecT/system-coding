#include <stdio.h>
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
int main(){
    SetConsoleOutputCP(CP_UTF8);
    tablYmnozh();
}