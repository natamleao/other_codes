#include <stdio.h>
#include <stdlib.h>

typedef struct _book{
    char *title;
    unsigned int pagesNumber;
    float price;
}Book;

typedef struct _student{
    char *name;
    unsigned int age;
    Book *favorityBook;
}Student;

Book *createBook(char *title, unsigned int pagesNumber, float price){
    Book *newBook = (Book*)malloc(sizeof(Book));
    newBook->title = title;
    newBook->pagesNumber = pagesNumber;
    newBook->price = price;
    return newBook;
}

Book *copyBook(const Book *book){
    return createBook(book->title, book->pagesNumber, book->price);
}

Student *createStudent(char *name, unsigned int age, const Book *favorityBook){
    Student *newStudent = (Student*)malloc(sizeof(Student));
    newStudent->name = name;
    newStudent->age = age;
    newStudent->favorityBook = copyBook(favorityBook);
    return newStudent;
}

void destroyBook(Book **bookReferency){
    Book *copyBook = *bookReferency;
    free(copyBook);
    *bookReferency = NULL;
}

void destroyStudent(Student **studentReferency){
    Student *copyStudent = *studentReferency;
    destroyBook(&(copyStudent->favorityBook));
    free(copyStudent);
    *studentReferency = NULL;
}

void printBook(const Book *book){
    if(book != NULL){
        printf("Book's title: %s\n", book->title);
        printf("Book page number: %d\n", book->pagesNumber);
        printf("Book price: %.2f\n", book->price);
    }
    else
        printf("Unregistered book\n");
}

void printStundet(const Student *student){
    if(student != NULL){
        printf("Student's name: %s\n", student->name);
        printf("Student's age: %d yers old\n", student->age);
        puts("Favority book");
        puts("-------------");
        printBook(student->favorityBook);
    }
    else
        printf("Unregistered student\n");     
}

int main(){

    Book *harryBook = createBook("Harry Poter", 180, 150.65);
    
    Student *ted = createStudent("Ted", 16, harryBook);
    
    printStundet(ted);

    destroyBook(&harryBook);

    printStundet(ted);

    destroyStudent(&ted);

    return 0;
}