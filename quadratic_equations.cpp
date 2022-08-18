#include <stdio.h>
#include <math.h>

int solveEq(int a, int b, int c, double roots[]);

int main(const int argc, const char* argv[])
{
    int a, b, c;
    double roots[2];

    printf("\nРешение уравнения: \nax^2+bx+c=0 \nВведите коэфиценты a, b и c: \n");
    scanf("%i %i %i", &a, &b, &c);
    printf("\n");

    //solving the equation
    if (0 == solveEq(a, b, c, roots)) {
        if (roots[0] == roots[1]){
            printf("Корень: %f\n", roots[0]);
        } else {
            printf("Корни: %f %f\n", roots[0], roots[1]);
        }
    } else {
        printf("Корни не действительны.\n");
    }

    return 0;
}

//quadratic equation function
int solveEq(int a, int b, int c, double roots[])
{
    double diskr, r, x1, x2;
    diskr = (b * b) - (4 * a * c);
    r = - b / 2 * a;
    if (0 < diskr) {
        roots[0] = r + (sqrt(diskr) / 2 * a);
        roots[1] = r - (sqrt(diskr) / 2 * a);
        return 0;
    } else if (0 == diskr)
    {
        roots[0] = r; 
        roots[1] = r;;
        return 0;
    }
    return -1;
}
