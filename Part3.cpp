#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////


int ForwardSearch(double n, double BV, double TBV, double BI, double* A, double* BA)
{

	//Variables
	double tempindex = 0;
	int counter = 1;
	double FeatureCounter = 0;
	double FinalValue = -1;
	double TempFinalValue = -1;


	//Initialize BA array
	for (int i = 0; i < n + 1; i++) {
		BA[i] = 0;
	}

	// Initial Case
	cout << "Using no features and random evaluation, I get an accuracy of ";
	FinalValue = A[0];
	cout << A[0];
	cout << "%" << endl << endl;

	//Best values
	BA[0] = 0;
	BI = 0;
	BV = A[0];
	TBV = BV;
	cout << "Beginning search." << endl << endl;



	//Begin Searching features
	for (int j = 0; j < n; j++) {
		TempFinalValue = -1;

		for (int i = 0; i < n - j; i++)
		{

			//Output features
			cout << "	Using feature(s) {";
			for (int l = 1; l < BI + 1; l++)
			{
				if (j != 0)
				{
					cout << BA[l] << ",";
				}
			}

		label:
			for (int m = 0; m < n; m++)
			{
				if (BA[m + 1] == i + 1 + FeatureCounter)
				{

					FeatureCounter++;
					goto label;
				}

			}

			cout << i + 1 + FeatureCounter << ",";
			cout << "} accuracy is " << A[counter] << "%" << endl;

			//Check if best
			if (A[counter] > BV)
			{
				BV = A[counter];

				if (BV > FinalValue)
				{
					FinalValue = BV;
					TempFinalValue = 1;
				}


				BA[j + 1] = i + 1 + FeatureCounter;
			}
			counter++;
			FeatureCounter = 0;

		}

		if (TempFinalValue != 1)
		{
			break;
		}


		//Check if best changed and incriment if yes
		if (BV != TBV && BV > TBV)
		{
			TBV = BV;
			BI++;
		}

		//Change BA incase there wasn't best
		if (BA[j + 1] == 0)
		{

			BA[j + 1] = tempindex;
			//cout << "Test BA " << BA[1] << endl; //Test
		}

		//Output best feature
		cout << endl << "Feature set {";
		for (int i = 1; i < BI + 1; i++)
		{

			cout << BA[i] << ",";
		}
		cout << "} was best, accuracy is " << BV << "%" << endl << endl;

		TempFinalValue = -1;
	}

	cout << endl << "Finished Forward search!!! The best Feature subset is {";
	for (int i = 1; i < BI + 1; i++)
	{

		cout << BA[i] << ",";
	}
	cout << "} which has an accuracy of " << FinalValue << "%" << endl << endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int BackwardSearch(double n, double BV, double TBV, double BI, double* A, double* BA)
{

	//Variables
	double tempindex = 0;
	double counter = 1;
	double FeatureCounter = 0;
	double FinalValue = -1;
	double TempFinalValue = -1;
	double ArraySize = ((n * (n + 1)) / 2 + 1);
	double Remove = -1;
	double index = -1;
	int icounter = 0;
	double flag = -1;
	double jcounter = 1;
	double tempy = -1;

	


	//Initialize BA array
	for (int i = 0; i < n + 1; i++) {
		BA[i] = -1;
	}

	// Initial Case
		if (A[0] > BA[0])
		{
			BA[0] = 0;
			tempindex = 1;
			FinalValue = A[0];
		}

	cout << "Using features {";
	
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ", ";
	}
	cout << "} and random evaluation, I get an accuracy of ";
	cout << A[0];
	cout << "%" << endl << endl;
	cout << "Beginning search." << endl << endl;

	BI = 1;
	//@@
	
	BA[6] = 0;


	//Backwards Output
	for (int k = 0; k < n; k++) //4x
	{
		for (int i = 1; i < n - k + 1; i++) // 4 , 3 , 2 , 1 
		{
			cout << "	Using feature(s) {";
			
			for (int j = 1; j < n + 1 - k ; j++) //Iterate through 234 134 124 123
			{
			
				
					if ((j == counter) || BA[0] == j)
					{

					}
					else {
						cout << j << ", ";

					}
				
			}
			
			counter++;

			icounter++;
			cout << "} accuracy is " << A[icounter] << "%";
			
			//Better Value
			if (A[icounter] > FinalValue)
			{
				FinalValue = A[icounter];
				BA[k + 1] = counter - 1;
				flag = 1;
			}
			cout << endl;


		}
		


		//
		cout << endl << "Feature set {";
		tempy = -1;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (i == BA[j])
				{
					tempy++;
				}
				
			}
			if (tempy != -1)
			{

			}
			else { 
				cout << i << ", "; 
			}
			
		}

		cout << "} was best, accuracy is " << FinalValue << "%" << endl << endl;
		
		counter = 1;
		if (flag == -1)
		{
			break;
		}
		
		flag = -1;
	}
	
	//Finished
	cout << endl << "Finished Backwards search!!! The best Feature subset is {";
	tempy = -1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == BA[j])
			{
				tempy++;
			}

		}
		if (tempy != -1)
		{

		}
		else {
			cout << i << ", ";
		}

	}

	cout << "} which has an accuracy of " << FinalValue << "%" << endl << endl;



	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


