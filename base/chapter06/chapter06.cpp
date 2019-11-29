//
// Created by scq on 2019/11/16.
//

#include "chapter06.h"

#define __STDC_WANT_LIB_EXT1__ 1

// 字符串结尾标识：'\0'
int chapter0601() {
    printf("The character \0 is used to terminate a string.");
    return 0;
}

// 确定字符串的长度：遍历字符数
int chapter0602() {
    char str1[] = "To be or not to be";
    char str2[] = ", that is the question";

    unsigned int count = 0;
    while (str1[count] != '\0') {
        ++count;
    }
    printf("The length of string \"%s\" is %d characters.\n", str1, count);

    count = 0;
    while (str2[count] != '\0') {
        ++count;
    }
    printf("The length of string \"%s\" is %d characters.\n", str2, count);

    return 0;
}

// 字符串数组：遍历，确定字符串个数（数组维度遍历）
int chapter0603() {
    char str[][70] = {
            "Computers do what you tell them to do, not you want them to do.",
            "When you put something in memory, remember where you put it.",
            "Never test for a condition you don't know what to do with."
    };

    unsigned int count = 0;
    // 计算字符串数组中字符串的个数
    unsigned int strCount = sizeof(str) / sizeof(str[0]);
    printf("There are %u strings.\n", strCount);

    // 遍历字符串
    for (unsigned int i = 0; i < strCount; i++) {
        count = 0;
        // 以 '\0' 为结尾标记
        while (str[i][count]) {
            ++count;
        }
        // 字符串输出格式控制：%s
        printf("The string: \n \"%s\"\n contains %u characters.\n", str[i], count);
    }

    return 0;
}

// C11标准检查
int chapter0604() {
#if defined __STDC_LIB_EXT1__
    printf("Optional function are defined.\n");
#else
    printf("Optional functions are not defined.\n");
#endif // defined __STDC_LIB_EXT1__
    return 0;
}

// 确定字符串长度：strlen_s()或者strlen()
int chapter0605() {
    char str[][70] = {
            "Computers do what you tell them to do, not you want them to do.",
            "When you put something in memory, remember where you put it.",
            "Never test for a condition you don't know what to do with."
    };

    unsigned int count = 0;
    // 计算字符串数组中字符串的个数
    unsigned int strCount = sizeof(str) / sizeof(str[0]);
    printf("There are %u strings.\n", strCount);

    // 遍历字符串
    for (unsigned int i = 0; i < strCount; i++) {
        // strlen():确定字符串长度
        printf("The string: \n \"%s\"\n contains %zu characters.\n", str[i], strlen(str[i]));
    }

    return 0;
}

// 字符串复制：strcpy(), 字符串连接：strcat()
int chapter0605_cpy_cat() {
    // 字符串复制：strcpy();
    char source[] = "Only the mediocre are always at their best.";
    char destination[50];

    // 复制指定长度字符串
    strncpy(destination, source, 4);
    printf("\n%s\n", destination);

    if (strcpy(destination, source)) {
        printf("\n%s\n", destination);
    } else {
        printf("An error occurred copying the string.\n");
    }

    // 字符串连接：strcat()
    char str1[50] = "To be, or not to be, ";
    char str2[] = "that is the question.";
    strcat(str1, str2);
    printf("\nThe combined strings:\n%s\n", str1);

    // 连接指定长度字符串
    strncat(str1, str2, 4);
    printf("\n%s\n", str1);

    return 0;
}

// 连接字符串
int chapter0605_combine() {
    char preamble[] = "The joke is:\n\n";
    char str[][40] = {
            "My dog hasn\'t got any noise.\n",
            "How does your dog smell then?\n",
            "My dog smell horrible.\n"
    };

    // 计算字符串长度
    unsigned int strCount = sizeof(str) / sizeof(str[0]);

    // 计算字符串数组实际长度
    unsigned int length = 0;
    for (unsigned int i = 0; i < strCount; ++i) {
        length += strlen(str[i]);
    }

    // 初始化目的字符串: '+1':给'\0'预留空间
    char joke[length + strlen(preamble) + 1];

    // 复制字符串
    strncpy(joke, preamble, sizeof(preamble));
    // 拼接字符串数组
    for (int j = 0; j < strCount; ++j) {
        strncat(joke, str[j], sizeof(str[j]));
    }
    printf("%s", joke);

    return 0;
}


// 比较字符串：strcmp():比较俩个字符串的第一对不同的字符的ASCII码
int chapter0606() {
    char str1[] = "The quick brown fox";
    char str2[] = "The quick black fox";
    if (strcmp(str1, str2) > 0) {
        printf("str1 is greater than str2\n");
    }

    if (strncmp(str1, str2, 10) <= 0) {
        printf("\n%s\n%s\n", str1, str2);
    } else {
        printf("\n%s\n%s\n", str2, str1);
    }

    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];

    printf("Type the first word (maximum %d characters): ", MAX_LENGTH - 1);
    int retval = scanf("%s", word1, sizeof(word1));
    if (EOF == retval) {
        printf("Error reading the word.\n");
        return 1;
    }

    printf("Type the second word (maximum %d characters): ", MAX_LENGTH - 1);
    retval = scanf("%s", word2, sizeof(word2));
    if (EOF == retval) {
        printf("Error reading the word.\n");
        return 2;
    }

    if (strcmp(word1, word2) == 0) {
        printf("You have entered indentical words.");
    } else {
        printf("%s precedes %s \n",
               (strcmp(word1, word2) < 0) ? word1 : word2,
               (strcmp(word1, word2) < 0) ? word2 : word1);
    }
    return 0;
}

