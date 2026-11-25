#pragma once
#include <iostream>
#include <string>
using namespace std;

// input
int readInt();
double readDouble();
string readText();
bool readYesNo();
void pressEnter();

// output
void printLeft(string text, int width);
void printRight(string text, int width);
string formatPrice(double price);
void printTitle(string title);
