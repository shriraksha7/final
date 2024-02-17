#include <stdio.h>
#include "patient.h"
#include<string.h>
#include <stdlib.h>
void savePatientData(struct Patient (*patients)[3], int n) {
    FILE *patientFile = fopen("patient_data.txt", "w");
    if (patientFile == NULL) {
        printf("Error opening file for writing patient data!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(patientFile, "%s,%d,%s,%s,%c,%s\n",
                    (*(patients + i) + j)->name, (*(patients + i) + j)->age,
                    (*(patients + i) + j)->address, (*(patients + i) + j)->disease,
                    (*(patients + i) + j)->sex, (*(patients + i) + j)->contact);
        }
    }

    fclose(patientFile);
}


void readPatientData(struct Patient (*patients)[3], int n) {
    FILE *patientFile = fopen("patient_data.txt", "r");
    if (patientFile == NULL) {
        printf("Error opening file for reading patient data!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            fscanf(patientFile, "%[^,],%d,%[^,],%[^,],%c,%s\n",
                   (*(patients + i) + j)->name, &(*(patients + i) + j)->age,
                   (*(patients + i) + j)->address, (*(patients + i) + j)->disease,
                   &(*(patients + i) + j)->sex, (*(patients + i) + j)->contact);
        }
    }

    fclose(patientFile);
}


void printPatient(struct Patient *patient) {
    printf("Patient Name: %s\n", patient->name);
    printf("Age: %d\n", patient->age);
    printf("Address: %s\n", patient->address);
    printf("Disease: %s\n", patient->disease);
    printf("Sex: %c\n", patient->sex);
    printf("Contact: %s\n", patient->contact);
    printf("\n");
}
void addNewPatient(struct Patient **patients, int index, struct Patient newPatient) {
    FILE *patientFile = fopen("patient_data.txt", "a");
    if (patientFile == NULL) {
        printf("Error opening file for adding new patient!\n");
        return;
    }

    // Assuming you keep track of the number of patients in each hospital
    int numPatients = 3; // Replace this with the actual number of patients

    // Dynamic memory allocation to expand patient data
    patients[index] = realloc(patients[index], (numPatients + 1) * sizeof(struct Patient));
    if (patients[index] == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    patients[index][numPatients] = newPatient;

    fprintf(patientFile, "%s,%d,%s,%s,%c,%s\n",  // '1' indicating active record
            newPatient.name, newPatient.age, newPatient.address,
            newPatient.disease, newPatient.sex, newPatient.contact);

    fclose(patientFile);
}