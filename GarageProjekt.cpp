#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int bicycleCounter = 0;
int carCounter = 0;																					// Global variables
int motorCycleCounter = 0;
int busCounter = 0;
int truckCounter = 0;
int counter = 0;
int maxLimit = 0;
std::string search = "";
int selection = 0;
int selectionTwo = 0;
int selectionThree = 0;
int selectionFour = 0;
int numberSearch = 0;

class Vehicle  {
protected:
	std::string regNr;
	std::string color;
	std::string vehicleType;
	int wheels = 0;
public:
	Vehicle() { }
	Vehicle(std::string a, std::string b, int c) : regNr(a), color(b), wheels(c)
	{ 


	}
	virtual void set_RegNr(std::string x) {};
	virtual	void set_VehicleType(std::string x) {};		// Void because it doesnt return a value, just takes an argument 
	virtual void set_Model(std::string x) { };
	virtual void set_Electric(std::string x) { };

	std::string get_VehicleType() { return vehicleType; };			// Returns value of the variable vehicleType so that you can use it at the point when its most useful
	std::string get_RegNr() { return regNr; };
	std::string get_Color() { return color; };
	virtual std::string get_Model() { return ""; };
	virtual std::string get_Electric() { return ""; };
	int get_Wheels() { return wheels; };
	
	
	virtual void listVehicles() = 0;
	};


class Car : public Vehicle
{
protected:
	std::string model;
	std::string electric;
public:
	Car() {}
	Car(std::string regNr, std::string color, int wheels, std::string inkModel, std::string inkElectric) : Vehicle(regNr, color, wheels)
	{
		vehicleType = "Car";
		model = inkModel;
		electric = inkElectric;
	}
	void listVehicles() {
		std::cout << "\n RegNumber: " << this->regNr << "\n Color: " << this->color << "\n Number of wheels: " << this->wheels <<
			"\n Model: " << this->model << "\n Electric: " << this->electric << std::endl;

	}


	
	void set_Model(std::string x)
	{
		model = x;
	}
	std::string get_Model() { return model; };
	void set_Electric(std::string x)
	{

		electric = x;
	}
	void set_VehicleType(std::string x) 
	{
		vehicleType = x;


	}
	void set_RegNr(std::string x)
	{

		regNr = x;
	}
/*	void listTypeOfVehicles() {



		if (vehicleType == "Car")
		{

			std::cout << "Number of Cars in the Garage" << carCounter << std::endl;
		}
	*/
};
class Bicycle : public Vehicle
{
protected:
	std::string model;
	int gears = 0;

public:
	Bicycle() {}
	Bicycle(std::string regNr, std::string color, int wheels, std::string inkModel, int inkGears) : Vehicle (regNr, color, wheels)
	{
		vehicleType = "Bicycle";
		model = inkModel;
		gears = inkGears;
	}

	void listVehicles() {
		std::cout <<  " \n RegNumber: " << this->regNr << "\n Color: " << this->color << "\n Number of wheels: " << this->wheels <<
			"\n model: " << this->model << "\n Number of Gears: " << this->gears <<  std::endl;
	}

	void set_Model(std::string x)
	{
		model = x;
	}
	std::string get_model() { return model; };

	

};
class Motorcycle : public Vehicle
{
protected:
	std::string model;
	int gears = 0;

public:
	Motorcycle() {}
	Motorcycle(std::string regNr, std::string color, int wheels, std::string inkModel, int inkGears) : Vehicle(regNr, color, wheels)
	{
		vehicleType = "Motorcycle";
		model = inkModel;
		gears = inkGears;
	}

	void listVehicles() {
		std::cout << "\n RegNumber: " << this->regNr << "\n Color: " << this->color << "\n Number of wheels: " << this->wheels <<
			"\n Model: " << this->model << "\n Number of Gears: " << this->gears << std::endl;
	}

	void set_Model(std::string x)
	{
		model = x;
	}
	std::string get_model() { return model; };

};
class Truck : public Vehicle
{
protected:
	std::string model;
	std::string automatic;

public:
	Truck() {}
	Truck(std::string regNr, std::string color, int wheels, std::string inkModel, std::string inkAutomatic) : Vehicle(regNr, color, wheels)
	{
		vehicleType = "Truck";
		model = inkModel;
		automatic = inkAutomatic;
	}

