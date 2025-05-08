#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void help_menu(char *app);

int is_float(const char *s);

float miles(float distance);
float kilometers(float distance);
float kilograms(float weight);
float pounds(float weight);
float meters(float height);
float feet(float height);
float inches(float units);
float centimeters(float units);
float fahrenheit(float temp);
float celsius(float temp);


//Start of the actual App
const char VERSION[] = "0.2";

int main(int argc, char* argv[]) {
    char pre[64];
    char post[64];
    float units;

    if (argc < 2) {
        printf("Usage: %s <unit> <value>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        help_menu(argv[0]);
        return 0;
    } else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-V") == 0) {
        printf("%s Version %s\n", argv[0], VERSION);
        return 0;
    }


    if (argc >= 3)
        units = atof(argv[2]);

    if (is_float(argv[2])) { // Validate before executing
        if (strcmp(argv[1], "-MtoK") == 0 || strcmp(argv[1], "--kilometers") == 0) {
            miles(units);
        } else if (strcmp(argv[1], "-KtoM") == 0 || strcmp(argv[1], "--miles") == 0) {
            kilometers(units);
        } else if (strcmp(argv[1], "-LtoK") == 0 || strcmp(argv[1], "--kilograms") == 0) {
            kilograms(units);
        } else if (strcmp(argv[1], "-KtoL") == 0 || strcmp(argv[1], "--pounds") == 0) {
            pounds(units);
        } else if (strcmp(argv[1], "-MtoF") == 0 || strcmp(argv[1], "--feet") == 0) {
            feet(units);
        } else if (strcmp(argv[1], "-FtoM") == 0 || strcmp(argv[1], "--meters") == 0) {
            meters(units);
        } else if (strcmp(argv[1], "-CtoI") == 0 || strcmp(argv[1], "--inches") == 0) {
            inches(units);
        } else if (strcmp(argv[1], "-ItoC") == 0 || strcmp(argv[1], "--centimeters") == 0) {
            centimeters(units);
        } else if (strcmp(argv[1], "-FtoC") == 0 || strcmp(argv[1], "--celsius") == 0) {
            celsius(units);
        } else if (strcmp(argv[1], "-CtoF") == 0 || strcmp(argv[1], "--fahrenheit") == 0) {
            fahrenheit(units);
        } else {
            printf("Unknown Input: %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("Error: %s is not a number\n", argv[2]);
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
    printf("  -CtoI --inches\tCentimeters to Inches\n");
    printf("  -ItoC --centimeters\tInches to Centimeters\n");
    printf("  -FtoC --celsius\tFahrenheit to Celsius\n");
    printf("  -CtoF --fahrenheit\tCelsius to Fahrenheit\n");
    printf("\nFor bug reporting instructions, please see:\n");
    printf("<https://github.com/RileyMeta/rconvert/issues>\n");
}

int is_float(const char *s) {
    if (s == NULL || *s == '\0') return 0;

    char *end;
    errno = 0;
    strtod(s, &end);
    return errno == 0 && *end == '\0';
}

float miles(float distance) {
    float result = distance / 1.60934;
    printf("%.2f km is %.2f miles\n", distance, result);
    return result;
}

float kilometers(float distance) {
    float result = distance * 1.60934;
    printf("%.2f miles is %.2f km\n", distance, result);
    return result;
}

float kilograms(float weight) {
    float result = weight * 0.453592;
    printf("%.2f lbs is %.2f kg\n", weight, result);
    return result;
}

float pounds(float weight) {
    float result = weight / 2.205;
    printf("%.2f kg is %.2f lbs\n", weight, result);
    return result;
}

float meters(float height) {
    float result = height / 3.281;
    printf("%.2f feet is %.2f meters\n", height, result);
    return result;
}

float feet(float height) {
    float result = height * 3.281;
    printf("%.2f meters is %.2f feet\n", height, result);
    return result;
}

float fahrenheit(float temp) {
    float result = (temp * 9.0 / 5.0) + 32;
    printf("%.2f°C is %.2f°F\n", temp, result);
    return result;
}

float celsius(float temp) {
    float result = (temp - 32.0) * 5.0 / 9.0;
    printf("%.2f°F is %.2f°C\n", temp, result);
    return result;
}

float inches(float units) {
    float result = units / 2.54;
    printf("%.2f cm. is %.2f in.\n", units, result);
    return result;
}

float centimeters(float units) {
    float result = units * 2.54;
    printf("%.2f in. is %.2f cm.\n", units, result);
    return result;
}
