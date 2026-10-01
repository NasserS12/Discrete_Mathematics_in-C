#include <stdio.h>

/*
 * Discrete Math -> C translations
 * Topic: Truth Tables & Classifying Logical Statements
 *
 * Each function below builds the truth table for one logical
 * expression by looping over every combination of true/false (1/0)
 * for its variables (p, q, r, ...), the same way you'd do it by hand
 * on paper.
 */

// Truth table for: p -> q, q -> r, and (p -> q) && (q -> r)
void basic_truth_table(void) {
    printf("\t=== Basic Logical Operators Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            for (int r = 1; r >= 0; r--) {
                int p_implies_q = (!p || q);
                int q_implies_r = (!q || r);
                int and_result = p_implies_q && q_implies_r;

                printf("p = %d, q = %d, r = %d | p -> q = %d | q -> r = %d | (p -> q) && (q -> r) = %d\n",
                       p, q, r, p_implies_q, q_implies_r, and_result);
            }
        }
    }
}

// Tautology: a statement that is true for every combination of inputs.
// Example: (p && q) -> p
void tautology(void) {
    printf("\n\t=== Tautology Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_and_q = p && q;
            int implies_p = !(p && q) || p;
            printf("p = %d, q = %d | p && q = %d | (p && q) -> p = %d\n",
                   p, q, p_and_q, implies_p);
        }
    }
}

// Contradiction: a statement that is false for every combination of inputs.
// Example: (p && q) && ~p
void contradiction(void) {
    printf("\n\t=== Contradiction Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_and_q = p && q;
            int not_p = !p;
            int result = not_p && p_and_q;
            printf("p = %d, q = %d | (p && q) = %d | ~p = %d | (p && q) && ~p = %d\n",
                   p, q, p_and_q, not_p, result);
        }
    }
}

// Contingency: a statement that is sometimes true and sometimes false.
// Example: p -> q
void contingency(void) {
    printf("\n\t=== Contingency Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_implies_q = !p || q;
            printf("p = %d, q = %d | p -> q = %d\n", p, q, p_implies_q);
        }
    }
}

// Classifies a statement as Tautology, Contradiction, or Contingency
// by counting how many rows of its truth table come out true.
// Example statement checked here: (p && q) -> p
void classify_statement(void) {
    printf("\n\t=== Classifying (p && q) -> p ===\n\n");
    int true_count = 0;
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int result = !(p && q) || p;
            if (result == 1) {
                true_count++;
            }
        }
    }

    if (true_count == 4) {
        printf("Result: Tautology\n");
    } else if (true_count == 0) {
        printf("Result: Contradiction\n");
    } else {
        printf("Result: Contingency\n");
    }
}

int main(void) {
    basic_truth_table();
    tautology();
    contradiction();
    contingency();
    classify_statement();
    return 0;
}
