#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <libc.h>

FILE *file;

void std_Input();

void readData();

bool subRead(FILE *pFile);

bool dob_Validation(char[10]);

void teacher_Input();

int genarateStudentId();

int genarateTeacherId();

void stdvalue_Assign(int code, char name[50], int age, int grade, char dob[10]);

void teacher_ValueAssign(int code, char name[50], int level, int experience, char dob[10]);

void std_Present();


bool sub_present(int *pInt);

void teacher_Present();

void exam_ListGenerate();

void salary_calculater();

void genarate_file();

void write_data();

char std_Name[800][50], std_DOB[800][10];
int nextIndex = 0, std_Age[800], std_Grade[800], std_ID[800], std_present[800], hold_dates = 0, exam_Qualification[800];
int teacher_QualificationLevel[40], teacher_ID[40], teacher_nextIndex = 0, teacher_Experince[40], teacher_present[40];
char teacher_Name[40][50], teacher_DOB[40][10];


int main() {
    readData();
    start:
    printf("");
    system("clear");
    printf("\n\t__          __  _ _                          \n");
    printf("\t\\ \\        / / | | |                         \n");
    printf("\t \\ \\  /\\  / /__| | | ___ ___  _ __ ___   ___ \n");
    printf("\t  \\ \\/  \\/ / _ \\ | |/ __/ _ \\| '_ ` _ \\ / _ \\\n");
    printf("\t   \\  /\\  /  __/ | | (_| (_) | | | | | |  __/\n");
    printf("\t    \\/  \\/ \\___|_|_|\\___\\___/|_| |_| |_|\\___|\n\n\n");

    printf("[1] Input Students to school\n");
    printf("[2] Input Teachers to school\n");
    printf("[3] present mark for students\n");
    printf("[4] present mark for Teachers\n");
    printf("[5] Getting qualified students for Examination\n");
    printf("[6] precent list for teacher\n");
    printf("[6] Exit\n\n\n");

    int input_process;

    printf("Enter your Selection : ");
    scanf("%d", &input_process);

    switch (input_process) {
        case 01:
            std_Input(); //input Students
            goto start;
        case 02:
            teacher_Input(); //input teacher
            goto start;
        case 03:
            std_Present(); //calculate Leave
            goto start;
        case 04:
            teacher_Present(); //calculate Teachers leave
            goto start;
        case 05:
            exam_ListGenerate();//calculate teachers salaries
            goto start;
        case 06:
            salary_calculater();//calculate teachers salaries
            goto start;
        default:
            printf("Your chose is not in the list!!!");
            write_data();
            break;
    }
    return 0;
}

void write_data() {
    FILE *write;
    write = fopen("data.txt", "w");
    for (int i = 0; i < nextIndex; i++) {
        fprintf(write, "S%04d \n",std_ID[i]);
        fprintf(write, "%s \n",std_Name[i]);
        fprintf(write, "%d \n",std_Age[i]);
        fprintf(write, "%d \n",std_Grade[i]);
        fprintf(write, "%.10s \n",std_DOB[i]);

    }
    fclose(write);
}
//----------------------------------------old file data reading---------------------------------------------------------
void readData() {
    FILE *data;
    data = fopen("data.txt", "r");
    if (data != NULL) { // Check if the file was opened successfully
        while (nextIndex < 800 && subRead(data)) {
            nextIndex++;
        }
        fclose(data); // Close the file after reading the data
    } else {
        printf("Error opening the file data.txt\n");
    }
}

bool subRead(FILE *data) {
    if (fscanf(data, "S%04d", &std_ID[nextIndex]) == 1) {
        // Read strings with spaces using "%99[^\n]"
        if (fscanf(data, " %99[^\n]", std_Name[nextIndex]) == 1 &&
            fscanf(data, "%d", &std_Age[nextIndex]) == 1 &&
            fscanf(data, " %d", &std_Grade[nextIndex]) == 1 &&
            fscanf(data, " %10[^\n]", std_DOB[nextIndex]) == 1) {
            fscanf(data, "\n");
            return true;
        }
    }
    return false;
}

