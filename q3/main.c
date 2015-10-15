#include <stdio.h>
#include <assert.h>

#include IMPL
#include TIMER
#include BST

int main(void)
{
    struct timespec start, end;
    double cpu_time;

    node *root = create_node();
    create_tree(root);

    printf("PostOrder: ");
    traversal_postOrder(root);
    printf("\n");

    printf("Before flatten: ");
    traversal_quizRequire(root);
    printf("\n");

    clock_gettime(CLOCK_REALTIME, &start);
    flatten(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_milisecond(&start, &end);

    int i = 1;
    node* tmp = root;
    for (; i <= 6; i++) {
        assert(tmp->data == i);
        tmp = tmp->right;
    }

    printf("After flatten: ");
    traversal_quizRequire(root);
    printf("\n");
    printf("Exec time: %lf\n", cpu_time);
    return 0;
}
