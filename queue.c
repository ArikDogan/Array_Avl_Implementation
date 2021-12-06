#include "queue.h"

LINKED_QUEUE linked_queue_init() {
    LINKED_QUEUE new = malloc(sizeof(LINKED_QUEUE_t));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

LINKED_QUEUE_NODE linked_queue_node_init() {
    LINKED_QUEUE_NODE new = malloc(sizeof(LINKED_QUEUE_NODE_t));
    new->data = NULL;
    new->next = NULL;
    return new;
}

void *linked_queue_dequeue(LINKED_QUEUE queue) {
    LINKED_QUEUE_NODE res, node;
    node = (LINKED_QUEUE_NODE) queue->head;
    if (node != NULL) {
        queue->head = node->next;
        res = node->data;
    } else {
        printf("Queue is empty!");
    }
    return res;
}

void linked_queue_enqueue(LINKED_QUEUE queue, void *data) {
    LINKED_QUEUE_NODE newNode = linked_queue_node_init();
    newNode->data = data;
    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        LINKED_QUEUE_NODE tmpNode = (LINKED_QUEUE_NODE) queue->tail;
        while (tmpNode->next != NULL) {
            tmpNode = tmpNode->next;
        }
        tmpNode->next = newNode;
        queue->tail = newNode;
    }
}

void linked_queue_print(LINKED_QUEUE queue) {
    LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE) queue->head;
    while (node != NULL) {
        printf("%d ", *(int *) node->data);
        node = node->next;
    }
}

bool linked_queue_is_empty(LINKED_QUEUE queue) {
    LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE) queue->head;
    if (node != NULL) {
        return false;
    }
    return true;
}

