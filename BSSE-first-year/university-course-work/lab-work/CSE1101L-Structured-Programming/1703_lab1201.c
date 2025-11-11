/*
Saeed Ahmed Mahin
Roll: 1703
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findTop5(FILE *employeeFile) {
    fscanf(employeeFile, "%*s %*s %*s %*s %*s");

    char empId[10], empName[20], empDesignation[20], deptId[5];
    int empSalary;

    int topSalaries[5] = {0, 0, 0, 0, 0};
    char topEmployees[5][20];

    while (fscanf(employeeFile, "%s %s %s %s %d", empId, empName, empDesignation, deptId, &empSalary) == 5) {
        int insertPos = -1;
        for (int i = 0; i < 5; i++) {
            if (empSalary > topSalaries[i]) {
                insertPos = i;
                break;
            }
        }

        if (insertPos != -1) {
            for (int i = 4; i >= insertPos + 1; i--) {
                strcpy(topEmployees[i], topEmployees[i - 1]);
                topSalaries[i] = topSalaries[i - 1];
            }
            topSalaries[insertPos] = empSalary;
            strcpy(topEmployees[insertPos], empName);
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%s %d\n", topEmployees[i], topSalaries[i]);
    }
}

void empInLoc(FILE *employeeFile, FILE *officeFile, char *targetLocation) {
    fscanf(officeFile, "%*s %*s %*s");

    char deptId[10], deptName[20], officeLocation[20];
    char matchingDeptIds[6][20];
    int matchingDeptCount = 0;

    while (fscanf(officeFile, "%s %s %s", deptId, deptName, officeLocation) == 3) {
        if (strcmp(officeLocation, targetLocation) == 0) {
            strcpy(matchingDeptIds[matchingDeptCount], deptId);
            matchingDeptCount++;
        }
    }

    if (matchingDeptCount > 0) {
        fscanf(employeeFile, "%*s %*s %*s %*s %*s");

        char empId[10], empName[20], empDesignation[20], empDeptId[5];
        int empSalary;

        while (fscanf(employeeFile, "%s %s %s %s %d", empId, empName, empDesignation, empDeptId, &empSalary) == 5) {
            for (int i = 0; i < matchingDeptCount; i++) {
                if (strcmp(matchingDeptIds[i], empDeptId) == 0) {
                    printf("%s\n", empName);
                }
            }
        }
    }
}

void deptWiseSal(FILE *employeeFile, FILE *officeFile) {
    fscanf(officeFile, "%*s %*s %*s");

    char deptId[10], deptName[20], officeLocation[20];
    int totalDepartments = 0;

    while (fscanf(officeFile, "%s %s %s", deptId, deptName, officeLocation) == 3) {
        totalDepartments++;
    }

    char **deptIds = malloc(totalDepartments * sizeof(char *));
    for (int i = 0; i < totalDepartments; i++) {
        deptIds[i] = malloc(10 * sizeof(char));
    }

    rewind(officeFile);
    fscanf(officeFile, "%*s %*s %*s");

    char deptNames[totalDepartments][20];
    int index = 0;

    while (fscanf(officeFile, "%s %s %s", deptId, deptName, officeLocation) == 3) {
        strcpy(deptIds[index], deptId);
        strcpy(deptNames[index], deptName);
        index++;
    }

    int *deptSalaryTotals = malloc(totalDepartments * sizeof(int));
    for (int i = 0; i < totalDepartments; i++) {
        deptSalaryTotals[i] = 0;
    }

    fscanf(employeeFile, "%*s %*s %*s %*s %*s");

    char empId[10], empName[20], empDesignation[20], empDeptId[5];
    int empSalary;

    while (fscanf(employeeFile, "%s %s %s %s %d", empId, empName, empDesignation, empDeptId, &empSalary) == 5) {
        for (int i = 0; i < totalDepartments; i++) {
            if (strcmp(deptIds[i], empDeptId) == 0) {
                deptSalaryTotals[i] += empSalary;
            }
        }
    }

    for (int i = 0; i < totalDepartments; i++) {
        printf("%s %d\n", deptNames[i], deptSalaryTotals[i]);
    }

    for (int i = 0; i < totalDepartments; i++) {
        free(deptIds[i]);
    }
    free(deptIds);
    free(deptSalaryTotals);
}

int main() {
    FILE *empFp = fopen("employees.txt", "r");
    if (empFp == NULL) {
        printf("Error opening employees.txt\n");
        return 1;
    }

    FILE *offFp = fopen("offices.txt", "r");
    if (offFp == NULL) {
        printf("Error opening offices.txt\n");
        fclose(empFp);
        return 1;
    }

    deptWiseSal(empFp, offFp);

    fclose(empFp);
    fclose(offFp);
    return 0;
}

