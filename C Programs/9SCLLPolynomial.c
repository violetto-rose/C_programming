/*9) Develop a Program in C for the following operations on Singly Circular Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = (6x^2 y^2 z)-(4y z^5)+(3x^3 y z)+(2x y^5 z)-(2x y z^3).
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z).
Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int coeff;
    int power_x;
    int power_y;
    int power_z;
    struct term *next;
} Term;

Term *createTerm(int coeff, int power_x, int power_y, int power_z) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newTerm->coeff = coeff;
    newTerm->power_x = power_x;
    newTerm->power_y = power_y;
    newTerm->power_z = power_z;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(Term **poly, int coeff, int power_x, int power_y, int power_z) {
    Term *temp = createTerm(coeff, power_x, power_y, power_z);
    if (*poly == NULL) {
        *poly = temp;
        (*poly)->next = *poly; // Circular link
    } else {
        temp->next = (*poly)->next;
        (*poly)->next = temp;
        *poly = temp;
    }
}

void displayPoly(Term *poly) {
    Term *temp = poly->next; // Skip header node
    if (temp == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    while (temp != poly) {
        printf("(%dx^%dy^%dz^%d)", temp->coeff, temp->power_x, temp->power_y, temp->power_z);
        temp = temp->next;
        if (temp != poly) {
            printf(" + ");
        }
    }
    printf("\n");
}

void addPoly(Term *poly1, Term *poly2, Term **polySum) {
    Term *temp1 = poly1->next; // Skip header node
    Term *temp2 = poly2->next; // Skip header node

    while (temp1 != poly1 && temp2 != poly2) {
        if (temp1->power_x == temp2->power_x && temp1->power_y == temp2->power_y && temp1->power_z == temp2->power_z) {
            insertTerm(polySum, temp1->coeff + temp2->coeff, temp1->power_x, temp1->power_y, temp1->power_z);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->power_x > temp2->power_x || 
                   (temp1->power_x == temp2->power_x && temp1->power_y > temp2->power_y) || 
                   (temp1->power_x == temp2->power_x && temp1->power_y == temp2->power_y && temp1->power_z > temp2->power_z)) {
            insertTerm(polySum, temp1->coeff, temp1->power_x, temp1->power_y, temp1->power_z);
            temp1 = temp1->next;
        } else {
            insertTerm(polySum, temp2->coeff, temp2->power_x, temp2->power_y, temp2->power_z);
            temp2 = temp2->next;
        }
    }

    while (temp1 != poly1) {
        insertTerm(polySum, temp1->coeff, temp1->power_x, temp1->power_y, temp1->power_z);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        insertTerm(polySum, temp2->coeff, temp2->power_x, temp2->power_y, temp2->power_z);
        temp2 = temp2->next;
    }
}

int main() {
    Term *poly1 = NULL, *poly2 = NULL, *polySum = NULL;

    // Representing polynomial P(x,y,z)
    insertTerm(&poly1, 6, 2, 2, 1); // 6x^2 y^2 z
    insertTerm(&poly1, -4, 0, 1, 5); // -4y z^5
    insertTerm(&poly1, 3, 3, 1, 1); // 3x^3 y z
    insertTerm(&poly1, 2, 1, 5, 1); // 2x y^5 z
    insertTerm(&poly1, -2, 1, 1, 3); // -2x y z^3

    // Displaying polynomial P(x,y,z)
    printf("Polynomial P(x,y,z): ");
    displayPoly(poly1);

    // Representing polynomial Q(x,y,z)
    insertTerm(&poly2, 1, 2, 2, 1); // x^2 y^2 z
    insertTerm(&poly2, 2, 1, 1, 1); // 2x y z
    insertTerm(&poly2, -3, 0, 1, 3); // -3y z^3

    // Displaying polynomial Q(x,y,z)
    printf("Polynomial Q(x,y,z): ");
    displayPoly(poly2);

    // Adding polynomials P(x,y,z) and Q(x,y,z) to get the sum
    addPoly(poly1, poly2, &polySum);

    // Displaying sum of polynomials P(x,y,z) and Q(x,y,z)
    printf("Sum of polynomials P(x,y,z) and Q(x,y,z): ");
    displayPoly(polySum);

    return 0;
}
