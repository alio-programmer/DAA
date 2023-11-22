#include <bits/stdc++.h>
using namespace std;
class Item {
    public:
    int profit, weight;
    Item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};
bool cmp1(Item a, Item b){
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
bool cmp2(Item a, Item b){
    double r1 = (double)a.profit;
    double r2 = (double)b.profit;
    return r1 > r2;
}

bool cmp3(Item a, Item b){
    double r1 = (double)a.weight;
    double r2 = (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack1(int W, vector<Item> arr, int N){
    sort(arr.begin(), arr.end(), cmp1);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else {
            finalvalue+= arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
double fractionalKnapsack2(int W, vector<Item> arr, int N){
    sort(arr.begin(), arr.end(), cmp2);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else {
            finalvalue+= arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
double fractionalKnapsack3(int W, vector<Item> arr, int N){
    sort(arr.begin(), arr.end(), cmp3);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else {
            finalvalue+= arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main(){
    int W = 50;
    vector<Item> arr = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    cout << fractionalKnapsack1(W, arr, arr.size())<<endl;
    cout << fractionalKnapsack2(W, arr, arr.size())<<endl;
    cout << fractionalKnapsack3(W, arr, arr.size())<<endl;
    return 0;
}