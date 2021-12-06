#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Array_AVL_s{
    int *key;
    int *height;
    void **data;
    int level;
    int size;
}ARRAY_AVL_t[1], *ARRAY_AVL;

ARRAY_AVL init_array_avl();
void deallocate_array_avl(ARRAY_AVL tree);
void insert_array_avl(ARRAY_AVL tree, int key, void* data, int start, int *height);
void delete_array_avl(ARRAY_AVL tree, int key, int min_key, int start, int *height, int choose);
int update_height(ARRAY_AVL tree , int index);
int balance_factor(ARRAY_AVL tree, int index);
void breath_first_traverse(ARRAY_AVL tree);
void print_array_avl(ARRAY_AVL tree, int start, int counter);
void left_left_rotation(ARRAY_AVL tree, int parent, int child);
void right_right_rotation(ARRAY_AVL tree, int parent, int child);
void decrease_size(ARRAY_AVL tree);
void size_subtree(ARRAY_AVL tree, int index, int *counter_ptr);
void bft_for_rotations(ARRAY_AVL tree, ARRAY_AVL index_sub, int index, int *point_ptr, int size_sub);
void bft_swap_elements(ARRAY_AVL tree, ARRAY_AVL index_sub, int index, int *point_ptr, int size_sub);
void delete_with_one_child(ARRAY_AVL tree, int index);
void delete_dublicate(ARRAY_AVL tree);
void print_height_array_avl(ARRAY_AVL tree, int start, int counter);
void balance_array_avl(ARRAY_AVL tree, int start);

//When running code it gives some error but it works these errors causes by inserting integer into to queue which keeps void* = 8 byte but also integer is 4 byte so it can keep it


