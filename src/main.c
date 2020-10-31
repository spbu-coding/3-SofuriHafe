#include <stdio.h>
#include <math.h>

#define f_MAX_DEVIATION 0.000001f
#define d_MAX_DEVIATION 0.000001

void solve_as_float_and_double()
{
    //Float field
    float f_deviation = 0.0001f;
    float f_distance;

    float f_start_x = 1.0f, f_start_y = 1.0f;
    float f_delta_x, f_delta_y;
    float f_solution;
    //

    //Double field
    double d_deviation = 0.0001;
    double d_distance;

    double d_start_x = 1.0, d_start_y = 1.0;
    double d_delta_x, d_delta_y;
    double d_solution;
    //

    int count = 1;
    do
    {
        //Floats
        f_delta_y = ((2.0001f + f_deviation) - 2.0f) / 0.0001f;
        f_delta_x = 2.0f - f_delta_y;
        f_solution = 1.0001f * f_delta_y + f_delta_x;

        f_distance = sqrtf((f_start_x - f_delta_x) * (f_start_x - f_delta_x) + 
            (f_start_y - f_delta_y) * (f_start_y - f_delta_y));

        printf("Experiment #%i\n", count);
        printf("--------------------------------------------------\n");
        printf("<Floats>\n");
        printf("Delta X: %.30f, Delta Y: %.30f\n", f_delta_x, f_delta_y);
        printf("Solution: %.30f\n", f_solution);
        printf("Deviation: %.30f\n", f_deviation);
        printf("Distance: %.30f\n", f_distance);
        //

        //Doubles
        d_delta_y = ((2.0001 + d_deviation) - 2.0) / 0.0001;
        d_delta_x = 2.0 - d_delta_y;
        d_solution = 1.0001 * d_delta_y + d_delta_x;

        d_distance = sqrt((d_start_x - d_delta_x) * (d_start_x - d_delta_x) + 
            (d_start_y - d_delta_y) * (d_start_y - d_delta_y));

        printf("\n<Doubles>\n");
        printf("Delta X: %.30lf, Delta Y: %.30lf\n", d_delta_x, d_delta_y);
        printf("Solution: %.30lf\n", d_solution);
        printf("Deviation: %.30lf\n", d_deviation);
        printf("Distance: %.30lf\n", d_distance);
        printf("--------------------------------------------------\n\n");
        //

        f_deviation /= 2.0f;
        d_deviation /= 2.0;

        count++;
    }while(f_distance > f_MAX_DEVIATION && d_distance > d_MAX_DEVIATION);
}

int main()
{
    solve_as_float_and_double();

    return 0;
}