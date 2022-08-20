#include <stdio.h>
#include <math.h>
#include <assert.h>

//comparison error
const double e = 0.0000000001;
//number of roots return value enum
enum RETVAL{INFINITE_ROOTS, TWO_ROOTS, TWO_SAME_ROOTS, ONE_ROOT, NO_ROOTS};

int solveLinEq(double b, double c, double roots[]);
int solveQuadrEq(double a, double b, double c, double roots[]);
int isDoubleEqual(double a, double b);
int input(double* a, double* b, double* c);
enum RETVAL solve(double a, double b, double c, double roots[]);
int output(double roots[], RETVAL rootsNum);

int main(const int argc, const char* argv[])
{
    RETVAL rootsNum = RETVAL::NO_ROOTS;
    double a = 0.0, b = 0.0, c = 0.0;
    double roots[2] = {};

    input(&a, &b, &c);
    rootsNum = solve(a, b, c, roots);
    output(roots, rootsNum);

    return 0;
}

/**
 * @brief 
 * Scanning for a, b, c coefficients to attribute to ax^2 + bx + c = 0 equation
 * @param a the quadratic coefficient
 * @param b the linear coefficient
 * @param c free term
 * @return int 0 in case of successful operation, -1 otherwise
 */
int input(double* a, double* b, double* c)
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    printf("\nРешение уравнения: \nax^2+bx+c=0 \nВведите коэфиценты a, b и c: \n");
    if (0 == scanf("%lf %lf %lf", a, b, c)){
        printf("\n");
        return 0;
    }

    printf("Ошибка ввода.\n");
    return -1;
}

/**
 * @brief 
 * Solving the ax^2 + bx + c = 0 equation
 * @param a the quadratic coefficient
 * @param b the linear coefficient
 * @param c free term
 * @param roots an array containing the roots of the equation
 * @return enum RETVAL the amount of roots obtained
 */
enum RETVAL solve(double a, double b, double c, double roots[])
{
    //Нулевые коэфиценты.
    if (0 == isDoubleEqual(a, 0)) {
        if (0 == isDoubleEqual(b, 0)){
            if (0 == isDoubleEqual(c, 0)){
                //Корень любой.
                return RETVAL::INFINITE_ROOTS;
            } else {
                //Корней нет.
                return RETVAL::NO_ROOTS;
            }
        } else {
            //Корень 1.
            solveLinEq(b, c, roots);
            return RETVAL::ONE_ROOT;
        }
    }

    //solving the equation
    if (0 == solveQuadrEq(a, b, c, roots)) {
        if (0 == isDoubleEqual(roots[0], roots[1])){
            return RETVAL::TWO_SAME_ROOTS;
        } else {
            return RETVAL::TWO_ROOTS;
        }
    } else {
        //Корни не действительны.
        return RETVAL::NO_ROOTS;
    }

    return RETVAL::NO_ROOTS;
}

/**
 * @brief 
 * Printing the roots we found
 * @param roots an array containing the roots of the equation
 * @param rootsNum the amount of roots obtained
 * @return int 0 in case of successful operation, -1 otherwise
 */
int output(double roots[], RETVAL rootsNum)
{
    switch (rootsNum)
    {
    case RETVAL::INFINITE_ROOTS:
        printf("Корень любой.\n");
        break;
    case RETVAL::TWO_ROOTS:
        printf("Корни: %lf, %lf.\n", roots[0], roots[1]);
        break;
    case RETVAL::TWO_SAME_ROOTS:
        printf("Два сопадающих корня: %lf.\n", roots[0]);
        break;
    case RETVAL::ONE_ROOT:
        printf("Корень: %lf.\n", roots[0]);
        break;
    case RETVAL::NO_ROOTS:
        printf("Нет действительных корней.\n");
        break;
    default: 
        printf("Ошибка в количестве корней.");
        return -1;
    }
    
    return 0;
}

/**
 * @brief 
 * Solving the linear equation bx + c = 0
 * @param b the linear coefficient
 * @param c free term
 * @param roots an array containing the roots of the equation
 * @return int 0 in case of successful operation, -1 otherwise
 */
int solveLinEq(double b, double c, double roots[])
{
    roots[0] = - c / b;
    //Да, она не может вернуть -1, 
    //я не придумала проверку
    return 0;
}

/**
 * @brief 
 * Solving the quadratic equation ax^2 + bx + c = 0
 * @param a the quadratic coefficient
 * @param b the linear coefficient
 * @param c free term
 * @param roots an array containing the roots of the equation
 * @return int 0 in case of successful operation, -1 otherwise
 */
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

/**
 * @brief 
 * Checking if two doubles are equal
 * @param a first double
 * @param b second double
 * @return int 1 in case the numbers are equal, -1 otherwise
 */
int isDoubleEqual(double a, double b)
{
    if (a - b < e) {
        return 0;
    }
    return 1;
}
