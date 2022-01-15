#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int c =0;
class Product{
    
    public : 
        int id;
        string name;
        int price;
        int count;
        
    Product(){
        cout << "Enter Product#"<<c<<" ID : ";
        cin>> this->id;
        cout << "Enter Product#"<<c<<" name : ";
        cin>> this->name;
        cout << "Enter Product#"<<c<<" price : ";
        cin>> this->price;
        cout << "Enter Product#"<<c<<" count : ";
        cin>> this->count;
    }   
    int EditMenu(){
        cout <<"what do you want to edit ?"<<endl;
        cout<<"1- Edit id"<<endl;
        cout<<"2- Edit name"<<endl;
        cout<<"3- Edit price"<<endl;
        cout<<"4- Edit count"<<endl;
        int i;
        cin>>i;
        return i;
    }
    void Edit(){
        switch(EditMenu ()){
            case 1: cout << "Enter Product ID : ";
            cin>> this->id;
            break;
            
            case 2: cout << "Enter Product name : ";
            cin>> this->name;
            break;
            
            case 3: cout << "Enter Product price : ";
            cin>> this->price;
            break;
            
            case 4: cout << "Enter Product count : ";
            cin>> this->count;
            break;
            
        }
        
    }
    static int search();
    void ShowDetails(){
        cout << this->name<<endl;
        cout << "id : "<<this->id<<endl;
        cout << "price : "<<this->price<<endl;
        cout << "count : "<<this->count<<endl;
    }
    static void Delete();
    static void Buy();
};


int MainMenu(){
    cout << "1- Add product "<<endl;
    cout << "2- Edit product "<<endl;
    cout << "3- Search product "<<endl;
    cout << "4- Delete a product "<<endl;
    cout << "5- Buy " << endl;
    
    int i;
    cin >> i ;
    return i;
    
}

vector <Product> products;
int main() {
    
    
    
    while(true){
    
    switch(MainMenu()){
        case 1: 
        {
            c++;
            Product buf;
            products.push_back(buf);
            break;
        }
        case 2:
        {
            int index = Product::search();
            if (index == -1 )
            {
                cout << "Product Not Found!" <<endl;
                break;
            }
            products[index].Edit();
            break;
        }
        case 3: 
        {
            int index = Product::search();
            if (index == -1 )
            {
                cout << "Product Not Found!" <<endl;
                break;
            }
            products[index].ShowDetails();
            break;
        }   
        case 4:{ 
            Product::Delete();
            break ;
        }
        case 5:{
            Product::Buy();    
        }
    }
}
    
    return 0;
}




int Product:: search(){
            cout <<"Enter product id :";
        int Id;
        cin>>Id;
        for(int i =0 ;i<c;i++)
            if(Id == products[i].id)
                return i;
        return -1;
}
void Product :: Delete(){
        int index = Product::search();
        if (index == -1 )
        {
            cout << "Product Not Found!" <<endl;
        }
        else {
            products.erase(products.begin() + index);
            cout << "Product was deleted succesfully!"<<endl;
            c--;
        }
    }
void Product :: Buy()  {
        int factor [1000][2] ;
        int n = 0 ;
        while (true) {
            int index = Product::search();
            if (index == -1 )
            {
                cout << "Product Not Found!" <<endl;    
                continue;
            }
            else if (products[index].count == 0 ) 
            {
                cout << "We are out of supplies for this product !"<<endl;
                continue;
            }
            else 
                {
                    cout << "How many " << products[index].name << "s do you want ? : ";
                    int c;
                    cin >> c;
                    if (c > products[index].count )
                    {
                        cout << "we dont have that many !"<<endl;
                        cout << "1 - buy all we have " <<endl;
                        cout << "2 - dont buy this item !"<<endl;
                        int i;
                        cin >> i;
                        if(i == 1)
                        {
                            factor[n][0] = index ;
                            factor[n][1] = products[index].count;
                            n++;
                            cout << "1- Buy more items " <<endl;
                            cout << "2- print the factor " << endl;
                            cin >> i;
                            if (i == 1)
                                continue;
                            else
                                break;                            
                        }
                        else 
                            continue;
                    }
                    else if (c <= products[index].count)
                    {
                        products[index].count -= c;
                        factor[n][0] = index ;
                        factor[n][1] = c;
                        n++;
                        cout << "1- Buy more items " <<endl;
                        cout << "2- print the factor " << endl;
                        int i;
                        cin >> i;
                        if (i == 1)
                            continue;
                        else
                            break;
                    }
                }
        }

        cout << "Factor : "<<endl;   
        
        for (int i=0 ; i<n ; i++)
        {
            cout << products[factor[i][0]].name <<"\t" << factor[i][1] << "\t" << products[factor[i][0]].price *  factor[i][1]<<endl;
        }
        ofstream FactorFile("Factor.txt");
        for (int i=0 ; i<n ; i++)
        {
            FactorFile << products[factor[i][0]].name <<"\t" << factor[i][1] << "\t" << products[factor[i][0]].price *  factor[i][1]<<endl;
        }

        FactorFile.close();
        exit(0);
   }