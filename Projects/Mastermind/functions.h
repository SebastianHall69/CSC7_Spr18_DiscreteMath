/* 
 * File:   functions.h
 * Author: Sebastian Hall
 * Created on April 26, 2018, 1:02 AM
 * Purpose: Hold The Function Declarations For V1 Of The Mastermind Project
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>   //For Strings



//Function Declarations


/*
 **************************************************************************
 * Displays The Current Screen Of The Game Along With The Current Number  *
 * Of Correct Colors And Positions For The Current Round                  *
 **************************************************************************
 */
void gmeScrn(std::string [],std::string [],std::string [],
             std::string [],std::string [],std::string [],
             std::string [],std::string [],std::string [],
             short,short);


/*
 **************************************************************************
 * Displays The Colors Of The Array In The Center Of The Four Circles To  *
 * Build The Current Gameboard Display                                    *
 **************************************************************************
 */
void circle(std::string []);


/*
 **************************************************************************
 * Goes Through The Color Picking And Playing Of A Singular Round Of      *
 * The Mastermind Game, Calls Functions To Update Correct Values          *
 **************************************************************************
 */
void round(std::string [],std::string [],short &,short &);


/*
 **************************************************************************
 * Uses Random Number Generation To Randomly Select Colors For The Key    *
 **************************************************************************
 */
void setWin(std::string []);


/*
 **************************************************************************
 * Checks The Users Current Round Answers Against The Answer Key And      *
 * Counts The Number Of Circles With The Right Position And The Number    *
 * Of Circles With The Correct Color, But Not Position                    *
 **************************************************************************
 */
void chckAns(std::string [],std::string [],short &,short &);


/*
 **************************************************************************
 * Lazy And Bad Programming At It's Finest. Don't Judge                   *
 **************************************************************************
 */
void wchRow(std::string [],std::string [],std::string [],
            std::string [],std::string [],std::string [],
            std::string [],std::string [],std::string [],
            short &,short &,short);

#endif /* FUNCTIONS_H */