double classtest(vector<vector<double>> d, vector<double> ctf, double r, double c)
{
	double tempvalue = 0;
	double classifier = -1;
	double best = -1;

	
	for (int i = 0; i < r; i++)
	{
		for (int j = 1; j < c; j++)
		{
			tempvalue += pow((ctf[j] - d[i][j]), 2);
		}

		tempvalue = sqrt(tempvalue);
		if (best == -1)
		{
			best = tempvalue;
			classifier = d[i][0];
		}
		else if (tempvalue < best)
		{
			best = tempvalue;
			classifier = d[i][0];
		}
		tempvalue = 0;
	}

	return classifier;
}



double validator(vector<vector<double>> d, double f[], int fsize, double r, double c, int k)
{
	int correctcounter = 0;
	double tempvalue = 0;
	double tempy = 0;
	double classifier = -1;
	double classifierreal = -1;
	double best = -1;
	vector<vector<double>> validatorvector = d;

	
		for (int i = 0; i < r; i++)
		{
			classifierreal = d[i][0];
			for (int j = 1; j < c; j++)
			{
				
				if (k != i)
				{
					for (int l = 0; l < fsize; l++)
					{
						tempvalue = 0;
						if (f[l] == j)
						{
							
							//cout << "validatorvector: " << validatorvector[k][j] << endl;
							//cout << "d: " << d[i][j] << endl << endl;
							tempvalue +=  pow((validatorvector[k][j] - d[i][j]), 2);
							//cout << "(validatorvector[k][j] - d[i][j]):  " << (validatorvector[k][j] - d[i][j]) << endl;
							//cout << "tempvalue: " << tempvalue << endl;
						}

					}

				}
			}
			//cout << "tempvalue: sqrt before " << tempvalue << endl;
				tempvalue = sqrt(tempvalue);
				//cout << "tempvalue: sqrt after " << tempvalue << endl;
				if ((best == -1) && (tempvalue !=0))
				{
					
					best = tempvalue;
				
					classifier = d[i][0];
				}
				if (tempvalue < best)
				{
					best = tempvalue;
					
					classifier = d[i][0];
				}

				if (classifier == classifierreal) {
					correctcounter++;
				}
				
				tempvalue = 0;

			

		}
		
	

	return (correctcounter*100) / (r*(r-1) * (c-1));
}


///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	


	int row = 0;
	int col = 0;

	double accuracy = -1;
	
	
	
	//Create vector to store data
	vector<vector<double>> data;

	// get the filepath
	string filePath = "testdata.txt";

	// Open the file using ifstream
	ifstream file(filePath);

	// confirm file opening
	if (!file.is_open()) {
		// print error message and return
		cerr << "Failed to open file: " << filePath << endl;

		return 1;
	}

	// Read the file line by line into a string
	string line;
	while (getline(file, line)) {
		stringstream linestream(line);
		vector<double> vectorrow;
		double value;
		row++;

		//Read each value in the line
		while (linestream >> value) {
			vectorrow.push_back(value);
			col++;
		}
		data.push_back(vectorrow);
	}

	// Close the file
	file.close();

	col = col / row;
	
	
	cout << "data: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << fixed << setprecision(8) << data[i][j] << " ";
		}
		cout << endl;
	}
	


	// Class test

	//classtest(data, classtestfeatures, row, col);


	int featuressize = col-1;

	//cout << "Enter the feature numbers: ";

	/*
	int* features = new int[col - 1];
	for (int i = 0; i < col-1; i++)
	{
		features[i] = i;
		cout << features[i] << endl;
	}

	*/

	
	
	

	


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Variables
	int NumFeatures = -1;
	double featureselection = -1;
	double Selection = -1;
	double ArraySize = -1;
	double num = -1;
	double BestIndex = -1;
	double BestValue = -1;
	double TempBestValue = -1;
	double featuresize = -1;
	

	// Prompt User
	cout << "Welcome to William Yi's Feature Selection Algorithm." << endl;
	cout << endl;
	cout << "Please enter total number of features: ";
	
	//Select Number of total Features
	cin >> NumFeatures;
	cout << endl;
	num = NumFeatures;
	



	//Select feature numbers
	cout << "Enter the number of feature(s) to select from total features: ";
	cin >> featuresize;
	cout << endl;


	double* features = new double[featuresize];

	cout << "Enter the features to be selected: " << endl;
	for (int i = 0; i < featuresize; i++)
	{
		cin >> features[i];
	}
	cout << endl;
	



	cout << "Type the number of the algorithm you want to run.";
	cout << endl << endl;
	cout << "1) Forward Selection" << endl;
	cout << "2) Backward Elimination" << endl;
	cout << endl;

	//Select Algorithm
	cin >> Selection;

	// Create array list 
	// Best Array
	double*BestArray = new double[featuresize + 1];

	// 1 + 2 + 3 + 4... summation = (N * (N+1)) /2
	ArraySize = (featuresize * (featuresize + 1)) / 2 + 1;
	double *Array = new double[ArraySize];



	//Fill in array values
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = validator(data, features, featuressize, row, col, i);
		
	}
	





	cout << endl;


	if (Selection == 1)
	{
		ForwardSearch(num, BestValue, TempBestValue, BestIndex, Array, BestArray);
	}

	if (Selection == 2)
	{
		BackwardSearch(num, BestValue, TempBestValue, BestIndex, Array, BestArray);
	}



	delete[] Array;
	cout << endl;

	
	return 0;
}

///////////////////////////////////////////////////////////////

