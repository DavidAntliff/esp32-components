/*
 * MIT License
 *
 * Copyright (c) 2017 David Antliff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// An example of "three-step" C allocation, initialisation, configuration and deallocation.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * Component A Interface
 */

// Component structure
typedef struct
{
    bool init;
    int x;
    float y;
} A;

// Dynamica Allocator
A * A_malloc(void);

// Initialisation
void A_init(A * a);

// Alternative Initialisation
void A_init_with_x(A * a, int x);

// Configuration
void A_set_x(A * a, int x);
void A_set_y(A * a, float y);
void A_set_x_y(A * a, int x, float y);

// Destruction
void A_free(A ** a);


/*
 * Component B Interface
 */

// Component structure
typedef struct
{
    bool init;
    A a0;       // inline (private)
    A * a1;     // dynamic (private)
    A * a2;     // dynamic (public)
} B;

// Dynamic Allocator
B * B_malloc(void);

// Initialisation
void B_init(B * b);

// Configuration
void B_set_a0_x(B * b, int x);
void B_set_a1_x(B * b, int x);

// Destruction
void B_free(B ** b);


/*
 * Example
 */

int main(int argc, char ** argv)
{
    // static allocation
    A a1_static;
    A * a1 = &a1_static;

    B b0_static;
    B * b0 = &b0_static;   // use a pointer for consistency
    B_init(b0);
    B_set_a0_x(b0, 17);
    B_set_a1_x(b0, 42);
    printf("b0: a0.x %d, a1->x %d\n", b0->a0.x, b0->a1->x);
//    B_free(&b0);

    // dynamic allocation
    B * b1 = B_malloc();
    B_init(b1);
    B_set_a0_x(b1, 18);
    B_set_a1_x(b1, 42);
    printf("b1: a0.x %d, a1->x %d\n", b1->a0.x, b1->a1->x);
    B_free(&b1);
}





/*
 * Implementation
 */


A * A_malloc(void)
{
    A * a = malloc(sizeof(*a));
    if (a != NULL)
    {
        memset(a, 0, sizeof(*a));
    }

    return a;
}

void A_init(A * a)
{
    if (a != NULL)
    {
        a->x = 0;
        a->y = 1.0;  // non-zero default
        a->init = true;
    }
}

void A_init_with_x(A * a, int x)
{
    if (a != NULL)
    {
        a->x = x;
        a->y = 1.0;
        a->init = true;
    }
}

void A_set_x(A * a, int x)
{
    if (a != NULL && a->init)
    {
        a->x = x;
    }
}

void A_set_y(A * a, float y)
{
    if (a != NULL && a->init)
    {
        a->y = y;
    }
}

void A_set_x_y(A * a, int x, float y)
{
    if (a != NULL && a->init)
    {
        a->x = x;
        a->y = y;
    }
}

void A_free(A ** a)
{
    if (a != NULL && (*a != NULL))
    {
        free(*a);
        *a = NULL;
    }
}



B * B_malloc(void)
{
    B * b = malloc(sizeof(*b));
    if (b != NULL)
    {
        memset(b, 0, sizeof(*b));
        b->a1 = A_malloc();
    }

    return b;
}

void B_init(B * b)
{
    if (b != NULL)
    {
        A_init(&b->a0);  // initialise first sub-component
        A_init(b->a1);   // initialise second sub-component
        b->init = true;
    }
}

void B_set_a0_x(B * b, int x)
{
    if (b != NULL && b->init)
    {
        A_set_x(&b->a0, x);
    }
}

void B_set_a1_x(B * b, int x)
{
    if (b != NULL && b->init)
    {
        A_set_x(b->a1, x);
    }
}

void B_free(B ** b)
{
    if (b != NULL && (*b != NULL))
    {
        A_free(&(*b)->a1);
        free(*b);
        *b = NULL;
    }
}


