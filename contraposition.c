#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof techniques: Contraposition and Contradiction
 *
 * - Contraposition: to prove "P -> Q", we instead prove the logically
 *   equivalent statement "not Q -> not P".
 * - Contradiction: to prove "P -> Q", we assume P is true and Q is
 *   false at the same time, then show this combination is impossible.
 *
 * For the contradiction functions below, the assumption should never
 * actually hold, so calling them with any input is expected to
 * return false ("no contradiction found" = the original claim is
 * safe).
 */

// Claim: If n is even, then n^2 is even.
// (This is the lemma used for the contrapositive proof of
//  "if n^2 is odd, then n is odd".)
bool even_implies_even_square(int n) {
    if (n % 2 == 0) {
        int result = n * n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

// Claim: If n is odd, then n^2 - 1 is divisible by 4.
bool odd_implies_square_minus_one_div4(int n) {
    if (n % 2 != 0) {
        int result = (n * n) - 1;
        if (result % 4 == 0) {
            return true;
        }
    }
    return false;
}

// Claim: If x is even, then 5x + 3 is odd.
bool even_implies_5x_plus_3_odd(int x) {
    if (x % 2 == 0) {
        int result = (5 * x) + 3;
        if (result % 2 != 0) {
            return true;
        }
    }
    return false;
}

// Proof by contradiction: assume n is odd AND n^2 is even at the
// same time. An odd n always gives an odd n^2, so this can never
// happen -- the function should always return false.
bool contradiction_odd_n_even_square(int n) {
    if (n % 2 != 0 && n * n % 2 == 0) {
        return true;
    }
    return false;
}

// Proof by contradiction: assume a < 5 and b < 5 AND a + b >= 10 at
// the same time. If both are under 5, their sum can never reach 10,
// so the function should always return false.
bool contradiction_sum_ge_10_both_under5(int a, int b) {
    if (a + b >= 10 && a < 5 && b < 5) {
        return true;
    }
    return false;
}

// Proof by contradiction: assume n is even AND 3n + 2 is odd at the
// same time. 3n stays even whenever n is even, so 3n + 2 is always
// even too -- the function should always return false.
bool contradiction_even_n_3n_plus_2_odd(int n) {
    if (n % 2 == 0) {
        int result = (3 * n) + 2;
        if (result % 2 != 0) {
            return true;
        }
    }
    return false;
}

// Proof by contradiction: assume a*b is odd AND (a is even OR b is
// even) at the same time. If either factor is even, the product is
// even, so the function should always return false.
// Note: fixed the odd-product check to "% 2 != 0" -- the original
// commented code used "!= 0", which only tested "product is not
// zero" and did not actually check oddness.
bool contradiction_product_odd_but_one_even(int a, int b) {
    bool product_is_odd = (a * b) % 2 != 0;
    bool one_is_even = (a % 2 == 0) || (b % 2 == 0);

    if (product_is_odd && one_is_even) {
        return true;
    }
    return false;
}

// Proof by contradiction: assume a + b is odd AND both a and b are
// odd at the same time. Two odd numbers always sum to an even
// number, so the function should always return false.
bool contradiction_sum_odd_both_odd(int a, int b) {
    bool sum_is_odd = (a + b) % 2 != 0;
    bool both_odd = (a % 2 != 0) && (b % 2 != 0);

    if (sum_is_odd && both_odd) {
        return true;
    }
    return false;
}

int main(void) {
    printf("[n even -> n^2 even]                 n=4       -> %s\n",
           even_implies_even_square(4) ? "True" : "False");

    printf("[n odd -> n^2-1 div by 4]             n=3       -> %s\n",
           odd_implies_square_minus_one_div4(3) ? "True" : "False");

    printf("[x even -> 5x+3 odd]                  x=4       -> %s\n",
           even_implies_5x_plus_3_odd(4) ? "True" : "False");

    printf("[contradiction: odd n, even n^2]      n=3       -> %s\n",
           contradiction_odd_n_even_square(3) ? "Found (bug!)" : "None (as expected)");

    printf("[contradiction: a,b<5 but a+b>=10]    a=3,b=3   -> %s\n",
           contradiction_sum_ge_10_both_under5(3, 3) ? "Found (bug!)" : "None (as expected)");

    printf("[contradiction: even n, odd 3n+2]     n=4       -> %s\n",
           contradiction_even_n_3n_plus_2_odd(4) ? "Found (bug!)" : "None (as expected)");

    printf("[contradiction: odd product, 1 even]  a=3,b=6   -> %s\n",
           contradiction_product_odd_but_one_even(3, 6) ? "Found (bug!)" : "None (as expected)");

    printf("[contradiction: odd sum, both odd]    a=4,b=6   -> %s\n",
           contradiction_sum_odd_both_odd(4, 6) ? "Found (bug!)" : "None (as expected)");

    return 0;
}
