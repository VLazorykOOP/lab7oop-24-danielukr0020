#include <iostream>
#include <cstring>

template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <>
const char* min(const char* const& a, const char* const& b) {
    return (strcmp(a, b) < 0) ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <>
const char* max(const char* const& a, const char* const& b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

template <>
void selectionSort<const char*>(const char* arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int a = 10, b = 20;
    std::cout << "min(10, 20) = " << min(a, b) << std::endl;
    std::cout << "max(10, 20) = " << max(a, b) << std::endl;

    double c = 10.5, d = 20.5;
    std::cout << "min(10.5, 20.5) = " << min(c, d) << std::endl;
    std::cout << "max(10.5, 20.5) = " << max(c, d) << std::endl;

    const char* e = "apple";
    const char* f = "banana";
    std::cout << "min(\"apple\", \"banana\") = " << min(e, f) << std::endl;
    std::cout << "max(\"apple\", \"banana\") = " << max(e, f) << std::endl;

    int arrInt[] = { 5, 2, 9, 1, 5, 6 };
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    selectionSort(arrInt, nInt);
    std::cout << "Sorted integers: ";
    for (int i = 0; i < nInt; ++i) {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;

    double arrDouble[] = { 3.5, 2.1, 5.9, 1.6, 3.5 };
    int nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    selectionSort(arrDouble, nDouble);
    std::cout << "Sorted doubles: ";
    for (int i = 0; i < nDouble; ++i) {
        std::cout << arrDouble[i] << " ";
    }
    std::cout << std::endl;

    const char* arrStr[] = { "banana", "apple", "cherry", "date" };
    int nStr = sizeof(arrStr) / sizeof(arrStr[0]);
    selectionSort(arrStr, nStr);
    std::cout << "Sorted strings: ";
    for (int i = 0; i < nStr; ++i) {
        std::cout << arrStr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void remove(const T& data) {
        if (head == nullptr) return;

        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next == nullptr) return;

        Node<T>* temp = current->next;
        current->next = current->next->next;
        if (current->next == nullptr) {
            tail = current;
        }
        delete temp;
    }

    bool search(const T& data) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print();

    list.remove(2);
    list.print();

    std::cout << "Search 3: " << list.search(3) << std::endl;
    std::cout << "Search 2: " << list.search(2) << std::endl;

    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* p) : ptr(p) {}

    T& operator*() const {
        return *ptr;
    }

    Iterator& operator++() {
        ++ptr;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++ptr;
        return tmp;
    }

    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }
};

template <typename T, int size>
class Array {
private:
    T arr[size];

public:
    Array() {}

    T& operator[](int index) {
        return arr[index];
    }

    Iterator<T> begin() {
        return Iterator<T>(arr);
    }

    Iterator<T> end() {
        return Iterator<T>(arr + size);
    }
};

int main() {
    Array<int, 5> arr;

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }

    cout << "Array elements: ";
    for (Iterator<int> it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
