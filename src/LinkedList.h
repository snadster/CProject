#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// A linked list containing any type of pointer.
// The linked list does _not_ own its elements.

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

struct LinkedList 
{
	LinkedListNode *head;
	LinkedListNode *tail;
	int size;
};

struct LinkedListNode 
{
	LinkedListNode *next;
	LinkedListNode *prev;
	void *data;
};

// Allocate and initialize an empty linked list.
// Returns: a pointer to the new linked list, or NULL on error.
// Post: the caller owns the linked list.
LinkedList *LinkedList_new()
{
	LinkedList *l = malloc(sizeof(LinkedList));
	LinkedList newLinkedList = {NULL, NULL, 0};
	l = newLinkedList;
	return l;
}

// Deallocate the given linked list, including all nodes
// (but _not_ the data they point to, the user owns that).
void LinkedList_delete(LinkedList *ll);
{
	LinkedListNode *current = ll.head;
	for (int i = 0; i < ll.size; i++) {
		LinkedListNode *next = current.next;
		free(current);
		current = next;
	}
	free(ll);
}

// Append the given element to the list.
// The linked list does _not_ take ownership over the element
// (only the linked list node).
// Returns: a pointer to the node with the new element, or NULL on error.
LinkedListNode *LinkedList_append(LinkedList *ll, void *elem)
{
	LinkedListNode *n = malloc(sizeof(LinkedListNode));
	LinkedListNode newNode = {NULL, ll.tail, elem}
	n = newNode;
	ll.tail.next = n;
	ll.tail = n;
	ll.size++;
	return n;
}

// Remove and return the first element from the given list.
// Pre: ll->size != 0
void *LinkedList_popFront(LinkedList *ll)
{
	if (ll.size == 0) {
		printf("Cannot pop from empty list");
	}
	LinkedListNode elem = ll.head;
	ll.head.next.prev = NULL;
	ll.head = ll.head.next;
	ll.size = ll.size - 1;
	return elem.data;
}

// Find the linked list node containing the given element.
// Returns: a pointer to the found node, or NULL if the element was not found.
LinkedListNode *LinkedList_find(LinkedList *ll, void *elem)
{
	LinkedListNode *current = ll.head;
	void *result = NULL;
	for (int i = 0; i <= ll.size; i++) {
		if (&elem == &current.data) {
			result = current.data;
		}
	}
	return result;
}

// Remove the given node from the given linked list (and deallocate it).
// Pre: node must belong to ll
// Returns: node->data
void *LinkedList_remove(LinkedList *ll, LinkedListNode *node)
{
	if (LinkedList_find(ll, node.data) == NULL) {
		printf("Node not in list");
	}
	node.prev.next = node.next;
	node.next.prev = node.prev; 
	ll.size = ll.size - 1;
	void *data = node.data;
	free(node);
	return data;
}

#endif // LINKEDLIST_H
