#include <iostream>
#include <fstream>
using namespace std;

class CheckUp
{
    // declare check up fields
private:
    int _patientNumber;
    double _bloodPressureSystolic;
    double _bloodPressureDiastolic;
    double _CholesterolLDL;
    double _CholesterolHDL;

    // create check up constructor with parameters
public:
    CheckUp(int patientNumber, double bloodPressureSystolic, double bloodPressureDiastolic, double CholesterolHDL, double CholesterolLDL)
    {
        _patientNumber = patientNumber;
        _bloodPressureSystolic = bloodPressureSystolic;
        _bloodPressureDiastolic = bloodPressureDiastolic;
        _CholesterolHDL = CholesterolHDL;
        _CholesterolLDL = CholesterolLDL;
    }

    // create check up constructors without parameters
public:
    CheckUp()
    {

    }

    // method help to get  patent number

public:
    int getPatientNumber()
    {
        return _patientNumber;
    }

    // method help to set patient number
    void setPatientNumber(int patientNumber)
    {
        _patientNumber =  patientNumber;
    }

    // help to  get blood pressure systolic value
    double getbloodPressureSystolic()
    {
        return _bloodPressureSystolic;
    }

    // help to set blood pressure systolic value
    void setbloodPressureSystolic(double bloodPressureSystolic)
    {
        _bloodPressureSystolic =  bloodPressureSystolic;
    }


    // help to get blood pressure Diastolic value
    double getbloodPressureDiastolic()
    {
        return _bloodPressureDiastolic;
    }

    // help to set blood pressure Diastolic value
    void setbloodPressureDiastolic(double bloodPressureSystolic)
    {
        _bloodPressureSystolic = bloodPressureSystolic;
    }


    // help to get LDL
    double getCholesterolLDL()
    {
        return _CholesterolLDL;
    }

    // help to set LDL
    void setCholesterolLDL(double CholesterolLDL)
    {
        _CholesterolLDL =  CholesterolLDL;
    }


    // help to get HDL
    double getCholesterolHDL()
    {
        return _CholesterolHDL;
    }

    // help to set HDL
    void setCholesterolHDL(double CholesterolHDL)
    {
        _CholesterolHDL =  CholesterolHDL;
    }


    // a method to compute test ratio
    double ComputeRatio()
    {
        return  _CholesterolLDL / _CholesterolHDL;
    }

    // a method to explain ratio
    string ExplainRatio()
    {
        if(_CholesterolHDL <= 3.5)
        {
            return "good cholesterol in your HDL";
        }

        return "Too much cholesterol in your HDL";
    }

};

int main()
{

    // declare variables
    int  number;
    double data;
    string line ;
    int numberOfPatent,init=1;

    // call input file streams and output file stream class for writing to files
    ifstream infile;
    ofstream outfile;



    // initialize check up class with constructor;
    CheckUp chekup1(123,3.5,3.5,3.5,3.5);

    // keep track numbers of patient to attend to//
    cout << "How many patient do you want to diagnose  ? " << endl;
    cin >> numberOfPatent;
    cin.ignore();

    // create and open text file and clear out data in file if it exist
    infile.open("result.txt",ios::out | ios::trunc);
    infile.close();


    // loop through number of patient to diagnose
    while(init <= numberOfPatent)
    {


        cout << "................" << init << "..................." << endl;

        // open a file to write into

        outfile.open("result.txt", ios::app);

        // write into the file
        outfile << "................" << init << "..................." << endl;
        cout << "Writing to the file" << endl;
        cout << "Enter patient number" << endl;
        cin >> number;
        cin.ignore();

        // call check up class methods
        chekup1.setPatientNumber(number);

        //write the inputed data into a file
        outfile << "Patient Number " << chekup1.getPatientNumber() << endl;


        // set blood pressure
        cout << "Enter blood Pressure Systolic value" << endl;
        cin >> data;
        cin.ignore();

        chekup1.setbloodPressureSystolic(data);

        //write the inputed data into a file
        outfile << "Systolic " << chekup1.getbloodPressureSystolic() << endl;


        // set blood pressure
        cout << "Enter  blood Pressure Diastolic value" << endl;
        cin >> data;
        cin.ignore();

        chekup1.setbloodPressureDiastolic(data);

        //write the inputed data into a file
        outfile << "Diastolic " << chekup1.getbloodPressureDiastolic() << endl;

        //set cholesterol
        // set blood pressure
        cout << "Enter  cholesterol HDL" << endl;
        cin >> data;
        cin.ignore();

        chekup1.setCholesterolHDL(data);

        //write the inputed data into a file
        outfile << "HDL " << chekup1.getCholesterolHDL() << endl;

        cout << "Enter  cholesterol LDL" << endl;
        cin >> data;
        cin.ignore();

        chekup1.setCholesterolLDL(data);

        //write the inputed data into a file
        outfile << "LDL " << chekup1.getCholesterolLDL() << endl;

        //write the inputed data into a file
        outfile << "Computed Ratio " << chekup1.ComputeRatio() << endl;

        outfile << "Ratio explanation  " << chekup1.ExplainRatio() << endl;

        // close file
        outfile.close();

        // increase loop
        init++;

        cout << "..................................." << endl;
        outfile << "................" << init << "..................." << endl;
    }

    // open file in a read mode


    cout << "Reading from the file" << endl;
    infile.open("result.txt");
    // loop through all the files to read.

    if (infile.is_open())
    {
        while (getline(infile,line))
        {
            cout << line << '\n';
        }
        // close the opened file
        infile.close();
    }
    return 0;
}
