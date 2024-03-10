#include <iostream>
#include <vector>
#include <string>

class Car {
private:
    std::string model;
    std::string color;
    bool available;

public:
    Car(std::string model, std::string color) : model(model), color(color), available(true) {}

    std::string getModel() const {
        return model;
    }

    std::string getColor() const {
        return color;
    }

    bool isAvailable() const {
        return available;
    }

    void rentCar() {
        available = false;
    }

    void returnCar() {
        available = true;
    }
};

class CarRental {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void displayAvailableCars() const {
        std::cout << "Available Cars:" << std::endl;
        for (const auto& car : cars) {
            if (car.isAvailable()) {
                std::cout << "Model: " << car.getModel() << ", Color: " << car.getColor() << std::endl;
            }
        }
        std::cout << "---------------------------" << std::endl;
    }

    Car* rentCar(const std::string& model) {
        for (auto& car : cars) {
            if (car.getModel() == model && car.isAvailable()) {
                car.rentCar();
                return &car;
            }
        }
        return nullptr;
    }

    void returnCar(Car* car) {
        if (car != nullptr) {
            car->returnCar();
            std::cout << "Car returned successfully" << std::endl;
        } else {
            std::cout << "Car not found or already returned" << std::endl;
        }
    }
};

int main() {
    CarRental rentalSystem;

    rentalSystem.addCar(Car("Toyota Sedan", "Black"));
    rentalSystem.addCar(Car("Maruti Suzuki Swift", "White"));
    rentalSystem.addCar(Car("Toyota Innova", "White"));
    
    int choice;
    
     while (true) {
         std :: cout <<"1. Display Available Cars\n2. Rent a Car\n3. Return a Car\n4. Exit\n";
         std :: cout <<"Enter your choice: ";
         std :: cin >> choice ;

         switch(choice){
             case 1:
                 rentalSystem.displayAvailableCars();
                 break;

             case 2:{
                 std :: string rentModel ;
                 std :: cout <<"Enter the car model to rent: ";
                 std :: cin.ignore();
                 getline(std :: cin, rentModel);

                 Car* rentedCar = rentalSystem.rentCar(rentModel);
                 if(rentedCar != nullptr){
                     std :: cout <<"Car rented successfully: " << rentedCar->getModel() <<std :: endl ;
                 } else{
                     std :: cout <<"Car not available" <<std :: endl ;
                 }
                 break ;
             }

             case 3:{
                  std :: string returnModel ;
                  std :: cout <<"Enter the car model to return: ";
                  std :: cin.ignore();
                  getline(std :: cin, returnModel);

                  Car* carToReturn = rentalSystem.rentCar(returnModel);
                  rentalSystem.returnCar(carToReturn);
                  break ;
              }

              case 4:
                   std :: cout <<"Exiting....."<<std :: endl ;
                   return 0 ;

               default :
                   std :: cout <<"Invalid Choice"<<std :: endl ;
          }
      }

      return 0 ;
}