#include <iostream>
#include "Test.h"

Test::Test() {
    std::cout << "Running Test Suite:\n";

    std::cout << "Test 1: " << "Newly created queue is empty: " << (test_isEmpty_on_empty_queue() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 2: " << "Enqueued new queue is not empty: " << (test_isEmpty_on_non_empty_queue() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 3: " << "Enqueued 100 times queue is not empty: " << (test_isEmpty_on_non_empty_queue_large() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 4: " << "Enqueued and Dequeued twice is empty: " << (test_isEmpty_on_empty_queue_enque_deque() ? "PASSED" : "FAILED") << '\n';

    std::cout << "Test 5: " << "Peek on empty queue throws error: " << (test_peekFront_on_empty_queue() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 6: " << "Peek on queue with one node returns correct value " << (test_peekFront_on_non_empty_queue() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 7: " << "Peek on queue with 100 nodes returns correct value: " << (test_peekFront_on_non_empty_queue_large() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 8: " << "Peek on queue will 100 nodes and then each node has correct value after dequeue: " << (test_peekFront_on_non_empty_queue_large_dequeued() ? "PASSED" : "FAILED") << '\n';

    std::cout << "Test 9: " << "Enqueueing one value and then dequeueing one value makes the queue empty: " << (test_dequeue_removes_normal() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 10: " << "Dequeuing on an empty queue throws an error: " << (test_dequeue_throws_on_empty_queue() ? "PASSED" : "FAILED") << '\n';

    std::cout << "Test 11: " << "Enqueue one element and the queue is not empty: " << (test_enqueue_adds_elements() ? "PASSED" : "FAILED") << '\n';
    std::cout << "Test 12: " << "Enqueue one element adds the correct element to the queue: " << (test_enqueue_adds_correct_single_element() ? "PASSED" : "FAILED") << '\n';

    std::cout << "Test 12: " << "The constructor creates an empty queue: " << (test_constructor() ? "PASSED" : "FAILED") << '\n';
}

/**
 * isEmpty()
 */
bool Test::test_isEmpty_on_empty_queue() {
    Queue q;
    return q.isEmpty();
}

bool Test::test_isEmpty_on_non_empty_queue() {
    Queue q;
    q.enqueue(1);
    return !q.isEmpty();
}

bool Test::test_isEmpty_on_non_empty_queue_large() {
    Queue q;
    for(int i = 0; i < 100; i++) {
        q.enqueue(i);
    }
    return !q.isEmpty();
}

bool Test::test_isEmpty_on_empty_queue_enque_deque() {
    Queue q;
    q.enqueue(1);
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    return q.isEmpty();
}

/**
 * peekFront()
 */
bool Test::test_peekFront_on_empty_queue() {
    Queue q;
    try {
        q.peekFront();
        return false;
    } catch(std::runtime_error e) {
        return true;
    }
    return false;
}

bool Test::test_peekFront_on_non_empty_queue() {
    Queue q;
    q.enqueue(1);
    if(q.peekFront() == 1) {
        return true;
    }
    return false;
}

bool Test::test_peekFront_on_non_empty_queue_large() {
    Queue q;
    for(int i = 0; i < 100; i++) {
        q.enqueue(i);
    }
    if(q.peekFront() == 0) {
        return true;
    }
    return false;
}

bool Test::test_peekFront_on_non_empty_queue_large_dequeued() {
    Queue q;
    for(int i = 0; i < 100; i++) {
        q.enqueue(i);
    }
    for(int i = 0; i < 100; i++) {
        if(q.peekFront() != i) {
            return false;
        }
        q.dequeue();
    }
    return true;
}

/**
 * dequeue()
 */
bool Test::test_dequeue_removes_normal() {
    Queue q;
    for(int i = 0; i < 100; i++) {
        q.enqueue(i);
    }
    for(int i = 0; i < 100; i++) {
        q.dequeue();
    }

    return q.isEmpty();
}

bool Test::test_dequeue_throws_on_empty_queue() {
    Queue q;
    q.enqueue(1);
    q.dequeue();
    try {
        q.dequeue();
    } catch(std::runtime_error e) {
        std::cout << e.what() << "\n";
        return true;
    }
    return false;
}

/**
 * enqueue();
 */
bool Test::test_enqueue_adds_elements() {
    Queue q;
    q.enqueue(1);
    return !q.isEmpty();
}

bool Test::test_enqueue_adds_correct_single_element() {
    Queue q;
    q.enqueue(1);
    return q.peekFront() == 1;
}

/**
 * constructor/destructor
 */
bool Test::test_constructor() {
    Queue q;
    return q.isEmpty();
}
