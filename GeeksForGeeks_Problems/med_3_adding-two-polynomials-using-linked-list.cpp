// https://www.geeksforgeeks.org/adding-two-polynomials-using-linked-list/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void show(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
    cout << endl;
}

void create_node(int x, int y, struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

// Add polyinomial function
struct Node* polyadd(struct Node* poly1, struct Node* poly2) {
	struct Node* poly = NULL;
	struct Node* res = NULL;

    if ((poly1 == NULL) && (poly2 == NULL))
    	return NULL;
    
    if(poly1 == NULL){
    	poly = poly2;
    	return poly;
    }
    
    if(poly2 == NULL){
    	poly = poly1;
    	return poly;
    }
    while((poly1 != NULL) && (poly2 != NULL)) {
    	if(poly1->pow > poly2->pow) {
    		if(poly != NULL) {
    			poly->next = poly1;
    			poly = poly->next;
    		}
    		else {
    			poly = poly1;
    			res = poly;
    		}
    		poly1 = poly1->next;
    	}
    	else if(poly2->pow > poly1->pow) {
    		if(poly != NULL) {
    			poly->next = poly2;
    			poly = poly->next;
    		}
    		else {
    			poly = poly2;
    			res = poly;
    		}
    		poly2 = poly2->next;
    	}
    	else {
    		poly1->coeff = poly1->coeff + poly2->coeff;
    		if(poly != NULL) {
    			poly->next = poly1;
    			poly = poly->next;
    		}
    		else {
    			poly = poly1;
    			res = poly;
    		}
    		poly1 = poly1->next;
    		poly2 = poly2->next;
    	}
    }
    return res;
}
 
// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
 
    // Create first list of 5x^2 + 4x^1 + 2x^0
    create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);
 
    // Create second list of -5x^1 - 5x^0
    create_node(-5, 1, &poly2);
    create_node(-5, 0, &poly2);
 
    cout << "1st Number: " ;
    show(poly1);
 
    cout << "2nd Number: ";
    show(poly2);
 
    // Function add two polynomial numbers
    poly = polyadd(poly1, poly2);
    if(poly == NULL)
    	cout << "NULL" << endl;
 
    // Display resultant List
    cout << "Added polynomial: ";
    show(poly);
 
    return 0;
}
