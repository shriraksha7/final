#include <stdio.h>
#include <string.h>
#include "hospital.h"

void saveHospitalData(struct Hospital *hospitals, int n) {
    FILE *hospitalFile = fopen("hospital_data.txt", "w");
    if (hospitalFile == NULL) {
        printf("Error opening file for writing hospital data!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(hospitalFile, "%s,%s,%d,%.2f,%.1f,%d\n",
                (hospitals + i)->name, (hospitals + i)->city,
                (hospitals + i)->beds, (hospitals + i)->price,
                (hospitals + i)->rating, (hospitals + i)->reviews);
    }

    fclose(hospitalFile);
}


void readHospitalData(struct Hospital *hospitals, int n) {
    FILE *hospitalFile = fopen("hospital_data.txt", "r");
    if (hospitalFile == NULL) {
        printf("Error opening file for reading hospital data!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(hospitalFile, "%[^,],%[^,],%d,%f,%f,%d\n",
               (hospitals + i)->name, (hospitals + i)->city,
               &(hospitals + i)->beds, &(hospitals + i)->price,
               &(hospitals + i)->rating, &(hospitals + i)->reviews);
    }

    fclose(hospitalFile);
}


void printHospital(struct Hospital *hosp) {
    printf("Hospital Name: %s\n", hosp->name);
    printf("City: %s\n", hosp->city);
    printf("Total Beds: %d\n", hosp->beds);
    printf("Price per Bed: $%.2f\n", hosp->price);
    printf("Rating: %.1f\n", hosp->rating);
    printf("Reviews: %d\n", hosp->reviews);
    printf("\n");
}


void sortByPrice(struct Hospital *hospitals, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((hospitals + j)->price > (hospitals + j + 1)->price) {
                struct Hospital temp = *(hospitals + j);
                *(hospitals + j) = *(hospitals + j + 1);
                *(hospitals + j + 1) = temp;
            }
        }
    }
}

void sortByAvailableBeds(struct Hospital *hospitals, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((hospitals + j)->beds < (hospitals + j + 1)->beds) {
                struct Hospital temp = *(hospitals + j);
                *(hospitals + j) = *(hospitals + j + 1);
                *(hospitals + j + 1) = temp;
            }
        }
    }
}

void sortByName(struct Hospital *hospitals, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp((hospitals + j)->name, (hospitals + j + 1)->name) > 0) {
                struct Hospital temp = *(hospitals + j);
                *(hospitals + j) = *(hospitals + j + 1);
                *(hospitals + j + 1) = temp;
            }
        }
    }
}

void sortByRating(struct Hospital *hospitals, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float ratingWeight1 = (hospitals + j)->rating * (hospitals + j)->reviews;
            float ratingWeight2 = (hospitals + j + 1)->rating * (hospitals + j + 1)->reviews;

            if (ratingWeight1 < ratingWeight2) {
                struct Hospital temp = *(hospitals + j);
                *(hospitals + j) = *(hospitals + j + 1);
                *(hospitals + j + 1) = temp;
            }
        }
    }
}

void printHospitalsInCity(struct Hospital *hospitals, int n) {
    char city[50];
    int hospitalsFound = 0;

    printf("Enter city name: ");
    scanf("%s", city);

    printf("Hospitals in %s:\n", city);

    for (int i = 0; i < n; i++) {
        if (strcmp((hospitals + i)->city, city) == 0) {
            printf("%s\n", (hospitals + i)->name);
            hospitalsFound++;
        }
    }

    if (hospitalsFound == 0) {
        printf("No hospitals found in %s\n", city);
    }
}
void updateHospitalData(struct Hospital *hospital, int index) {
    FILE *hospitalFile = fopen("hospital_data.txt", "r+");
    if (hospitalFile == NULL) {
        printf("Error opening file for updating hospital data!\n");
        return;
    }

   // fseek(hospitalFile, index * sizeof(struct Hospital), SEEK_SET);
  fseek(hospitalFile,0, SEEK_END);
    fprintf(hospitalFile, "%s,%s,%d,%.2f,%.1f,%d\n",
            hospital->name, hospital->city, hospital->beds,
            hospital->price, hospital->rating, hospital->reviews);

    fclose(hospitalFile);
}