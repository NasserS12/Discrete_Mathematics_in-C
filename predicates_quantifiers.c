
#include <stdio.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------
// 1. Universal Quantifier: forall x P(x)
//    Rule: Start with true (1), invert condition in 'if' to catch failure.
// ----------------------------------------------------------------------------
void test_universal_quantifier() {
    printf("--- 1. Universal Quantifier (forall x) ---\n");
    
    // Example: Check if ALL elements are odd
    int numbers[] = {3, 7, 11, 2, 9};
    int size = 5;

    bool is_all_odd = true;

    for (int i = 0; i < size; i++) {
        // Inverted condition: if we find an EVEN number, the predicate fails
        if (numbers[i] % 2 == 0) {
            is_all_odd = false;
            break; // Counterexample found, terminate search
        }
    }

    if (is_all_odd) {
        printf("Result: True (All elements satisfy the predicate)\n\n");
    } else {
        printf("Result: False (Counterexample found)\n\n");
    }
}

// ----------------------------------------------------------------------------
// 2. Existential Quantifier: exist x P(x)
//    Rule: Start with false (0), use direct condition in 'if' to catch success.
// ----------------------------------------------------------------------------
void test_existential_quantifier() {
    printf("--- 2. Existential Quantifier (exist x) ---\n");

    // Example: Check if THERE EXISTS at least one element less than 10
    int data[] = {12, 18, 11, 22, 40};
    int size = 5;

    bool exists = false;

    for (int x = 0; x < size; x++) {
        // Direct condition: searching for the first element matching the predicate
        if (data[x] < 10) {
            exists = true;
            break; // First success found, terminate search
        }
    }

    if (exists) {
        printf("Result: True (At least one element satisfies the predicate)\n\n");
    } else {
        printf("Result: False (No elements satisfy the predicate)\n\n");
    }
}

// ----------------------------------------------------------------------------
// 3. Universal Quantifier with Compound Condition: forall x (P(x) AND Q(x))
// ----------------------------------------------------------------------------
void test_universal_compound() {
    printf("--- 3. Universal Quantifier with Compound Predicate ---\n");

    // Example: Check if ALL numbers are multiples of 5
    int data[] = {15, 25, 30, 45, 50};
    int size = 5;

    bool all_multiples_of_5 = true;

    for (int i = 0; i < size; i++) {
        // Inverted condition: Catch anything not divisible by 5
        if (data[i] % 5 != 0) {
            all_multiples_of_5 = false;
            break;
        }
    }

    if (all_multiples_of_5) {
        printf("Result: True (All elements are multiples of 5)\n\n");
    } else {
        printf("Result: False (Not all elements are multiples of 5)\n\n");
    }
}

// ----------------------------------------------------------------------------
// 4. Existential Quantifier with Compound Condition: exist x (P(x) AND Q(x))
// ----------------------------------------------------------------------------
void test_existential_compound() {
    printf("--- 4. Existential Quantifier with Compound Predicate ---\n");

    // Example: Check if THERE EXISTS an element > 15 AND odd
    int data[] = {10, 20, 25, 30, 40};
    int size = 5;

    bool found = false;

    for (int x = 0; x < size; x++) {
        // Direct condition with AND logic
        if (data[x] > 15 && data[x] % 2 != 0) {
            found = true;
            break;
        }
    }

    if (found) {
        printf("Result: True (Element found matching both criteria)\n\n");
    } else {
        printf("Result: False (No element matches criteria)\n\n");
    }
}

// ============================================================================
// Main Execution Function
// ============================================================================
int main() {
    printf("====================================================\n");
    printf("   PREDICATES AND QUANTIFIERS DEMONSTRATION (C)     \n");
    printf("====================================================\n\n");

    test_universal_quantifier();
    test_existential_quantifier();
    test_universal_compound();
    test_existential_compound();

    return 0;
}