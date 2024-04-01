#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
  for (int x = len; x > idx; x--){
    arr[x] = arr[x-1];
  }
  arr[idx] = num;
  len++;
}

void erase(int idx, int arr[], int& len){
  for (idx; idx<=len - 1; idx++)
    arr[idx] = arr[idx+1];
  len--;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test() {
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  insert(3, 80, arr, len);
  for (int i = 0; i < len; i++){
    cout << arr[i] << " "; 
  }
  cout << endl;
  
}

void erase_test() {
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(3, arr, len);
  for (int i = 0; i < len; i++){
    cout << arr[i] << " "; 
  }
}

int main(void){
  insert_test();
  erase_test();
}