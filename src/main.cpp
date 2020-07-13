#include <iostream>
#include "linear_regression.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {

    string train = argv[1];
    string test = argv[2];
    string output = argv[3];

    ifstream file;
	file.open(train);
    string line;
    getline(file, line);

    string curSlotTrain;
    string slotsTrain = line;

    vector<vector<string>> trains; 

    while (!file.eof()) {

        getline(file, line);
        slotsTrain = line;

        if (line.length() > 0) {
            vector<string> curLineTrain(23);  //train tiene 23 columnas
            for (int i = 0; i < 23; ++i) {

                if (slotsTrain[0] == '"') {    
                    slotsTrain = slotsTrain.substr(1,slotsTrain.size()-2); //nos deshacemos del primer "
					int endSlot = slotsTrain.find('"');
    				
    				if (endSlot == -1) {  //caso en el que abren " y no lo cierran dentro del mismo line
        				curSlotTrain = slotsTrain;
			        	while (endSlot == -1) {
            				getline(file, line);
					        slotsTrain = line;
				            endSlot = slotsTrain.find('"');
            				if (endSlot != -1) {
					            slotsTrain = slotsTrain.substr(0, endSlot);
					        }
            				curSlotTrain = curSlotTrain + slotsTrain;
					    }
					    slotsTrain = line.substr(endSlot + 2);
					} else {
    					string curSlotTrain = slotsTrain.substr(0, endSlot);  //ponemos al slot en curslot
    					slotsTrain = slotsTrain.substr(endSlot + 2);
					}

				    
                } else {
                    int endSlot = slotsTrain.find(",");  //buscamos siguiente slot
                    curSlotTrain = slotsTrain.substr(0, endSlot);  //ponemos en curSlot el slot
                    slotsTrain = slotsTrain.substr(endSlot + 1);  
                }
                curLineTrain[i] = curSlotTrain;
            }

            trains.push_back(curLineTrain);
        }
    }

    file.close();

    Matrix trainMatrix = Matrix(trains.size(), 16); //16 son los topicos que nos interesan
    for (unsigned int i = 0; i < trains.size(); ++i) {
 	   unsigned int j = 0;
   		for (unsigned int k = 7; k < trains[i].size(); k++) {
       		if(trains[i][k].length()>0){
       			trainMatrix(i,j)=stod(trains[i][k]);
			}else{
       			trainMatrix(i,j) = 0;
			}
        	j++;	 
		}
    }




    ifstream file2;
    file2.open(test);
    string line2;
    getline(file2, line2);

    string curSlotTest;
    string slotsTest = line2;

    vector<vector<string>> tests; 

    while (!file.eof()) {

        getline(file2, line2);
        slotsTest = line2;

        if (line.length() > 0) {
            vector<string> curLineTest(22); //en test son 22
            for (int i = 0; i < 22; ++i) {

                if (slotsTest[0] == '"') {
                    slotsTest = slotsTest.substr(1,slotsTest.size()-2); 
					int endSlotTest = slotsTest.find('"');
    				if (endSlotTest == -1) {
        				curSlotTest = slotsTest;
			        	while (endSlotTest == -1) {
            				getline(file, line);
					        slotsTest = line;
				            endSlotTest = slotsTest.find('"');
            				if (endSlotTest != -1) {
					            slotsTest = slotsTest.substr(0, endSlotTest);
					        }
            				curSlotTest = curSlotTest + slotsTest;
					    }
					    slotsTest = line.substr(endSlotTest + 2);
					} else {
    					string curSlotTest = slotsTest.substr(0, endSlotTest);
    					slotsTest = slotsTest.substr(endSlotTest + 2);
					}

				    
                } else {
                    int endSlotTest = slotsTest.find(",");
                    curSlotTest = slotsTest.substr(0, endSlotTest);
                    slotsTest = slotsTest.substr(endSlotTest + 1);
                }
                curLineTest[i] = curSlotTest;
            }

            tests.push_back(curLineTest);
        }
      }
    

    file.close();

    Matrix XTest = Matrix(tests.size(), 15);
    for (unsigned int i = 0; i < tests.size(); i++) {
        unsigned int j = 0;
   		for (unsigned int k = 7; k < tests[i].size(); k++) {
       		if(tests[i][k].length()>0){
       			XTest(i,j)=stod(trains[i][k]);
			}else{
       			XTest(i,j) = 0;
			}
        	j++;
   			 
		}
    }

    Matrix XTrain = trainMatrix.conservativeResize(trainMatrix.rows(),trainMatrix.cols()-1);
    Matrix xTrain = XTrain;
    xTrain.conservativeResize(xTrain.rows(), 2);
    Matrix yTrain = trainMatrix.col(trainMatrix.cols()-1); //precio
 
    Matrix xTest = XTrain;
    xTest.conservativeResize(xTest.rows(), 2);

    LinearRegression lr = LinearRegression();
    lr.fit(xTrain, yTrain);
    Vector y = lr.predict(xTest);

   return 0;
}
