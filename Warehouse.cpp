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
    int getQuantity(){return quantity;}
    std::string getName(){return name;}
    double getPrice(){return price;}
    Part(std::string name, int id, double price, int quantity) : name(name), id(id), price(price), quantity(quantity){}
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
    std::string UName;
    int UId;
    double UPrice;
    int UQuantity;
    char choice;
    do{
        std::cout << "Print name of the part: " << '\n';
        std::cin >> UName;
        std::cout << "Print ID of " << UName << ": " << '\n';
        std::cin >> UId;
        std::cout << "Print price of " << UName << ": " << '\n';
        std::cin >> UPrice;
        std::cout << "Print quantity of " << UName << ": " << '\n';
        std::cin >> UQuantity;
        warehouse.push_back(Part(UName, UId, UPrice, UQuantity));
        std::cout << "Do you want to input another detail(Y/N)?: ";
        std::cin >> choice;
    }while(choice == 'Y' || choice == 'y');

    for(Part &p : warehouse){
        p.display();
        //p.sell(3);
    }
    std::ofstream outFile("dataprices.txt");
    if(outFile.is_open()){
        for(Part &p : warehouse){
            outFile << p.getName() << " " << p.getPrice() << " " << p.getQuantity() << '\n';
        }
    }
    outFile.close();
    if(outFile.is_open()){
        std::cout << "Error while saving data to dataprices.txt" << std::endl;
    }else{std::cout << "Data is saved in dataprices.txt" << std::endl;}
    return 0;
}