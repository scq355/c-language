//
// Created by 孙常青 on 2019/12/3.
//

#ifndef C_LANAGUE_SQ_LIST_H
#define C_LANAGUE_SQ_LIST_H

#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef struct {
    int *elem;
    int length;
    int list_size;
} SqList;


/**
 * 初始化顺序表
 * @param L
 * @return
 */
int init_list_sq(SqList L);

/**
 * 在顺序线性表L中第i个位置之前插入新元素e
 * @param L 顺序线性表
 * @param i 插入元素的位置
 * @param e 待插入的元素
 * @return
 */
int insert_list_sq(SqList L, int i, int e);

/**
 * 顺序线性表L中删除第i个元素，并用e返回其值
 * @param L 包含待删元素的线性顺序表
 * @param i 被删元素的位置
 * @param e 用于存储被删元素的变量
 * @return
 */
int delete_list_sq(SqList L, int i, int e);

/**
 * 相等
 * @param a
 * @param b
 * @return
 */
int get_equal(int a, int b);

/**
 * 在线性顺序表L中查找第一个值与e满足compare的元素的位序,若找到返回L中的位序，否则返回0
 * @param L 待查找的线性顺序表
 * @param e 待查找元素
 * @param compare 比较方案（函数指针）
 * @return
 */
int locate_elem_sq(SqList L, int e, int (*compare)(int, int));

#endif //C_LANAGUE_SQ_LIST_H
