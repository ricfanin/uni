#include <iostream>

// Funzione di partizione per il Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Scegli l'ultimo elemento come pivot
    int i = (low - 1); // Indice del più piccolo elemento

    for (int j = low; j <= high - 1; j++) {
        // Se l'elemento corrente è più piccolo o uguale al pivot
        if (arr[j] <= pivot) {
            i++;

            // Scambia arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Scambia arr[i + 1] e arr[high] (posiziona il pivot al suo posto)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Funzione ricorsiva per eseguire il Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Trova l'indice di partizione, arr[p] è ora al posto giusto
        int pivotIndex = partition(arr, low, high);

        // Ordina gli elementi prima e dopo la partizione
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Array originale: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    quickSort(array, 0, size - 1);

    std::cout << "\nArray ordinato: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
