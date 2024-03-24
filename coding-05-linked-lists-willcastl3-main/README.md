# Doubly Linked List Implementation

## Overview

This repository contains a fully functional implementation of a doubly linked list in C++. The linked list is implemented using a custom `LinkedList` class, along with supporting structures and functions.

## Files

- **data.h**: Header file defining the `Data` struct used in the linked list.
- **linkedlist.h**: Header file defining the `LinkedList` class.
- **linkedlist.cpp**: Implementation file for the methods of the `LinkedList` class.
- **main.h**: Header file for the main program.
- **main.cpp**: Main program file demonstrating the usage of the doubly linked list.
- **testdata.h**: Header file defining the `testData` class used for generating test data.
- **testdata.cpp**: Implementation file for the methods of the `testData` class.

## Usage

To use the provided doubly linked list implementation, follow these steps:

1. Clone the repository to your local machine.
2. Include the necessary header files (`data.h`, `linkedlist.h`, `main.h`, `testdata.h`) in your project.
3. Implement the main logic of your program using the `LinkedList` class methods as needed.
4. Compile your program with the necessary source files (`linkedlist.cpp`, `main.cpp`, `testdata.cpp`).

## Functionality

The `LinkedList` class provides the following functionality:

- **Adding a Node**: Add a new node to the linked list with a specified ID and data.
- **Deleting a Node**: Delete a node from the linked list based on its ID.
- **Getting a Node**: Retrieve the data of a node with a specified ID from the linked list.
- **Printing the List**: Print the contents of the linked list, either forward or backward.
- **Counting Nodes**: Get the total count of nodes in the linked list.
- **Clearing the List**: Remove all nodes from the linked list.
- **Checking Node Existence**: Check if a node with a specified ID exists in the linked list.

## Example
```cpp
#include "linkedlist.h"

int main() {
    LinkedList list;

    // Add nodes to the list
    list.addNode(1, new std::string("First node"));
    list.addNode(2, new std::string("Second node"));
    list.addNode(3, new std::string("Third node"));

    // Print the list forward
    std::cout << "Printing list forward:" << std::endl;
    list.printList();

    // Print the list backward
    std::cout << "\nPrinting list backward:" << std::endl;
    list.printList(true);

    // Get node with ID 2
    Data data;
    if (list.getNode(2, &data)) {
        std::cout << "\nNode with ID 2: " << data.data << std::endl;
    } else {
        std::cout << "\nNode with ID 2 not found." << std::endl;
    }

    // Delete node with ID 2
    list.deleteNode(2);

    // Print the list forward after deletion
    std::cout << "\nPrinting list forward after deletion:" << std::endl;
    list.printList();

    return 0;
}
```

## Testing

The main program (`main.cpp`) demonstrates the usage of the doubly linked list with a set of test data generated using the `testData` class. You can modify or extend this program to further test the functionality of the linked list implementation.