//------------------------------------------Student input method--------------------------------------------------------
void std_Input() {
    system("clear");
    printf("  _____                   _      _____ _             _            _       \n");
    printf(" |_   _|                 | |    / ____| |           | |          | |      \n");
    printf("   | |  _ __  _ __  _   _| |_  | (___ | |_ _   _  __| | ___ _ __ | |_ ___ \n");
    printf("   | | | '_ \\| '_ \\| | | | __|  \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __/ __|\n");
    printf("  _| |_| | | | |_) | |_| | |_   ____) | |_| |_| | (_| |  __/ | | | |_\\__ \\\n");
    printf(" |_____|_| |_| .__/ \\__,_|\\__| |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|___/\n");
    printf("             | |                                                          \n");
    printf("             |_|                                                          \n");

    new_studentLine:
    printf("");
    char name[50], dob[10];
    int age, grade, code = genarateStudentId();

    //input new students data
    printf("S%.04d\n", code);
    printf("=========");

    name:
    printf("\nName               : ");
    if (scanf("%s",&name) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto name;
    }
    char name_t[50];
    for (int i = 0; i < 50; ++i) {
        name_t[i] = name[i];
    }

    age:
    printf("Age                : ");
    if ((scanf("%d", &age)) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto age;
    }

    grade:
    printf("Grade              : ");
    if ((scanf("%d", &grade)) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto grade;
    }

    dob:
    printf("DOB                : ");
    printf("yyyy-mm-dd\n");
    printf("\033[A");
    printf("\033[2K\r");
    printf("DOB                : ");
    if (dob_Validation(&dob)) {
        printf("\033[2A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto dob;
    }
    stdvalue_Assign(code, name_t, age, grade, dob);

    char option;
    printf("\n\nWould you want to enter another Student (Y/N) : ");
    scanf("%s", &option);
    if (option == 'Y' || option == 'y') {
        goto new_studentLine;
    }

}

void stdvalue_Assign(int code, char name[50], int age, int grade, char dob[10]) {
    std_ID[nextIndex] = code;
    for (int i = 0; i < 50; ++i) {
        std_Name[nextIndex][i] = name[i];
    }
    std_Age[nextIndex] = age;
    std_Grade[nextIndex] = grade;
    for (int i = 0; i < 10; ++i) {
        std_DOB[nextIndex][i] = dob[i];
    }
    nextIndex++;
}

int genarateStudentId() {
    int last_ID = std_ID[nextIndex - 1];
    return (last_ID + 1);
}

bool dob_Validation(char *dob) {
    if ((scanf("%s", dob)) != 1) {
        return true;
    } else {
        for (int i = 0; i < 10; i++) {
            if ((i != 4) && (i != 7)) {
                if (!(isdigit(dob[i]))) {
                    return true;
                }
            }
        }
    }

    char str_year[4], str_month[2], str_day[2];
    for (int i = 0; i < 10; i++) {
        if (i < 4) {
            str_year[i] = dob[i];

        } else if ((i > 4) && (i < 7)) {
            str_month[i - 5] = dob[i];
            break;
        } else if ((i > 7) && (i < 10)) {
            str_day[i - 8] = dob[i];
            break;
        } else {
            break;
        }
    }
    int year, month, day;
    sscanf(dob, "%d-%d-%d", &year, &month, &day);
    int month_ar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((month > 12) || (month < 0)) {
        return true;
    } else if ((year % 4 == 0) && (year % 100 == 0)) {
        if ((month == 02) && (day > 29)) {
            return true;
        } else if (day > month_ar[month - 1]) {
            return true;
        }
    } else if (day > month_ar[month - 1]) {
        return true;
    } else {
        return false;
    }
    return false;
}

//-----------------------------------------Teachers input method--------------------------------------------------------
void teacher_Input() {
    system("clear");
    printf("   _____                   _     _______              _               \n");
    printf("  |_   _|                 | |   |__   __|            | |              \n");
    printf("    | |  _ __  _ __  _   _| |_     | | ___  __ _  ___| |__   ___ _ __ \n");
    printf("    | | | '_ \\| '_ \\| | | | __|    | |/ _ \\/ _` |/ __| '_ \\ / _ \\ '__|\n");
    printf("   _| |_| | | | |_) | |_| | |_     | |  __/ (_| | (__| | | |  __/ |   \n");
    printf("  |_____|_| |_| .__/ \\__,_|\\__|    |_|\\___|\\__,_|\\___|_| |_|\\___|_|   \n");
    printf("              | |                                                     \n");
    printf("              |_|                                                     \n");

    new_TeacherLine:
    printf("");
    char name[50], dob[10];
    int qualification_Level, experience, code = genarateTeacherId();

    //input new students data
    printf("T%.04d\n", code);
    printf("=========");

    name:
    printf("\nName               : ");
    if ((scanf("%s", &name)) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto name;
    }

    qualificationLevel:
    printf("Qualification level: ");
    if ((scanf("%d", &qualification_Level)) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto qualificationLevel;
    }

    experience:
    printf("Experience         : ");
    if ((scanf("%d", &experience)) != 1) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto experience;
    }

    dob:
    printf("DOB                : ");
    printf("yyyy-mm-dd\n");
    printf("\033[A");
    printf("DOB                : ");
    if (dob_Validation(&dob)) {
        printf("\033[A");  //move cursor up
        printf("\033[2K\r");
        while (getchar() != '\n')// clear new line command get as input
            continue;
        goto dob;
    }

    teacher_ValueAssign(code, name, qualification_Level, experience, dob);

    char option;
    printf("\n\nWould you want to enter another Teacher (Y/N) : ");
    scanf("%s", &option);
    if (option == 'Y' || option == 'y') {
        goto new_TeacherLine;
    }
}

