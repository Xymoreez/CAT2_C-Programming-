#include <stdio.h>

int main() {
    float hours_worked, hourly_wage, gross_pay, taxes, net_pay;

    // user input
    printf("Enter hours worked: ");
    scanf("%f", &hours_worked);

    printf("Enter hourly wage: ");
    scanf("%f", &hourly_wage);

    // Calculate gross pay with overtime
    if (hours_worked > 40) {
        float overtime_hours = hours_worked - 40;
        gross_pay = (40 * hourly_wage) + (overtime_hours * hourly_wage * 1.5);
    } else {
        gross_pay = hours_worked * hourly_wage;
    }

    // Calculate taxes
    if (gross_pay > 600) {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    } else {
        taxes = gross_pay * 0.15;
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Print the results
    printf("\nGross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0;
}
