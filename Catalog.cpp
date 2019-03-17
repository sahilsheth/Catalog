//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<fstream>
#include	<iostream>
#include	<string>



#include	"Catalog.h"

using namespace std;


bool	Catalog::AddCategory(uint64_t categoryNumber, const string& name)
{
	// to be completed

		//add it to the catalog
		//creTE A NEW struct of type cat and put name in there.
		if(myCatalog.find(categoryNumber) != myCatalog.end())
		{
			return false;
		}
		else
		{
			Cat &c = myCatalog[categoryNumber];
			c.catNam= name;
			myCatalog[categoryNumber]=c;
			catalogCount++;

		//Cat *c = new Cat();
		//c->catNam = name;
  //map<uint64_t, Cat*>::value_type CategoryMapValue(categoryNumber,c);
    //myCatalog.insert(CategoryMapValue);

		//catalogCount++;


			return true;
	}
}

bool	Catalog::AddProduct(uint64_t categoryNumber, uint64_t productNumber, const string& name)
{
	// to be completed
		//add the product to the catalog
		//choco = myCatalog.find(categoryNumber, productNumber, name);
		//choco++;
		//myCatalog[categoryNumber].products.insert(productNumber, name);
		if(myCatalog.find(categoryNumber) == myCatalog.end() && myCatalog.find(productNumber) != myCatalog.end())
		{
			return false;
		}
		else
		{


			Cat &m =myCatalog[categoryNumber];
			m.products[productNumber]=name;



		return false;
	}
	return true;
}

uint64_t	Catalog::GetCategoryCount()
{
	// to be completed
	//return catalogCount;
	return myCatalog.size();

}

int64_t	Catalog::GetProductCount(uint64_t categoryNumber)
{
	// to be completed
	//return 1;
	if(myCatalog.find(categoryNumber) == myCatalog.end())
	{
		return -1;
	}
	else
	{
		Cat n;
    n = myCatalog[categoryNumber];
    return n.products.size();

	}
}

bool	Catalog::Load(const string& fileName)
{
	fstream  myfile(fileName.c_str());
  if(myfile.is_open())
  {
    string line;
		uint64_t categoryNumber;
		//uint64_t productNumber;
    cout << "Successfully opened up file" <<endl;
		//catalogCount=0;
    while(getline(myfile,line))
    {
			stringstream the_thing(line);
			string first;
			getline(the_thing, first, '\t');
			if(first == "")
			{
				continue;
			}
			if(first == "Category")
			{
				string word1;
				getline(the_thing, word1, '\t');
				categoryNumber = stoi(word1);
				string word2;
				getline(the_thing, word2);
				//AddCategory(stoi(w1), w2);
				//cout << "bye" << endl;
				AddCategory(categoryNumber, word2);

			}
			else if (first != "Category")
			{

					string m1;
					getline(the_thing, m1, '\t');
					AddProduct(categoryNumber, stoi(first), m1);
			}

		}
  }
	return true;
}


//****************************************************************************************
//
//	Show... methods
//
//	The stream argument allows thess functions to write its output to any output stream,
//	such as cout or a file, that the caller passes. The argument's name "stream" should
//	be used just as you would use "cout":
//
//		stream << "X = " << x << endl;
//
//	The output will go where the caller intended without special action by this function.
//
//****************************************************************************************

bool	Catalog::ShowProduct(ostream& stream, uint64_t categoryNumber, uint64_t productNumber)
{
	// to be completed
	Cat category;
	map <int, string>::iterator itProd;

	if(myCatalog.find(categoryNumber) == myCatalog.end() || myCatalog.find(productNumber) == myCatalog.end())
	{
		return false;
	}
	else
	{
	itProd = category.products.begin();
	while (itProd != category.products.end())
		  {
   		//show products in order
		 stream << itProd->first << '\t' << itProd -> second << endl;
		 itProd++;		return true;
		 } 

	}
	return false;
}

bool	Catalog::ShowCategory(ostream& stream, uint64_t categoryNumber)
{
	// to be completed
	if (myCatalog.find(categoryNumber) == myCatalog.end())
	{
		return false;
}
else
{
	Cat category;
	map <int, string>::iterator itProd;
	map< uint64_t, Cat>::iterator itCat;
	category = myCatalog[categoryNumber];
	stream <<"Category"<< '\t' << categoryNumber << '\t' << category.catNam << endl;
	itProd = category.products.begin();
	while (itProd != category.products.end())
  {
            stream << itProd->first << '\t' << itProd->second << endl;
						//stream <<  itProd->first << endl;

            ++itProd;
  }
}

	return true;
}

bool	Catalog::ShowAll(ostream& stream)
{
	// to be completed
	//while(choco != myCatalog.end())
	//{

		//ShowCategory(stream, categoryNumber);
		//choco++;

	//}
map<uint64_t, Cat>::iterator itCat;
map <int, string>::iterator itProd;

// Prints each category and all of the products under it
//stream << myCatalog.size() << endl;
//stream << "Category" << '\t' << GetCategoryCount() << '\t'<< "Category One" << endl;
//check catalog size=0?
	if (myCatalog.size() == 0)
{
	return false;
}

for (itCat = myCatalog.begin(); itCat != myCatalog.end(); ++itCat)
{
    //stream << "Category data (catNum & catName): ";

    stream << "Category" << '\t' << itCat->first << '\t' << itCat->second.catNam << endl;

    //stream << "\nShow all products for category " << itCat->first << ":" << endl;

    //itProd = itCat->second.products.begin();
		//stream << "Category" << '\t' << GetCategoryCount() << '\t'<< "Category Two" << endl;

    for (itProd = itCat->second.products.begin(); itProd != itCat->second.products.end(); ++itProd)
    {
        stream << itProd->first << '\t' << itProd->second << endl;
    }

}
	return true;
}
