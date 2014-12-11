#include<iostream>
#include<string>
class Lab
{
	private:
		std::string LabID;
		int Capacity;
		std::string SubjectCode;
		int BuildingNumber;
		int RoomNumber;
		std::string LabTime;
	public:
		void setID(std::string ID) { LabID=ID; };
		std::string getID() const { return LabID; };
		void setCode(std::string code) { SubjectCode=code; };
		std::string getCode() const { return SubjectCode; };
		void setTime(std::string time) { LabTime=time; };
		std::string getTime() const { return LabTime; };
		void setCap(int max) { Capacity=max; };
		int getCap() const { return Capacity; };
		void setBN(int bnumber) { BuildingNumber=bnumber; };
		int getBN() const { return BuildingNumber; };
		void setRN(int rnumber) { RoomNumber=rnumber; };
		int getRN() const { return RoomNumber; };
		Lab();
};
