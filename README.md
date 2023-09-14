# Forward List (FList) C++ Class

The `FList` (Forward List) is a C++ class template designed to implement a singly linked list. It provides basic operations for creating, manipulating, and working with a list of elements.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Public Member Functions](#public-member-functions)
- [Iterator](#iterator)
- [Example Usage](#example-usage)
- [Contributing](#contributing)

## Introduction

The `FList` class is a versatile data structure that allows you to create a singly linked list of elements of any data type. It supports operations such as insertion, deletion, finding elements, merging lists, and more.

## Usage

To use the `FList` class in your C++ program, follow these steps:

1. Include the necessary headers:
   ```cpp
   #include "FList.h"
   ```

2. Create an instance of the `FList` class, specifying the data type you want to store in the list:
   ```cpp
   FList<int> myList; // Creates a list of integers
   ```

3. Use the available member functions to manipulate the list as needed. Refer to the [Public Member Functions](#public-member-functions) section for details on available functions.

4. Don't forget to manage memory properly when using dynamic memory allocation.

## Public Member Functions

The `FList` class provides the following public member functions:

- `FList()`: Default constructor.
- `FList(const FList<T>&)`: Copy constructor.
- `FList(FList<T>&&) noexcept`: Move constructor.
- `FList(std::initializer_list<T>)`: Constructor that accepts an initializer list.
- `~FList()`: Destructor.
- Various functions for insertion, deletion, finding, and manipulation of elements.
- `T& front()`: Returns a reference to the first element.
- `bool operator==(const FList<T>&) const`: Equality operator.
- `void print()`: Outputs the elements of the list.
- `begin()`: Returns an iterator pointing to the beginning of the list.
- `end()`: Returns an iterator pointing to the end of the list.

## Iterator

The `FList` class includes an iterator class that allows you to iterate over the elements of the list.

To use the iterator:

```cpp
FList<int>::Iterator it = myList.begin();
while (it != myList.end()) {
    // Access the current element using *it or it->value
    ++it; // Move to the next element
}
```

## Example Usage

Here's a simple example of how to use the `FList` class:

```cpp
#include "FList.h"

int main() {
    FList<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    myList.print(); // Output: 1 2 3

    return 0;
}
```

## Contributing

Contributions to this project are welcome! If you find a bug or have an improvement suggestion, please create an issue or submit a pull request.
