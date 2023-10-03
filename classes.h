//-------------------------------------------
//--------------FUNCTION es---------------
//-------------------------------------------
int distance (int x1 ,int y1 ,int x2 ,int y2);


//-------------------------------------------
//----------------CLASS es-----------------
//-------------------------------------------
class Time;
class Person;
class Account;
class Car;
class  Passenger;
class Driver;
class Admin;
class Discount;
class Signin;
class Login;
class Ride;
class Peyment;


class Time{
	int hour;
	int minute;
	int second;
public:
    Time (int a=0, int b=0, int c=0):hour(a), minute(b), second(c){}
    
    friend ostream & operator << (ostream &, Time &);
};



class Person{
protected:
	string firstName;
	string lastName;
	string email;
	string telephone;
	int age;
public:
    void setFName (string str) { firstName = str;}
    void setLName (string str) { lastName = str;}
    void setEmail (string str) { email = str;}
    void setTel (string str) { telephone = str;}
    void setAge (int a) { age = a; }
    
    string getFName () { return firstName;}
    string getLName () { return lastName;}
    string getEmail () { return email;}
    string getTel () { return telephone;}
    int getAge () { return age; }
};



class Account{
	string userName;
	string password;
	double balance;
public:
    Account () {} 
    Account (string un, string pss, double b): userName(un), password(pss), balance(b){}
    
    string getUserName(){ return userName;}
    string getPassword(){ return password;}
    double getBalance(){ return balance;}
    
    void setUserName (string un) { userName = un;}
    void setPassword (string pass) { password = pass; }
    void setBalance (double blc) { balance = blc; }
};


class Car{
	string model;
	string color;
	string plaque;
public:
    Car () {}
    Car (string _model, string _color, string _plaque): model(_model), color(_color), plaque(_plaque){}
    
    void setModel (string mdl) { model = mdl; }
    void setColor (string clr ) { color = clr; }
    void setPlaque (string plq) { plaque = plq; }
    
    string getModel () { return model; }
    string getColor () { return color; }
    string getPlaque () { return plaque; }
};


class Passenger:public Person{
	Account account;
	int rating;
	bool firstRide;
	int x,y;
public:
    Passenger () {}
    Passenger (Account a,int r,bool fr, int b , int c):account(a), x(b),y(c),rating(r),firstRide(fr) {}
    
    void setUserName (string un) { account.setUserName(un);}
    void setPassword (string pass) { account.setPassword(pass); }
    void setBalance (double blc) { account.setBalance(blc); }
    void setRating (int r ) { rating = r; }
    void setFirstRide (bool f) { firstRide = f; }
    void setXY (int _x, int _y) { x=_x;  y=_y; }
    
    string getUserName () { return account.getUserName(); }
    string getPassword () { return account.getPassword(); }
    double getBalance () { return account.getBalance() ; }
    int getRating () { return rating; }
    void getXY (int &_x , int &_y) { _x=x;  _y=y; }
    
    bool isFirstRide () { return firstRide; }
    Peyment peyment ();
    
};



class Driver:public Person{
	Account account;
	int rating;
	Car car;
	bool active;
	int x,y;
public:
    Driver () {}
    Driver (Account a, int r, Car c, bool ac, int i, int j):account(a),rating(r),car(c),active(ac),x(i),y(j) {}
    
     void setUserName (string un) { account.setUserName(un);}
    void setPassword (string pass) { account.setPassword(pass); }
    void setBalance (double blc) { account.setBalance(blc); }
    void setRating (int r ) { rating = r; }
    void setCarModel (string mdl) { car.setModel(mdl); }
    void setCarColor (string clr ) { car.setColor(clr); }
    void setCarPlaque (string plq) { car.setPlaque(plq); }
    void setActivation ( bool a) { active = a; }
    void setXY (int _x, int _y) { x=_x;  y=_y; }
    
