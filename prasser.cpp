#include <iostream>
#include <fstream>

std::fstream plik;
void open_file(){
    if plik.open("solar_panel_data_20240522.json",std::ios::in ){
        std::cout<<"File opened succesfully"<<std::endl;
        else{
            std::cout<<"Error"<<std::endl;
        }
    }
}


