// THIS IS AN EXERCISE FOR ARAYS IN C FOR CMSC 123.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int find(int x); //x is the value to be searched
int find_kth(int k); //i is the index to be searched for.
int insert(int x, int i); //x is the value and place x aon index i, shifting all the succeding elements Hwever, last element will be gone.
int removeEntry(int x); //remove the first element with x value and shifts all succeeding elements to fill the gap. Return the index.
void print_list();


int arr[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12};

int main() {

    int choice, search, temp, index;
    while(1){
        system("cls");
        printf("\nPlease select from the options:\n\t0 find(x)\n\t1 find_kth(k)\n\t2 insert(x,i)\n\t3 remove(x)\n\t4 print_list()\n\t5 exit\n");
        scanf("%d", &choice);
        system("cls");
        switch(choice) {
            case 0: 
            //find(x)
                printf("Please input a number that you would like to find: ");
                scanf(" %d", &search);
                temp = find(search);
                if (!temp){
                    printf("Value not found");
                } else {
                    printf("%d is at index %d.", search, temp);
                }
                printf("\n");
                system("pause");
                break;

            case 1: 
            //find_kth(k)
                printf("PLease input the index that you want to know the value of: ");
                scanf(" %d", &search);
                if (search >= MAX_SIZE || search < 0){
                    printf("Index out of bounds.");
                } else {
                    temp = find_kth(search);
                    printf("The value of the element in the index of %d is %d.", search, temp);
                }
                printf("\n");
                system("pause");
                break;
                
            case 2: 
            //insert(x,i)
                while(1){
                    printf("Please enter the position where you want it to be placed: ");
                    scanf("%d", &index);
                    if(index > 0 && index < MAX_SIZE) {
                        break;
                    }
                    printf("Index out of bounds!!\n");
                }

                printf("Please enter a value for that position: ");
                scanf("%d", &search);

                temp = insert(search, index);

                printf("%d inserted successfully at index %d.",search, temp);
                
                printf("\n");
                system("pause");
                break;

            case 3: 
            //remove(x)
                printf("Please select input the value that you want to remove: (NOTE: only the first element that has this value will be removed) ");
                scanf("%d", &search);
                temp = removeEntry(search);
                if (!temp){
                    printf("Value not found");
                } else {
                    printf("%d at index %d has been removed.", search, temp);
                }
                
                printf("\n");
                system("pause");
                break;

            case 4: 
            //print_list()
                print_list();
                
                printf("\n");
                system("pause");
                break;

            case 5: //exit
                exit(0);
                break;

            default: 
                break;
        }
    }
    return 0;
}

int find(int x){
    //using linear search for now
    for (int i =  0; i < MAX_SIZE; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return 0;
}

int find_kth(int x){
    return arr[x];
}

int insert(int x, int i) {
    for (int j  = MAX_SIZE - 1 ; j > i; j--){
        arr[j] = arr[j-1];
    }
    arr[i] = x;
    return i;
}

int removeEntry(int x) {
    for (int i = 0; i < MAX_SIZE; i++){
        if (arr[i] == x ) {
            for (int j = i; j < MAX_SIZE; j++){
                arr[j] = arr[j+1];
            }
            return i;
        }
    }
    return 0;
}

void print_list() {
    for (int i = 0; i < MAX_SIZE; i++){
        printf("%d with index %d.\n", arr[i], i);
    }
    
}