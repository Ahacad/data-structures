void tower(int n, int A, int B, int C) {
    stack s;
    int done = false;
    while (!done) {
        while (n > 1) {
            s_tack(n, A, B, C, &s);
            setvar1(&n, &A, &B, &C);
        }
        printf("\n %d -> %d \n", A, C);
        if (!empty(&s)) {
            restore(&n, &A, &B, &C);
            printf("\n %d -> %d \n", A, C);
            setvar2(&n, &A, &B, &C);
        } else { 
            done = true;
        }
    }
}
