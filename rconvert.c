#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help_menu(char *app);

float miles(float distance);
float kilometers(float distance);
float kilograms(float weight);
float pounds(float weight);
float meters(float height);
float feet(float height);


// Start of the actual App
const char VERSION[] = "0.1";

int main(int argc, char* argv[]) {
    char pre[64];
    char post[64];
    float units;

    if (argc < 2) {
        printf("Usage: %s <unit> <value>\n", argv[0]);
        return 1;
    }

    if (argc >= 3) {
        units = atof(argv[2]);
    }

    if (strcmp(argv[1], "--help") == 0) {
        help_menu(argv[0]);
    } else if (strcmp(argv[1], "-V") == 0 || (strcmp(argv[1], "--version") == 0)) {
        printf("%s Version %s\n", argv[0], VERSION);
    } else if (strcmp(argv[1], "-MtoK") == 0 || strcmp(argv[1], "--kilometers") == 0) {
        float result = miles(units);
    } else if (strcmp(argv[1], "-KtoM") == 0 || strcmp(argv[1], "--miles") == 0) {
        float result = kilometers(units);
    } else if (strcmp(argv[1], "-LtoK") == 0 || strcmp(argv[1], "--kilograms") == 0) {
        float result = kilograms(units);
    } else if (strcmp(argv[1], "-KtoL") == 0 || strcmp(argv[1], "--pounds") == 0) {
        float result = pounds(units);
    } else if (strcmp(argv[1], "-MtoF") == 0 || strcmp(argv[1], "--feet") == 0) {
        float result = feet(units);
    } else if (strcmp(argv[1], "-FtoM") == 0 || strcmp(argv[1], "--meters") == 0) {
        float result = meters(units);
    } else {
        printf("Unknown Input: %s", argv[1]);
        return 1;
    }

    return 0;
}

void help_menu(char *app) {
    printf("Usage: %s <conversion> <units>\n", app);
    printf("Options:\n");
    printf("        --help\t\tShows this menu\n");
    printf("  -V    --version\tShow version info\n");
    printf("\nAvailable Conversion Units:\n");
    printf("  -MtoK --kilometers\tMiles to Kilometers\n");
    printf("  -KtoM --miles\t\tKilometers to Miles\n");
    printf("  -LtoK --kilograms\tPounds (LBS) to Kilograms\n");
    printf("  -KtoL --pounds\tKilograms to Pounds (LBS)\n");
    printf("  -MtoF --feet\t\tMeters to Feet\n");
    printf("  -FtoM --meters\tFeet to Meters\n");
    printf("\nFor but reporting instructions, please see:\n");
    printf("<https://github.com/RileyMeta/rconvert/issues>\n");
}

float miles(float distance) {
    float result = distance / 1.60934;
    printf("%.2f km is %.2f miles", distance, result);
    return result;
}

float kilometers(float distance) {
    float result = distance * 1.60934;
    printf("%.2f miles is %.2f km", distance, result);
    return result;
}

float kilograms(float weight) {
    float result = weight * 0.453592;
    printf("%.2f lbs is %.2f kg", weight, result);
    return result;
}

float pounds(float weight) {
    float result = weight / 2.205;
    printf("%.2f kg is %.2f lbs", weight, result);
    return result;
}

float meters(float height) {
    float result = height * 3.281;
    printf("%.2f feet is %.2f meters", height, result);
    return result;
}

float feet(float height) {
    float result = height / 3.281;
    printf("%.2f meters is %.2f feet", height, result);
    return result;
}
