/*
ID: ericm101
LANG: C++
TASK: palsquare
*/

/*
This program will take a number in represented in base 10 and
find all the values from 1 to 300 whose squares are palindromic when
represented in the base of the number read in. Each number, along with
its square will then be printed out in the specified base.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// This function is used to represent digits larger than 9 as letters
void extra_digits(vector<string> & palind, int temp){
	switch (temp){
		case 10:
			palind.push_back("A");
			break;
		case 11:
			palind.push_back("B");
			break;
		case 12:
			palind.push_back("C");
			break;
		case 13:
			palind.push_back("D");
			break;
		case 14:
			palind.push_back("E");
			break;
		case 15:
			palind.push_back("F");
			break;
		case 16:
			palind.push_back("G");
			break;
		case 17:
			palind.push_back("H");
			break;
		case 18:
			palind.push_back("I");
			break;
		default:
			palind.push_back("J");
			break;
	}
}

int main(){
	ifstream in("palsquare.in");
	int base, start, begin;
	// read in the specified base
	in >> base;

	// This switch is simply used to make a starting point when converting
	// numbers from base 10 to the specified base
	switch (base){
		case 2: 
			start = 16;
			begin = 7;
			break;
		case 3:
			start = 10;
			begin = 5;
			break;
		case 4: 
			start = 8;
			begin = 3;
			break;
		case 5:
			start = 7;
			begin = 3;
			break;
		case 6: 
			start = 6;
			begin = 2;
			break;
		case 7:
			start = 5;
			begin = 2;
			break;
		default:
			start = 4;
			begin = 2;
			break;	
	} // switch

	

	ofstream out("palsquare.out");
	for (int i = 1; i <= 300; ++i){
		bool first = false, ispal = true;
		vector<string> palind;
		int num = pow(i, 2), temp;
		for (int k = start; k >= 0; --k){
			if (pow(base, k) <= num){
				temp = num / pow(base, k);
				if (temp >= 10){
					extra_digits(palind, temp);
				}else{
					stringstream ss;
					ss << temp;
					string tempstring = ss.str();
					palind.push_back(tempstring);
				}
				num -= temp * pow(base, k);
				first = true;
			}else if (first){
				stringstream ss;
				ss << 0;
				string tempstring = ss.str();
				palind.push_back(tempstring);
			}
		}
		for (unsigned d = 0; d <= palind.size() / 2; ++d){
			if (palind[d] != palind[palind.size() - d - 1]){
				ispal = false;
				break;
			}
		}

		if (ispal){
			int num2 = i, temp2;
			bool f = false;
			vector<string> pal;
			for (int k = begin; k >= 0; --k){
				if (pow(base, k) <= num2){
					temp2 = num2 / pow(base, k);
					if (temp2 >= 10){
						extra_digits(pal, temp2);
					}else{
						stringstream ss;
						ss << temp2;
						string tempstring = ss.str();
						pal.push_back(tempstring);
					}
					num2 -= temp2 * pow(base, k);
					f = true;
				}else if (f){
					stringstream ss;
					ss << 0;
					string tempstring = ss.str();
					pal.push_back(tempstring);
				}
			}
			
			for (unsigned d = 0; d < pal.size(); ++d){
				out << pal[d];
			}
			out << " ";
			
			for (unsigned d = 0; d < palind.size(); ++d){
				out << palind[d];
			}
			out << endl;
			
		}
	}
	return 0;
} // main