void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Scambia gli elementi se sono nell'ordine sbagliato
            if (arr[j] > arr[j + 1]) {
                // Utilizza una variabile temporanea per lo scambio
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void recursiveBubbleSort(int arr[], int n) {
    // Caso base: se l'array ha 1 o 0 elementi, è già ordinato
    if (n <= 1) {
        return;
    }

    // Attraversa l'array e sposta il più grande elemento alla fine
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Chiamata ricorsiva su tutto l'array tranne l'ultimo elemento
    recursiveBubbleSort(arr, n - 1);
}
