#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Subject{
    private :
        int credit;
        string ID, name, instructorID, instructorName;
        double attendant, point, midTerm, finalTerm, totalScore, grade=-1.0;

    public :
        Subject(string name="", string ID="", string instructorID="", string instructorName="", int credit=0)
            : name(name), ID(ID), instructorID(instructorID), instructorName(instructorName), credit(credit){
                cout << "Subject information has been created." << endl;
            }

        void insightInfo(){
            cout << "ID : " << ID << "\nName : " << name << endl;
            cout << "Instructor : " << instructorName << endl;
        }

        string getID(){
            return ID;
        }

        string getName(){
            return name;
        }

        double getGrade(){
            return grade;
        }

        double getCredit(){
            return credit;
        }

        void getScore(double attendant_=0, double point_=0, double midTerm_=0, double finalTerm_=0){
            attendant = attendant_;
            point = point_;
            midTerm = midTerm_;
            finalTerm = finalTerm_;

            calculateGrade();
        }

        void calculateGrade(){
            totalScore = attendant + point + midTerm + finalTerm;
            if(attendant < 6 || totalScore < 50){
                grade = 0;
            }else if(totalScore < 55){
                grade = 1;
            }else if(totalScore < 60){
                grade = 1.5;
            }else if(totalScore < 65){
                grade = 2;
            }else if(totalScore < 70){
                grade = 2.5;
            }else if(totalScore < 75){
                grade = 3;
            }else if(totalScore < 80){
                grade = 3.5;
            }else{
                grade = 4;
            }
        }
};

class Student{
    private :
        double totalGrade;
        string ID, className, name;
        vector<Subject> subjects;

    public :
        Student(string name="", string ID="", string className="")
            : name(name), ID(ID), className(className){
                cout << "Student information has been created." << endl;
            }

        void insightInfo(){
            calculateTotalGrade();
            cout << "Name : " << name
                << "\nID : " << ID
                << "\nClass : " << className
                << printf("\nTotal Grade : %.2lf", totalGrade)
                << "\n\nSubjects : "
                << endl;

                for(int i=0; i<subjects.size(); i++){
                    cout << " - (" << subjects[i].getCredit() << ")";
                    printf("%.2lf ", subjects[i].getGrade());
                    cout << subjects[i].getName() << endl;
                }
        }

        void notGradedYet(){
            for(int i=0; i<subjects.size(); i++){
                if(subjects[i].getGrade() == -1.0){
                    cout << "(" << subjects[i].getID() << ") " << subjects[i].getName() << ", ";
                }
            }
        }

        string getClassName(){
            return className;
        }

        string getID(){
            return ID;
        }

        string getName(){
            return name;
        }

        int getSubjectSize(){
            return subjects.size();
        }

        string getSubjectID(int x){
            return subjects[x].getID();
        }

        void setScore(int index, double attendant_=0, double point_=0, double midTerm_=0, double finalTerm_=0){
            subjects[index].getScore(attendant_, point_, midTerm_, finalTerm_);
        }

        void addSubject(const Subject& sub){
            subjects.push_back(sub);
        }

        void deleteSubject(string ID_target = ""){
            for(int i=0; i<subjects.size(); i++){
                if(ID_target.compare(subjects[i].getID()) == 0) subjects.erase(subjects.begin() + i);
            }
        }

        void calculateTotalGrade(){
            double rawGrade=0, totalCredit=0;
            for(int i=0; i<subjects.size(); i++){
                rawGrade += subjects[i].getGrade()*subjects[i].getCredit();
                totalCredit += subjects[i].getCredit();
            }
            totalGrade = rawGrade/totalCredit;
        }
};

class Teacher{
    string ID, name, classConsult;
    vector<Subject> subjects;

    public :
        Teacher(string name="", string ID="", string classConsult="")
            : name(name), ID(ID), classConsult(classConsult){
                cout << "Teacher information has been created." << endl;
            }

        void insightInfo(){
            cout << "Name : " << name
            << "\nID : " << ID
            << "\nClass Consultant : " << classConsult
            << "\n\nSubjects taught : "
            << endl;

            for(int i=0; i<subjects.size(); i++){
                cout << " - " << subjects[i].getName() << endl;
            }
        }

        string getID(){
            return ID;
        }

        string getName(){
            return name;
        }


        void addSubject(const Subject& sub){
            subjects.push_back(sub);
        }

        void deleteSubject(string ID_target=""){
            for(int i=0; i<subjects.size(); i++){
                if(ID_target.compare(subjects[i].getID()) == 0) subjects.erase(subjects.begin() + i);
            }
        }
};

