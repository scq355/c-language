//
// Created by scq on 2019/11/16.
//

#include "chapter07.h"

// 声明指针
int chapter0701() {
    int number = 0;
    int *pnumber = NULL;

    number = 10;
    printf("number's address: %p\n", &number);
    printf("number's address: %p\n", (void *) &number);
    printf("number's value: %d\n\n", number);

    pnumber = &number;
    printf("pnumber's address: %p\n", (void *) &pnumber);
    printf("pnumber's size: %zd bytes\n", sizeof(pnumber));
    printf("pnumber's value: %p\n", pnumber);
    printf("value pointed to: %d\n", *pnumber);

    return 0;
}

// 使用指针
int chapter0702() {
    long num1 = 0L;
    long num2 = 0L;
    long *pnum = NULL;

    pnum = &num1;
    *pnum = 2L;
    ++num2;
    num2 += *pnum;

    pnum = &num2;
    // ++ 和 * 的优先级相同，都是从右到左
    ++*pnum;

    printf("num1 = %ld \nnum2 = %ld \n*pnum = %ld \n*pnum + num2  = %ld\n",
           num1, num2, *pnum, *pnum + num2);

    return 0;
}

// 接收输入时使用指针
int chapter0703() {
    int value = 0;
    int *pvalue = &value;

    printf("Input an integer: ");
    scanf(" %d", pvalue);

    printf("You have entered %d.\n", value);
    return 0;
}

// 数组和指针
int chapter0704() {
    char multiple[] = "My string.";
    char *p = &multiple[0];
    printf("The address of the first array element: %p\n", p);

    p = multiple;
    printf("The address obtained from the array name: %p\n", multiple);

    return 0;
}

// 数组和指针
int chapter0705() {
    char multiple[] = "a string";
    char *p = multiple;

    for (int i = 0; i < strlen(multiple); ++i) {
        printf("multiple[%d] = %c ... * (p + %d) = %c ... &multiple[%d] = %p ... p + %d = %p\n",
               i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    }
    return 0;
}

// 不同类型的数组
int chapter0706() {
    long multiple[] = {15L, 25L, 35L, 45L};
    long *p = multiple;

    for (int i = 0; i < sizeof(multiple) / sizeof(multiple[0]); ++i) {
        printf("address p + %d (&multiple[%d]): %llu ...... * (p + %d) value: %ld\n",
               i, i, (unsigned long long) (p + i), i, *(p + i));
    }

    printf("Type long occupies: %d bytes\n", (int) sizeof(long));
    return 0;
}

// [7, 10]: 多维数组
int chapter0707() {
    char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };
    // 二维数组和指针
    printf("address of board[0][0]: %p\n", &board[0][0]);
    printf("address of board: %p\n", board);
    printf("value of board[0]: %p\n\n", board[0]);

    printf("value of board[0][0]: %c\n", board[0][0]);
    printf("value of board: %c\n", **board);
    printf("value of board[0]: %c\n\n", *board[0]);

    // 得到二维数组中的所有值
    for (int i = 0; i < 9; ++i) {
        printf("board: %c --- ", *(*board + i));
    }
    printf("\n\n");

    // 多维数组和指针
    char *pboard = *board;
    for (int i = 0; i < 9; ++i) {
        printf("board: %c --- ", *(pboard + i));
    }

    return 0;
}

// 动态内存分配：malloc() | calloc()
int chapter0711() {
    unsigned long long *pPrimes = NULL;
    unsigned long long trail = 0;
    bool found = false;
    int total = 0;
    int count = 0;

    printf("How many primes would you like - you'll get at lest 4? ");
    scanf("%d", &total);
    total = total < 4 ? 4 : total;
    // 动态分配total * size(long)的内存，并且指针p指向该内存起始地址
    // malloc()不做初始化，分配到的空间中的数据是随机数据
//    pPrimes = (unsigned long long *) malloc(total * sizeof(unsigned long long));
    // calloc()在动态分配完内存后，自动初始化该内存空间为零
    pPrimes = static_cast<unsigned long long int *>(calloc((size_t) total, sizeof(unsigned long long)));

    if (!pPrimes) {
        printf("Not enough memory. It's the end I'm afraid.\n");
        return 1;
    }
    // 显式指定前三个素数
    *pPrimes = 2ULL;
    *(pPrimes + 1) = 3ULL;
    *(pPrimes + 2) = 5ULL;
    count = 3;
    trail = 5ULL;

    // 循环检验：当前数值是否为素数：当前数与当前之前的所有素数取余
    while (count < total) {
        trail += 2ULL;
        for (int i = 0; i < count; i++) {
            if (!(found = (trail % *(pPrimes + i)))) {
                break;
            }
        }
        if (found) {
            *(pPrimes + count++) = trail;
        }
    }
    // 循环打印所有素数
    for (int i = 0; i < total; i++) {
        printf("%12llu", *(pPrimes + i));
        if (!((i + 1) % 5)) {
            printf("\n");
        }
    }
    // 释放内存空间
    free(pPrimes);
    pPrimes = NULL;
    return 0;
}

