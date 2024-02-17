#ifndef PATIENT_H_
#define PATIENT_H_

struct Patient {
    char name[50];
    int age;
    char address[100];
    char disease[50];
    char sex;
    char contact[20];
     int active; // Flag to indicate if the record is active or inactive
};
void savePatientData(struct Patient (*patients)[3], int n);
void readPatientData(struct Patient (*patients)[3], int n);
void printPatient(struct Patient *patient);
void addNewPatient(struct Patient **patients, int index, struct Patient newPatient);


#endif /* PATIENT_H_ */

