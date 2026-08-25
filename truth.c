#include <stdio.h>

// Generates a truth table for 3 variables (p, q, r) testing hypothetical syllogism
void basic_truth_table() {
    printf("\t=== Basic Logical Operators Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            for (int r = 1; r >= 0; r--) {                
                int p_implies_q = (!p || q);      // p -> q
                int q_implies_r = (!q || r);      // q -> r
                int and_result = p_implies_q && q_implies_r; // (p -> q) ^ (q -> r)
                
                printf("p = %d, q = %d, r = %d | p -> q = %d | q -> r = %d | (p -> q) && (q -> r) = %d\n\n", 
                        p, q, r, p_implies_q, q_implies_r, and_result);
            }
        }
    }
}

// Demonstrates a Tautology: statement is ALWAYS true (all outputs = 1)
void tautology() {
    printf("\t== Tautology Truth Table ==\n\n");

    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_and_q = p && q;
            int implies_p = !(p && q) || p; // (p ^ q) -> p
            printf("p = %d, q = %d | p && q = %d | (p && q) -> p = %d\n\n", p, q, p_and_q, implies_p);
        }    
    }        
} 

// Demonstrates a Contradiction: statement is ALWAYS false (all outputs = 0)
void contradiction() {
    printf("\t== Contradiction Truth Table == \n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_and_q = p && q;
            int not_p = !p;
            int result = not_p && p_and_q; // ~p ^ (p ^ q)
            printf("p = %d, q = %d | (p && q) = %d | ~p = %d | (p && q) && ~p = %d\n\n",
                    p, q, p_and_q, not_p, result);
        }
    }
}

// Demonstrates a Contingency: statement outputs a mix of true (1) and false (0)
void contingency() {
    printf("\t== Contingency Truth Table == \n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_implies_q = !p || q; // p -> q
            printf("p = %d, q = %d | p -> q = %d\n", p, q, p_implies_q);
        }
    }
}

// Automatically evaluates and classifies any logical proposition for 2 variables
void classify_statement() {
    int true_count = 0;

    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            // Change the expression in 'result' to test any logical statement
            int result = !(p && q) || p;

            if (result == 1) {
                true_count++;
            }
        }
    }

    // Classification based on the total number of true states
    if (true_count == 4) {
        printf("Result: Tautology\n");
    } 
    else if (true_count == 0) {
        printf("Result: Contradiction\n");
    } 
    else {
        printf("Result: Contingency\n");
    }
}

int main() {
    basic_truth_table();
    // tautology();
    // contradiction();
    // contingency();
    // classify_statement();
    return 0;
}
