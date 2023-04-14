#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to store weather data for a city
typedef struct { 
    char name[50];
    float temperature;
    float wind_speed;
    float humidity;
} City;

// function to get weather data from the user for each city
void get_weather_data(City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("\nEnter weather data for city %d:\n", i + 1);
        printf("City name: ");
        scanf("%s", cities[i].name);
        printf("Temperature: ");
        scanf("%f", &cities[i].temperature);
        printf("Wind speed: ");
        scanf("%f", &cities[i].wind_speed);
        printf("Humidity: ");
        scanf("%f", &cities[i].humidity);
    }
}

// function to print weather data for all cities
void print_weather_data(City *cities, int num_cities) {
    printf("\nWeather data for all cities:\n\n");
    printf("%-20s %-20s %-20s %-20s\n", "City Name", "Temperature (deg C)", "Wind Speed(km/h)", "Humidity(%)");
    for (int i = 0; i < num_cities; i++) {
        printf("%-20s %-20.2f %-20.2f %-20.2f\n", cities[i].name, cities[i].temperature,
               cities[i].wind_speed, cities[i].humidity);
    }
}

// function to find the minimum and maximum values for a given weather field
void find_min_max_field(City *cities, int num_cities, char *field, float *min_val, float *max_val,
                        char *min_city_name, char *max_city_name) {
    float min = cities[0].temperature;
    float max = cities[0].temperature;
    int field_index;
    // determine the index of the field to search for
    if (strcmp(field, "temperature") == 0) {
        field_index = 0;
    } else if (strcmp(field, "wind speed") == 0) {
        field_index = 1;
        min = cities[0].wind_speed;
        max = cities[0].wind_speed;
    } else if (strcmp(field, "humidity") == 0){
        field_index = 2;
        min = cities[0].humidity;
        max = cities[0].humidity;
    }
    // loop through all cities to find the minimum and maximum values for the given field
    for (int i = 0; i < num_cities; i++) {
        if (field_index == 0) {
            if (cities[i].temperature < min) {
                min = cities[i].temperature;
                strcpy(min_city_name, cities[i].name);
            }
            if (cities[i].temperature > max) {
                max = cities[i].temperature;
                strcpy(max_city_name, cities[i].name);
            }
        } else if (field_index == 1) {
            if (cities[i].wind_speed < min) {
                min = cities[i].wind_speed;
                strcpy(min_city_name, cities[i].name);
            }
            if (cities[i].wind_speed > max) {
                max = cities[i].wind_speed;
                strcpy(max_city_name, cities[i].name);
            }
        } else {
            if (cities[i].humidity < min) {
                min = cities[i].humidity;
                strcpy(min_city_name, cities[i].name);
            }
            if (cities[i].humidity > max) {
                max = cities[i].humidity;
                strcpy(max_city_name, cities[i].name);
            }
        }
    }
    *min_val = min;
    *max_val = max;
}

int main() {
    int num_cities;
    printf("Enter the number of cities for which you would like to enter weather data: ");
    scanf("%d", &num_cities);
    City *cities = (City *) malloc(num_cities * sizeof(City));
	get_weather_data(cities, num_cities);
	print_weather_data(cities, num_cities);

	char field[50];
	float min_val, max_val;
	char min_city_name[50], max_city_name[50];


	printf("\nEnter the weather field (temperature, wind_speed or humidity) for which you would like to find the minimum and maximum values: ");
	scanf("%s", field);

	find_min_max_field(cities, num_cities, field, &min_val, &max_val, min_city_name, max_city_name);
	printf("Maximum %s: %.2f, found in %s\n", field, max_val, max_city_name); //find the max chosen field.

	free(cities); //release the memory.
	return 0;
}
