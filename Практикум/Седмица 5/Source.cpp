#include <iostream>
#include "Vector.h"

int main() {
    std::cout << "Enter the size of your array: ";
    unsigned int size;
    std::cin >> size;
    if (!std::cin || size < 0) {
        throw std::runtime_error("Error! Invalid size!");
        return -1;
    }

    int* arr = new int[size];

    std::cout << "Enter the elements in your array: ";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
        if (!std::cin) {
            throw std::runtime_error("Error! Invalid input!");
            return -1;
        }
    }

    Vector vec(arr, size);

    std::cout << "Original Vector: ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    vec.pushBack(11);
    vec.insertAt(3, 8);
    vec.deleteAt(2);
    vec.popBack();
    vec.sort();
    vec.reverse();

    std::cout << "Modified Vector: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    Vector* vecSliced = vec.slice(1, 4);
    if (vecSliced) {
        std::cout << "Sliced Vector: ";
        for (size_t i = 0; i < vecSliced->getSize(); ++i) {
            std::cout << vecSliced->at(i) << " ";
        }
        std::cout << std::endl;
        delete vecSliced;
    }
    else {
        std::cout << "Invalid slice parameters." << std::endl;
    }

    return 0;
}
