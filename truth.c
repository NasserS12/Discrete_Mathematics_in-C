#include <stdio.h>


void basic_truth_table() {
    printf("\t=== Basic Logical Operators Truth Table ===\n\n");
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            for (int r = 1; r >= 0; r--) {
                
                int p_implies_q = (!p || q);
                int p_implies_r = (!q || r);
                int and_result = (!p || q) && (!q || r);
                
                printf("p = %d, q = %d, r = %d | p --> q = %d | q --> r = %d | (p -> q) && (q -> r) = %d\n\n", 
                        p, q, r,p_implies_q,p_implies_r,and_result);
            }
        }
    }
}

void tautology() {
    printf("\t== Tautology Truth Table ==\n\n");

    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {
            int p_and_q = p && q;
            int implies_p = !(p && q) || p;
            printf("p = %d, q = %d | p && q = %d | (p && q) > p = %d\n\n",p,q,p_and_q,implies_p);

        }    
    }        
} 

void contradiction(){
    printf("\t== Contradiction Truth Table == \n\n");
    for(int p = 1; p >= 0; p--){
        for(int q = 1; q >= 0; q--){
            int p_and_q = p && q;
            int not_p = !p;
            int result = not_p && p_and_q;
            printf("p = %d, q = %d | (p && q) = %d | ~p = %d | (p && q) && ~p = %d\n\n",
            p,q,p_and_q,not_p,result);

        }
    }
}

void contingency(){
    for(int p = 1; p >= 0; p--){
        for(int q = 1; q >= 0; q--){
            int p_implies_q = !p || q;
            printf("p = %d, q = %d | p -> q = %d\n",p,q,p_implies_q);
        }
    }

}

void classify_statement() {
    int true_count = 0;
    for (int p = 1; p >= 0; p--) {
        for (int q = 1; q >= 0; q--) {

           int result = !(p && q) || p;
           if(result == 1){
            true_count ++;
           }
        }
    }
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