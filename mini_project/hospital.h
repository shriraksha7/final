#ifndef HOSPITAL_H_
#define HOSPITAL_H_

struct Hospital {
    char name[50];
    char city[50];
    int beds;
    float price;
    float rating;
    int reviews;
};

void saveHospitalData(struct Hospital *hospitals, int n);
void readHospitalData(struct Hospital *hospitals, int n);
void printHospital(struct Hospital *hosp);
void sortByPrice(struct Hospital *hospitals, int n);
void sortByAvailableBeds(struct Hospital *hospitals, int n);
void sortByName(struct Hospital *hospitals, int n);
void sortByRating(struct Hospital *hospitals, int n);
void printHospitalsInCity(struct Hospital *hospitals, int n);
void updateHospitalData(struct Hospital *hospital, int index);
#endif /* HOSPITAL_H_ */