// 在字符串中搜索字符：strchr()
int chapter0606_chr() {
    char str1[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_char = NULL;
    pGot_char = strchr(str1, ch);
    if (pGot_char != NULL) {
        printf("Character found was %c.", *pGot_char);
    }

    char str2[] = "Peter piper picked a peck of picked pepper.";
    ch = 'p';
    char *pGot_chars = str2;
    int count = 0;
    while (pGot_chars = strchr(pGot_chars, ch)) {
        ++count;
        ++pGot_chars;
    }
    printf("\nThe character '%c' was found %d times in the following string:\n\"%s\"\n", ch, count, str2);

    return 0;
}

// 在字符串中查找子串:strstr()
int chapter0607() {
    char str1[] = "This string contains the holy girl";
    char str2[] = "the holy girl";
    char str3[] = "the holy girll";

    if (strstr(str1, str2)) {
        printf("\"%s\" was found in \"%s\" \n", str2, str1);
    } else {
        printf("\n\"%s\" was not found.", str2);
    }
    if (!strstr(str1, str3)) {
        printf("\"%s\" was not found.\n", str3);
    } else {
        printf("\n We shouldn't get to here!");
    }
    return 0;
}

// 单元化字符串：strtok()
// TODO: strtok(), strtok_s()的参数、区别
int chapter0607_strtock() {
    // 文本分隔符，输入缓冲区字符串，数据存储字符串，指针，终止符
    char delimiters[] = "\".,;:!?()";
    char buf[100];
    char str[1000];
    char *ptr = NULL;
    str[0] = '\0';

    size_t str_len = sizeof(str);
    size_t buf_len = sizeof(buf);
    printf("Enter some prose that is less than %zd characters.\n"
           "Terminate input by entering an empty line:\n", str_len);

    while (true) {
        // 输入一行字符串，存放在buf字符数组（缓冲区）
        if (!gets(buf)) {
            printf("Error reading string.\n");
            return 1;
        }
        // 输入的字符串为空的话停止迭代输入
        if (!strlen(buf)) {
            break;
        }
        // 将缓冲区的字符串拼接在str字符串后面，str为累计输入的最终字符串
        if (!strcat(str, buf)) {
            printf("Maximum permitted input length exceeded.\n");
            return 1;
        }
    } // 需要输入的多行字符串输入完毕

    printf("The words in prose that you entered are: %s\n", str);

    // 分割统计
    unsigned int word_count = 0;
    // 返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针
    // 找到第一个字符串
    char *pWord = strtok(str, delimiters);
    if (pWord) {
        do {
            printf("%-18s", pWord);
            if (++word_count % 5 == 0) {
                printf("\n");
            }
            pWord = strtok(NULL, delimiters);
        } while (pWord);
        printf("\n%u words found.\n", word_count);
    } else {
        printf("No words found.\n");
    }

    return 0;
}

// 字符分类函数：isalpha(), isdigit(), ispunct()
int chapter0608() {
    // 输入的字符串，字母数，数字数，标点符号数
    char buf[BUF_SIZE];
    int nLetters = 0;
    int nDigits = 0;
    int nPunct = 0;
    // 输入字符串
    printf("Enter an interesting string of less than %d characters:\n", BUF_SIZE);
    if (!gets(buf)) {
        printf("Error reading string.\n");
        return 1;
    }
    size_t i = 0;
    // 遍历字符数组并分类
    while (buf[i]) {
        if (isalpha(buf[i])) {
            ++nLetters;
        } else if (isdigit(buf[i])) {
            ++nDigits;
        } else if (ispunct(buf[i])) {
            ++nPunct;
        }
        ++i;
    }
    printf("\n Your string contained %d 字母, %d 数字 and %d 标点符号.\n", nLetters, nDigits, nPunct);
    return 0;
}

// 转换字符：大小写形式转换
int chapter0609() {
    char text[TEXT_LEN];
    char substring[SUBSTR_LEN];
    // 第一个字符串
    printf("Enter the string to be searched(less than %d characters):\n", TEXT_LEN);
    gets(text);
    // 第二个字符串
    printf("\nEnter the string sought (less than %d characters):\n", SUBSTR_LEN);
    gets(substring);

    printf("\nFirst string entered:\n%s\n", text);
    printf("Second string entered:\n%s\n", substring);
    // 全部转为大写形式
    for (int i = 0; (text[i] = toupper(text[i])) != '\0'; ++i);
    for (int i = 0; (substring[i] = toupper(substring[i])) != '\0'; ++i);
    // 子串查找
    printf("The second string %s found in the first.\n", (strstr(text, substring) == NULL) ? "was not" : "was");
    return 0;
}