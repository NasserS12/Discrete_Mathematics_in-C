#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof technique: Mathematical Induction
 *
 * To prove a formula holds for every positive integer n, induction
 * shows: (1) it holds for the base case, and (2) if it holds for some
 * k, it also holds for k+1 -- so it holds for every n after that.
 *
 * Here, instead of re-deriving the base case and inductive step by
 * hand each time, each claim is checked numerically: one function
 * computes the left-hand side (the sum, built with a loop, exactly
 * as the formula defines it) and another computes the right-hand
 * side (the closed-form formula). If they match for a given n, the
 * formula holds for that n.
 */

/* ---------------------------------------------------------------
 * Claim: 1 + 3 + 5 + ... + (2n-1) = n^2
 * --------------------------------------------------------------- */

int sum_odd_numbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (2 * i - 1);
    }
    return sum;
}

int n_squared(int n) {
    return n * n;
}

/* ---------------------------------------------------------------
 * Claim: 3 + 6 + 9 + ... + 3n = 3n(n+1) / 2
 * --------------------------------------------------------------- */

int sum_multiples_of_3(int n) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
        sum += (3 * j);
    }
    return sum;
}

int closed_form_multiples_of_3(int n) {
    return (3 * n * (n + 1)) / 2;
}

/* ---------------------------------------------------------------
 * Claim: 4 + 8 + 12 + ... + 4n = 2n(n+1)
 * --------------------------------------------------------------- */

int sum_multiples_of_4(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (4 * i);
    }
    return sum;
}

int closed_form_multiples_of_4(int n) {
    return 2 * n * (n + 1);
}

/* ---------------------------------------------------------------
 * Claim: 1*2 + 2*3 + 3*4 + ... + n(n+1) = n(n+1)(n+2) / 3
 * --------------------------------------------------------------- */

int sum_products(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1);
    }
    return sum;
}

int closed_form_products(int n) {
    return (n * (n + 1) * (n + 2)) / 3;
}

/* ---------------------------------------------------------------
 * Claim (deliberately WRONG, kept to show a "not equal" result):
 * 1 + 2 + 3 + ... + n = n(n+1)
 *
 * The correct closed form is n(n+1) / 2 -- this version is missing
 * the division by 2, so it will never match the loop sum except at
 * n = 0.
 * --------------------------------------------------------------- */

int sum_natural_numbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int wrong_closed_form_natural_numbers(int n) {
    return n * (n + 1);
}

int main(void) {
    int n;

    n = 3;
    printf("[1+3+...+(2n-1) = n^2]            n=%d -> %s\n", n,
           sum_odd_numbers(n) == n_squared(n) ? "equal" : "not equal");

    n = 4;
    printf("[3+6+...+3n = 3n(n+1)/2]          n=%d -> %s\n", n,
           sum_multiples_of_3(n) == closed_form_multiples_of_3(n)
               ? "equal"
               : "not equal");

    n = 4;
    printf("[4+8+...+4n = 2n(n+1)]            n=%d -> %s\n", n,
           sum_multiples_of_4(n) == closed_form_multiples_of_4(n)
               ? "equal"
               : "not equal");

    n = 3;
    printf("[1*2+2*3+...+n(n+1) = n(n+1)(n+2)/3] n=%d -> %s\n", n,
           sum_products(n) == closed_form_products(n) ? "equal" : "not equal");

    n = 5;
    printf("[1+2+...+n = n(n+1)]  (wrong formula) n=%d -> %s\n", n,
           sum_natural_numbers(n) == wrong_closed_form_natural_numbers(n)
               ? "equal"
               : "not equal");

    return 0;
}