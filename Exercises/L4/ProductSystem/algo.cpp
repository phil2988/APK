/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

#include <fstream>
#include <iostream>
#include <iterator>

#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>

#include <sstream>
#include <string.h>

#define PRODUCT_DB_FILE		"product.db"

class Product
{
public:
  Product(const std::string& name, float price, unsigned int sold = 0)
    : name_(name), price_(price), sold_(sold)
  {}
  Product()
    : name_(""), price_(0), sold_(0)
  {}
  
  const std::string& name() const
  {
    return name_;
  }
  
  float price() const
  {
    return price_;
  }

  void setPrice(float newPrice)
  {
    price_ = newPrice;
  }
  
  unsigned int sold() const
  {
    return sold_;
  }
  
  friend std::istream& operator>> ( std::istream& i, Product& p );
  friend std::ostream& operator<< ( std::ostream& o, const Product& p );
  friend std::vector<std::string>& operator<< ( std::vector<std::string>& o, const Product& p );
  
private:
  std::string   name_;
  float         price_;
  int           sold_;
};
typedef std::vector<Product>  ProductList;

std::vector<std::string>& operator<< ( std::vector<std::string>& o, const Product& p )
{ 
  std::string returnString;
  returnString.append(p.name_);

  std::ostringstream ss;
  ss.clear();

  ss << " " << p.price_ << " " << p.sold_;

  returnString.append(ss.str());

  o.push_back(returnString);
  return o;
}

std::ostream& operator<< ( std::ostream& o, const Product& p )
{ 
  return o << p.name_ << " " << p.price_ << " " << p.sold_; 
}

std::istream& operator>> ( std::istream& i, Product& p )
{
    return i >> p.name_ >> p.price_ >> p.sold_;
}



/**
 * Read products from file
 */
void productDBRead(ProductList& pl, const std::string& fileName)
{
  pl.clear();

  // Define the fileStream object used to read data from file
  std::ifstream pFile( fileName.c_str() );

  // Get input stream and end of stream iterators
  std::istream_iterator<Product> it(pFile);
  std::istream_iterator<Product> eos;

  // Copy elements from input to vector using copy function
  std::copy(it, eos, std::back_inserter(pl));
}


/**
 * Printout all products
 */
void printAll(const ProductList& pl)
{
  std::vector<std::string> outputVector;
  
  outputVector.push_back("##################################################");
  outputVector.push_back("Printing out all products...");
  outputVector.push_back("----------------------------");
  for(ProductList::const_iterator iter = pl.begin(); iter != pl.end(); ++iter)
  {
    outputVector << *iter;
  }  
  outputVector.push_back("##################################################");

  std::ostream_iterator<std::string> os(std::cout, "\n");
  std::copy(outputVector.begin(), outputVector.end(), os);
}

/**
   Add item
*/
void addItem(ProductList& pl)
{
  std::string input;
  std::cout << "Enter name of product:" << "\n";
  std::cin >> input;
  std::string pName = input;
  std::cout << "Name of product is: " << pName << "\n";

  std::cout << "Enter price of product:" << "\n";
  std::cin >>  input;
  float pPrice = std::stof(input);
  std::cout << "Name of product is: " << pPrice << "\n";

  std::cout << "Enter amount sold :" << "\n";
  std::cin >>  input;
  int pSold = std::stoi(input);
  std::cout << "Amount sold: " << pSold << "\n";

  pl.push_back(Product(pName, pPrice, pSold));
}

/**
   Write data to db file
*/
void productDBWrite(const ProductList& pl, const std::string& fileName)
{
  std::ofstream pFile( fileName.c_str() );
  std::ostream_iterator<Product> it(pFile, "\n");

  std::copy(pl.begin(), pl.end(), it);
}

bool hasMoreThanTenSold(Product p){
  return p.sold() > 10;
}

/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList& pl)
{
  std::vector<std::string> outputVector;
  
  outputVector.push_back("##################################################");
  outputVector.push_back("Printing out products with less than 10 sold...");
  outputVector.push_back("----------------------------");

  std::vector<Product> rpl(pl.capacity());
  
  std::remove_copy_if(pl.begin(), pl.end(), rpl.begin(), hasMoreThanTenSold);

  for(ProductList::const_iterator iter = rpl.begin(); iter != rpl.end(); ++iter)
  {
    // Filters off undefined products
    std::string s;
    if(iter.base()->name().compare(s))
      outputVector << *iter;
  }  

  outputVector.push_back("##################################################");
  std::ostream_iterator<std::string> os(std::cout, "\n");
  std::copy(outputVector.begin(), outputVector.end(), os);
}

/**
 * Set a discount on all products - Using for_each()
 */
void addDiscountUsingForEach(ProductList& pl)
{
  std::for_each(pl.begin(), pl.end(), [](Product& p) -> void {
    p.setPrice(p.price()/100*90);
  });
}

/**
 * Set a discount on all products - Using transform()
 */
void addDiscountUsingTransform(ProductList& pl)
{
}


/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(ProductList& pl)
{
}


/**
 * Setting discount using bind2nd - OPTIONAL
 */


int main()
{
  bool        running = true;
  ProductList pl;
  
  while(running)
  {
    char choice;
    
    std::cout << "********************" << std::endl;
    std::cout << "Help menu: " << std::endl;
    std::cout << "'1' Read product database" << std::endl;
    std::cout << "'2' Print all items" << std::endl;
    std::cout << "'3' Add item" << std::endl;
    std::cout << "'4' Write product database" << std::endl;
    std::cout << "'5' Print poorly selling products" << std::endl;
    std::cout << "'6' Set a discount on all products (using for_each() )" << std::endl;
    std::cout << "'7' Set a discount on all products (using transform() )" << std::endl;
    std::cout << "'8' Calculate the total amount of sold products" << std::endl;
    
    
    std::cout << "'q' Quit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    
    switch(choice)
    {
      case '1':
        productDBRead(pl, PRODUCT_DB_FILE);
        break;

      case '2':
        printAll(pl);
        break;

      case '3':
        addItem(pl);
        break;

      case '4':
        productDBWrite(pl, PRODUCT_DB_FILE);
        break;

      case '5':
        printPoorlySellingProducts(pl);
        break;
        
      case '6':
        addDiscountUsingForEach(pl);
        break;

      case '7':
        addDiscountUsingTransform(pl);
        break;

      case '8':
        calcTotalSoldProducts(pl);
        break;
        
      case 'q':
      case 'Q':
        running = false;
    }
    
    
  }
}
