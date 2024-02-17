#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"
#include "patient.h"

int main() {
    struct Hospital hospitals[5] = {
        { "Manipal Hospital", "Bangalore", 100, 250.0, 4.5, 110 },
        { "Apollo Hospital", "Bangalore", 150, 200.0, 4.2, 90 },
        { "Raj Clinic", "Bhatkal", 200, 180.0, 4.0, 70 },
        { "Amita Hospital", "Bhatkal", 80, 300.0, 4.8, 130 },
        { "Empire Dental Hospital", "Ballari", 120, 220.0, 4.6, 120 }
    };
    struct Patient patients[5][3] = {
        { 
            { "Shriraksha Moger", 22, "Heble Bhatkal", "Cold", 'F', "123-456-7890" },
            { "Kevin", 22, "456 Avenue Town Bhatkal", "Fever", 'M', "987-654-3210" },
            { "Dayana V", 25, "789 Road Village Bhatkal", "Allergy", 'F', "111-222-3333" } 
        },
        { 
            { "Rakshith Anand", 22, "321 Lane Suburb", "Infection", 'M', "444-555-6666" },
            { "Vandana", 22, "654 Boulevard Bangalore", "Headache", 'F', "777-888-9999" },
            { "Nikhil G", 23, "987 Drive Bangalore", "Migraine", 'M', "123-987-6543" } 
        },
        { 
            { "Zafar", 50, "456 Avenue Ballari", "Diabetes", 'M', "444-333-2222" },
            { "Rahul", 30, "123 Street Ballari", "Asthma", 'M', "999-888-7777" },
            { "Priya", 40, "789 Road Ballari", "Hypertension", 'F', "111-333-5555" } 
        },
        { 
            { "Amir", 22, "456 Avenue Bhatkal", "Flu", 'M', "888-777-6666" },
            { "Asif", 38, "321 Lane Ballari", "Migraine", 'M', "222-333-4444" },
            { "Prince", 60, "987 Drive Ballari", "Arthritis", 'M', "555-666-7777" } 
        },
        { 
            { "Aditya", 28, "654 Boulevard Bangalore", "Stomachache", 'M', "666-777-8888" },
            { "Aman", 48, "123 Street Bangalore", "Backache", 'M', "444-555-6666" },
            { "Sahil", 33, "789 Road Bangalore", "Insomnia", 'M', "777-888-9999" } 
        }
    };
   

    int n = 5; // Number of hospitals

    struct Hospital *hospitalsPtr = hospitals;
    struct Patient (*patientsPtr)[3] = patients;

    saveHospitalData(hospitalsPtr, n);
    savePatientData(patientsPtr, n);

    int choice;

    do {
        printf("\n\n\n*********** Hospital Management System Menu: ************\n\n");
        printf("1. Printing Hospital Data\n");
        printf("2. Printing Patients Data\n");
        printf("3. Sorting Hospitals by Beds Price (Ascending)\n");
        printf("4. Sorting Hospitals by Available Beds (Descending)\n");
        printf("5. Sorting Hospitals by Name (Ascending)\n");
        printf("6. Sorting Hospitals by Rating and Reviews (Descending)\n");
        printf("7. Print Hospitals in a Specific City\n");
        printf("8. Update Hospital Data\n");
        printf("9. Add New Patients\n");
        printf("10. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPrinting Hospital Data:\n\n");
                readHospitalData(hospitals, n);
                for (int i = 0; i < n; i++) {
                    printHospital(&hospitals[i]);
                }
                break;
            case 2:
                printf("Printing Patients Data:\n\n");
                readPatientData(patients, n);
                for (int i = 0; i < n; i++) {
                    printf("Hospital: %s\n", hospitals[i].name);
                    for (int j = 0; j < 4; j++) {
                        printPatient(&patients[i][j]);
                    }
                }
                break;
            case 3:
                printf("Sorting Hospitals by Beds Price (Ascending):\n");
                readHospitalData(hospitals, n);
                sortByPrice(hospitals, n);
                for (int i = 0; i < n; i++) {
                    printHospital(&hospitals[i]);
                }
                break;
            case 4:
                printf("Sorting Hospitals by Available Beds (Descending):\n");
                readHospitalData(hospitals, n);
                sortByAvailableBeds(hospitals, n);
                for (int i = 0; i < n; i++) {
                    printHospital(&hospitals[i]);
                }
                break;
            case 5:
                printf("Sorting Hospitals by Name (Ascending):\n");
                readHospitalData(hospitals, n);
                sortByName(hospitals, n);
                for (int i = 0; i < n; i++) {
                    printHospital(&hospitals[i]);
                }
                break;
            case 6:
                printf("Sorting Hospitals by Rating and Reviews (Descending):\n");
                readHospitalData(hospitals, n);
                sortByRating(hospitals, n);
                for (int i = 0; i < n; i++) {
                    printHospital(&hospitals[i]);
                }
                break;
            case 7:
                printf("Print Hospitals in a Specific City:\n");
                readHospitalData(hospitals, n);
                printHospitalsInCity(hospitals, n);
                break;
            case 8:
                printf("Update Hospital Data:\n");
                readHospitalData(hospitals, n);
                printf("Enter the index of the hospital to update: ");
                int updateIndex;
                scanf("%d", &updateIndex);
                if (updateIndex >= 0 && updateIndex < n) {
                    printf("Enter new details for hospital:\n");
                    // Get new details from the user or from file
                    struct Hospital newDetails;
                    printf("Enter Hospital Name: ");
                    scanf("%s", newDetails.name);
                    printf("Enter City: ");
                    scanf("%s", newDetails.city);
                    printf("Enter Total Beds: ");
                    scanf("%d", &newDetails.beds);
                    printf("Enter Price per Bed: ");
                    scanf("%f", &newDetails.price);
                    printf("Enter Rating: ");
                    scanf("%f", &newDetails.rating);
                    printf("Enter Reviews: ");
                    scanf("%d", &newDetails.reviews);
                    updateHospitalData(&newDetails, updateIndex);
                    printf("Hospital details updated successfully!\n");
                } else {
                    printf("Invalid index!\n");
                }
                break;
            case 9:
                printf("Add New Patients:\n");
                readHospitalData(hospitals, n);
                printf("Enter the hospital index to add a patient: ");
                int patientHospitalIndex;
                scanf("%d", &patientHospitalIndex);
                if (patientHospitalIndex >= 0 && patientHospitalIndex < n) {
                    struct Patient newPatient;
                    printf("Enter Patient Name: ");
                    scanf("%s", newPatient.name);
                    printf("Enter Age: ");
                    scanf("%d", &newPatient.age);
                    printf("Enter Address: ");
                    scanf("%s", newPatient.address);
                    printf("Enter Disease: ");
                    scanf("%s", newPatient.disease);
                    printf("Enter Sex (M/F): ");
                    scanf(" %c", &newPatient.sex);
                    printf("Enter Contact: ");
                    scanf("%s", newPatient.contact);
                    addNewPatient(&patients[patientHospitalIndex], patientHospitalIndex, newPatient);
                    printf("New patient added successfully!\n");
                } else {
                    printf("Invalid hospital index!\n");
                }
                break;
            case 10:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 10);

    // Free allocated memory for patients
    for (int i = 0; i < n; i++) {
        free(patients[i]);
    }
    

    return 0;
}
