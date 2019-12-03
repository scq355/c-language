//
// Created by 孙常青 on 2019/12/3.
// 线性表-顺序表
//

#include "../../headers/data_structure/sq_list.h"

int init_list_sq(SqList L) {
    L.elem = malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem) {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.list_size = LIST_INIT_SIZE;
    return OK;
}

int insert_list_sq(SqList L, int i, int e) {
    //
    if (i < 1 || i > L.length + 1) { // i的位置不合法
        return ERROR;
    }
    int *new_base;
    if (L.length >= L.list_size) { // 当前存储空间已满，增加分配
        new_base = realloc(L.elem, (L.list_size + LIST_INCREMENT) * sizeof(int));
        if (!new_base) { // 存储空间分配失败
            exit(OVERFLOW);
        }
        // 新基址
        L.elem = new_base;
        // 增加存储容量
        L.list_size += LIST_INCREMENT;
    }
    // 找到待插入的位置
    int *q = &(L.elem[i - 1]);
    // 插入位置及之后元素位置后移一位
    for (int *p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    // 插入元素
    *q = e;
    // 表长+1
    ++L.length;

    return OK;
}

int delete_list_sq(SqList L, int i, int e) {
    // i的合法位置为[1, ListLength_Sq + 1]
    if (i < 1 || i > L.length) { // i值不合法
        return ERROR;
    }
    // 被删除元素的位置
    int *p = &(L.elem[i - 1]);
    // 被删元素的数据
    e = *p;
    // 表尾元素的位置
    int *q = L.elem + L.length - 1;
    // 被删元素之后的元素左移
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    // 表长-1
    --L.length;

    return OK;
}

int locate_elem_sq(SqList L, int e, int (*compare)(int, int)) {
    // i的初始值为第一个元素的位序
    int i = 1;
    // p的初始值为第一个元素的地址
    int *p = L.elem;
    // 遍历顺序表，直到满足compare函数为止
    while (i < L.length && !(*compare)(*p++, e)) {
        ++i;
    }
    // 找到满足的元素位置
    if (i <= L.length) {
        return i;
    } else { // 未找到
        return 0;
    }
}

/**
 * 相等
 * @param a
 * @param b
 * @return
 */
int get_equal(int a, int b) {
    return a == b ? TRUE : FALSE;
}


