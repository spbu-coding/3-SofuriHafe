#include <stdio.h>
#include <math.h>

#define MAX_DEVIATION 0.000001

struct float_points
{
    float x1;
    float x2;
};

struct double_point
{
    double x1;
    double x2;
};

struct float_points solve_equation_float(float delta)
{
    struct float_points solution;

    solution.x2 = (2.0001f - 2.0f + delta) * 10000.0f;
    solution.x1 = 2.0f - solution.x2;

    return solution;
}

struct double_point solve_equation_double(double delta)
{
    struct double_point solution;

    solution.x2 = (2.0001 - 2.0 + delta) * 10000.0;
    solution.x1 = 2.0 - solution.x2;

    return solution;
}

float calculate_distance_float(struct float_points point1, struct float_points point2)
{
    return sqrtf((point1.x1 - point2.x1) * (point1.x1 - point2.x1) + (point1.x2 - point2.x2) * (point1.x2 - point2.x2));
}

double calculate_distance_double(struct double_point point1, struct double_point point2)
{
    return sqrtf((point1.x1 - point2.x1) * (point1.x1 - point2.x1) + (point1.x2 - point2.x2) * (point1.x2 - point2.x2));
}

int main()
{
    struct float_points f_solution = solve_equation_float(0.0f);
    struct double_point d_solution = solve_equation_double(0.0);

    float f_delta = 0.0001f;
    double d_delta = 0.0001;

    float f_distance;
    double d_distance;

    int count = 1;
    do
    {
        printf("Experiment #%d\n", count);
        printf("--------------------------------------------------\n");

        struct float_points f_delta_solution = solve_equation_float(f_delta);
        f_distance = calculate_distance_float(f_solution, f_delta_solution);

        printf("Floats:\n");
        printf("x1: %.18f x2: %.18f \n", f_solution.x1,  f_solution.x2);
        printf("Delta solutions x1: %.18f Delta x2: %.18f \n", f_delta_solution.x1,  f_delta_solution.x2);
        printf("Delta: %.18f Distance: %.16f \n", f_delta, f_distance);
        printf("\n");
        f_delta /= 2.0f;

        struct double_point d_delta_solution = solve_equation_double(d_delta);
        d_distance = calculate_distance_double(d_solution, d_delta_solution);

        printf("Doubles:\n");
        printf("x1: %.18lf x2: %.18lf \n", d_solution.x1,  d_solution.x2);
        printf("Delta solutions x1: %.18lf Delta x2: %.18lf \n", d_delta_solution.x1,  d_delta_solution.x2);
        printf("Delta: %.18lf Distance: %.16lf \n", d_delta, d_distance);
        printf("--------------------------------------------------\n\n");
        d_delta /= 2.0;

        count++;
    } while (f_distance > MAX_DEVIATION || d_distance > MAX_DEVIATION);

    return 0;
}