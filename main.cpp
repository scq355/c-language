#include "headers/data_structure/sq_list.h"

int main() {

    SqList L;
    // 初始化
    init_list_sq(L);
    for (int i = 1; i <= 4; ++i) {
        insert_list_sq(L, i, i * 10);
    }
    int elem;
    delete_list_sq(L, 2, elem);
    locate_elem_sq(L, 30, get_equal);

    return 0;
}
