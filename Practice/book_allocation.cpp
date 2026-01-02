#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_possible(int *books, int size, int students, int *s, int *e){
    int mid = *s + (*e - *s)/2, current_pages = 0, student_Alloted = 1;
    for(int i = 0; i<size; i++){
        current_pages += books[i];
        if(current_pages > mid && books[i] <= mid){
            student_Alloted ++;
            current_pages = books[i];
        }
        else if(books[i] > mid){
            *s = mid+1;
            return 0;
        }
    }

        if(student_Alloted > students){
            *s = mid+1;
            return 0;
        }
        if(student_Alloted < students){
            *e = mid - 1;
            return 0;
        }
    return 1;
}

int book_allocation(int books[], int students, int size){

    int s = *max_element(books, books + size);
    int e = accumulate(books, books+size, 0);
    if(size<students) return -1;
    if(size == students) return s;
    int ans = -1;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(is_possible(books, size, students, &s, &e)){
            ans = mid;
            // cout<<"When mid : "<<mid<<" ans : "<<ans<<endl;
            e = mid - 1;
        }
    }
    return ans;
}

int main(){

    int no_of_books = 0;
    cin>>no_of_books;

    int books [no_of_books];
    for(int i = 0; i< no_of_books; i++){
        cin>>books[i];
    }
    int students = 0;
    cin>>students;
    
    cout<<book_allocation(books, students , no_of_books)<<endl;
    

    return 0;
}
