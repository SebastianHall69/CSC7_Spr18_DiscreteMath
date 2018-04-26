/* 
 * File:   Functions.h
 * Author: Sebastian Hall
 *
 * Created on April 11, 2018, 12:44 PM
 */




#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>   //Self Explanatory
#include <vector>   //Vector To Hold Food Strings


/*
 * ***********************************************
 * addFood Function Allows The User To Add A New *
 * Meal Into The List Of Already Available Food  *
 * Items Separated Into Meal Options             *
 * ***********************************************
 */
void addFood();




/*
 * *******************************************
 * svFood Function Saves New Meal Into Files *
 * *******************************************
 */
void svFood(std::string,std::string);




/*
 * **********************************************************
 * enumTxt Function Returns Character Representation Of The * 
 * Enumerated Choice Made When Selecting A Food To Add      *
 * **********************************************************
 */
std::string enumTxt(short);



/*
 * *******************************************
 * fileIn Function For Title And Menu String *
 * *******************************************
 */
void strngIn(std::string &,std::string &);



void vectIn(std::string,std::vector<std::string> &);




void fillVec(std::vector<std::string> &,std::vector<std::string> &
            ,std::vector<std::string> &,std::vector<std::string> &);




void foodOpt(const std::vector<std::string> &);



void as();


/*
 * ********************************************
 * Input Function For Menu Exception Handling *
 * ********************************************
 */
void input(short &);

#endif /* FUNCTIONS_H */