void teacher_ValueAssign(int code, char name[50], int level, int experience, char dob[10]) {
    teacher_ID[teacher_nextIndex] = code;
    for (int i = 0; i < 50; ++i) {
        teacher_Name[teacher_nextIndex][i] = name[i];
    }
    teacher_QualificationLevel[teacher_nextIndex] = level;
    teacher_Experince[teacher_nextIndex] = experience;
    for (int i = 0; i < 10; ++i) {
        teacher_DOB[teacher_nextIndex][i] = dob[i];
    }
    teacher_nextIndex++;
}

int genarateTeacherId() {
    int last_ID = teacher_ID[nextIndex - 1];
    return (last_ID + 1);
}

//---------------------------------------------present mark for students------------------------------------------------
void std_Present() {
    printf("   _____ _             _            _     _____            _     _            \n");
    printf("  / ____| |           | |          | |   |  __ \\          (_)   | |           \n");
    printf(" | (___ | |_ _   _  __| | ___ _ __ | |_  | |__) |___  __ _ _ ___| |_ ___ _ __ \n");
    printf("  \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| |  _  // _ \\/ _` | / __| __/ _ \\ '__|\n");
    printf("  ____) | |_| |_| | (_| |  __/ | | | |_  | | \\ \\  __/ (_| | \\__ \\ ||  __/ |   \n");
    printf(" |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |_|  \\_\\___|\\__, |_|___/\\__\\___|_|   \n");
    printf("                                                      __/ |                   \n");
    printf("                                                     |___/                    \n");

    printf("Enter 0 and 1 to mark absent and present");

    for (int i = 0; i < nextIndex; i++) {
        int present;
        printf("\nc%04d \n=====\n", std_ID[i]);
        present:
        printf("%s\t\t : ", std_Name[i]);
        if (sub_present(&present)) {
            printf("\033[A");  //move cursor up
            printf("\033[2K\r");
            while (getchar() != '\n') {// clear new line command get as input
                continue;
            }
            goto present;
        }
        std_present[i]++;
    }
    hold_dates++;
}

bool sub_present(int *present) {
    if ((scanf("%d", present)) != 1) {
        return true;
    } else {
        if ((*present <= 1) && (*present >= 0)) {
            return false;
        }
    }
    return false;
}

//---------------------------------------------present of teachers------------------------------------------------------
void teacher_Present() {
    printf("  _______              _                 _____            _     _            \n");
    printf(" |__   __|            | |               |  __ \\          (_)   | |           \n");
    printf("    | | ___  __ _  ___| |__   ___ _ __  | |__) |___  __ _ _ ___| |_ ___ _ __ \n");
    printf("    | |/ _ \\/ _` |/ __| '_ \\ / _ \\ '__| |  _  // _ \\/ _` | / __| __/ _ \\ '__|\n");
    printf("    | |  __/ (_| | (__| | | |  __/ |    | | \\ \\  __/ (_| | \\__ \\ ||  __/ |   \n");
    printf("    |_|\\___|\\__,_|\\___|_| |_|\\___|_|    |_|  \\_\\___|\\__, |_|___/\\__\\___|_|   \n");
    printf("                                                     __/ |                   \n");
    printf("                                                    |___/                    \n");

    printf("Enter 0 and 1 to mark absent and present");

    for (int i = 0; i < teacher_nextIndex; i++) {
        int present;
        printf("c%04d \n=====\n", teacher_ID[i]);
        present:
        printf("%s\t\t : ", teacher_Name[i]);
        if (sub_present(&present)) {
            printf("\033[A");  //move cursor up
            printf("\033[2K\r");
            while (getchar() != '\n') {// clear new line command get as input
                continue;
            }
            goto present;
        }
        teacher_present[i]++;
    }
}

