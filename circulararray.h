#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray(int _capacity = 10);
    virtual ~CircularArray();
    void push_front(T data) {
        if (is_full()) {
            cout << "No more free space" << endl;
        }
        else if (is_empty()) {
            front = 0;
            back = 0;
            array[front] = data;
        }
        else {
            front = (front - 1 + capacity) % capacity;
            array[front] = data;
        }
    };
    void push_back(T data) {
        if (is_full()) {
            cout << "No more free space" << endl;
        }
        else if (is_empty()) {
            front = 0;
            back = 0;
            array[back] = data;
        }
        else {
            back = (back + 1) % capacity;
            array[back] = data;
        }
    };
    void insert(T data, int pos);
    T pop_front() {
        if (is_empty()) {
            cout << "No values in array" << endl; 
        }
        else if (front == back) {
            front = -1;
            back = -1;
        }
        else {
            front = (front + 1) % capacity
        }
    };
    T pop_back() {
        if (is_empty()) {
            cout << "No values in array" << endl;
        }
        else if (front == back) {
            front = -1;
            back = -1;
        }
        else {
            back = (back - 1 + capacity) % capacity;
        }
    };
    bool is_full() {
        return (back + 1) % capacity == front;
    };
    bool is_empty() {
        return front == -1 && back == -1;
    };
    int size() {
        if (is_empty()) {
            return 0;
        }
        else if (front <= back) {
            return back - front + 1;
        }
        else {
            return capacity - front + back + 1;
        }
    };
    void clear() {
        front = -1;
        back = -1;
    };
    T& operator[](int) {
        if (is_empty( || int < 0 || int >= getSize())) {
            cout << "Invalid value" << endl
        }
        return array[int]
    };    
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}
