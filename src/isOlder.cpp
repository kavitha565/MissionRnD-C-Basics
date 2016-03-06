/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int checkdate(int day1, int day2, int month1, int month2, int year1, int year2)
{
	if (day1 == 0 || day2 == 0 || month1 == 0 || month2 == 0 || year1 == 0 || year2 == 0)
		return(-1);
	else if (month1>12 || month2>12 || day1>31 || day2>31)
		return(-1);
	else if (month1 == 2 || month2 == 2)
	{
		if (year1 % 4 == 0)
		{
			if (day1>29)
				return(-1);
		}
		else
		{
			if (day1>28)
				return(-1);
		}
		if (year2 % 4 == 0)
		{
			if (day2>29)
				return(-1);
		}
		else
		{
			if (day2>28)
				return(-1);
		}

	}
	if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
	{
		if (day1>30)
			return(-1);
	}
	if (month2 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
	{
		if (day2>30)
			return(-1);
	}
}
int isOlder(char *dob1, char *dob2) {
	int day1, day2, month1, month2, year1, year2, flag;
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return(-1);
	day1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	day2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	month1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	month2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	year1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
	year2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
	flag = checkdate(day1, day2, month1, month2, year1, year2);
	if (flag != -1)
	{
		if (year1<year2)
		{
			return(1);
		}
		else if (year1>year2)
		{
			return(2);
		}
		else
		{
			if (month1<month2)
				return(1);
			else if (month1>month2)
				return(2);
			else
			{
				if (day1<day2)
					return(1);
				else if(day1>day2)
					return(2);
				else
					return(0);
			}
		}
	}
	else
	return(-1);

}