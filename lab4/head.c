#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 1. Сумма элементов массива
int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 2. Максимальный элемент
int max_element(int arr[], int size) {
    if (size == 0) return INT_MIN;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// 3. Реверс массива
void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// 4. Удаление дубликатов (с сортировкой)
int remove_duplicates(int arr[], int size) {
    if (size <= 1) return size;
    // Сортировка для упрощения удаления
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Удаление дубликатов
    int unique = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[unique]) {
            arr[++unique] = arr[i];
        }
    }
    return unique + 1;
}

// 5. Циклический сдвиг вправо на k позиций
void rotate_array(int arr[], int size, int k) {
    k = k % size;
    if (k == 0) return;
    // Обращение всего массива
    reverse_array(arr, size);
    // Обращение первых k элементов
    reverse_array(arr, k);
    // Обращение оставшихся элементов
    reverse_array(arr + k, size - k);
}

// 6. Сортировка слиянием
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 7. Алгоритм Кадане
void max_subarray(int arr[], int size, int *start, int *end, int *max_sum) {
    *max_sum = INT_MIN;
    int current_sum = 0;
    *start = *end = 0;
    int temp_start = 0;

    for (int i = 0; i < size; i++) {
        current_sum += arr[i];
        if (current_sum > *max_sum) {
            *max_sum = current_sum;
            *start = temp_start;
            *end = i;
        }
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }
}

// 8. Пересечение отсортированных массивов
int* intersection(int arr1[], int size1, int arr2[], int size2, int *result_size) {
    int i = 0, j = 0, k = 0;
    int *result = (int*)malloc((size1 + size2) * sizeof(int));

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) i++;
        else if (arr1[i] > arr2[j]) j++;
        else {
            // Добавляем элемент и пропускаем дубликаты
            result[k++] = arr1[i];
            while (i < size1 - 1 && arr1[i] == arr1[i + 1]) i++;
            while (j < size2 - 1 && arr2[j] == arr2[j + 1]) j++;
            i++;
            j++;
        }
    }
    *result_size = k;
    return result;
}

int main() {
    // Примеры использования функций
    int arr[] = {1, 2, 3, 2, 4};
    int size = 5;

    // 1. Сумма
    printf("Sum: %d\n", sum_array(arr, size));

    // 2. Максимальный элемент
    printf("Max: %d\n", max_element(arr, size));

    // 3. Реверс
    reverse_array(arr, size);
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // 4. Удаление дубликатов
    int new_size = remove_duplicates(arr, size);
    printf("Unique array: ");
    for (int i = 0; i < new_size; i++) printf("%d ", arr[i]);
    printf("\n");

    // 5. Сдвиг на 2 позиции
    int arr2[] = {1, 2, 3, 4, 5};
    rotate_array(arr2, 5, 2);
    printf("Rotated array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr2[i]);
    printf("\n");

    // 6. Сортировка слиянием
    int arr3[] = {5, 3, 8, 4, 2};
    merge_sort(arr3, 0, 4);
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr3[i]);
    printf("\n");

    // 7. Подмассив с максимальной суммой
    int arr4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int start, end, max_sum;
    max_subarray(arr4, 9, &start, &end, &max_sum);
    printf("Max subarray: sum=%d, indices [%d, %d]\n", max_sum, start, end);

    // 8. Пересечение массивов
    int arr5[] = {1, 2, 2, 3, 4};
    int arr6[] = {2, 2, 3, 5};
    int res_size;
    int *res = intersection(arr5, 5, arr6, 4, &res_size);
    printf("Intersection: ");
    for (int i = 0; i < res_size; i++) printf("%d ", res[i]);
    printf("\n");
    free(res);

    return 0;
}