//------------------------------------------getting Examination List----------------------------------------------------
void exam_ListGenerate() {
    int timer_duration = 3;

    time_t start_time = time(NULL);
    time_t current_time;

    while (1) {
        current_time = time(NULL);
        int elapsed_time = current_time - start_time;

        if (elapsed_time >= timer_duration) {
            genarate_file();
            break;
        }
        if (elapsed_time == 0) {
            system("clear");
            printf("   _____                           _   _                         \n");
            printf("  / ____|                         | | (_)                        \n");
            printf(" | |  __  ___ _ __   ___ _ __ __ _| |_ _ _ __   __ _            \n");
            printf(" | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __| | '_ \\ / _` |            \n");
            printf(" | |__| |  __/ | | |  __/ | | (_| | |_| | | | | (_| |  _    \n");
            printf("  \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__|_|_| |_|\\__, | (_) \n");
            printf("                                                __/ |            \n");
            printf("                                               |___/             \n");
        } else if (elapsed_time == 1) {
            system("clear");
            printf("   _____                           _   _                         \n");
            printf("  / ____|                         | | (_)                        \n");
            printf(" | |  __  ___ _ __   ___ _ __ __ _| |_ _ _ __   __ _            \n");
            printf(" | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __| | '_ \\ / _` |            \n");
            printf(" | |__| |  __/ | | |  __/ | | (_| | |_| | | | | (_| |  _   _    \n");
            printf("  \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__|_|_| |_|\\__, | (_) (_) \n");
            printf("                                                __/ |            \n");
            printf("                                               |___/             \n");
        } else {
            system("clear");
            printf("   _____                           _   _                         \n");
            printf("  / ____|                         | | (_)                        \n");
            printf(" | |  __  ___ _ __   ___ _ __ __ _| |_ _ _ __   __ _            \n");
            printf(" | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __| | '_ \\ / _` |            \n");
            printf(" | |__| |  __/ | | |  __/ | | (_| | |_| | | | | (_| |  _   _   _ \n");
            printf("  \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__|_|_| |_|\\__, | (_) (_) (_)\n");
            printf("                                                __/ |            \n");
            printf("                                               |___/             \n");
        }
        sleep(1);
    }

}

void genarate_file() {
    file = fopen("exam.txt", "w");
    for (int i = 0; i < nextIndex; i++) {
        if (((std_present[i] / hold_dates) * 100) >= 80) {
            exam_Qualification[i] = std_ID[i];
        }
    }

    fprintf(file, "  ________   __          __  __   _      _____  _____ _______ \n");
    fprintf(file, " |  ____\\ \\ / /    /\\   |  \\/  | | |    |_   _|/ ____|__   __|\n");
    fprintf(file, " | |__   \\ V /    /  \\  | \\  / | | |      | | | (___    | |   \n");
    fprintf(file, " |  __|   > <    / /\\ \\ | |\\/| | | |      | |  \\___ \\   | |  \n");
    fprintf(file, " | |____ / . \\  / ____ \\| |  | | | |____ _| |_ ____) |  | |   \n");
    fprintf(file, " |______/_/ \\_\\/_/    \\_\\_|  |_| |______|_____|_____/   |_|   \n\n\n");

    for (int i = 0; i < nextIndex; i++) {
        fprintf(file, "S%04d  -  %02d\n",exam_Qualification[i],(i+1));
    }
    fclose(file);
}


//----------------------------------------------generate salaries-------------------------------------------------------
void salary_calculater() {
    FILE *teacher_file;
    teacher_file = fopen("teacher.txt", "w");

    fprintf(teacher_file," _______              _                                                _       \n");
    fprintf(teacher_file,"|__   __|            | |                                              | |      \n");
    fprintf(teacher_file,"   | | ___  __ _  ___| |__   ___ _ __   _ __  _ __ ___  ___  ___ _ __ | |_ ___ \n");
    fprintf(teacher_file,"   | |/ _ \\/ _` |/ __| '_ \\ / _ \\ '__| | '_ \\| '__/ _ \\/ __|/ _ \\ '_ \\| __/ __|\n");
    fprintf(teacher_file,"   | |  __/ (_| | (__| | | |  __/ |    | |_) | | |  __/\\__ \\  __/ | | | |\\__ \\ \n");
    fprintf(teacher_file,"   |_|\\___|\\__,_|\\___|_| |_|\\___|_|    | .__/|_|  \\___||___/\\___|_| |_|\\__|___/\n");
    fprintf(teacher_file,"                                       | |                                      \n");
    fprintf(teacher_file,"                                       |_|                                      \n");


    for (int i = 0; i < teacher_nextIndex; i++) {
        fprintf(teacher_file, "T%04d  -  %03d%\n",teacher_ID[i],((teacher_present[i] / hold_dates) * 100));
    }

    fclose(teacher_file);
}
 