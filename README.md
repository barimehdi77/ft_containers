# 🤔 Description
In this project, I re-implement a few container types of the C++ standard template library.
I have to comply with the C++98 standard, so any later feature of the containers *MUST NOT* be implemented, but every C++98 feature (even deprecated ones) is expected.

## Mandatory part
Implement the following containers and turn in the necessary <container>.hpp files:
  - vector
  - map
  - stack : </br>
    It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included.
    
You also have to implement:
  - iterators_traits
  - reverse_iterator
  - enable_if
  - is_integral
  - equal and/or lexicographical_compare
  - std::pair
  - std::make_pair

# 🛢 Containers
A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows great flexibility in the types supported as elements. 

The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers). 

## 🗃 vector
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

I re-implement the following member functions in vector class:
  - **Iterators**:
    - begin(): Returns an iterator pointing to the first element in the vector.
    - end(): Returns an iterator pointing to the theoretical element that follows the last element in the vector.
    - rbegin(): Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
    - rend(): Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
  - **Capacity**
    - size(): Returns the number of elements in the vector.
    - max_size(): Returns the maximum number of elements that the vector can hold.
    - capacity(): Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    - resize(n): Resizes the container so that it contains ‘n’ elements.
    - empty(): Returns whether the container is empty.
    - reserve(n): Requests that the vector capacity be at least enough to contain n elements.
  - **Element access:**
    - operator[g]: Returns a reference to the element at position ‘g’ in the vector.
    - at(g): Returns a reference to the element at position ‘g’ in the vector.
    - front(): Returns a reference to the first element in the vector.
    - back(): Returns a reference to the last element in the vector.
  - **Modifiers**
    - assign(): It assigns new value to the vector elements by replacing old ones.
    - push_back(): It push the elements into a vector from the back.
    - pop_back(): It is used to pop or remove elements from a vector from the back.
    - insert(): It inserts new elements before the element at the specified position.
    - erase(): It is used to remove elements from a container from the specified position or range.
    - swap(): It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
    - clear(): It is used to remove all the elements of the vector container.
  - **Allocator**
    - get_allocator(): Returns a copy of the allocator object associated with the vector.

## 🗄 stack
Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.  Stack uses an encapsulated object of either vector as its underlying container, providing a specific set of member functions to access its elements.

I re-implement the following member functions in vector class:
  - empty(): Returns whether the stack is empty – Time Complexity : O(1).
  - size(): Returns the size of the stack – Time Complexity : O(1).
  - top(): Returns a reference to the top most element of the stack – Time Complexity : O(1).
  - push(g): Adds the element ‘g’ at the top of the stack – Time Complexity : O(1).
  - pop(): Deletes the top most element of the stack – Time Complexity : O(1).

## 🗺 map
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have the same key values.
I re-implement the following member functions in map class:
  - **Iterators**
    - begin(): Returns an iterator referring to the first element in the map container.
    - end(): Returns an iterator referring to the past-the-end element in the map container
    - rbegin(): Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
    - rend(): Returns a reverse iterator pointing to the theoretical element right before the first element in the map container (which is considered its reverse end).
  - **Capacity**
    - empty(): Returns whether the map container is empty (i.e. whether its size is 0).
    - size(): Returns the number of elements in the map container.
    - max_size(): Returns the maximum number of elements that the map container can hold.
  - **Element access**
    - operator[g]: returns a reference to mapped value of key g.
  - **Modifiers**
    - insert(): Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
    - erase(): Removes from the map container either a single element or a range of elements ([first,last])).
    - swap(): Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
    - clear(): Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
  - **Observers**
    - key_comp(): Returns a copy of the comparison object used by the container to compare keys.
    - value_comp(): Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
  - **Operations**
    - find(g): Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.
    - count(g): Returns the number of matches to element with key-value ‘g’ in the map.
    - lower_bound(g): Returns an iterator to the first element that is equivalent to the mapped value with key-value ‘g’ or definitely will not go before the element with key-value ‘g’ in the map.
    - upper_bound(g): Returns an iterator to the first element that is equivalent to mapped value with key-value ‘g’ or definitely will go after the element with key-value ‘g’ in the map.
    - equal_range(g): Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to g.
  - **Allocator**
    - get_allocator(): Returns a copy of the allocator object associated with the map.