	void listVehicles() {
		std::cout << "\n RegNumber: " << this->regNr << "\n Color: " << this->color << "\n Number of wheels: " << this->wheels <<
			"\n Model: " << this->model << "\n A/M: " << this->automatic << std::endl;
	}

	void set_Model(std::string x)
	{
		model = x;
	}
	std::string get_model() { return model; };

};
class Bus : public Vehicle
{
protected:
	std::string model;
	int seats = 0;

public:
	Bus() {}
	Bus(std::string regNr, std::string color, int wheels, std::string inkModel, int inkSeats) : Vehicle(regNr, color, wheels)
	{
		vehicleType = "Bus";
		model = inkModel;
		seats = inkSeats;
	}

	void listVehicles() {
		std::cout  << " \n RegNumber: " << this->regNr  <<  " \n Color: " << this->color << " \n Number of wheels: " << this->wheels
			 << " \n Model: " << this->model <<  " \n Number of seats: " << this->seats << std::endl;
	}

	void set_Model(std::string x)
	{
		model = x;
	}
	std::string get_model() { return model; };

};
	class Garage {
	protected:
		std::string regNr;
		std::string color;
		int wheels = 0;
		std::string model;
		std::string electric;
	
	public:
		Garage() {}
		Garage(std::string regNr, std::string color, int wheels, std::string inkModel, std::string inkElectric) {}
		std::vector <Vehicle*> listGarage;
	
		int vectorSize()

		{
			return listGarage.size();
		}

		void addVehicles(Vehicle* x) {
		if (counter < maxLimit)
		{
				listGarage.push_back(x);
				counter++;

				if (x->get_VehicleType() == "Car")
				{

					carCounter++;
				}
				if (x->get_VehicleType() == "Bicycle")
				{
					bicycleCounter++;
				}
				if (x->get_VehicleType() == "Motorcycle")

				{

					motorCycleCounter++;
				}
				if (x->get_VehicleType() == "Bus")

				{

					busCounter++;
				}

				if (x->get_VehicleType() == "Truck")

				{

					truckCounter++;
				}

				std::cout << "Number of vehicles in garage: " << counter << std::endl;
			}
			else if (counter >= maxLimit)
			{
				std::cout << "Full, please remove a vehicle first" << std::endl;
				
				
			}

			
		} 
		void removeVehicles(Vehicle * y)
		{
			std::vector<Vehicle*>::iterator it = std::find(listGarage.begin(), listGarage.end(), y);

			if (it != listGarage.end())
			{
				std::cout << "Element found "  << std::endl;
				
				listGarage.erase(it);
				counter--;
				// std::cout << counter << std::endl;
			}
			if (y->get_VehicleType() == "Car")
			{

				carCounter--;

				}
			if (y->get_VehicleType() == "Bicycle")
			{

				bicycleCounter--;
			}

			if (y->get_VehicleType() == "MotorCycle")
			{
				motorCycleCounter--;
			}
			if (y->get_VehicleType() == "Bus")
			{
				busCounter--;
			}
			if (y->get_VehicleType() == "Truck")
			{
				truckCounter--;
			}


		
		}
		void listVehicles() {
			std::cout << " RegNumber: " << this->regNr << " Color: " << this->color << " Number of wheels: " << this->wheels <<
				" Model: " << this->model << " Electric: " << this->electric << std::endl;
		}
		void printVehicles(std::vector <Vehicle*> x) {

			for (int i = 0; i < x.size(); i++)
			{

				x[i]->listVehicles();

			}
		}
		void printAllCars(std::vector <Vehicle*> x)
		{
			for (int i = 0; i < x.size(); i++)
			{
				if (x[i]->get_VehicleType() == "Car")
				{
					x[i]->listVehicles();

				}
			}
		}
			void printAllBicycles(std::vector <Vehicle*> x)
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_VehicleType() == "Bicycle")
					{

						x[i]->listVehicles();
					}
				}
			}

			void printAllMotorCycles(std::vector <Vehicle*> x)
				{
					for (int i = 0; i < x.size(); i++)
					{
						if (x[i]->get_VehicleType() == "Motorcycle")
						{
							x[i]->listVehicles();

						}
					}
				}

			void printAllBuses(std::vector <Vehicle*> x)
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_VehicleType() == "Bus")
					{
						x[i]->listVehicles();

					}
				}
			}

			void printAllTrucks(std::vector <Vehicle*> x)
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_VehicleType() == "Truck")
					{

						x[i]->listVehicles();

					}
				}
			}


			void searchVehiclesRegNr(std::vector <Vehicle*> x, std::string y)
			{
				

				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_RegNr() == y)
					{
						std::cout << "Found Vehicle: " << std::endl;
						x[i]->listVehicles();
						break;
					}
				}
			}
	
			void searchVehiclesColor(std::vector <Vehicle*> x, std::string y)
			{


				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_Color() == y)
					{
						std::cout << "Found Vehicle: " << std::endl;
						x[i]->listVehicles();
						
					}
				}
			}

			void searchVehiclesWheels(std::vector <Vehicle*> x, int y)
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_Wheels() == y)
					{
						std::cout << "Found Vehicle: " << std::endl;
						x[i]->listVehicles();
					
					}
				}


			}
			void searchVehiclesModel(std::vector <Vehicle*> x, std::string y)
			{


				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_Model() == y)
					{
						std::cout << "Found Vehicle: " << std::endl;
						x[i]->listVehicles();
						
					}
				}
			}

			Vehicle* searchAndDestroy(std::vector <Vehicle*> &x, std::string y)
			{
				

				for (int i = 0; i < x.size(); i++)
				{
					if (x[i]->get_RegNr() == y)
					{
						
						std::cout << "Found Vehicle: " << std::endl;
						x[i]->listVehicles();
						
						delete x[i];

					
						x.erase(std::remove(x.begin(), x.end(), x[i]), x.end());
						break;
					}

				}
				return 0;
			
			}
			
	};
	

	int main()
	{

		// std::cout << "Search for RegNr: " << std::endl;
		//std::cin >> search;

		bool garageCreated = false;
		bool run = false;
		bool iValid = false;

		std::string choiceA, choiceB, choiceD, choiceE;
		int choiceC, choiceF;

		int select;
		Garage a;



		// std::cout << " This many spaces: " << a.listGarage.size() << std::endl;

	//	Vehicle* ptrCarOne = new Car("abc123", "1", 4, "Tesla", "Yes");
	 // Vehicle* ptrCarTwo = new Car("def456", "2", 4, "Volvo", "No");
	//	Vehicle* ptrBikeOne = new Bicycle("Bike", "3", 2, "Nishiki", 7);

		// ptrCarOne->set_VehicleType();			// set vehicletype to doda	
		// ptrCarOne->set_RegNr("3123");
	//	ptrCarOne->set_Model("lalala");
		//ptrCarOne->set_Electric("No");
		//ptrBikeOne->set_Model("fufuf");
		// std::cout << ptrCarOne->get_VehicleType() << std::endl;		

		//a.addVehicles(ptrCarOne);
		// a.addVehicles(ptrCarTwo);
	//	a.addVehicles(ptrBikeOne);
		// ptrCarOne->get_Wheels();
	// 	a.removeVehicles(ptrCarOne);
		// a.addVehicles(ptrCarOne);
		// a.listTypeOfVehicles();

		// a.printVehicles(a.listGarage);
		 // a.printAllCars(a.listGarage);
	//	a.printAllCars(a.listGarage);
		//a.printAllBicycles(a.listGarage);
		//std::cout << "Bicycles: " << bicycleCounter << " Cars: " << carCounter << std::endl;






		while (run == false)
		{
			std::cout << "Number of parking spaces: " << std::endl;
			std::cin >> maxLimit;

			if (std::cin.fail())
			{
				std::cin.clear(); // clears error flags
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong! Enter a #!" << std::endl;
	
			}
			else {
				run = true;
				garageCreated = true;
			}
			while (run == true)
			{
				std::cout << "\n Menu";

				std::cout << "\n========";

				std::cout << "\n 1 - Park a vehicle";

				std::cout << "\n 2 - Drive a vehicle out of the garage";

				std::cout << "\n 3 - Search for a vehicle";

				std::cout << "\n 4 - List vehicles in the garage";

				std::cout << "\n 5 - Create new garage";

				std::cout << "\n 6 - Delete existing garage";

				std::cout << "\n 7 - Exit";

				std::cout << "\n Enter selection: ";



				std::cin >> selection;
				if (std::cin.fail())
				{
					std::cin.clear(); // clears error flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max());
					std::cout << "Wrong! Enter a #!" << std::endl;
					std::cin >> selection;
				}

				switch (selection)

				{

				case 1:
				{

					std::cout << "\n What type of Vehicle? ";

					std::cout << "\n 1 - Car";

					std::cout << "\n 2 - Bicycle";

					std::cout << "\n 3 - Motorcycle";

					std::cout << "\n 4 - Truck";

					std::cout << "\n 5 - Bus";

					std::cout << "\n Enter selection: ";

					std::cin >> selectionTwo;

					if (std::cin.fail())
					{
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max());
						std::cout << "Wrong! Enter a #!" << std::endl;
						std::cin >> selectionTwo;
					}

					switch (selectionTwo)
					{
					case 1: {																															//Case 1
						std::cout << "Regnr: " << std::endl;
						std::cin >> choiceA;
						std::cout << "Color: " << std::endl;
						std::cin >> choiceB;
						std::cout << "Number of Wheels: " << std::endl;
						std::cin >> choiceC;
						std::cout << "Model: " << std::endl;
						std::cin >> choiceD;
						std::cout << "Electric? Yes/No: " << std::endl;
						std::cin >> choiceE;

						Vehicle* ptrCarOne = new Car(choiceA, choiceB, choiceC, choiceD, choiceE);
						a.addVehicles(ptrCarOne);
						a.printVehicles(a.listGarage);
					}
						  break;

					case 2:
					{
						std::cout << "Regnr: " << std::endl;
						std::cin >> choiceA;
						std::cout << "Color: " << std::endl;
						std::cin >> choiceB;
						std::cout << "Number of Wheels: " << std::endl;
						std::cin >> choiceC;
						std::cout << "Model: " << std::endl;
						std::cin >> choiceD;
						std::cout << "Number of gears: " << std::endl;
						std::cin >> choiceF;
						Vehicle* ptrBikeOne = new Bicycle(choiceA, choiceB, choiceC, choiceD, choiceF);
						a.addVehicles(ptrBikeOne);
						a.printVehicles(a.listGarage);
					}
					break;
					case 3:
					{
						std::cout << "Regnr: " << std::endl;
						std::cin >> choiceA;
						std::cout << "Color: " << std::endl;
						std::cin >> choiceB;
						std::cout << "Number of Wheels: " << std::endl;
						std::cin >> choiceC;
						std::cout << "Model: " << std::endl;
						std::cin >> choiceD;
						std::cout << "Number of gears: " << std::endl;
						std::cin >> choiceF;
						Vehicle* ptrMotorcycleOne = new Motorcycle(choiceA, choiceB, choiceC, choiceD, choiceF);
						a.addVehicles(ptrMotorcycleOne);
						a.printVehicles(a.listGarage);
					}

					break;
					case 4:
					{
						std::cout << "Regnr: " << std::endl;
						std::cin >> choiceA;
						std::cout << "Color: " << std::endl;
						std::cin >> choiceB;
						std::cout << "Number of Wheels: " << std::endl;
						std::cin >> choiceC;
						std::cout << "Model: " << std::endl;
						std::cin >> choiceD;
						std::cout << "A/M? (Automatic or Manual) " << std::endl;
						std::cin >> choiceE;

						Vehicle* ptrTruckOne = new Truck(choiceA, choiceB, choiceC, choiceD, choiceE);
						a.addVehicles(ptrTruckOne);
						a.printVehicles(a.listGarage);
					}
					break;
					case 5:
					{
						std::cout << "Regnr: " << std::endl;
						std::cin >> choiceA;
						std::cout << "Color: " << std::endl;
						std::cin >> choiceB;
						std::cout << "Number of Wheels: " << std::endl;
						std::cin >> choiceC;
						std::cout << "Model: " << std::endl;
						std::cin >> choiceD;
						std::cout << "Number of seats: " << std::endl;
						std::cin >> choiceF;

						Vehicle* ptrBusOne = new Bus(choiceA, choiceB, choiceC, choiceD, choiceF);
						a.addVehicles(ptrBusOne);
						a.printVehicles(a.listGarage);

					}
					default:
						break;
					}
					break;
				}


				break;


				case 2:																													//case 2
				{

					std::cout << "\n Type the RegNr of the Vehicle you want to remove: ";
					std::cin >> search;
					a.searchAndDestroy(a.listGarage, search);


				}
				break;


				case 3:																													//case 3
				{
					std::cout << "\n 1 - Search for a RegNr: ";
					std::cout << "\n 2 - Search for a color: ";
					std::cout << "\n 3 - Search for number of wheels: ";
					std::cout << "\n 4 - Search for a specific model: " << std::endl;

					std::cin >> selectionThree;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max());
						std::cout << "Wrong! Enter a #!" << std::endl;
						std::cin >> selectionThree;
					}


					switch (selectionThree)
					{
					case 1:
					{
						std::cout << "Type RegNr: " << std::endl;
						std::cin >> search;

						a.searchVehiclesRegNr(a.listGarage, search);


					}

					break;

					case 2:
					{
						std::cout << "Type color: " << std::endl;
						std::cin >> search;
						a.searchVehiclesColor(a.listGarage, search);

					}
					break;

					case 3:
					{
						std::cout << "Type number of wheels: " << std::endl;
						std::cin >> numberSearch;

						a.searchVehiclesWheels(a.listGarage, numberSearch);

					}
					case 4:
					{
						std::cout << "Type model: " << std::endl;
						std::cin >> search;

						a.searchVehiclesModel(a.listGarage, search);

					}
					default:
						break;
					}
					break;
				}


				break;




				case 4:																							//Case 4
				{

					std::cout << "\n 1- List all Cars ";
					std::cout << "\n 2- List all Bicycles ";
					std::cout << "\n 3- List all Motorcycles ";
					std::cout << "\n 4- List all Trucks ";
					std::cout << "\n 5- List all Buses ";
					std::cout << "\n 6- List all vehicles in the garage ";

					std::cin >> selectionFour;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max());
						std::cout << "Wrong! Enter a #!" << std::endl;
						std::cin >> selectionFour;
					}

					switch (selectionFour)
					{
					case 1:
					{
						a.printAllCars(a.listGarage);

					}
					break;
					case 2:
					{
						a.printAllBicycles(a.listGarage);

					}
					break;
					case 3:
					{
						a.printAllMotorCycles(a.listGarage);

					}
					break;
					case 4:
					{
						a.printAllTrucks(a.listGarage);

					}
					break;
					case 5:
					{
						a.printAllBuses(a.listGarage);
					}
					break;
					case 6:
					{
						a.printVehicles(a.listGarage);

					}
					default:
						break;
					}
				}

				break;

				case 5:
				{
					if (garageCreated == false)
					{
						std::vector <Vehicle*> listGarage;
						std::cout << "Number of parking spaces: " << std::endl;
						std::cin >> maxLimit;
						garageCreated = true;
					}
					else if (garageCreated == true)
					{
						std::cout << "Delete existing garage before creating a new one" << std::endl;

					}

				}
				break;
				case 6:
				{
					a.listGarage.clear();
					garageCreated = false;
					std::cout << "Garage Deleted" << std::endl;
				}
				break;
				case 7:
				{
					run = false;
					std::cout << "Exiting..." << std::endl;
				}

				break;

				default:
					std::cout << "Invalid selection" << std::endl;

				}
			}
		}
	}
/*
Cout << “Find a vehicle in the garage by adding a parameter."
<< "\n1. To find with a registration number."
<< "\n2. To find all with colour."
<< "\n3. To find all with a specified number of wheels."
<< "\n4. To find all with a minimum number of passengers."
<< "\n5. To find all with cabriolet"
<< "\n0. Exit the finding!";

*/