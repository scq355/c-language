//
// Created by scq on 2019/11/16.
//

#include "chapter11.h"

typedef struct Horses horse;
typedef struct Horsee horsee;
typedef struct Family family;
typedef struct Node Node;

typedef union  UDate UDate;
typedef struct Dates Dates;
typedef struct MixedDate MixedDate;
typedef struct NumbericDate NumbericDate;

Family *get_person(void);
void show_people(bool forwards, Family *pfirst, Family *plast);
void release_memory(Family *pfirst);

Node *create_node(long value);
Node *add_node(long value, Node *pNode);
void list_nodes(Node *pNode);
void free_nodes(Node *pNode);

void print_date(const Dates* date);
enum Date_Format { numberic, text, mixed };

struct MixedDate {
    char *day;
    char *date;
    int year;
};

struct NumbericDate {
    int day;
    int month;
    int year;
};

union UDate {
    char *date_str;
    MixedDate day_date;
    NumbericDate nDate;
};

struct Dates {
    enum Date_Format format;
    UDate date;

};

struct Horses {
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
};

struct Horse {
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
    Horse *next;
};

struct Horsee {
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
    Horsee *next;
    Horsee *previous;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Family {
    Date dob;
    char name[20];
    char father[20];
    char mother[20];
    Family *next;
    Family *previous;
};

struct Node {
    long item;
    int count;
    Node *pLeft;
    Node *pRight;
};

int chapter1101(void) {
    Horses my_horse;

    printf("Enter the name of horse: ");
    scanf("%s", my_horse.name, sizeof(my_horse.name));

    printf("How old is %s? ", my_horse.name);
    scanf("%d", &my_horse.age);

    printf("How heigh is %s ( int hands ) ?", my_horse.name);
    scanf("%d", &my_horse.height);

    printf("Who is %s's father? ", my_horse.name);
    scanf("%s", my_horse.father, sizeof(my_horse.father));

    printf("Who is %s's mother? ", my_horse.name);
    scanf("%s", my_horse.mother, sizeof(my_horse.mother));

    printf("%s is %d years old, %d hands high", my_horse.name, my_horse.age, my_horse.height);
    printf(" and has %s and %s as parents.", my_horse.father, my_horse.mother);

    return 0;
}

int chapter1102() {
    Horses my_horse[50];
    int hcount = 0;
    char test = '\0';

    for (hcount = 0; hcount < sizeof(my_horse) / sizeof(Horses); ++hcount) {
        printf("Do you want to enter details of a%s horse (Y or N)?", hcount ? "nother" : "");

        scanf(" %c", &test, sizeof(test));
        if (tolower(test) == 'n') {
            break;
        }

        printf("Enter the name of the horse: ");
        scanf("%s", my_horse[hcount].name, sizeof(my_horse[hcount].name));

        printf("How old is %s?", my_horse[hcount].name);
        scanf("%d", &my_horse[hcount].age);

        printf("How heigh is %s ( int hands ) ?", my_horse[hcount].name);
        scanf("%d", &my_horse[hcount].height);

        printf("Who is %s's father? ", my_horse[hcount].name);
        scanf("%s", my_horse[hcount].father, sizeof(my_horse[hcount].father));

        printf("Who is %s's mother? ", my_horse[hcount].name);
        scanf("%s", my_horse[hcount].mother, sizeof(my_horse[hcount].mother));

    }

    printf("\n");
    for (int i = 0; i < hcount; i++) {
        printf("%s is %d years old, %d hands high", my_horse[i].name, my_horse[i].age, my_horse[i].height);
        printf(" and has %s and %s as parents.", my_horse[i].father, my_horse[i].mother);
    }

    return 0;
}


int chapter1103(void) {
    Horses *phorse[50];
    int hcount = 0;
    char test = '\0';

    for (hcount = 0; hcount < sizeof(phorse) / sizeof(Horses*); ++hcount) {
        printf("Do you want to enter details of a%s horse (Y or N)?", hcount ? "nother" : "");

        scanf(" %c", &test, sizeof(test));
        if (tolower(test) == 'n') {
            break;
        }

        phorse[hcount] = (Horses*)malloc(sizeof(Horses));

        printf("Enter the name of the horse: ");
        scanf("%s", phorse[hcount]->name, sizeof(phorse[hcount]->name));

        printf("How old is %s?", phorse[hcount]->name);
        scanf("%d", &phorse[hcount]->age);

        printf("How heigh is %s ( int hands ) ?", phorse[hcount]->name);
        scanf("%d", &phorse[hcount]->height);

        printf("Who is %s's father? ", phorse[hcount]->name);
        scanf("%s", phorse[hcount]->father, sizeof(phorse[hcount]->father));

        printf("Who is %s's mother? ", phorse[hcount]->name);
        scanf("%s", phorse[hcount]->mother, sizeof(phorse[hcount]->mother));

    }

    printf("\n");
    for (int i = 0; i < hcount; i++) {
        printf("%s is %d years old, %d hands high", phorse[i]->name, phorse[i]->age, phorse[i]->height);
        printf(" and has %s and %s as parents.", phorse[i]->father, phorse[i]->mother);
    }

    return 0;
}

int chapter1104() {
    Horse *first = NULL;
    Horse *current = NULL;
    Horse *previous = NULL;

    char test = '\0';

    for ( ; ; ) {
        printf("Do you want to enter details of a%s horse (Y or N) ? ", first != NULL ? "nother" : "");
        scanf(" %c", &test, sizeof(test));

        if (tolower(test) == 'n') {
            break;
        }
        current = (Horse*)malloc(sizeof(Horse));
        if (first == NULL) {
            first = current;
        }
        if (previous != NULL) {
            previous->next = current;
        }
        printf("Enter the name of the horse: ");
        scanf("%s", current->name, sizeof(current->name));

        printf("How old is %s? ", current->name);
        scanf("%d", &current->age);

        printf("How heigh is %s ( int hands ) ?", current->name);
        scanf("%d", &current->height);

        printf("Who is %s's father? ", current->name);
        scanf("%s", current->father, sizeof(current->father));

        printf("Who is %s's mother? ", current->name);
        scanf("%s", current->mother, sizeof(current->mother));

        current->next = NULL;
        previous = current;
    }

    printf("\n");
    current = first;
    while (current != NULL) {
        printf("%s is %d years old, %d hands high", current->name, current->age, current->height);
        printf(" and has %s and %s as parents.", current->father, current->mother);

        previous = current;
        current = current->next;
        free(previous);
        previous = NULL;
    }

    return 0;
}


int chapter1105(void) {
    Horsee *first = NULL;
    Horsee *current = NULL;
    Horsee *previous = NULL;
    Horsee *last = NULL;

    char test = '\0';

    for (; ; ) {
        printf("Do you want to enter details of a%s horse (Y or N) ? ", first != NULL ? "nother" : "");
        scanf(" %c", &test, sizeof(test));

        if (tolower(test) == 'n') {
            break;
        }
        current = (Horsee*)malloc(sizeof(Horsee));
        if (first == NULL) {
            first = current;
            current->previous = NULL;
        } else {
            last->next = current;
            current->previous = last;
        }

        printf("Enter the name of the horse: ");
        scanf("%s", current->name, sizeof(current->name));

        printf("How old is %s? ", current->name);
        scanf("%d", &current->age);

        printf("How heigh is %s ( int hands ) ?", current->name);
        scanf("%d", &current->height);

        printf("Who is %s's father? ", current->name);
        scanf("%s", current->father, sizeof(current->father));

        printf("Who is %s's mother? ", current->name);
        scanf("%s", current->mother, sizeof(current->mother));

        current->next = NULL;
        last = current;
    }

    printf("\n");
    current = first;
    while (current != NULL) {
        printf("%s is %d years old, %d hands high", current->name, current->age, current->height);
        printf(" and has %s and %s as parents.", current->father, current->mother);

        last = current;
        current = current->previous;
        free(last);
        last = NULL;
    }
    first = NULL;

    return 0;
}


int chapter1106(void) {
    Family *first = NULL;
    Family *current = NULL;
    Family *last = NULL;

    char more = '\0';
    while (true) {
        printf("\nDo you want to enter details of a %s person (Y or N) ?", first != NULL ? "nother" : "");

        scanf(" %c", &more, sizeof(more));
        if (tolower(more) == 'n') {
            break;
        }

        current = get_person();

        if (first == NULL) {
            first = current;
        } else {
            last->next = current;
            current->previous = last;
        }
        last = current;
    }

    show_people(true, first, last);
    release_memory(first);
    first = last = NULL;

    return 0;
}


Family *get_person(void) {
    Family *temp = (Family*)malloc(sizeof(Family));

    printf("\nEnter the name of the person: ");
    scanf("%s", temp->name, sizeof(temp->name));

    printf("\nEnter %s's date of birth (day month year); ", temp->name);
    scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);

