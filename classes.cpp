#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

#include "classes.h"

//---------------------------------------------
//----------------FUNCTIONs-----------------
//---------------------------------------------

int distanceComputer (int x1 ,int y1 ,int x2 ,int y2){
    	return sqrt(( pow((x1 - x2 ),2) +  pow((y1 - y2 ),2 ) ) ) ; 
}



//-------------------------------------------
//----------------CLASS es-----------------
//-------------------------------------------
ostream & operator << (ostream & out, Time & t){
	out<<t.hour<<':'<<t.minute<<':'<<t.second;
	return out;
}



void Signin::readFiles (){	
	//general variables
	string userName, password, fName, lName, email, telephone;
	double balance;
	int rating , x , y , age;
	ifstream ifs;
	
	//drivers:
	bool active;
	string modle , color , plaque;
	ifs.open("DataBase/drivers.txt");
	while ( ! ifs.eof() ){
		ifs>>age; ifs.ignore();
		getline(ifs , fName , '*'); getline(ifs , lName , '*'); getline(ifs , email , '*'); getline(ifs , telephone);
		getline(ifs , userName , '*'); getline(ifs , password); 
		ifs>>balance>>rating>>x>>y>>active;
		ifs.ignore();
		getline(ifs , modle , '*'); getline(ifs , color , '*'); getline(ifs , plaque);
		Driver d (Account(userName,password,balance), rating,Car(modle,color,plaque),active,x,y);
		d.setFName(fName);
		d.setLName(lName);
		d.setEmail(email);
		d.setTel(telephone);
		d.setAge( age );
		driver.push_back(d);
	}
	ifs.close();
	
	//passengers
	bool firstRide;
	ifs.open("DataBase/passengers.txt");
	while ( ! ifs.eof() ){
		ifs>>age; ifs.ignore();
		getline(ifs , fName , '*'); getline(ifs , lName , '*'); getline(ifs , email , '*'); getline(ifs , telephone);
		getline(ifs , userName , '*'); getline(ifs , password); 
		ifs>>balance>>rating>>x>>y>>firstRide;
		ifs.ignore();
		Passenger  p (Account(userName,password,balance), rating,active,x,y);
		p.setFName(fName);
		p.setLName(lName);
		p.setEmail(email);
		p.setTel(telephone);
		p.setAge( age );
		passenger.push_back(p);
	}
	ifs.close();
	
	//admins
	ifs.open("DataBase/admins.txt");
	while ( ! ifs.eof() ){
		ifs>>age; ifs.ignore();
		getline(ifs , fName , '*'); getline(ifs , lName , '*'); getline(ifs , email , '*'); getline(ifs , telephone);
		getline(ifs , userName , '*'); getline(ifs , password); 
		
		Admin a (Account(userName,password,balance));
		a.setFName(fName);
		a.setLName(lName);
		a.setEmail(email);
		a.setTel(telephone);
		a.setAge( age );
	    admin.push_back(a);
	}
	ifs.close();
	
	//rides
	int num,ph,pm,ps,dh,dm,ds, p_rate,d_rate;
	string d_userName , p_userName;
	ifs.open("DataBase/rides.txt");
	while ( ! ifs.eof() ){
		ifs>>num>>d_rate>>p_rate>>ph>>pm>>ps >>dh>>dm>>ds;
		ifs.ignore();
		getline(ifs , d_userName , '*'); getline(ifs , p_userName );
		
	    Driver d;
	    Passenger p;
	    for (int i=0 ; i<driver.size() ; i++)
	        if(driver[i].getUserName() == d_userName){
	            d = driver[i]; break; }
	    for (int i=0 ; i<passenger.size() ; i++)
	        if(passenger[i].getUserName() == p_userName){
	             p = passenger[i]; break; }
	    
	    ride.push_back(Ride (num,Time(ph,pm,ps), Time(dh,dm,ds) ,d,p,d_rate,p_rate));
	}
	ifs.close();
	
	//peyments
	int ride_num , off;
	double amount;
	bool status;
	ifs.open("DataBase/peyments.txt");
	while ( ! ifs.eof() ){
		ifs>>ride_num >>amount >>status>>off;
		ifs.ignore();
		Ride r;
	    for (int i=0 ; i<ride.size() ; i++)
	        if(ride[i].getNum() == num){
	             r = ride[i]; break; }
		peyment.push_back ( Peyment(r,amount,status,off) );
	}
	ifs.close();
	
	//discounts
	int amountDis;
	string name;
	ifs.open ("DataBase/discounts.txt");
	while ( !ifs.eof() ){
		ifs>>name;
		ifs.ignore();
		ifs>>amountDis;
		ifs.ignore() ; ifs.ignore() ; ifs.ignore();
		discount.push_back( Discount(name,amountDis));
	}
}







