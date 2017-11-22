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

// An example of "classical" C allocation, initialisation and deallocation.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A sub-component
typedef struct
{
    int x;
} A;

// Top-level component
typedef struct
{
    A a0;
    A * a1;
} B;

int main(int argc, char ** argv)
{
    // static allocation of B
    A a1 = { 42 };
    B b0 = { { 17 }, &a1 };

    // dynamic allocation of B
    B * b1 = malloc(sizeof(*b1));
    memset(b1, 0, sizeof(*b1));
    b1->a0.x = 18;
    b1->a1 = malloc(sizeof(A));
    b1->a1->x = 42;

    // mixed allocation of B
    B b2 = { { 19 }, malloc(sizeof(A)) };
    memset(b2.a1, 0, sizeof(A));
    b2.a1->x = 42;

    printf("b0: a0.x %d, a1->x %d\n", b0.a0.x, b0.a1->x);
    printf("b1: a0.x %d, a1->x %d\n", b1->a0.x, b1->a1->x);
    printf("b1: a0.x %d, a1->x %d\n", b2.a0.x, b2.a1->x);


    // no deallocation of statically allocated b0

    // deallocation of dynamically allocated b1
    free(b1->a1);
    free(b1);

    // dellocation of mixed allocation of B
    free(b2.a1);
}