// After each insertion *heigh_ptr must be assigned to 1 (*height_ptr = 1)
int main(){
    int height = 1, choose = 0;
    ARRAY_AVL tree = init_array_avl();
    int *height_ptr = &height;

    //example for calling insert_array_avl(tree, key, data should be null, start should be 0, height_ptr)

    insert_array_avl(tree, 17, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 47, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 33, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    for(int i = 0; i < (1 << (tree->level + 1)) - 1; i++){
    printf("%d ", tree->height[i]);
    }
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 12, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 8, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 25, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 37, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 44, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 2, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 13, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 98, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 82, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;
    insert_array_avl(tree, 75, NULL, 0, height_ptr);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    printf("\nBreath_First_Traverse\n");
    breath_first_traverse(tree);
    printf("\n");


    printf("\n\n DELETION \n\n");
    printf("------------------------------------------");
    printf("\n\n");


    // After each deletion you can use decrease size function to delete unnecessary empty areas
    // When we are deleting node from array min_key, start and choose must be assigned to 0 also *height_ptr must be assigned to 1
    // example for calling deletion delete_array_avl(tree, key, min_key should be 0, start should be 0, heigh_ptr, choose should be 0
    delete_array_avl(tree, 17, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 98, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 13, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 12, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 2, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 44, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 82, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 33, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 8, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 25, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 47, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 75, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;

    delete_array_avl(tree, 37, 0, 0 , height_ptr, 0);
    decrease_size(tree);
    print_array_avl(tree, 0, 1);
    printf("\n");
    print_height_array_avl(tree, 0, 1);
    printf("\n");
    printf("------------------------------------------");
    printf("\n");
    *height_ptr = 1;


    return 0;
}

ARRAY_AVL init_array_avl(){
    ARRAY_AVL tree = (ARRAY_AVL) malloc(sizeof(ARRAY_AVL_t));
    tree->key = NULL;
    tree->height = NULL;
    tree->data = NULL;
    tree->level = 0;
    tree->size = 0;
    return tree;
}

ARRAY_AVL init_array_avl2(int size){
    ARRAY_AVL tree = (ARRAY_AVL) malloc(sizeof(ARRAY_AVL_t));
    tree->key = (int *) malloc(sizeof(int) * size);
    tree->height = (int *) malloc(sizeof(int) * size);
    tree->data = (void **) malloc(sizeof(void *) * size);
    tree->level = 0;
    tree->size = 0;
    return tree;
}

void deallocate_array_avl(ARRAY_AVL tree){
    free(tree->key);
    for(int i = 0; i < (1 << (tree->level + 1)) - 1; i++){
        if(tree->key[i] != -1){
            free(tree->data[i]);
        }
    }
    free(tree->data);
    free(tree->height);
    free(tree);
}

void insert_array_avl(ARRAY_AVL tree, int key, void* data, int start, int *height) {
    if (tree == NULL) {
        printf("Error @@ Tree is not initiliazed !!!\n");
    } else if (tree->size == 0) {
        tree->level = 1;
        tree->key = (int *) malloc(sizeof(int) * ((1 << (tree->level + 1)) - 1));
        tree->key[0] = key;
        tree->height = (int *) malloc(sizeof(int) * ((1 << (tree->level + 1)) - 1));
        tree->height[0] = 1;
        tree->data = (void **) malloc(sizeof(void *) * ((1 << (tree->level + 1)) - 1));
        tree->data[0] = data;
        tree->size = tree->size + 1;
        for (int i = 1; i < 3; i++) {
            tree->key[i] = -1;
            tree->height[i] = 0;
        }
    } else {
        if (tree->key[start] == -1) {
            if (*height > tree->level) {
                tree->level = tree->level + 1;
                tree->key = (int *) realloc(tree->key, sizeof(int) * ((1 << (tree->level + 1)) - 1));
                tree->height = (int *) realloc(tree->height, sizeof(int) * ((1 << (tree->level + 1)) - 1));
                tree->data = (void **) realloc(tree->data, sizeof(void *) * ((1 << (tree->level + 1)) - 1));

                int before = (1 << (tree->level)) - 1;
                int after = (1 << (tree->level + 1)) - 2;
                for (int i = before; i <= after; i++) {
                    tree->key[i] = -1;
                    tree->height[i] = 0;
                }
            }
            tree->key[start] = key;
            tree->height[start] = 1;
            tree->data[start] = data;
            tree->size = tree->size + 1;

        } else if (tree->key[start] == key) {
            printf("Error @@ Dublicated key not inserted !!!\n");
        }
        else if (key < tree->key[start]) {
            int left_child = 2 * start + 1, right_child = 2 * start + 2;
            *height = *height + 1;
            insert_array_avl(tree, key, data, (start * 2) + 1, height);
            tree->height[start] = update_height(tree, start);
            if (balance_factor(tree, start) == 1) {
                if (tree->height[left_child] > tree->height[right_child]) {
                    int left_left_child = 2 * left_child + 1, left_right_child = 2 * left_child + 2;
                    if (tree->height[left_left_child] >= tree->height[left_right_child]) {
                        left_left_rotation(tree, start, 2 * start + 1);
                        tree->height[start] = update_height(tree, start);
                    }
                    else if (tree->height[left_left_child] < tree->height[left_right_child]){
                        int parent = 2 * start + 1;
                        int child = 2 * parent + 2;
                        right_right_rotation(tree, parent, child);
                        left_left_rotation(tree, start, 2 * start + 1);
                        tree->height[start] = update_height(tree, start);
                    }
                }
            }
        } else {
            int left_child = 2 * start + 1, right_child = 2 * start + 2;
            *height = *height + 1;
            insert_array_avl(tree, key, data, (start * 2) + 2, height);
            tree->height[start] = update_height(tree, start);
            if (balance_factor(tree, start) == 1) {
                if (tree->height[left_child] < tree->height[right_child]) {
                    int right_right_child = 2 * right_child + 2, right_left_child = 2 * right_child + 1;
                    if (tree->height[right_right_child] >= tree->height[right_left_child]){
                        right_right_rotation(tree, start, 2 * start + 2);
                        tree->height[start] = update_height(tree, start);
                    }
                    else if (tree->height[right_right_child] < tree->height[right_left_child]) {
                        int parent = 2 * start + 2;
                        int child = 2 * parent + 1;
                        left_left_rotation(tree, parent, child);
                        right_right_rotation(tree, start, 2 * start + 2);
                        tree->height[start] = update_height(tree, start);
                    }
                }
            }

        }
    }
}

void delete_array_avl(ARRAY_AVL tree, int key, int min_key, int start, int *height, int choose){
    if(choose == 1){
        if(tree->key[2 * min_key + 1] != -1){
            delete_array_avl(tree, key, 2 * min_key + 1, start, height, choose);
            tree->height[min_key] = update_height(tree, min_key);
            if(balance_factor(tree, min_key) == 1){
                balance_array_avl(tree, min_key);
                tree->height[min_key] = update_height(tree, min_key);
            }
        }
        else{
            tree->key[start] = tree->key[min_key];
            tree->data[start] = tree->data[min_key];
            delete_with_one_child(tree, 2 * min_key + 2);
        }
    }
    else if(tree == NULL){
        printf("ERROR @@ Tree is not initiliazed !!!\n");
    }
    else{
        if(tree->key[start] == -1){
            printf("ERROR @@ There is no element which have your key !!!\n");
        }
        else if(tree->key[start] == key) {
            int left_child = 2 * start + 1, right_child = 2 * start + 2;
            if(tree->key[left_child] == -1 && tree->key[right_child] == -1){
                free(tree->data[start]);
                tree->key[start] = -1;
                tree->height[start] = 0;
                tree->size = tree->size - 1;
            }
            else if(tree->key[left_child] != -1 && tree->key[right_child] == -1){
                free(tree->data[start]);
                tree->size = tree->size - 1;
                delete_with_one_child(tree, 2 * start + 1);
            }
            else if(tree->key[left_child] == -1 && tree->key[right_child] != -1){
                free(tree->data[start]);
                tree->size = tree->size - 1;
                delete_with_one_child(tree, 2 * start + 2);
            }
            else{
                int min_index = 2 * start + 2;
                if(tree->key[2 * min_index + 1] == - 1){
                    tree->data[start] = tree->data[min_index];
                    tree->key[start] = tree->key[min_index];
                    delete_with_one_child(tree, 2 * min_index + 2);
                    tree->height[start] = update_height(tree, start);
                    if(balance_factor(tree, start) == 1){
                        balance_array_avl(tree, start);
                        tree->height[start] = update_height(tree, start);
                    }
                }
                else{
                    choose = 1;
                    delete_array_avl(tree, key, min_index, start, height, choose);
                    tree->height[start] = update_height(tree, start);
                }
            }
        }
        else if(key < tree->key[start]){
            delete_array_avl(tree, key, min_key, 2 * start + 1, height, choose);
            tree->height[start] = update_height(tree, start);
            if(balance_factor(tree, start) == 1){
                balance_array_avl(tree, start);
                tree->height[start] = update_height(tree, start);
            }
        }
        else if(key > tree->key[start]){
           delete_array_avl(tree, key, min_key, 2 * start + 2, height, choose);
           tree->height[start] = update_height(tree, start);
           if(balance_factor(tree, start) == 1){
               balance_array_avl(tree, start);
               tree->height[start] = update_height(tree, start);
           }
        }
    }
}

int update_height(ARRAY_AVL tree , int index){
    int left_child = (2 * index) + 1, right_child = (2 * index) + 2;

    if(tree->height[left_child] > tree->height[right_child]){
        return tree->height[left_child] + 1;
    }
    return tree->height[right_child] + 1;
}

int balance_factor(ARRAY_AVL tree, int index){
    int left_child = (2 * index) + 1, right_child = (2 * index) + 2;
    int difference = tree->height[left_child] - tree->height[right_child];

    if(difference == 1 || difference == 0 || difference == -1){
        return 0; // No need for rotation
    }
    return 1; // Make rotation
}

void breath_first_traverse(ARRAY_AVL tree){
    for(int i = 0; i  < (1 << (tree->level + 1)) - 1; i++){
        if(tree->key[i] != -1){
            printf("%d ", tree->key[i]);
        }
    }
}

void print_array_avl(ARRAY_AVL tree, int start, int counter){
    if(tree->key[start] != -1){
        counter++;
        print_array_avl(tree, 2 * start + 2, counter);
        counter--;
        printf("\n");
        for(int i = 0; i < counter*5; i++){
            printf(" ");
        }
        printf("%d", tree->key[start]);
        counter++;
        print_array_avl(tree, 2 * start + 1,counter);
        counter--;
    }
}

void decrease_size(ARRAY_AVL tree){
    if(tree->height[0] < tree->level){
        tree->key = (int *) realloc(tree->key, sizeof(int) * (1 << tree->level));
        tree->height = (int *) realloc(tree->height, sizeof(int) * (1 << tree->level));
        tree->data = (void **) realloc(tree->data, sizeof(void *) * (1 << tree->level));
        tree->level = tree->level - 1;
    }
}

void delete_with_one_child(ARRAY_AVL tree, int index){
    int size_sub = 0, point = 0, parent;
    int *size_sub_ptr = &size_sub;
    int *point_ptr = &point;
    size_subtree(tree, index, size_sub_ptr);
    ARRAY_AVL index_sub = init_array_avl2(size_sub);
    bft_for_rotations(tree, index_sub, index, point_ptr, size_sub);
    parent = (index - 1)/2;
    *point_ptr = 0;
    bft_swap_elements(tree, index_sub, parent, point_ptr, size_sub);
    delete_dublicate(tree);
}
void bft_swap_elements(ARRAY_AVL tree, ARRAY_AVL index_sub, int index, int *point_ptr, int size_sub){
    LINKED_QUEUE queue = linked_queue_init();
    int current_index;
    linked_queue_enqueue(queue, index);
    while(*point_ptr < size_sub){
        current_index = linked_queue_dequeue(queue);
        tree->key[current_index] = index_sub->key[*point_ptr];
        tree->data[current_index] = index_sub->data[*point_ptr];
        tree->height[current_index] = index_sub->height[*point_ptr];
        *point_ptr = *point_ptr + 1;

        if(index_sub->key[(*point_ptr - 1)/2] < index_sub->key[*point_ptr]){
            linked_queue_enqueue(queue, 2 * current_index + 2);
            linked_queue_enqueue(queue, 2 * current_index + 1);
        }
        else{
            linked_queue_enqueue(queue, 2 * current_index + 1);
            linked_queue_enqueue(queue, 2 * current_index + 2);
        }
    }
}


void size_subtree(ARRAY_AVL tree, int index, int *counter_ptr){
    if(tree->key[index] != -1){
        *counter_ptr = *counter_ptr + 1;
        size_subtree(tree, 2 * index + 1, counter_ptr);
        size_subtree(tree, 2 * index + 2, counter_ptr);
    }
}

void bft_for_rotations(ARRAY_AVL tree, ARRAY_AVL index_sub, int index, int *point_ptr , int size_sub){
    LINKED_QUEUE queue = linked_queue_init();
    int current_index;
    linked_queue_enqueue(queue, index);
    while(linked_queue_is_empty(queue) == false && *point_ptr < size_sub){
        current_index = linked_queue_dequeue(queue);
        index_sub->key[*point_ptr] = tree->key[current_index];
        index_sub->data[*point_ptr] = tree->data[current_index];
        index_sub->height[*point_ptr] = tree->height[current_index];
        tree->key[current_index] = -1;
        tree->height[current_index] = 0;
        *point_ptr = *point_ptr + 1;
        if(tree->key[2 * current_index+ 1] != -1){
            linked_queue_enqueue(queue, 2 * current_index + 1);
        }
        if(tree->key[2 * current_index + 2] != -1){
            linked_queue_enqueue(queue, 2 * current_index + 2);
        }
    }
}

void delete_dublicate(ARRAY_AVL tree){
    for(int i = 0; i < (1 << (tree->level + 1)) - 1; i++){
        if(tree->key[i] != -1){
            for(int j = i + 1; j < (1 << (tree->level + 1)) - 1; j++){
             if(tree->key[i] == tree->key[j]){
                 tree->key[j] = -1;
                 tree->height[j] = 0;
             }
            }
        }
    }
}

void left_left_rotation(ARRAY_AVL tree, int parent, int child){
    int t1_size = 0, t2_size = 0, t3_size = 0, point = 0;

    int *t1_size_ptr = &t1_size;
    int *t2_size_ptr = &t2_size;
    int *t3_size_ptr = &t3_size;

    int *point_ptr = &point;

    void *parent_data = tree->data[parent];
    void *child_data = tree->data[child];

    size_subtree(tree, 2 * child + 1, t1_size_ptr);
    size_subtree(tree, 2 * child + 2, t2_size_ptr);
    size_subtree(tree, 2 * parent + 2, t3_size_ptr);


    ARRAY_AVL t1 = init_array_avl2(t1_size);
    ARRAY_AVL t2 = init_array_avl2(t2_size);
    ARRAY_AVL t3 = init_array_avl2(t3_size);
    if(t1_size != 0){
        bft_for_rotations(tree, t1, 2 * child + 1, point_ptr, t1_size);
    }
    *point_ptr = 0;
    if(t2_size != 0){
        bft_for_rotations(tree, t2, 2 * child + 2, point_ptr, t2_size);
    }
    *point_ptr = 0;
    if(t3_size != 0){
        bft_for_rotations(tree, t3, 2 * parent + 2, point_ptr, t3_size);
    }
    *point_ptr = 0;
    //for(int i = 0; i < t1_size; i++){
    //    printf("%d ", t1->key[i]);
    //}
    //printf("\n");
    //for(int i = 0; i < t2_size; i++){
    //    printf("%d ", t2->key[i]);
    //}
    //printf("\n");
    //for(int i = 0; i < t3_size; i++){
    //    printf("%d ", t3->key[i]);
    //}
    //printf("\n");

    *point_ptr = 0;


    if(t1_size == 0 && t2_size == 0 && t3_size == 0){
        tree->key[2 * parent + 2] = tree->key[parent];
        tree->key[parent] = tree->key[child];
        tree->key[2 * parent + 1] = -1;
        tree->height[2 * parent + 1] = 0;
        tree->data[2 * parent + 2] = parent_data;
        tree->data[parent] = child_data;
    }
    else{
        tree->key[2 * parent + 2] = tree->key[parent];
        tree->key[parent] = tree->key[child];
        tree->data[2 * parent + 2] = parent_data;
        tree->data[parent] = child_data;
    }

    if(t1_size == 1){
        tree->key[child] = t1->key[0];
        tree->data[child] = t1->data[0];
        tree->height[child] = t1->height[0];
    }
    if(t1_size != 0 && t1_size != 1){
        bft_swap_elements(tree, t1, child, point_ptr, t1_size);
    }
    *point_ptr = 0;
    int parent_right = 2 * parent + 2;

    if(t2_size != 0){
        bft_swap_elements(tree, t2, 2 * parent_right + 1 , point_ptr, t2_size);
    }
    *point_ptr = 0;
    if(t3_size != 0){
        bft_swap_elements(tree, t3, 2 * parent_right + 2 , point_ptr, t3_size);
    }
    *point_ptr = 0;

    tree->height[2 * parent + 2] = update_height(tree, 2 * parent + 2);
    tree->height[parent] = update_height(tree, child);
}


void right_right_rotation(ARRAY_AVL tree, int parent, int child){
    int t1_size = 0, t2_size = 0, t3_size = 0, point = 0;

    int *t1_size_ptr = &t1_size;
    int *t2_size_ptr = &t2_size;
    int *t3_size_ptr = &t3_size;

    int *point_ptr = &point;

    void *parent_data = tree->data[parent];
    void *child_data = tree->data[child];

    size_subtree(tree, 2 * parent + 1, t1_size_ptr);
    size_subtree(tree, 2 * child + 1, t2_size_ptr);
    size_subtree(tree, 2 * child + 2, t3_size_ptr);


    ARRAY_AVL t1 = init_array_avl2(t1_size);
    ARRAY_AVL t2 = init_array_avl2(t2_size);
    ARRAY_AVL t3 = init_array_avl2(t3_size);
    if(t1_size != 0){
        bft_for_rotations(tree, t1, 2 * parent + 1, point_ptr, t1_size);
    }
    *point_ptr = 0;
    if(t2_size != 0){
        bft_for_rotations(tree, t2, 2 * child + 1, point_ptr, t2_size);
    }
    *point_ptr = 0;
    if(t3_size != 0){
        bft_for_rotations(tree, t3, 2 * child + 2, point_ptr, t3_size);
    }
    *point_ptr = 0;
    //printf("\nt1 = ");
    //for(int i = 0; i < t1_size; i++){
    //    printf("%d ", t1->key[i]);
    //}
    //printf("\n");
    //printf("t2 = ");
    //for(int i = 0; i < t2_size; i++){
    //    printf("%d ", t2->key[i]);
    //}
    //printf("\n");
    //printf("t3 = ");
    //for(int i = 0; i < t3_size; i++){
    //    printf("%d ", t3->key[i]);
    //}
    //printf("\n");
    *point_ptr = 0;

    if(t1_size == 0 && t2_size == 0 && t3_size == 0){
        tree->key[2 * parent + 1] = tree->key[parent];
        tree->key[parent] = tree->key[child];
        tree->key[2 * parent + 2] = -1;
        tree->height[2 * parent + 2] = 0;
        tree->data[2 * parent + 1] = parent_data;
        tree->data[parent] = child_data;
    }
    else{
        tree->key[2 * parent + 1] = tree->key[parent];
        tree->key[parent] = tree->key[child];
        tree->data[2 * parent + 1] = parent_data;
        tree->data[parent] = child_data;
    }

    if(t3_size == 1){
        tree->key[child] = t3->key[0];
        tree->data[child] = t3->data[0];
        tree->height[child] = t3->height[0];
    }
    if(t3_size != 0 && t3_size != 1){
        bft_swap_elements(tree, t3, child, point_ptr, t3_size);
    }
    *point_ptr = 0;
    int parent_left = 2 * parent + 1;

    if(t1_size != 0){
        bft_swap_elements(tree, t1, 2 * parent_left + 1 , point_ptr, t1_size);
    }
    *point_ptr = 0;
    if(t2_size != 0){
        bft_swap_elements(tree, t2, 2 * parent_left + 2 , point_ptr, t2_size);
    }
    *point_ptr = 0;

    tree->height[2 * parent + 1] = update_height(tree, 2 * parent + 1);
    tree->height[parent] = update_height(tree, child);

}

void print_height_array_avl(ARRAY_AVL tree, int start, int counter){
    if(tree->height[start] != 0){
        counter++;
        print_height_array_avl(tree, 2 * start + 2, counter);
        counter--;
        printf("\n");
        for(int i = 0; i < counter*5; i++){
            printf(" ");
        }
        printf("%d", tree->height[start]);
        counter++;
        print_height_array_avl(tree, 2 * start + 1,counter);
        counter--;
    }
}

void balance_array_avl(ARRAY_AVL tree, int start){
    int balance = tree->height[2 * start + 1] - tree->height[2 * start + 2];
    if(balance < 0){
        int first = 2 * start + 2;
        balance = tree->height[2 * first + 1] - tree->height[2 * first + 2];
        if(balance <= 0){
            right_right_rotation(tree, start, 2 * start + 2);
            tree->height[start] = update_height(tree, start);
        }
        else{
            left_left_rotation(tree, first, 2 * first + 1);
            right_right_rotation(tree, start, 2 * start + 2);
            tree->height[start] = update_height(tree, start);
        }
    }
    else{
        int first = 2 * start + 1;
        balance = tree->height[2 * first + 1] - tree->height[2 * first + 2];
        if(balance >= 0){
            left_left_rotation(tree, start, 2 * start + 1);
            tree->height[start] = update_height(tree, start);
        }
        else{
            right_right_rotation(tree, first, 2 * first + 2);
            left_left_rotation(tree, start, 2 * start + 1);
            tree->height[start] = update_height(tree, start);
        }
    }
}