    string getUserName () { return account.getUserName(); }
    string getPassword () { return account.getPassword(); }
    double getBalance () { return account.getBalance() ; }
    int getRating () { return rating; }
    string getCarModel () { return car.getModel(); }
    string getCarColor () { return car.getColor(); }
    string getCarPlaque () { return car.getPlaque(); }
    void getXY (int &_x , int &_y) { _x=x;  _y=y; }
    
    bool isActive () { return active; }
};



class Admin:public Person{
	Account account;
public:
    Admin (Account a):account(a) {}
    void setAccount (Account a) {account = a;}
    
    void setUserName (string un) { account.setUserName(un);}
    void setPassword (string pass) { account.setPassword(pass); }
    void setBalance (double blc) { account.setBalance(blc); }
    
    string getUserName () { return account.getUserName(); }
    string getPassword () { return account.getPassword(); }
    double getBalance () { return account.getBalance() ; }
};



class Discount{
	int amount;
	string name;
public:
	Discount (string n, int a):amount(a),name(n){}
	
	int getAmount () {return amount;}
	string getName () {return name; }
};




class Ride{
	int num;
	Time pickUpTime;
	Time dropOffTime;
	Driver driver;
	Passenger passenger;
	int driver_rate;
	int passenger_rate;
public:
    Ride () {}
    Ride (int n, Time p, Time d, Driver dd, Passenger pp, int dr, int pr):num(n),pickUpTime(p), dropOffTime(d),driver(dd), passenger(pp),driver_rate(dr), passenger_rate(pr) {}
    
    void setNum (int n) { num = n; }
    void setPickUpTime (Time t) { pickUpTime = t;}
    void setDropOffTime (Time t) { dropOffTime = t; }
    void setDriver (Driver d) {driver = d;}
    void setPassenger (Passenger p) {passenger = p;}
    void setDriverRate (int a) { driver_rate = a;}
    void setPassengerRate (int a) { passenger_rate = a;}
    
    int getNum () { return num; }
    Time getPickUpTime () { return pickUpTime; }
    Time getDropOffTime () { return dropOffTime; }
    Driver getDriver () { return driver; }
    Passenger getPassenger () { return passenger; }
    int getDriverRate () { return driver_rate; }
    int getPassengerRate () { return passenger_rate; }
    
    int getANum () { static int n=0; return ++n; }
};



class Peyment{
	Ride ride;
	double amount;
	bool status;
	int off;
public:
    Peyment () {}
    Peyment (Ride r , double a, bool s, int o):ride(r) , amount(a),status(s),off(o) {}
    
    void setRide (Ride r) { ride = r; }
    void setAmount (double a) {amount = a;}
    void setStatus (bool s) {status = s;}
    void setOff (int o) {off = o;}
    
    Ride getRide () { return ride; }
    double getAmount () { return amount; }
    bool getStatus () { return status; }
    int getOff () { return off; }
};



class Signin{
	vector <Driver> driver;
	vector <Passenger> passenger;
	vector <Admin> admin;
	vector <Peyment> peyment;
	vector <Ride> ride;
	vector <Discount> discount;
public:
    Signin () { this->readFiles(); }
    ~ Signin () { this->writOnFiles(); }
    
    void setNewDriver (Driver d) { driver.push_back(d) ; }
    void setNewPassenger (Passenger p) { passenger.push_back(p); }
    void setNewAdmin (Admin a) { admin.push_back(a); }
    void setNewPeyment (Peyment p) { peyment.push_back(p); }
    void setNewRide (Ride r) { ride.push_back(r); }
    void setNewDiscount (Discount d) { discount.push_back(d); }
    
    void readFiles ();
    void writOnFiles ();
    bool discountChecker (string);
};


class Login{
	vector <Driver> driver;
	vector <Passenger> passenger;
	vector <Admin> admin;
public:
    Login () {}
    
    void loginDriver (Driver d) { 
        d.setActivation(1);
        driver.push_back(d);
    }
    void loginPassenger (Passenger p) { passenger.push_back(p); }
    void loginAdmin (Admin a) { admin.push_back(a); }
    
    void logOutDriver (Driver);
    void logOutPassenger (Passenger);
    void logOutAdmin (Admin);
};













