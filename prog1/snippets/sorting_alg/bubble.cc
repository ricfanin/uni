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
