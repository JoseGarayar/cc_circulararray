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
    void insert(T data, int pos) {
        array[front] = data;
        front = (front + 1) % size();
    };
    T pop_front() {
        int return_val;
        if (is_empty()) {
            cout << "No values in array" << endl; 
        }
        else if (front == back) {
            front = -1;
            back = -1;
        }
        else {
            return_val = array[front];
            front = (front + 1) % capacity;
        }
        return return_val;
    };
    T pop_back() {
        int return_val;
        if (is_empty()) {
            cout << "No values in array" << endl;
        }
        else if (front == back) {
            front = -1;
            back = -1;
        }
        else {
            return_val = array[back];
            back = (back - 1 + capacity) % capacity;
        }
        return return_val;
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
    T& operator[](int i) {
        if (is_empty() || i < 0 || i >= size()) {
            cout << "Invalid value" << endl;
        }
        return array[i];
    };    
    void sort() {
        int i, j, temp;
        int actual_size = size();
        for (int i = 0; i < actual_size; i++) {
            for (int j = i + 1; j < actual_size; j++) {
                int current = (front + i) % actual_size;
                int next = (front + j) % actual_size;
                if (array[current] > array[next]) {
                    temp = array[current];
                    array[current] = array[next];
                    array[next] = temp;
                }
            }
        }
    };
    bool is_sorted() {
        int actual_size = size();
        for (int i = 0; i < actual_size - 1; i++){
            int current = (front + i) % actual_size;
            int next = (front + i + 1) % actual_size;
            if (array[current] > array[next]) {
                return false;
            }
        }
        return true;
    };
    void reverse() {
        int i, j, temp;
        int actual_size = size();
        for (i = 0, j = actual_size - 1; i < j; i++, j--) {
            int current = (front + i) % actual_size;
            int reverse = (front + j) % actual_size;
            temp = array[current];
            array[current] = array[reverse];
            array[reverse] = temp;
        }
    };
    string to_string(string sep=" ") {
        if (is_empty()) {
            cout << "No elements" << endl;
        }
        string return_val = "";
        for (int i = 0; i < size(); i++) {
            auto s = std::to_string(array[i]);
            return_val.append(s + sep);
        }
        return return_val;
    };

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
