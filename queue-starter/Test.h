/**
*	@file .h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef TEST_H
#define TEST_H
#include "Queue.h"

class Test
{
	public:

	/**
	*	@post All tests are ran
	*/
	Test();


	/**
	*	@return true if isEmpty returns true on an empty queue
	*/
	bool test_isEmpty_on_empty_queue();

	/**
	*	@return true if isEmpty returns false on a non empty queue
	*/
    bool test_isEmpty_on_non_empty_queue();

	/**
	*	@return true if isEmpty returns true on a queue with logs of values
	*/
    bool test_isEmpty_on_non_empty_queue_large();

	/**
	*	@return true if isEmpty returns true when queue is enqueued twice and then dequeued twice
	*/
    bool test_isEmpty_on_empty_queue_enque_deque();


	/**
	*	@return true if peekFront returns error when called on empty queue
	*/
    bool test_peekFront_on_empty_queue();

	/**
	*	@return true if peekFront returns correct value if one node is enqueued
	*/
    bool test_peekFront_on_non_empty_queue();

	/**
	*	@return true if peekFront returns correct value for queue with 100 values
	*/
    bool test_peekFront_on_non_empty_queue_large();

	/**
	*	@return true if peekFront returns correct value after dequeueing all values
	*/
    bool test_peekFront_on_non_empty_queue_large_dequeued();


	/**
	*	@return true if dequeing a value from a queue with one value makes that queue empty
	*/
    bool test_dequeue_removes_normal();

	/**
	*	@return true if dequeue throws error when called on empty queue
	*/
    bool test_dequeue_throws_on_empty_queue();


	/**
	*	@return true if enqueueing once makes the queue not empty
	*/
    bool test_enqueue_adds_elements();

	/**
	*	@return true if enqueue adds correct value to queue
	*/
    bool test_enqueue_adds_correct_single_element();


	/**
	*	@return true if queue constructor creates empty queue
	*/
    bool test_constructor();

};



#endif
