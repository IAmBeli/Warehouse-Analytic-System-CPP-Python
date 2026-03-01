#include<string>
#include<iostream>
#include<vector>
#include<fstream>
class Part{
    private:
        std::string name;
        int id;
        double price;
        int quantity;
    public:
    int getId(){return id;}
    int getQuantity(){return quantity;}
    std::string getName(){return name;}
    double getPrice(){return price;}
    Part(std::string name, int id, double price, int quantity) : name(name), id(id), price(price), quantity(quantity){}
    void addQuantity(int amount){
        quantity += amount;
    }
    void sell(int amount){
        if(quantity >= amount){
            quantity -= amount;
            std::cout << "Thank you for your purchase!" << '\n';
        }else{std::cout << "Sorry, there are not enough of this product" << '\n';}
    }
    void display(){       
        std::cout << "Name of the part: " << name << '\n';
        std::cout << "Id: " << id << '\n';
        std::cout << "Price is: " << price << '\n';
        std::cout << "Quantity: " << quantity << '\n';
    }
};
int main(){
    std::vector<Part> warehouse;
    std::ifstream inFile("c:\\works\\dataprices.txt");
    if(inFile.is_open()){
        std::string name;
        int id;
        double price;
        int quantity;
        while(inFile >> name >> id >> price >> quantity){
            if(name. empty()){continue;}
            warehouse.push_back(Part(name, id, price, quantity));
        }
    }
    inFile.close();
    std::cout << "Successfully loaded: " << warehouse.size() << " items from the file.\n";
    std::string UName;
    int UId;
    double UPrice;
    int UQuantity;
    char choice;
    do{
        std::cout << "Print name of the part: " << '\n';
        std::cin >> UName;
        bool found = false;
        for(Part &p : warehouse){
            if(p.getName() == UName){
                found = true;
                std::cout << "Found existing part! Current quantity is: " << p.getQuantity() << '\n';
                std::cout << "Do you want to add more to already existing quantity?(Y/N)?: ";
                char answer;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    std::cout << "Input amount to add: ";
                    int amount;
                    std::cin >> amount;
                    p.addQuantity(amount);
                }
                break;
            }
        }
        if(!found){std::cout << "Print ID of " << UName << ": " << '\n';
        std::cin >> UId;
        std::cout << "Print price of " << UName << ": " << '\n';
        std::cin >> UPrice;
        std::cout << "Print quantity of " << UName << ": " << '\n';
        std::cin >> UQuantity;
        warehouse.push_back(Part(UName, UId, UPrice, UQuantity));}
        std::cout << "Do you want to input another detail(Y/N)?: ";
        std::cin >> choice;
    }while(choice == 'Y' || choice == 'y');

    for(Part &p : warehouse){
        p.display();
    }
    std::ofstream outFile("c:\\works\\dataprices.txt");
    if(outFile.is_open()){
        for(Part &p : warehouse){
            outFile << p.getName() << " " << p.getId() << " " << p.getPrice() << " " << p.getQuantity() << '\n';
        }
    }
    outFile.close();
    if(outFile.is_open()){
        std::cout << "Error while saving data to dataprices.txt" << std::endl;
    }else{std::cout << "All data(old + new) is saved in dataprices.txt" << std::endl;}
    return 0;
}