void Signin::writOnFiles(){
	ofstream ofs;
	
	//drivers:
	ofs.open("DataBase/drivers.txt");
	for (int i=0 ; i< driver.size() ; i++){
		Driver * temp = & driver[i];
		ofs<< temp->getAge() <<" "<< temp->getFName() <<'*'<< temp->getLName() <<'*'<< temp->getEmail() <<'*'<<  temp->getTel() << endl;
		ofs<< temp->getUserName() <<'*'<< temp->getPassword() <<endl;
		int x,y;
		temp->getXY(x,y);
		ofs<< temp->getBalance() << " "<< temp->getRating() << " " << x <<" "<< y <<" "<<  temp->isActive() << endl;
		ofs << temp->getCarModel() <<"*"<<  temp->getCarColor() <<"*"<< temp->getCarPlaque() <<endl;
	}
	ofs.close();
	
	//passengers
	ofs.open("DataBase/passengers.txt");
	for (int i=0 ; i< passenger.size() ; i++){
		Passenger * temp = & passenger[i];
		ofs<< temp->getAge() <<" "<< temp->getFName() <<'*'<< temp->getLName() <<'*'<< temp->getEmail() <<'*'<<  temp->getTel() << endl;
		ofs<< temp->getUserName() <<'*'<< temp->getPassword() <<endl;
		int x,y;
		temp->getXY(x,y);
		ofs<< temp->getBalance() << " "<< temp->getRating() << " " << x <<" "<< y <<" "<<  temp->isFirstRide() << endl;
	}
	ofs.close();
	
	//admins
	ofs.open("DataBase/admins.txt");
	for (int i=0 ; i< admin.size() ; i++){
			Admin * temp = & admin[i];
		ofs<< temp->getAge() <<" "<< temp->getFName() <<'*'<< temp->getLName() <<'*'<< temp->getEmail() <<'*'<<  temp->getTel() << endl;
		ofs<< temp->getUserName() <<'*'<< temp->getPassword() <<endl;
	}
	ofs.close();
	
	//rides
	ofs.open("DataBase/rides.txt");
	for (int i=0 ; i< ride.size() ; i++){
		Ride * r= & ride[i];
		//ofs<< r->getNum() <<" "<< r->getDriverRate() <<" " << r->getPassengerRate() << " "<< r->getPickUpTime().getHour() << " " << r->getPickUpTime().getMin() << " " << r->getPickUpTime().getSec() << " " << 
	}
	ofs.close();
	
	//peyments
	ofs.open("DataBase/peyments.txt");
	for (int i=0 ; i< peyment.size() ; i++){
		ofs<<peyment[i].getRide().getNum() <<" "<< peyment[i].getAmount() << " " << peyment[i].getStatus() << " " << peyment[i].getOff() <<endl;
	}
	ofs.close();
	
	//discounts
	ofs.open("DataBase/discounts.txt");
	for (int i=0 ; i< discount.size() ; i++){
		ofs<<discount[i].getName() << " "<< discount[i].getAmount() <<"%\n";
	}
	ofs.close();
}


bool Signin::discountChecker (string dsc) {
	for (int i=0 ; i<discount.size() ; i++)
	    if (discount[i].getName() == dsc)
	        return 1;
	return 0;
}

void Login::logOutDriver (Driver d){
	for (int i=0 ; i<driver.size() ; i++)
	    if (d.getUserName() == driver[i].getUserName()){
	        driver.erase (driver.begin() + i);
	        break;
	    }
}

void Login::logOutPassenger (Passenger d){
	for (int i=0 ; i<passenger.size() ; i++)
	    if (d.getUserName() == passenger[i].getUserName()){
	        passenger.erase (passenger.begin() + i);
	        break;
	    }
}

void Login::logOutAdmin (Admin a){
	for (int i=0 ; i<admin.size() ; i++)
	    if (a.getUserName() == admin[i].getUserName()){
	        admin.erase (admin.begin() + i);
	        break;
	    }
}
