#include <stdio.h>
#include <math.h>
#include <assert.h>

int solveLinEq(double b, double c, double roots[]);
int solveQuadrEq(double a, double b, double c, double roots[]);
int isDoubleEqual(double a, double b);
int input(double* a, double* b, double* c);
int solve(double a, double b, double c, double roots[]);
int output(double roots[], int rootsNum);

//comparison error
const double e = 0.0000000001;

int main(const int argc, const char* argv[])
{
    int rootsNum = 0;
    double a = 0.0, b = 0.0, c = 0.0;
    double roots[2] = {};

    input(&a, &b, &c);
    rootsNum = solve(a, b, c, roots);
    output(roots, rootsNum);

    return 0;
}

//numbers input
int input(double* a, double* b, double* c)
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    printf("\nРешение уравнения: \nax^2+bx+c=0 \nВведите коэфиценты a, b и c: \n");
    scanf("%lf %lf %lf", a, b, c);
    printf("\n");

    return 0;
}

//equation functions calls
int solve(double a, double b, double c, double roots[])
{
    //Нулевые коэфиценты.
    if (0 == isDoubleEqual(a, 0)) {
        if (0 == isDoubleEqual(b, 0)){
            if (0 == isDoubleEqual(c, 0)){
                //Корень любой.
                return -1;
            } else {
                //Корней нет.
                return 0;
            }
        } else {
            //Корень 1.
            solveLinEq(b, c, roots);
            return 1;
        }
    }

    //solving the equation
    if (0 == solveQuadrEq(a, b, c, roots)) {
        return 2;
    } else {
        //Корни не действительны.
        return -1;
    }

    return 0;
}

//print answer
int output(double roots[], int rootsNum)
{
    if (-1 == rootsNum){
        printf("Нет действительных корней.\n");
    } else if (0 == rootsNum){
        printf("Корней нет.\n");
    } else if (1 == rootsNum){
        printf("Корень: %lf.\n", roots[0]);
    } else {
        if (0 == isDoubleEqual(roots[0], roots[1])){
            printf("Два сопадающих корня: %lf.\n", roots[0]);
        } else {
            printf("Корни: %lf, %lf.\n", roots[0], roots[1]);
        }
    }
    
    return 0;
}

//linear equation function
int solveLinEq(double b, double c, double roots[])
{
    roots[0] = - c / b;

    return 0;
}

//quadratic equation function
int solveQuadrEq(double a, double b, double c, double roots[])
{
    double diskr = 0, r = 0, x1 = 0, x2 = 0;
    diskr = (b * b) - (4 * a * c);
    r = - b / (2 * a);
    if (0 < diskr) {
        roots[0] = r + (sqrt(diskr) / (2 * a));
        roots[1] = r - (sqrt(diskr) / (2 * a));
        return 0;
    } else if (0 == diskr)
    {
        roots[0] = r; 
        roots[1] = r;;
        return 0;
    }
    return -1;
}

//equal double numbers fnction
int isDoubleEqual(double a, double b)
{
    if (a - b < e) {
        return 0;
    }
    return 1;
}
