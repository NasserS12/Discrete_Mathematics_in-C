#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof technique: Direct Proof
 *
 * In a direct proof, we assume the hypothesis (P) is true and show,
 * through a chain of valid steps, that the conclusion (Q) must also
 * be true. Each function below encodes one such proof: it checks the
 * hypothesis, computes the value from the conclusion, and verifies
 * the conclusion holds. Each should return true for every input that
 * satisfies the hypothesis.
 */

// Claim: If n is even, then 5n + 4 is even.
bool proof_5n_plus_4_is_even(int n) {
    if (n % 2 == 0) {               // hypothesis: n is even
        int result = 5 * n + 4;     // build the conclusion's expression
        if (result % 2 == 0) {      // check the conclusion: result is even
            return true;
        }
    }
    return false;
}

// Claim: If n is odd, then n^2 + 5n + 6 is even.
bool proof_n_squared_plus_5n_plus_6_is_even(int n) {
    if (n % 2 != 0) {                       // hypothesis: n is odd
        int result = n * n + 5 * n + 6;     // build the conclusion's expression
        if (result % 2 == 0) {              // check the conclusion: result is even
            return true;
        }
    }
    return false;
}

// Claim: If n is odd, then n^3 is odd.
bool proof_n_cubed_is_odd(int n) {
    if (n % 2 != 0) {               // hypothesis: n is odd
        int result = n * n * n;     // build the conclusion's expression
        if (result % 2 != 0) {      // check the conclusion: result is odd
            return true;
        }
    }
    return false;
}

int main(void) {
    int n1 = 4;
    printf("[5n+4 is even]          n=%d -> %s\n", n1,
           proof_5n_plus_4_is_even(n1) ? "True" : "False");

    int n2 = 3;
    printf("[n^2+5n+6 is even]      n=%d -> %s\n", n2,
           proof_n_squared_plus_5n_plus_6_is_even(n2) ? "True" : "False");

    int n3 = 7;
    printf("[n^3 is odd]            n=%d -> %s\n", n3,
           proof_n_cubed_is_odd(n3) ? "True" : "False");

    return 0;
}
