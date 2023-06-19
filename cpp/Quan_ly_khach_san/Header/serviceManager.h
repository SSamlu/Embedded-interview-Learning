#ifndef __SERVICE_MANAGER_H
#define __SERVICE_MANAGER_H
/**
 * Class: Service
 * Description: this is Service class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Service {
  private:
    string name;
    string description;
    double price;
  public:
    Service(string name, string description, double price);
    string getName();
    string getDescription();
    double getPrice();

    void setName(string nameService);
    void setDescription(string descriptionService);
    void setPrice(double price);
};

/**
 * Class: ServiceManager
 * Description: this is ServiceManager class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class ServiceManager {
  private:
    vector<Service> databaseServices;
  public:
    void addService();
    void editService();
    void removeService();
    void displayService();
};
#endif