int main(int argc, char const *argv[]) {

    //Build School -- Create Student
    int numStudent;
    cout << "Number of student : ";
    cin >> numStudent;

    vector<Student> students;
    students.reserve(numStudent);
    for(int i=0; i<numStudent; i++){
        string name, ID, className;
        cout << "Name : ";
        cin >> name;
        cout << "ID : ";
        cin >> ID;
        cout << "Class : ";
        cin >> className;

        students.emplace_back(name, ID, className);
    }

    //Build School -- Create Teacher
    int numTeacher;
    cout << "Number of teacher : ";
    cin >> numTeacher;

    vector<Teacher> teachers;
    teachers.reserve(numTeacher);
    for(int i=0; i<numTeacher; i++){
        string name, ID, classConsult;
        cout << "Name : ";
        cin >> name;
        cout << "ID : ";
        cin >> ID;
        cout << "ClassConsult : ";
        cin >> classConsult;

        teachers.emplace_back(name, ID, classConsult);
    }

    //Build School -- Create Subject
    int numSubject;
    cout << "Number of Subject : ";
    cin >> numSubject;

    vector<Subject> subjects;
    subjects.reserve(numSubject);
    for(int i=0; i<numSubject; i++){
        int credit;
        string name, ID, instructorID, instructorName;
        char yearStudy;
        cout << "Name : ";
        cin >> name;
        cout << "ID : ";
        cin >> ID;
        cout << "YearStudy : ";
        cin >> yearStudy;
        cout << "Instructor ID: ";
        cin >> instructorID;
        cout << "Credit : ";
        cin >> credit;

        for(int ii=0; ii<numTeacher; ii++){
            if(instructorID.compare(teachers[ii].getID()) == 0) instructorName = teachers[ii].getName();
        }

        subjects.emplace_back(name, ID, instructorID, instructorName, credit);
        for(int ii=0; ii<numStudent; ii++){
            if(students[ii].getClassName().at(0) == yearStudy){
                students[ii].addSubject(subjects[i]);
            }
        }
        for(int ii=0; ii<numTeacher; ii++){
            if(instructorID.compare(teachers[ii].getID()) == 0){
                teachers[ii].addSubject(subjects[i]);
            }
        }
    }

    //MANAGEMENT
    while(true){
        int operate;
        cout << "----------\nManagement Option \n1.New Student \n2.New Teacher \n3.New Subject"
            << "\n4.Delete Student \n5.Delete Teacher \n6.Delete Subject"
            << "\n7.Info Student \n8.Info Teacher \n9.Info Subject"
            << "\n10.Grading"
            << "\n0.END PROGRAM"
            << endl;
        cin >> operate;

        switch(operate){
            case 0:
                cout << "\nEXIT PROGRAM";
                exit(0);
            case 1: //NEW STUDENT
                cout << "----------\nNumber of student : ";
                cin >> numStudent;
                for(int i=0; i<numStudent; i++){
                    string name, ID, className;
                    cout << "Name : ";
                    cin >> name;
                    cout << "ID : ";
                    cin >> ID;
                    cout << "Class : ";
                    cin >> className;

                    students.emplace_back(name, ID, className);
                }
                break;
            case 2: //NEW TEACHER
                cout << "----------\nNumber of teacher : ";
                cin >> numTeacher;
                for(int i=0; i<numTeacher; i++){
                    string name, ID, classConsult;
                    cout << "Name : ";
                    cin >> name;
                    cout << "ID : ";
                    cin >> ID;
                    cout << "ClassConsult : ";
                    cin >> classConsult;

                    teachers.emplace_back(name, ID, classConsult);
                }
                break;
            case 3: //NEW SUBJECT
                cout << "----------\nNumber of Subject : ";
                cin >> numSubject;
                for(int i=0; i<numSubject; i++){
                    int credit;
                    string name, ID, instructorID, instructorName;
                    char yearStudy;
                    cout << "Name : ";
                    cin >> name;
                    cout << "ID : ";
                    cin >> ID;
                    cout << "YearStudy : ";
                    cin >> yearStudy;
                    cout << "Instructor ID: ";
                    cin >> instructorID;
                    cout << "Credit : ";
                    cin >> credit;

                    for(int ii=0; ii<numTeacher; ii++){
                        if(instructorID.compare(teachers[ii].getID()) == 0) instructorName = teachers[ii].getName();
                    }

                    subjects.emplace_back(name, ID, instructorID, instructorName, credit);
                    for(int ii=0; ii<numStudent; ii++){
                        if(students[ii].getClassName().at(0) == yearStudy){
                            students[ii].addSubject(subjects[students[ii].getSubjectSize() + i]);
                        }
                    }
                }
                break;
            case 4: //DELETE STUDENT
                {
                string ID_target;
                cout << "----------\nDelete Student ID : ";
                cin >> ID_target;
                for(int i=0; i<students.size(); i++){
                    if(ID_target.compare(students[i].getID()) == 0){
                        students.erase(students.begin() + i);
                        break;
                    }
                }
                break;
                }
            case 5: //DELETE TEACHER
                {
                string ID_target;
                cout << "----------\nDelete Teacher ID : ";
                cin >> ID_target;
                for(int i=0; i<teachers.size(); i++){
                    if(ID_target.compare(teachers[i].getID()) == 0){
                        teachers.erase(teachers.begin() + i);
                        break;
                    }
                }
                break;
                }
            case 6: //DELETE SUBJECT
                {
                string ID_target;
                cout << "----------\nDelete Subject ID : ";
                cin >> ID_target;
                for(int i=0; i<subjects.size(); i++){
                    if(ID_target.compare(subjects[i].getID()) == 0){
                        teachers.erase(teachers.begin() + i);
                        break;
                    }
                }
                for(int i=0; i<students.size(); i++) students[i].deleteSubject(ID_target);
                for(int i=0; i<teachers.size(); i++) teachers[i].deleteSubject(ID_target);
                break;
                }
            case 7: //INFO STUDENT
                {
                    int choose;
                    cout << "----------\nInfo Students\n1.Students List \n2.Student Insights\n";
                    cin >> choose;
                    if(choose == 1){
                        cout << "The total number of students is " << students.size() << endl;
                        for(int i=0; i<students.size(); i++){
                            cout << students[i].getID() << " " << students[i].getName() << endl;
                        }
                    }else{
                        string inputID;
                        cout << "Student ID : ";
                        cin >> inputID;
                        for(int i=0; i<students.size(); i++){
                            if(inputID.compare(students[i].getID()) == 0){
                                students[i].insightInfo();
                                break;
                            }
                        }
                    }
                    break;
                }
            case 8: //INFO TEACHER
                {
                    int choose;
                    cout << "----------\nInfo Teahcers\n1.Teachers List \n2.Teacher Insight\n";
                    cin >> choose;
                    if(choose == 1){
                        cout << "The total number of teachers is " << teachers.size() << endl;
                        for(int i=0; i<teachers.size(); i++){
                            cout << teachers[i].getID() << " " << teachers[i].getName() << endl;
                        }
                    }else{
                        string inputID;
                        cout << "TeacherID : ";
                        cin >> inputID;
                        for(int i=0; i<teachers.size(); i++){
                            if(inputID.compare(teachers[i].getID()) == 0){
                                teachers[i].insightInfo();
                            }
                        }
                    }
                    break;
                }
            case 9: //INFO SUBJECT
                {
                    int choose;
                    cout << "----------\nInfo Subjects\n1.Subjects List \n2.Subject Insight\n";
                    cin >> choose;
                    if(choose == 1){
                        cout << "The total number of subjects is " << subjects.size() << endl;
                        for(int i=0; i<subjects.size(); i++){
                            cout << subjects[i].getID() << " " << subjects[i].getName() << endl;
                        }
                    }else{
                        string inputID;
                        cout << "SubjectID : ";
                        cin >> inputID;
                        for(int i=0; i<teachers.size(); i++){
                            if(inputID.compare(subjects[i].getID()) == 0){
                                subjects[i].insightInfo();
                            }
                        }
                    }
                    break;
                }
            case 10: //GRADING
                {
                    cout << "----------\nGrading Students\nStudent ID : ";
                    string chooseStudentID;
                    cin >> chooseStudentID;
                    for(int i=0; i<students.size(); i++){
                        if(chooseStudentID.compare(students[i].getID()) == 0){
                            cout << "Not graded yet : ";
                            students[i].notGradedYet();

                            while(true){
                                char x;
                                cout << "\nCONTINUE GRADING YES(y) / NO(n) : ";
                                cin >> x;
                                if(x == 'n') break;

                                cout << "\nSubject ID : ";
                                string chooseSubjectID;
                                cin >> chooseSubjectID;
                                double attendant, point, midTerm, finalTerm;
                                cout << "attendant, point, midTerm, finalTerm";
                                cin >> attendant >> point >> midTerm >> finalTerm;

                                for(int ii=0; ii<students[i].getSubjectSize(); ii++){
                                    if(chooseSubjectID.compare(students[i].getSubjectID(ii)) == 0){
                                        students[i].setScore(ii, attendant, point, midTerm, finalTerm);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
        }
    }
    return 0;
}
