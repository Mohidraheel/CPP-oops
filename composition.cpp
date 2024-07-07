#include <iostream>
using namespace std;
class reception
{
protected:
    int patient_id;
    string doctor_name;
    string patient_name;

public:
    reception(int patient_id, string doctor_name, string patient_name)
    {
        this->patient_id = patient_id;
        this->doctor_name = doctor_name;
        this->patient_name = patient_name;
    }
};
class patient
{
    string medical;
    string patient_name;
    int patient_id;

public:
    patient(string medical, string name, int id)
    {
        this->medical = medical;
        this->patient_name = name;
        this->patient_id = id;
    }
    void pdisplay()
    {
        cout <<"paitent name:" <<patient_name << endl;
        cout <<"medical history:" <<medical << endl;
        cout <<"patient id:" <<patient_id << endl;
    }
};

class doctor
{
    string doctor_name;
    int did;
    string specialization;

public:
    doctor(string name, int did, string specialization)
    {
        this->doctor_name = name;
        this->did = did;
        this->specialization = specialization;
    }
    void recommendation(string history)
    {
        cout << "recommendation based on the patient hisory:" << history << endl;
    }
    void ddisplay()
    {
        cout <<"doctor name:" <<doctor_name << endl;
        cout <<"doctor id:" <<did << endl;
        cout <<"specialization:" <<specialization << endl;
    }
};
class administration : public doctor, public reception, public patient
{
    public:
    administration(int did, string specialization, int patient_id, string doctor_name, string patient_name, string medical):reception(patient_id,doctor_name,patient_name),doctor(doctor_name,did,specialization),patient(medical,patient_name,patient_id)
    {}
    void recommend(string medical)
    {
        recommendation(medical);
    }
    void adisplay()
    {
        pdisplay();
        ddisplay();
    }

};
 int main()
{
    administration adm(10,"surgery",101,"Abdul basit","Mohid","surgery history");
    adm.recommend("surgery history");
    adm.adisplay();
    return 0;
}
