#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof technique: Proof by Contradiction
 *
 * To prove a claim, we assume the opposite of what we want to prove
 * and show that this assumption leads to something impossible. Two
 * styles are used below:
 *   1. A direct hypothesis check (like in contraposition.c).
 *   2. A brute-force search over a range of integers, looking for a
 *      counterexample to the assumption. If none is found, the
 *      assumption is contradicted and the original claim holds.
 */

/* ---------------------------------------------------------------
 * Claim: If n is even, then n^2 is even.
 * Proof by contradiction: assume n is even but n^2 turns out odd.
 * This should never happen, so the check below always succeeds
 * whenever the hypothesis (n even) is true.
 * --------------------------------------------------------------- */
bool contradiction_even_n_implies_even_square(int n) {
    if (n % 2 == 0) {
        int result = n * n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------------------
 * Claim: There is no integer n such that 21n + 4 is divisible by 7.
 * Proof by contradiction: assume such an n exists, and search for it.
 * 21n is always a multiple of 7, so 21n + 4 always leaves remainder 4
 * mod 7 -- it can never be divisible by 7. The search below should
 * never find a counterexample.
 * --------------------------------------------------------------- */
bool exists_n_where_21n_plus_4_divisible_by_7(void) {
    for (int n = -100; n <= 100; n++) {
        if ((21 * n + 4) % 7 == 0) {
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------------------
 * Claim: There is no integer n such that 3n + 1 is divisible by 3.
 * Proof by contradiction: assume such an n exists, and search for it.
 * 3n is always a multiple of 3, so 3n + 1 always leaves remainder 1
 * mod 3 -- it can never be divisible by 3. The search below should
 * never find a counterexample.
 * --------------------------------------------------------------- */
bool exists_n_where_3n_plus_1_divisible_by_3(void) {
    for (int n = -100; n <= 100; n++) {
        if ((3 * n + 1) % 3 == 0) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int x = 4;
    printf("[n even -> n^2 even]      n=%d              -> %s\n", x,
           contradiction_even_n_implies_even_square(x) ? "True" : "False");

    printf("[exists n: 7 | 21n+4]     n in [-100,100]    -> %s\n",
           exists_n_where_21n_plus_4_divisible_by_7()
               ? "Found (bug!)"
               : "None (as expected)");

    printf("[exists n: 3 | 3n+1]      n in [-100,100]    -> %s\n",
           exists_n_where_3n_plus_1_divisible_by_3()
               ? "Found (bug!)"
               : "None (as expected)");

    return 0;
}