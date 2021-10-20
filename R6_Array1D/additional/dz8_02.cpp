#include <iostream>

void prnt(int n,int* arr){

    for (int i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }
    printf("\n");
}

int maximum(int n,int* arr){
    double m = arr[0];
    for (int j = 0; j <= n; j++){
        if ( m < arr[j]){
            m = arr[j];
        }
    }
    return m;
}

int siz(int n){
    int ans = 0;
    while (n != 0){
        n /= 10;
        ans += 1;
    }
    return ans;
}

int main(){
    int val;
    std :: cout << "enter your value: " << std :: endl;
    std :: cin >> val;
    int s = siz(val);
    int arr[s];
    for (int i = 0; i < s; i++){
        arr[i] = val % 10;
        val /= 10;
    }
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, zero = 0;
    for (int j = 0; j < s; j++){
        //std :: cout << arr[j] << std :: endl;
        if (arr[j] == 0) zero++;
        else if (arr[j] == 1) one ++;
        else if (arr[j] == 2) two ++;
        else if (arr[j] == 3) three ++;
        else if (arr[j] == 4) four ++;
        else if (arr[j] == 5) five ++;
        else if (arr[j] == 6) six ++;
        else if (arr[j] == 7) seven ++;
        else if (arr[j] == 8) eight ++;
        else if (arr[j] == 9) nine ++;
    }
    int ans_l[11] = {zero,one,two,three,four,five,six,seven,eight,nine};
    int an = maximum(10, ans_l);
    int k = 9;
    for (k ; k >= 0; k--){
        if (ans_l[k] == an) break;
    }
    std :: cout << "ans = " << k << std :: endl;
}
