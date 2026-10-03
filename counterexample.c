#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof technique: Disproof by Counterexample
 *
 * To disprove a "for all n" claim, it is enough to find a single n
 * that breaks it. Each function below searches a range of n for such
 * a counterexample and reports the first one it finds (if any).
 */

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

/* ---------------------------------------------------------------
 * Claim: 2^n + 1 is always prime (for n = 1, 2, 3, ...).
 * Counterexample: n = 3 gives 2^3 + 1 = 9 = 3 * 3, which is not
 * prime.
 * --------------------------------------------------------------- */
void find_counterexample_power_of_2_plus_1(void) {
    printf("[2^n + 1 is always prime]\n");
    for (int n = 1; n <= 20; n++) {
        int result = (1 << n) + 1;
        if (!is_prime(result)) {
            printf("  Counterexample found: n=%d -> %d is not prime\n", n, result);
            return;
        }
    }
    printf("  No counterexample found in range\n");
}

/* ---------------------------------------------------------------
 * Claim: n^2 + n + 41 is always prime (for n = 0, 1, 2, ...).
 * This is Euler's famous prime-generating polynomial -- it produces
 * primes for every n from 0 to 39, which makes it a good illustration
 * of why a few correct cases are never a proof.
 * Counterexample: n = 40 gives 40^2 + 40 + 41 = 1681 = 41 * 41, which
 * is not prime.
 * --------------------------------------------------------------- */
void find_counterexample_eulers_polynomial(void) {
    printf("[n^2 + n + 41 is always prime]\n");
    for (int n = 0; n <= 45; n++) {
        int result = n * n + n + 41;
        if (!is_prime(result)) {
            printf("  Counterexample found: n=%d -> %d is not prime\n", n, result);
            return;
        }
    }
    printf("  No counterexample found in range\n");
}

int main(void) {
    find_counterexample_power_of_2_plus_1();
    find_counterexample_eulers_polynomial();
    return 0;
}