    printf("\nWho is %s's father? ", temp->name);
    scanf("%s", temp->father, sizeof(temp->father));

    printf("\nWho is %s's mother? ", temp->name);
    scanf("%s", temp->mother, sizeof(temp->mother));


    temp->next = temp->previous = NULL;

    return temp;
}

void show_people(bool forwards, Family *pfirst, Family *plast) {
    printf("\n");

    for (Family *pcurrent = forwards ? pfirst : plast;
         pcurrent != NULL;
         pcurrent = forwards ? pcurrent->next : pcurrent->previous) {
        printf("%s was born %d/%d/%d and has %s and %s as parents.\n", pcurrent->name,
                 pcurrent->dob.day,
                 pcurrent->dob.month,
                 pcurrent->dob.year,
                 pcurrent->father,
                 pcurrent->mother);
    }
}

void release_memory(Family *pfirst) {
    Family *pcurrent = pfirst;
    Family *temp = NULL;

    while (pcurrent) {
        temp = pcurrent;
        pcurrent = pcurrent->next;
        free(temp);
    }
}

int chapter1107() {
    long newvalue = 0;
    Node *pRoot = NULL;
    char answer = 'n';
    do {
        printf("Enter the node value: ");
        scanf(" %ld", &newvalue);
        if (!pRoot) {
            pRoot = create_node(newvalue);
        } else {
            add_node(newvalue, pRoot);
        }
        printf("Do you want to enter another (y or n) ? ");
        scanf(" %c", &answer, sizeof(answer));
    } while (tolower(answer) == 'y');

    printf("The values in ascending sequence are: \n");
    list_nodes(pRoot);
    free_nodes(pRoot);

    return 0;
}


