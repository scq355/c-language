//
// Created by scq on 2019/11/16.
//

#include "chapter08.h"

char *str_in() {
    char buf[BUF_LEN];
    // 输入一行字符串，讲字符串存储到字符串数组中
    if (!gets(buf)) {
        printf("\nError reading string.\n");
        return NULL;
    }
    if (buf[0] == '\0') {
        return NULL;
    }
    // 将字符串移动到指定的一块内存空间中，并且返回该内存的起始位置
    size_t str_len = strnlen(buf, BUF_LEN) + 1;
    char *pString = (char *) malloc(str_len);

    if (!pString) {
        printf("Memory allocation failure.\n");
        return NULL;
    }

    strcpy(pString, buf);
    return pString;
}

void swap(const char **p1, const char **p2) {
    const char *pT = *p1;
    *p1 = *p2;
    *p2 = pT;
}

void str_sort(const char **p, size_t n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (strcmp(p[i], p[i + 1]) > 0) {
                sorted = false;
                swap(&p[i], &p[i + 1]);
            }
        }
    }
}

void str_out(const char *const *pStr, size_t n) {
    printf("The sorted strings are:\n");
    for (size_t i = 0; i < n; ++i) {
        printf("%s\n", pStr[i]);
    }
}

void free_memory(char **pS, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        free(pS[i]);
        pS[i] = NULL;
    }
    free(pS);
    pS = NULL;
}

// 作用域
int chapter0801() {
    int count = 1;
    do {
        int count1 = 0;
        ++count1;
        printf("count = %d count1 = %d\n", count, count1);
    } while (++count <= 5);

    printf("count = %d\n", count);
    return 0;
}

// 作用域
int chapter0802() {
    int count = 0;
    do {
        int count = 0;
        ++count;
        printf("count = %d\n", count);
    } while (++count <= 5);

    printf("count = %d\n", count);
    return 0;
}

double sum(double x[], size_t n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum;
}

double Average(double x[], size_t n) {
    return sum(x, n) / n;
}

size_t getData(double *data, size_t max_count) {
    size_t nValues = 0;
    printf("How many values do you want to enter (Maximum %zd)?", max_count);
    scanf("%zd", &nValues);
    if (nValues > max_count) {
        printf("Maximum count exceeded. %zd items will be read.", max_count);
        nValues = max_count;
    }
    for (size_t i = 0; i < nValues; i++) {
        scanf("%lf", &data[i]);
    }

    return nValues;
}

// 使用函数
int chapter0803() {
    double samples[MAX_COUNT] = {0.0};

    size_t sampleCount = getData(samples, MAX_COUNT);
    double average = Average(samples, sampleCount);
    printf("The average of the values you entered is %.2lf\n", average);

    return 0;
}

// 使用指针传输数据
int chapter0804() {
    size_t ps_size = INIT_NSTR;
    char **ps = (char **) calloc(ps_size, sizeof(char *));
    if (!ps) {
        printf("Failed to allocate memory for string pointers. \n");
        exit(1);
    }
    char **pTemp = NULL;

    size_t str_count = 0;
    char *pStr = NULL;
    printf("Enter one string per line. Press Enter to end:\n");
    while ((pStr = str_in()) != NULL) {
        if (str_count == ps_size) {
            ps_size += NSTR_INCR;
            if (!(pTemp = static_cast<char **>(realloc(ps, ps_size * sizeof(char *))))) {
                printf("Memory allocation for array of strings failed.\n");
                return 2;
            }
            ps = pTemp;
        }
        ps[str_count++] = pStr;
    }

//    TODO: str_sort(ps, str_count);
    str_out(ps, str_count);
    free_memory(ps, str_count);

    return 0;
}


long *incomePlus(long *pPay) {
    *pPay += 10000L;
    return pPay;
}

// 从函数中返回数值
int chapter0805() {
    long your_pay = 30000L;
    long *pold_pay = &your_pay;
    long *pnew_pay = NULL;

    pnew_pay = incomePlus(pold_pay);

    printf("Old pay = %ld\n", *pold_pay);
    printf(" New pay = %ld\n", *pnew_pay);

    return 0;
}


int any_function(int(*pfun)(int, int), int x, int y) {
    return pfun(x, y);
}

int sums(int x, int y) {
    return x + y;
}

int products(int x, int y) {
    return x * y;
}

int differences(int x, int y) {
    return x - y;
}


int chapter0806() {
    int a = 10;
    int b = 5;
    int result = 0;
    int (*pfun)(int, int);

    pfun = sums;
    result = pfun(a, b);
    printf("pfun = sum    result = %2d\n", result);

    pfun = products;
    result = pfun(a, b);
    printf("pfun = product   result = %2d\n", result);
    pfun = differences;
    result = pfun(a, b);
    printf("pfun = difference   result = %2d\n", result);

    return 0;
}


int chapter0807() {
    int a = 10;
    int b = 5;
    int result = 0;
    int (*pfun[3])(int, int);

    pfun[0] = sums;
    pfun[1] = products;
    pfun[2] = differences;

    for (int i = 0; i < 3; i++) {
        result = pfun[i](a, b);
        printf("result = %2d\n", result);
    }

    result = pfun[1](pfun[0](a, b), pfun[2](a, b));
    printf("The product of the sum and the difference = %2d\n", result);

    return 0;
}

int chapter0808() {
    int a = 10;
    int b = 5;
    int result = 0;
    int (*pf)(int, int) = sums;

    result = any_function(pf, a, b);
    printf("result = %2d\n", result);

    result = any_function(products, a, b);
    printf("result = %2d\n", result);

    printf("result = %2d\n", any_function(differences, a, b));

    return 0;
}


void test1(void) {
    int count = 0;
    printf("test1 count = %d\n", ++count);
}

void test2(void) {
    static int count = 0;
    printf("test2 count = %d\n", ++count);
}


int chapter0809() {
    for (int i = 0; i < 5; i++) {
        test1();
        test2();
    }
    return 0;
}


int count = 0;


void test3(void) {
    printf("test3 count = %d\n", ++count);
}

void test4(void) {
    static int count;
    printf("test4 count = %d\n", ++count);
}

int chapter0810() {
    int count = 0;
    for (; count < 5; ++count) {
        test3();
        test4();
    }
    return 0;
}


unsigned long long factorial(unsigned long long n) {
    if (n < 2LL) {
        return n;
    }

    return n * factorial(n - 1LL);
}

int chapter0811() {
    unsigned long long number = 0LL;
    printf("Enter an Integer value:");

    scanf("%llu", &number);
    printf("The factorial pf %llu is %llu\n", number, factorial(number));

    return 0;
}


double average(double v1, double v2, ...) {
    va_list parg;
    double sum = v1 + v2;
    double value = 0.0;
    int count = 2;

    va_start(parg, v2);
    while ((value = va_arg(parg, double)) != 0.0) {
        sum += value;
        ++count;
    }

    va_end(parg);
    return sum / count;
}

int chapter0812() {
    double v1 = 10.5;
    double v2 = 2.5;

    int num1 = 6;
    int num2 = 5;

    long num3 = 12L;
    long num4 = 20L;

    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0, 0));
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n", average((double) num2, v2, (double) num1, (double) num4, (double) num3, 0.0));

    return 0;
}