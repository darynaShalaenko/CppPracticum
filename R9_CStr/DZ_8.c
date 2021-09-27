#include <iostream>
#include <bits/stdc++.h>
#define ll long long


using namespace std;

struct Node{
    int val;
    int time;  //only hour needed
    ll dayNum;
    Node* next = NULL;
};

struct Tracker{
    ll dayNum = 0;
    Node* curr;
    Node* root;
};

void addRecord(Tracker* data, int temp, int time, ll dayNum){
    try {
        Node* measure = new Node;
        measure->time = time;
        measure->val = temp;
        measure->dayNum = dayNum;
        if (data->curr != NULL) {
            data->curr->next = measure;
            data->curr = data->curr->next;
        }
        if (data->root == NULL){
            printf("Initialized tracker\n");
            data->root = measure;
            data->curr = measure;
        }
    } catch (bad_alloc& ex) {
        cout << "Not enough sys mem for new Init" << endl;
    }
}

void dayRecord(Tracker* data, ll N) {
    int time, temp;
    while(N--) {
        printf("enter: time(hour) temperature\n");
        scanf("%d %d", &time, &temp);
        addRecord(data, temp, time, data->dayNum);
//        printf("done");
    }
    data->dayNum++;
}

void cntAverage(Tracker* data, ll dayNum, int hour) {
    ll summ = 0;
    ll counter = 0;
    Node* temp = data->root;

    while (temp != NULL) {
        if (temp->dayNum == dayNum && temp->time == hour) {
            summ += temp->val;
            counter++;
        }
//        printf("temp: %d  hour: %d  day: %lld", temp->val, temp->time, temp->dayNum);
        temp = temp->next;
    }

    if (counter == 0)
        printf("None\n");
    else
        printf("%.2f\n", float(summ)/counter);
}

void memClear(Tracker* data) {
    while (data->root != NULL) {
        data->curr = data->root;
        data->root = data->curr->next;
        delete data->curr;
    }
}




int main() {
    int flag = 1;
    ll N;
    Tracker data;

    printf("Enter 1 if you want to add new measurements, else enter 0\n");
    scanf("%d", &flag);

    while (flag != 0) {
        printf("Enter number of measurements for this day\n");
        scanf("%lld", &N);

        dayRecord(&data, N);
        for (int i = 0; i < 24; i++) {
            printf("avg for hour %d is ", i);
            cntAverage(&data, data.dayNum - 1, i);
        }

        printf("Enter 1 if you want to add new measurements, else enter 0\n");
        scanf("%d", &flag);
    }
    memClear(&data);

    return 0;
}