// 扩展动态分配的内存：void realloc(void *ptr, size_t new_Size)
// 用于对动态内存进行扩容(及已申请的动态空间不够使用，需要进行空间扩容操作)，
// ptr为指向原来空间基址的指针， new_size为接下来需要扩充容量的大小

// 如果size较小，原来申请的动态内存后面还有空余内存，系统将直接在原内存空间后面扩容，
// 并返回原动态空间基地址；如果size较大，原来申请的空间后面没有足够大的空间扩容，
// 系统将重新申请一块(20+size)*sizeof(int)的内存，并把原来空间的内容拷贝过去，
// 原来空间free;如果size非常大，系统内存申请失败，返回NULL,原来的内存不会释放。
// 注：如果扩容后的内存空间较原空间小，将会出现数据丢失，如果直接realloc(p, 0);相当于free(p).
int chapter0712() {
    // 初始指针，是否找到（被检验的数是否为素数标识），一共检验多少个数（被检验数据最大值），指针pPrimes的偏移量
    unsigned long long *pPrimes = NULL;
    bool found = false;
    unsigned long long limit = 0LL;
    int count = 0;

    printf("Enter the upper limit for primes you want to find: ");
    scanf("%llu", &limit);

    // 初始容量10个单位内存空间
    size_t capacity = 10;
    // calloc分配内存，并指定初始值都为0
    pPrimes = (unsigned long long *) calloc(capacity, sizeof(unsigned long long));
    if (!pPrimes) {
        printf("Not enough memory. It's the end I'm afraid.\n");
        return 1;
    }

    // 指定前三个素数，并放在内存空间，并且显式指定初始偏移量为3
    *pPrimes = 2ULL;
    *(pPrimes + 1) = 3ULL;
    *(pPrimes + 2) = 5ULL;
    count = 3;

    // 从第四个素数7开始
    unsigned long long trail = *(pPrimes + 2) + 2ULL;
    unsigned long long *pTemp = NULL;

    while (trail <= limit) {
        // 遍历素数：当前数跟当前之前所有的素数检验
        for (int i = 0; i < count; i++) {
            if (!(found = (trail % *(pPrimes + i)))) {
                break;
            }
        }
        // 上面的循环遍历的取余操作全部不为0，当前的数为素数 <==> found != 0
        if (found) {
            // 当为第capacity个数的时候，即pPrimes指向的内存空间已经被占满的时，
            if (count == capacity) {
                // 动态增量分配：原地址空间 + 10个数据类型的地址空间，一次增加十个单位内存
                capacity += CAP_INCR;
                // 临时指针指向新的内存空间，分配成功后，原指针指向新的内存空间
                pTemp = (unsigned long long *) realloc(pPrimes, capacity * sizeof(unsigned long long));
                if (!pTemp) {
                    printf("Unfortunately memory reallocation failed.\n");
                    free(pPrimes);
                    pPrimes = NULL;
                    return 2;
                }
                pPrimes = pTemp;
            }
            // 当前的数为素数，下一块单位内存来存放找到的这个素数
            *(pPrimes + count++) = trail;
        }
        // 自增到新的被检验的数
        trail += 2ULL;
    }

    // 遍历打印找到的素数
    printf("%d primes found up to %llu:\n", count, limit);
    for (int i = 0; i < count; i++) {
        printf("%12llu", *(pPrimes + i));
        if (!((i + 1) % 5)) {
            printf("\n");
        }
    }
    printf("\n");
    // 释放内存
    free(pPrimes);
    pPrimes = NULL;
    return 0;
}