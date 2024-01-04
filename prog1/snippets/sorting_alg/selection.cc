void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Trova l'indice del minimo elemento nell'array non ordinato
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Scambia l'elemento minimo trovato con il primo elemento dell'array non ordinato
        if (minIndex != i) {
            // Utilizza una variabile temporanea per lo scambio
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}