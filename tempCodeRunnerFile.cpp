    void Display() const override
    {
        // Implement the display logic for OutPatient
        Patient::Display(); // Optionally call the base class Display function
        cout << setw(18) << getCondition() << endl;
    }