# 👨‍💻 Ressources
 - [std::iterator is deprecated: Why, What It Was, and What to Use Instead](https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/).
 - [Writing a custom iterator in modern C++](https://internalpointers.com/post/writing-custom-iterators-modern-cpp).
 - [Writing an ITERATOR in C++](https://www.youtube.com/watch?v=F9eDv-YIOQ0) {Video}.
 - [ITERATORS in C++](https://www.youtube.com/watch?v=SgcHcbQ0RCQ) {video}.
 - [Introduction to Iterators in C++](https://www.geeksforgeeks.org/introduction-iterators-c/).
 - [std::iterator_traits](https://www.cplusplus.com/reference/iterator/iterator_traits/).
 - [ptrdiff_t](https://www.cplusplus.com/reference/cstddef/ptrdiff_t/).
 - [reverse_iterator cplusplus](https://www.cplusplus.com/reference/iterator/reverse_iterator/).
 - [reverse_iterator cppreference](https://en.cppreference.com/w/cpp/iterator/reverse_iterator).
 - [What does the explicit keyword mean?](https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean).
 - [vector insert() function in C++ STL](https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/).
 - [boost's Vector source file](https://www.boost.org/doc/libs/1_53_0/boost/container/vector.hpp).
 - [Tree data structure explain **arabic**](https://www.youtube.com/watch?v=7Gg8bbshTIw&list=PLwCMLs3sjOY4UQq4vXgGPwGLVX1Y5faaS&index=22&ab_channel=Hard-Code).
 - [AVL 1 Introduction](https://www.youtube.com/watch?v=-9sHvAnLN_w&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=60).
 - [AVL Trees with Implementation in C++, Java, and Python](https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/).
 - [AVL Tree Implementation](https://runestone.academy/ns/books/published/cppds/Trees/AVLTreeImplementation.html).
 - [AVL Tree visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html).
 - [Binary Search & AVL Tree visualization](https://visualgo.net/en/bst?slide=1).
 - [AVL Tree](https://www.programiz.com/dsa/avl-tree#cpp-code).
 - [AVL Tree | Set 1 (Insertion)](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/).
 - [AVL Tree 6 Rebalancing AVL trees](https://www.youtube.com/watch?v=wn1tc5SAGZk&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=66) {Video}.
 - [Inorder Successor in Binary Search Tree](https://www.youtube.com/watch?v=kr3BOCNEYHI) {video}.
 - [map insert() in C++ STL](https://www.geeksforgeeks.org/map-insert-in-c-stl/).
 - [std::allocator cplusplus](https://www.cplusplus.com/reference/memory/allocator/).
 - [std::map cplusplus](http://www.cplusplus.com/reference/map/map/).
 - [Binary Search Trees (BST) with code in C++, Python, and Java](https://algorithmtutor.com/Data-Structures/Tree/Binary-Search-Trees/).
 - [Data Structure and Algorithms - AVL Trees](https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm).
 - [std::map cppreference](https://en.cppreference.com/w/cpp/container/map).
 - [boost's map source file](https://www.boost.org/doc/libs/1_53_0/boost/container/map.hpp).
 - [boost's Tree source file](https://www.boost.org/doc/libs/1_53_0/boost/container/detail/tree.hpp).
 - [how exactly insert of map exactly work in c++?](https://stackoverflow.com/questions/71336702/how-exactly-insert-of-map-exactly-work-in-c).
 - [std::stack cplusplus](http://www.cplusplus.com/reference/stack/stack/?kw=stack).
 - [C++ enable-if](https://www.youtube.com/watch?v=H-m23Vvzcug) {video}.
 - [Containers in C++ STL (Standard Template Library)](https://www.geeksforgeeks.org/containers-cpp-stl/).
 - [Vector in C++ STL](https://www.geeksforgeeks.org/vector-in-cpp-stl/).
