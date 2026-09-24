#include <stdio.h>
#include <stdbool.h>

/*
 * Discrete Math -> C translations
 * Proof technique: Proof by Cases
 *
 * To prove a claim holds for every integer, we split the integers
 * into a few cases (usually based on remainder mod 2, mod 3, mod 4,
 * ...) that cover every possibility, then prove the claim separately
 * in each case. Below, each claim has one function per case; if the
 * hypothesis for that case holds, the function checks the claim and
 * returns true.
 */

/* ---------------------------------------------------------------
 * Claim: For every integer n, n^2 + 3n is even.
 * Cases: n even, n odd.
 * --------------------------------------------------------------- */

bool case_n2_plus_3n_even__n_even(int n) {
    if (n % 2 == 0) {
        int result = (n * n) + 3 * n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

bool case_n2_plus_3n_even__n_odd(int n) {
    if (n % 2 != 0) {
        int result = (n * n) + 3 * n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------------------
 * Claim: For every integer n, n^2 + n is even.
 * Cases: n even, n odd.
 * --------------------------------------------------------------- */

bool case_n2_plus_n_even__n_even(int n) {
    if (n % 2 == 0) {
        int result = n * n + n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

bool case_n2_plus_n_even__n_odd(int n) {
    if (n % 2 != 0) {
        int result = n * n + n;
        if (result % 2 == 0) {
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------------------
 * Claim: For every integer n, n^2 mod 4 is either 0 or 1.
 * Cases: n mod 4 = 0, 1, 2, 3.
 * --------------------------------------------------------------- */

bool case_n2_mod4__n_mod4_is_0(int n) {
    if (n % 4 == 0) {
        int result = n * n % 4;
        if (result == 0 || result == 1) {
            return true;
        }
    }
    return false;
}

bool case_n2_mod4__n_mod4_is_1(int n) {
    if (n % 4 == 1) {
        int result = n * n % 4;
        if (result == 0 || result == 1) {
            return true;
        }
    }
    return false;
}

bool case_n2_mod4__n_mod4_is_2(int n) {
    if (n % 4 == 2) {
        int result = n * n % 4;
        if (result == 0 || result == 1) {
            return true;
        }
    }
    return false;
}

bool case_n2_mod4__n_mod4_is_3(int n) {
    if (n % 4 == 3) {
        int result = n * n % 4;
        if (result == 0 || result == 1) {
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------------------
 * Claim: For every integer n, n(n+1)(n+2) is divisible by 3.
 * (Any 3 consecutive integers include a multiple of 3.)
 * Cases: n mod 3 = 0, 1, 2.
 * --------------------------------------------------------------- */

bool case_product3_div3__n_mod3_is_0(int n) {
    if (n % 3 == 0) {
        int result = n * (n + 1) * (n + 2);
        if (result % 3 == 0) {
            return true;
        }
    }
    return false;
}

bool case_product3_div3__n_mod3_is_1(int n) {
    if (n % 3 == 1) {
        int result = n * (n + 1) * (n + 2);
        if (result % 3 == 0) {
            return true;
        }
    }
    return false;
}

bool case_product3_div3__n_mod3_is_2(int n) {
    if (n % 3 == 2) {
        int result = n * (n + 1) * (n + 2);
        if (result % 3 == 0) {
            return true;
        }
    }
    return false;
}

int main(void) {
    /* Claim 1: n^2 + 3n is always even */
    int n1_even = 4, n1_odd = 3;
    bool claim1 = case_n2_plus_3n_even__n_even(n1_even) &&
                  case_n2_plus_3n_even__n_odd(n1_odd);
    printf("[n^2+3n is even]        n=%d(even), n=%d(odd)  -> %s\n",
           n1_even, n1_odd, claim1 ? "True" : "False");

    /* Claim 2: n^2 + n is always even */
    int n2_even = 4, n2_odd = 5;
    bool claim2 = case_n2_plus_n_even__n_even(n2_even) &&
                  case_n2_plus_n_even__n_odd(n2_odd);
    printf("[n^2+n is even]         n=%d(even), n=%d(odd)  -> %s\n",
           n2_even, n2_odd, claim2 ? "True" : "False");

    /* Claim 3: n^2 mod 4 is 0 or 1, for every residue mod 4 */
    int n3_r0 = 12, n3_r1 = 9, n3_r2 = 6, n3_r3 = 7;
    bool claim3 = case_n2_mod4__n_mod4_is_0(n3_r0) &&
                  case_n2_mod4__n_mod4_is_1(n3_r1) &&
                  case_n2_mod4__n_mod4_is_2(n3_r2) &&
                  case_n2_mod4__n_mod4_is_3(n3_r3);
    printf("[n^2 mod 4 is 0 or 1]   n=%d,%d,%d,%d (mod4=0,1,2,3) -> %s\n",
           n3_r0, n3_r1, n3_r2, n3_r3, claim3 ? "True" : "False");

    /* Claim 4: n(n+1)(n+2) is divisible by 3, for every residue mod 3 */
    int n4_r0 = 6, n4_r1 = 4, n4_r2 = 5;
    bool claim4 = case_product3_div3__n_mod3_is_0(n4_r0) &&
                  case_product3_div3__n_mod3_is_1(n4_r1) &&
                  case_product3_div3__n_mod3_is_2(n4_r2);
    printf("[n(n+1)(n+2) div by 3]  n=%d,%d,%d (mod3=0,1,2)    -> %s\n",
           n4_r0, n4_r1, n4_r2, claim4 ? "True" : "False");

    return 0;
}
