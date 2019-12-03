#include "headers/data_structure/sq_list.h"

int main() {

    SqList L;
    // 初始化
    init_list_sq(L);
    insert_list_sq(L, 1, 1 * 10);
    insert_list_sq(L, 2, 2 * 10);
    insert_list_sq(L, 3, 3 * 10);
    insert_list_sq(L, 4, 4 * 10);
    insert_list_sq(L, 5, 5 * 10);
    insert_list_sq(L, 6, 6 * 10);
    insert_list_sq(L, 7, 7 * 10);
    int elem = 0;
    delete_list_sq(L, 4, elem);
    locate_elem_sq(L, 50, get_equal);

    return 0;
}
