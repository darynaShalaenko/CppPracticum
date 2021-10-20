
#includ
e <stdio.h>
#define N 10


void ShowArray(int array[]) {
    for (unsigned i=0; i<N; i++) {
         printf("%d ", array[i]);
    }
}


void InputArray(int mas[]) {
    for (unsigned i=0; i<N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &mas[i]);
    }
}


void ArrayOrder(int arr[]) {
    int prev_el, cur_el, swapper;
    int i = 1;
    while (i<N) {
        prev_el = arr[i-1];
        cur_el = arr[i];
        if (cur_el<prev_el) {
            swapper = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = swapper;
            i--;
            prev_el = arr[i-1];
        } else i++;
    }
}


void FindRepeat(int arr[]) {
    int counter = 1, max_counter = 0;
    int counting_el = arr[0];
    for (int i=1; i<N; i++) {
        if (arr[i] == counting_el) {
            counter++;
        } else {
            counter = 1;
            counting_el = arr[i];
        }
        if (counter>max_counter) max_counter = counter;
    }
    counting_el = arr[0];
    counter = 1;
    for (int i=1; i<N; i++) {
        if (arr[i] == counting_el) {
            counter++;
        } else {
            counter = 1;
            counting_el = arr[i];
        }
        if (counter==max_counter) printf("\nMost repeated element is %d", arr[i]);
    }
}


int main() {
    int array[N] = {1, 2, 5, 3, 1, 2, 6, 1, 7, 2};
    //InputArray(array);
    ShowArray(array);
    ArrayOrder(array);
    printf("\n");
    ShowArray(array);
    FindRepeat(array);
}
