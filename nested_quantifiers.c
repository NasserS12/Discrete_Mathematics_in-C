
#include <stdio.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------
// 1. Universal - Existential: forall x in X, exist y in Y (P(x, y))
//    Condition: For every x, there must exist at least one y that satisfies P(x,y).
// ----------------------------------------------------------------------------
void test_forall_exists() {
    printf("--- 1. Universal-Existential (forall x, exist y) ---\n");
    printf("Statement: forall x in X, exist y in Y (x + y == 5)\n");

    int X[] = {1, 2, 3};
    int Y[] = {3, 4, 5};
    int sizeX = 3, sizeY = 3;

    bool all_x_valid = true; // Outer forall: assumes success for all x

    for (int x = 0; x < sizeX; x++) {
        bool found_y = false; // Inner exist: seeks first matching y

        for (int y = 0; y < sizeY; y++) {
            if (X[x] + Y[y] == 5) {
                found_y = true;
                break; // Found success for current x, stop inner search
            }
        }

        // Failure-seeking for outer forall: if any x fails to find a y, the whole statement fails
        if (!found_y) {
            all_x_valid = false;
            break;
        }
    }

    if (all_x_valid) {
        printf("Result: True\n\n");
    } else {
        printf("Result: False\n\n");
    }
}

// ----------------------------------------------------------------------------
// 2. Existential - Universal: exist x in X, forall y in Y (P(x, y))
//    Condition: There exists at least one x that satisfies P(x,y) for all y.
// ----------------------------------------------------------------------------
void test_exists_forall() {
    printf("--- 2. Existential-Universal (exist x, forall y) ---\n");
    printf("Statement: exist x in X, forall y in Y (x * y > 10)\n");

    int X[] = {1, 2, 3};
    int Y[] = {4, 5, 6};
    int sizeX = 3, sizeY = 3;

    bool exist_x = false; // Outer exist: seeks first valid x

    for (int x = 0; x < sizeX; x++) {
        bool valid_for_all_y = true; // Inner forall: assumes success for all y

        for (int y = 0; y < sizeY; y++) {
            // Inverted condition: seeking a counterexample where x * y <= 10
            if (X[x] * Y[y] <= 10) {
                valid_for_all_y = false;
                break; // Current x failed for at least one y
            }
        }

        // Success-seeking for outer exist: if an x satisfies all y, overall statement is true
        if (valid_for_all_y) {
            exist_x = true;
            break;
        }
    }

    if (exist_x) {
        printf("Result: True\n\n");
    } else {
        printf("Result: False\n\n");
    }
}

// ----------------------------------------------------------------------------
// 3. Universal - Universal: forall x in X, forall y in Y (P(x, y))
//    Condition: Every combination of x and y must satisfy P(x,y).
// ----------------------------------------------------------------------------
void test_forall_forall() {
    printf("--- 3. Universal-Universal (forall x, forall y) ---\n");
    printf("Statement: forall x in X, forall y in Y (x * y >= 10)\n");

    int X[] = {3, 4, 6};
    int Y[] = {2, 5, 8};
    int sizeX = 3, sizeY = 3;

    bool all_valid = true; // Outer forall: assumes success overall

    for (int x = 0; x < sizeX; x++) {
        bool valid_y = true; // Inner forall: assumes success for current x

        for (int y = 0; y < sizeY; y++) {
            // Inverted condition: seeking any pair that fails (x * y < 10)
            if (X[x] * Y[y] < 10) {
                valid_y = false;
                break;
            }
        }

        if (!valid_y) {
            all_valid = false;
            break; // Counterexample found, overall statement fails
        }
    }

    if (all_valid) {
        printf("Result: True\n\n");
    } else {
        printf("Result: False\n\n");
    }
}

// ----------------------------------------------------------------------------
// 4. Existential - Existential: exist x in X, exist y in Y (P(x, y))
//    Condition: There exists at least one pair (x, y) that satisfies P(x,y).
// ----------------------------------------------------------------------------
void test_exists_exists() {
    printf("--- 4. Existential-Existential (exist x, exist y) ---\n");
    printf("Statement: exist x in X, exist y in Y (x + y == 15)\n");

    int X[] = {2, 7, 11};
    int Y[] = {3, 8, 12};
    int sizeX = 3, sizeY = 3;

    bool exist_all = false; // Outer exist: seeks first matching pair

    for (int x = 0; x < sizeX; x++) {
        bool found_y = false; // Inner exist: seeks matching y

        for (int y = 0; y < sizeY; y++) {
            if (X[x] + Y[y] == 15) {
                found_y = true;
                break;
            }
        }

        if (found_y) {
            exist_all = true;
            break; // Single success is enough for the entire statement
        }
    }

    if (exist_all) {
        printf("Result: True\n\n");
    } else {
        printf("Result: False\n\n");
    }
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    printf("====================================================\n");
    printf("     NESTED QUANTIFIERS DEMONSTRATION (C)          \n");
    printf("====================================================\n\n");

    test_forall_exists();
    test_exists_forall();
    test_forall_forall();
    test_exists_exists();

    return 0;
}