Node *create_node(long value) {
    Node *pNode = (Node*)malloc(sizeof(Node));

    pNode->item = value;
    pNode->count = 1;
    pNode->pLeft = pNode->pRight = NULL;

    return pNode;
}

Node *add_node(long value, Node *pNode) {
    if (!pNode) {
        return create_node(value);
    }
    if (value == pNode->item) {
        ++pNode->count;
        return pNode;
    }
    if (value < pNode->item) {
        if (!pNode->pLeft) {
            pNode->pLeft = create_node(value);
            return pNode->pLeft;
        } else {
            return add_node(value, pNode->pLeft);
        }
    } else {
        if (!pNode->pRight) {
            pNode->pRight = create_node(value);
            return pNode->pRight;
        } else {
            return add_node(value, pNode->pRight);
        }
    }
}

void list_nodes(Node *pNode) {
    if (pNode->pLeft) {
        list_nodes(pNode->pLeft);
    }
    printf("%10ld x %10ld\n", pNode->count, pNode->item);
    if (pNode->pRight) {
        list_nodes(pNode->pRight);
    }
}


void free_nodes(Node *pNode) {
    if (!pNode) {
        return;
    }
    if (pNode->pLeft) {
        free_nodes(pNode->pLeft);
    }
    if (pNode->pRight) {
        free_nodes(pNode->pRight);
    }
    free(pNode);
}


int chapter1108(void) {
    NumbericDate yesterday = { 11, 11, 2012 };
    char *day = const_cast<char*> ("Monday");
    char *date = const_cast<char*> ("12th November");
    MixedDate today = { day , date , 2012 };
    char tomorrow[] = "Thus 13th Nov 2012";

    UDate udate = { tomorrow };
    Dates the_date;
    the_date.date = udate;
    the_date.format = text;
    print_date(&the_date);

    the_date.date.nDate = yesterday;
    the_date.format = numberic;
    print_date(&the_date);

    the_date.date.day_date = today;
    the_date.format = mixed;
    print_date(&the_date);

    return 0;
}


void print_date(const Dates* date) {
    switch (date->format) {
        case numberic:
            printf("The date is %d/%d/%d.\n", date->date.nDate.day,
                     date->date.nDate.month,
                     date->date.nDate.year);
            break;
        case text:
            printf("The date is %s.\n", date->date.date_str);
            break;
        case mixed:
            printf("The date is %s %s %d.\n",
                     date->date.day_date.day,
                     date->date.day_date.date,
                     date->date.day_date.year);
            break;
        default:
            printf("Invalid date format!\n");
            break;
    }
}